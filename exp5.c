#include<stdio.h>
#include<string.h>

void findE(int i,int *visited,char *matrix,int states,int ep){
    if(visited[i] == 1) return; // If already in list return
    visited[i] = 1;
    int j;
    char *temp =  (matrix+(i*states*(ep+1))+ep*states); // Get the list of states in the cell [i][ep]
    for(j=0;j<strlen(temp) && temp[j] != '-';j++) // For each state in the list, recrusive call.
	    findE((int)(temp[j])-65,visited,matrix,states,ep);
}

void main(){
    int states = 0,i,j,k,l;
    printf("Enter number of states : ");
    scanf("%d",&states);
    int visited[states],inp;
	printf("Enter the number of input symbols : ");
	scanf("%d",&inp);
	char ttable[states][inp+1][states],temp[states+1];
    printf("Enter the Transition table : \n \t");
    for(i=0;i<inp;i++) printf("%d\t",i); // Print the columns
	printf("E");
    for(i=0;i<states;i++){
        printf("\n%c\t",(char)(65+i)); // Print first row element ie. State
        for(j=0;j<inp+1;j++)
			scanf("%s",ttable[i][j]);
    }
    printf("\nResult\n \t\t");
    for(i=0;i<inp;i++) printf("%d\t\t",i); // Print the columns
	printf("\n");
    for(i=0;i<states;i++){
        for(j=0;j<states;j++) visited[j] = 0; // Reset visited
        findE(i,visited,(char *)ttable,states,inp); //Start recursive call
        for(j=0;j<states;j++) 
            if (visited[j] == 1) printf("%c",j+65); // Print the E closure - ie new states
        printf("\t\t");
        for(j=0;j<inp;j++){ // For each transition symbol
            int printed[states]; // To prevent repeats when merging cells
            for(k=0;k<states;k++) printed[k] = 0; // Reset printed
            for(k=0;k<states;k++) // For each state
                if(visited[k] == 1){ // If state is in the E closure
                    char *str = ttable[k][j]; // cell at [k][j]
                    for(l=0;l<strlen(str) && str[l] != '\0' && str[l] != '-';l++) // While str is not '-' or '\0'.
                        if(printed[str[l] - 65] == 0){   // If not yet printed, print it
                            printed[str[l] -65] = 1; // Mark as printed
                            printf("%c",str[l]);
                        }
                }
            printf("\t\t");
        }
        printf("\n");
        
    }
    printf("\n");
}
