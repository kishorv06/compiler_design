#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[20],val[10][18],sym[10],ip[50];
int top = -1,nop;

char* subString(char * str,int position, int length){
  int c=0;
  char* sub= malloc(length-position);
  while (c < length) {
      *(sub+c) = *(str+position+c);
      c++;
   }
   *(sub+c) = '\0';
  return sub;
}

char* srev(char* str,int length){
	int i,j;
	char* sub= malloc(length);
	for(i=0,j=length-1;i<length;i++,j--)
		*(sub+i)=*(str+j);
	 *(sub+i) = '\0';
	return sub;
}

int isReduce(){
	int i =0,j;
	char str[20];
	char* s;
	while(i<top){
		for(j=0;j<=i;j++)
			str[j] = stack[top-j];
		str[j] ='\0';
		s=srev(str,strlen(str));
		for(j=0;j<nop;j++){
			//printf("\n%s\t%s",s,val[j]);
			if(!strcmp(s,val[j])){
			return j;
			break;
			}
		}
		i++;
	}
	return -1;
}

void reduce(int pos){
	int i =0,j,k;
	char str[20];
	char* s;
	while(i<top){
		for(j=0;j<=i;j++)
			str[j] = stack[top-j];
		str[j] ='\0';
		s=srev(str,strlen(str));
		for(j=0;j<nop;j++){
			if(!strcmp(s,val[j])){
				top-=i;
				stack[top] = sym[pos];
				return;
			}
		}
		i++;
	}
}

void print(int pos,int index){
	int i=0;
	char msg[3][7]= {"NONE","SHIFT","REDUCE"};
	printf("%s\t\t",msg[index]);
	for(i=0;i<=top;i++)
		printf("%c",stack[i]);
	printf("\t\t");
	for(i=pos;i<strlen(ip);i++)
		printf("%c",ip[i]);
	printf("\n");
}

int main(){
  int i,j,k;
  printf("Enter number of productions: ");
  scanf("%d", &nop);
  char prod[nop][20],str[20];
  printf("Enter the productions: \n");
  for (i = 0; i < nop; i++){
    scanf("%s", prod[i]);
  }
  for (i = 0; i < nop; i++)
    {
      sym[i] = prod[i][0];
      strcpy (val[i],subString(prod[i],2,strlen(prod[i])));
      //printf("Sym: %c\tVal: %s\n",sym[i],val[i]);
    }
    
    printf("Enter the input string: ");
    scanf("%s", ip);

  stack[++top]='$';
  i=0;
  printf("\nAction\t\tStack\t\tInput Buffer\n");
  print(i,0);
 do
    {
    if(top==0){
    	stack[++top] = ip[i++];
    	print(i,1);
    }
    	
   
      if ((top == 1) && (ip[i] == '$')) {
        printf("\nString is accepted\n");
        break;
      } else if(k=isReduce()!=-1){
       		reduce(k);
       		print(i,2);
       } else if(ip[i] != '$'){
      		stack[++top] = ip[i++];	
      		print(i,1);	
      } else {
	 printf("\nString is rejected\n");
        break;
	}
    } while (1);

  return 0;
}
