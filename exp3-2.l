%{
#include <stdlib.h>
void yyerror(char *);
#include "y.tab.h"

%}
number		[0-9]
char		[A-z]

%%
" "		;
{number}	{return(DIGIT);};
{char}		{return(CHAR);};
.|\n		{return yytext[0];};
%%
int yywrap(void){
	return 1;
}
