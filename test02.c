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



int isop(char *buff){
	char aops[][2]={"+","-","*","/","%","="};
	char relops[][3]={"==","!=","<=",">="};
	char logops[][3]={"&&","||","!"};
	char asgops[][3]={"+=","-=","/=","*=","==","%="};
	int i;
	for(i=0;i<4;i++){
		if(strcmp(relops[i],buff) == 0){
			printf("<%s,relop>\n",buff);
			return 1;
		}
	}
	for(i=0;i<3;i++){
		if(strcmp(logops[i],buff) == 0){
			printf("<%s,logop>\n",buff);
			return 1;
		}
	}
	for(i=0;i<6;i++){
		if(strcmp(asgops[i],buff) == 0){
			printf("<%s,asgop>\n",buff);
			return 1;
		}
	}
	for(i=0;i<6;i++){
		if(strcmp(aops[i],buff) == 0){
			printf("<%s,arthop>\n",buff);
			return 1;
		}
	}
	return 0;
}

void trim(char * s) {
    char * p = s;
    int l = strlen(p);

    while(isspace(p[l - 1])) p[--l] = 0;
    while(* p && isspace(* p)) ++p, --l;

    memmove(s, p, l + 1);
}   

void main(){
	FILE *fp=fopen("tester.c","r");
	size_t size = 1024;
	char *line = NULL,buff[10],*tok;
	int status,count=0;
	while((status = getline(&line,&size,fp)) != EOF){
		line = strtok(line,";");
		trim(line);
		if(line != NULL){
			tok = strtok(line," ");
			while(tok != NULL){
				trim(tok);
				if(iskeyword(tok)){
					printf("<%s,keyword>\n",tok);
					count++;
				}else if(isdigit(tok[0])){
					printf("<%s,number>\n",tok);
					count++;
				}else if(isop(tok))
					count++;
				tok = strtok(0," ");
			}
		}
	}
	printf("Total tokens : %d",count);
	fclose(fp);
}
