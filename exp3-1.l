%{
#include <stdlib.h>
void yyerror(char *);
#include "y.tab.h"

%}
number		[0-9]
id		[A-z|_]([A-z]|[0-9])*

%%
" "		;
{number}	{return(DIGIT);};
{id}		{return(NAME);};
.		{return yytext[0];};
%%
int yywrap(void){
	return 1;
}
