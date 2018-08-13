#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isin(int* arr,int value){
	while(*arr != -1){
		if(*arr == value) return 1;
		arr++;
	}
	return 0;
}

void insertinto(int* arr,int val,int len){
	while(*arr != -1)
		arr++;
	*arr = val;
}

void findEpsilon(int state,int matrix[][10][10],int* visited,int* closure,int scnt,int ep){
	int *states = matrix[state][ep];
	while(*states != -1){
		if(!isin(visited,*states)){
			insertinto(visited,*states,scnt);
			insertinto(closure,*states,scnt);
			findEpsilon(*states,matrix,visited,closure,scnt,ep);
		}
		states++;
	}
}

void main(){
	int states,symbols,i,j,k,ep=0;
	printf("Enter the number of states and symbols : ");
	scanf("%d %d",&states,&symbols);
	int matrix[states][symbols][states+1];
	char inpsymbls[symbols],temp[10];
	printf("Enter the input symbols : \n");
	for(i=0;i<symbols;i++){
		scanf(" %c",&inpsymbls[i]);
		if(inpsymbls[i] == 'E')
			ep = i;
	}
	printf("Enter the transition table:\n");
	printf("State\t");
	for(i=0;i<symbols;i++)
                printf("%c\t",inpsymbls[i]);
	printf("\n");
	for(i=0;i<states;i++){
		printf("%d\t",i);
		for(j=0;j<symbols;j++){
			scanf("%s",temp);
			for(k=0;k<strlen(temp);k++)
				matrix[i][j][k] = atoi(&temp[k]);
		}
	}
	int visited[states],closure[states];
	for(i=0;i<states;i++){
                printf("\n%d\t",i);
		for(j=0;j<states;j++){
			visited[j] = -1;
			closure[j] = -1;
		}
		findEpsilon(i,matrix,visited,closure,states,ep);
		for(j=0;j<states;j++)
			printf("%d\t",closure[j]);
       }
}
