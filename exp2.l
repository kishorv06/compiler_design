keyword	auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while
number		[0-9]+
aops		\+|-|\*|\/|%
rops		==|!=|<=|>=|>|<
lops		&&|\|\||!
asop		=|\+=|-=|\/=|\*=|%=
scmt		\/\/.*
mcmt		\/\*(.|\n)*\*\/
str		\".*\"
id		[A-z|_]([A-z]|[0-9])*	
header		#.*

%%
{scmt}		;
{mcmt}		;
{header}	;
{str}		{printf("<%s,LITERAL>\n",yytext);};
{keyword}	{printf("<%s,KEYWORD>\n",yytext);};
{number}	{printf("<%s,NUMBER>\n",yytext);};
{asop}		{printf("<%s,ASG-OPERATOR>\n",yytext);};
{rops}		{printf("<%s,REL-OPERATOR>\n",yytext);};
{lops}		{printf("<%s,LOG-OPERATOR>\n",yytext);};
{aops}		{printf("<%s,ARTH-OPERATOR>\n",yytext);};
{id}		{printf("<%s,IDENTIFIER>\n",yytext);};
.					;
\n 				;
%%

void main(){
	FILE *fp=fopen("code.c","r");
	yyin=fp;
	yylex();
}
