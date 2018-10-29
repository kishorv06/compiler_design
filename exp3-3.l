%{
#include <stdlib.h>
void yyerror(char *);
#include "y.tab.h"

%}
number		[0-9]

%%
{number}	{	yylval = atoi(yytext);
			return(DIGIT);
		};
" "		;
.|\n		{	return yytext[0];
		};
%%
int yywrap(void){
	return 1;
}
