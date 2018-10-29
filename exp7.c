#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void removeChar(char *str, char garbage) {

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}

void main(){
	int states = 0,i,j,k,l,inp;
	char tmp;
	printf("Enter number of states : ");
	scanf("%d",&states);
	printf("Enter the number of input symbols : ");
	scanf("%d",&inp);
	char ttable[states][inp];
	printf("Enter the Transition table : \n \t");
	for(i=0;i<inp;i++) printf("%d\t",i);
	for(i=0;i<states;i++){
		printf("\n%c\t",(char)(65+i)); // Print first row element ie. State
		for(j=0;j<inp;j++){
			scanf(" %c",&ttable[i][j]);
		}
	}
	char sets[states][states+1];
	int groups = 2;
	printf("Enter the final states : ");	
	scanf("%s",sets[1]);	
	for(i = 0;i<states;i++){
		if(strchr(sets[1],(char)(65+i)) == NULL)
			sprintf(sets[0],"%s%c",sets[0],65+i);
	}
	printf("NON F : %s\nF : %s \n",sets[0],sets[1]);
	i=0;	
	while(i<groups){
		for(j=0;j<states && sets[i][j]!='\0';j++){
			for(k=0;k<inp;k++){
				char c = ttable[65-sets[i][j]][k];
				if(strchr(sets[i],c)==NULL){
					sprintf(sets[groups],"%c",sets[i][j]);
					removeChar(sets[i],sets[i][j]);					
					groups+=1;
					i = 0;
				}		
			}	
		}
		i += 1;
		for(j=0;j<groups;j++)
			printf("%d : %s\n",sets[i]);
	}
}


