#include <stdio.h>
#include <ctype.h>
#include <string.h>
int iskeyword(char buff[10]){
	char keywords[32][10] =  {"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while"};
	int i,j,flag;
	for(i=0;i<32;i++){
		j=0;
		flag = 1;
		while(flag){
			if(buff[j] != keywords[i][j])
				flag=0;
			else if(j == strlen(buff))
				break;
			j++;
		}
		if(flag) return 1;
	}
	return 0;
}

int isterminal(char ch){
	if (ch != '\0' || ch != '\n' || ch != '\t' || ch != ';' || ch != ' ') return 1;
	return 0;
}

void main(){
	FILE *fp=fopen("tester.c","r");
	char ch,ops[]="+-*/%=",buff[10];
	int i;
	while((ch = fgetc(fp))!= EOF){
		if(isdigit(ch))
			printf("<%c,digit>\n",ch);
		else if(isalpha(ch)){
			i = 0;
			buff[i++] =  ch;
			while((ch = fgetc(fp))!= EOF)
				if(isterminal(ch))
					buff[i++] = ch;
			buff[i++] = '\0';
			if(iskeyword(buff))
				printf("<%s,keyword>",buff);
		}

	}
	fclose(fp);
}
