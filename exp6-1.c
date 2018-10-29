#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define STATES  256
#define SYMBOLS 20
 
int N_symbols; 
int NFA_states;
char *NFAtab[STATES][SYMBOLS];
 
int DFA_states; /* number of DFA states */
int DFAtab[STATES][SYMBOLS];
 
/*Print state-transition table.*/
void put_dfa_table(int tab[][SYMBOLS],int nstates,int nsymbols){
    int i, j;
    puts("STATE TRANSITION TABLE");
    /* input symbols: '0', '1', ... */
    printf("     | ");
    for (i = 0; i < nsymbols; i++) printf("  %c  ", '0'+i);
    printf("\n-----+--");
    for (i = 0; i < nsymbols; i++) printf("-----");
    printf("\n");
    for (i = 0; i < nstates; i++) {
        printf("  %c  | ", 'A'+i);  /* state */
        for (j = 0; j < nsymbols; j++)
            printf("  %c  ", 'A'+tab[i][j]);
        printf("\n");
    }
}

void init_NFA_table(){
    DFA_states = 0;
	printf("Enter number of states : ");
    scanf("%d",&NFA_states);
	printf("Enter the number of input symbols : ");
	scanf("%d",&N_symbols);
	int i,j,k;
	char temp[NFA_states+1];
	printf("Enter the Transition table : \n \t");
    	for(i=0;i<N_symbols;i++) printf("%d\t",i); // Print the columns
	for(i=0;i<NFA_states;i++)
		printf("\n%c\t",(char)('A'+i));
		for(j=0;j<N_symbols;j++){
			NFAtab[i][j] = (char *) malloc(sizeof(char)*NFA_states+1);
			scanf("%s",NFAtab[i][j]);
			if(NFAtab[i][j][0] == '-') NFAtab[i][j][0] = '\0';
			for(k=0;k<NFA_states && NFAtab[i][j][k] != '\0';k++){
				NFAtab[i][j][k] -= 'A';
				NFAtab[i][j][k] += '0';
			}
			printf("%s",NFAtab[i][j]);
		}
}
void string_merge(char *s, char *t){
    char temp[STATES], *r=temp, *p=s;
    while (*p && *t) {
        if (*p == *t) {
            *r++ = *p++; t++;
        } else if (*p < *t) {
            *r++ = *p++;
        } else
            *r++ = *t++;
    }
    *r = '\0';
    if (*p) strcat(r, p);
    else if (*t) strcat(r, t);
    strcpy(s, temp);
}
 
/*Get next-state string for current-state string.*/
void get_next_state(char *nextstates, char *cur_states,char *nfa[STATES][SYMBOLS], int n_nfa, int symbol){
    int i;
    char temp[STATES];
    temp[0] = '\0';
    for (i = 0; i < strlen(cur_states); i++)
        string_merge(temp, nfa[cur_states[i]-'0'][symbol]);
    strcpy(nextstates, temp);
}
 
 
int state_index(char *state, char statename[][STATES], int *pn){
    int i;
    if (!*state) return -1; /* no next state */
    for (i = 0; i < *pn; i++)
        if (!strcmp(state, statename[i])) return i;
    strcpy(statename[i], state);    /* new state-name */
    return (*pn)++;
}
 
int nfa_to_dfa(char *nfa[STATES][SYMBOLS], int n_nfa,int n_sym, int dfa[][SYMBOLS]){
    char statename[STATES][STATES];
    int i = 0;  /* current index of DFA */
    int n = 1;  /* number of DFA states */
    char nextstate[STATES];
    int j;
    strcpy(statename[0], "0");  /* start state */
    for (i = 0; i < n; i++) {    /* for each DFA state */
        for (j = 0; j < n_sym; j++) {    /* for each input symbol */
            get_next_state(nextstate, statename[i], nfa, n_nfa, j);
            dfa[i][j] = state_index(nextstate, statename, &n);
        }
    }
    return n;   /* number of DFA states */
}
 
void main()
{
    init_NFA_table();
    DFA_states = nfa_to_dfa(NFAtab, NFA_states, N_symbols, DFAtab);
    put_dfa_table(DFAtab, DFA_states, N_symbols);
}
