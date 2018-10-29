%token DIGIT NAME

%%
stmt	:	NAME '=' exp ';'
	;
exp	:	exp '+' exp
	|	exp '-' exp
	|	exp '*'	exp
	|	exp '/' exp
	|	'(' exp ')'
	|	DIGIT
	;

%%
int main(void){
	yyparse();
	return 0;
}
