#include <stdio.h>
#include <string.h>

int isIn(char text[],char *newstates, int size){
    int i;
    for(i=0;i<size;i++){
        if(strcmp(text,newstates+i*size) == 0) return 1;
    }
    return 0;
}

int shouldSkipState(int state,char *newstates,int size){
    int i,j;
    char *temp;
    for(i=0;i<size;i++){
        temp = newstates+(i*size);
        for(j=0;temp[j] != '\0';j++)
            if(temp[j] == (char)state) return 1;
    }
    return 0;
}

void addToNewState(char *state,char *newstates,int *nsp,int states){
    int i;
    if(!isIn(state,newstates,states+1)){
        for(i=0;i<states && nsp[i] != -1;i++);
        if(i != states){
            strcpy(newstates+i*(states+1),state);
            nsp[i] = 0;
        }
    }
}


void main(){
    int states = 0,i,j,final,inp;
    printf("Enter number of states : ");
    scanf("%d",&states);
	printf("Enter the number of input symbols : ");
	scanf("%d",&inp);
	char newstates[states][states+1],ttable[states][inp][states];
    printf("Enter the Transition table : \n \t");
    for(i=0;i<inp;i++) printf("%d\t",i); // Print the columns
    for(i=0;i<states;i++){
        printf("\n%c\t",(char)(65+i)); // Print first row element ie. State
        for(j=0;j<inp;j++)
			scanf("%s",ttable[i][j]);
    }
    printf("Enter the final state : ");
    scanf(" %c",(char *)&final);
    final -= 65;
    printf("\nResult\n \t\t");    
    int nsp[states];
    for(i=0;i<states;i++) nsp[i] = -1;
    for(i=0;i<inp;i++) printf("%d\t\t",i); // Print the columns
	printf("\n");
    char cstate[2];
    int skip;
    for(i=0;i<states;i++){    
        skip = shouldSkipState(i+65,(char *)newstates,states+1);    
        if(!skip) printf("%c\t\t",i+65);
        for(j=0;j<inp;j++){
            if(strlen(ttable[i][j]) > 1){
                addToNewState(ttable[i][j],(char *)newstates,nsp,states);
            }
            if(!skip) printf("%s\t\t",ttable[i][j]);
        }
        if(!skip) printf("\n");
        //printNewStates(newstates,nsp,ttable,states);
    }
    for(i=0;i<states && nsp[i] != -1;i++)printf("New state %s\n",newstates[i]);
}
