%{
	#include <stdio.h>
	int yylex(void);
	void yyerror(char *);
%}
%start stmt

%token DIGIT NAME

%%
stmt	:	NAME '=' exp ';' 
	{	printf("Valid Statement\n");
	}
	;
exp	:	exp '+' exp
	|	exp '-' exp
	|	exp '*'	exp
	|	exp '/' exp
	|	'(' exp ')'
	|	DIGIT
	;

%%
void yyerror(char *s){
	printf("Invalid Statement\n");
	return;
}

int main(void){
	yyparse();
	return 0;
}
