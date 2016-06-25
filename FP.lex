%{
#include "FP.h"
#include <stdio.h>
#include "y.tab.h"
%}
constants			(CONSTANTS)
functions			(FUNCTIONS)
main				(MAIN)
readkey				(read)
printkey			(print)
returnkey			(return)
ifstmt				(if)
thenstmt			(then)
elsestmt			(else)
loopstmt 			(loop)
whilestmt 			(while)
equal				(=)
spaces				[ ]*
predefined_function		((\+)|(\*)|(\-)|(\/)|(\%))
comparison_op			(==|>|<|>=|<=|!=)
open_special_char		([\{])
close_special_char		([\}])
boolean				[T]|[F]	
invalidnum			([1-9]+[2-9][0-9]{6})|([\-]{spaces}[1-9]+[2-9][0-9]{6})|([1][0]{7}[0-9]+)|([\-]{spaces}[1][0]{7}[0-9]+)|([1][0]{6}[1-9][0-9]*)|([\-]{spaces}[1][0]{6}[1-9][0-9]*)|([1][0]{5}[1-9][0-9]+)|([\-]{spaces}[1][0]{5}[1-9][0-9]+)|([1][0]{4}[1-9][0-9][0-9]*)|([\-]{spaces}[1][0]{4}[1-9][0-9][0-9]*)|([1][0]{3}[1-9][0-9][0-9][0-9]*)|([\-]{spaces}[1][0]{3}[1-9][0-9][0-9][0-9]*)|([1][0]{2}[1-9][0-9][0-9][0-9][0-9]+)|([\-]{spaces}[1][0]{2}[1-9][0-9][0-9][0-9][0-9]+)|([1][0]{1}[1-9][0-9][0-9][0-9][0-9][0-9]+)|([\-]{spaces}[1][0]{1}[1-9][0-9][0-9][0-9][0-9][0-9]+)|([1][0-9][0-9][0-9][0-9][0-9][0-9][1-9]+)|([\-]{spaces}[1][0-9][0-9][0-9][0-9][0-9][0-9][1-9]+)|([1-9]+[2-9][0-9]{7})|([\-]{spaces}[1-9]+[2-9][0-9]{7})
float				(0[\.][0-9]+)|([1-9]+[\.][0-9]+)|(0[\.][0]+)|([\-]{spaces}0[\.][1-9][0-9]*)|([\-]{spaces}[1-9]+[\.][0-9]+)|([\-]{spaces}0[\.][0]+[1-9]+[0-9]*)
integer				([0-9])|([\-]{spaces}[1-9])|([1-9][0-9])|([\-]{spaces}[1-9][0-9])|([1-9][0-9]{2})|([\-]{spaces}[1-9][0-9]{2})|([1-9][0-9]{3})|([\-]{spaces}[1-9][0-9]{3})|([1-9][0-9]{4})|([\-]{spaces}[1-9][0-9]{4})|([1-9][0-9]{5})|([\-]{spaces}[1-9][0-9]{5})|([1-9][0-9]{6})|([\-]{spaces}[1-9][0-9]{6})|([1][0]{7})|([\-]{spaces}[1][0]{7})
number				({integer}|{float})
identifier			[a-z]+
invalid_id			([A-Z]+)					
string				([\(][a-z,A-Z,0-9, ,\n,\\n]+[\)])	
space				[\n, ,\t,\r]
invalid_char			[\`]|[\~]|[\!]|[\@]|[\#]|[\$]|[\^]|[\&]|[\_]|[\:]|[\;]|[\|]|[\']|[\"]|[\,]|[\?]|[\\]|[\.]
%%

{constants}							{ yylval.string_val = strdup(yytext); return constant; }
{functions}							{ yylval.string_val = strdup(yytext); return function; }
{main}								{ yylval.string_val = strdup(yytext); return mainkey; }
{readkey}							{ yylval.string_val = strdup(yytext); return readkey; }
{printkey}							{ yylval.string_val = strdup(yytext); return printkey; }
{returnkey}							{ yylval.string_val = strdup(yytext); return returnkey; }
{ifstmt}							{ yylval.string_val = strdup(yytext); return ifkey; }
{thenstmt}							{ yylval.string_val = strdup(yytext); return thenkey; }
{elsestmt}							{ yylval.string_val = strdup(yytext); return elsekey; }
{loopstmt}							{ yylval.string_val = strdup(yytext); return loop; }
{whilestmt}							{ yylval.string_val = strdup(yytext); return whilekey; }
{equal}								{ yylval.string_val = strdup(yytext); return equal; }
"exit"				 			  	{ yylval.string_val = strdup(yytext); return exit_command;}
{predefined_function}						{ yylval.string_val = strdup(yytext); return predefined; }
{comparison_op}							{ yylval.string_val = strdup(yytext); return comparison_op; }
{open_special_char}						{ yylval.string_val = strdup(yytext); return open_spl_char; }
{close_special_char}						{ yylval.string_val = strdup(yytext); return close_spl_char; }
{boolean}							{ yylval.string_val = strdup(yytext); return boolean; }
{string}							{ yylval.string_val = strdup(yytext); return string; }
{identifier}							{ yylval.string_val = strdup(yytext); return identifier; }
{invalid_id}							{ ECHO; yyerror ("unexpected character"); }
{invalidnum}							{ ECHO; yyerror ("unexpected character"); }
{invalid_char}							{ ECHO; yyerror ("unexpected character"); }
{integer}							{ yylval.string_val = strdup(yytext); return integer_value; }
{float}								{ yylval.string_val = strdup(yytext); return float_value; }
%%

int yywrap (void) {return 1;}