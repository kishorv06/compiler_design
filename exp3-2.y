%{
	#include <stdio.h>
	int yylex(void);
	void yyerror(char *);
%}
%start stmt

%token DIGIT CHAR

%%
stmt 	:	var '\n'
	{	printf("Valid Variable\n");
		return 0;
	}
	;
var	:	CHAR chardig
	|	'_' chardig
	;

chardig :	CHAR chardig
	|	DIGIT chardig
	|	CHAR
	|	DIGIT
	;

%%
void yyerror(char *s){
	printf("Invalid Variable\n");
	return;
}

int main(void){
	yyparse();
	return 0;
}
