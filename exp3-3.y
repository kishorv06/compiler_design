%{
	#include <stdio.h>
	int yylex(void);
	void yyerror(char *);
%}
%start stmt

%token DIGIT
%left '+' '-'
%left '*' '/'

%%
stmt	:	exp '\n'
	{	printf("%d\n",$1);
		return 0;
	}
	;
exp	:	exp '+' exp
	{	$$ = $1 + $3;
	}	
	|	exp '-' exp
	{	$$ = $1 - $3;
	}
	|	exp '*'	exp
	{	$$ = $1 * $3;
	}
	|	exp '/' exp
	{	$$ = $1 / $3;
	}
	|	'(' exp ')'
	{	$$ = $2;
	}
	|	DIGIT
	{	$$ = $1;
	}
	|	DIGIT DIGIT
	{	$$ = $$*10 + $2;
	}
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
