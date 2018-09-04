#include<stdio.h>

char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void findE(int i,int *visited,int *matrix,int states){
    if(visited[i] == 1) return; //If already in list return
    visited[i] = 1;
    printf("%c",alpha[i]);
    int j;
    for(j=0;j<states;j++)
        if(*((matrix+i*states)+j) == 1 && i != j) // If there is transition, and not self, recursive call
            findE(j,visited,matrix,states);
}

void main(){
    int states = 0,i,j;
    printf("Enter number of states : ");
    scanf("%d",&states);
    int matrix[states][states];
    int visited[states];
    printf("Enter the transition matrix for input symbol E : \n \t");
    for(i=0;i<states;i++) printf("%c\t",alpha[i]); //Print the columns
    for(i=0;i<states;i++){
        printf("\n%c\t",alpha[i]); //Print first row element ie. State
        for(j=0;j<states;j++)
            scanf("%d",&matrix[i][j]); //Read is there transition or not (1/0)
    }
    printf("\nEpsilon Closures\n");
    for(i=0;i<states;i++){
        for(j=0;j<states;j++) visited[j] = 0; //Reset visited
        printf("\n%c\t->",alpha[i]);
        findE(i,visited,(int *)matrix,states); //Start recursive call
    }
    printf("\n");
}