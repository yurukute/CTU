#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_M 100
#define MAX_N 100

typedef struct {
	int m, n;
	int A[MAX_M][MAX_N];
	int r, c;
} State;

void init_state(State *S, char *fname){
    FILE *f = fopen(fname, "r");
    fscanf(f, "%d %d", &S->m, &S->n);
    for(int i = 0; i < S->m; i++){
        for(int j = 0; j < S->n; j++){
            fscanf(f, "%d", &S->A[i][j]);
        }
    }
    fscanf(f, "%d %d", &S->r, &S->c);
}

void print_state(State S){
    for(int i = 0; i < S.m; i++){
		for(int j = 0; j < S.n; j++)
		    if(i != S.r || j != S.c)
			    printf("%2d ", S.A[i][j]);
			else 
			    printf(".. ");
		printf("\n");
	}
	printf("%d %d\n", S.r, S.c);
}

int is_finished(State S){
	for(int i = 0; i < S.m; i++)
	    for(int j = 0; j < S.n; j++)
		    if(S.A[i][j] != i*S.n + j + 1)
			    return 0;
	return 1;
}

int up(State S, State *N){
    *N = S;
    if(N->r == 0)
        return 0;
    int x = N-> r;
    int y = N-> c;
    int t = N->A[x][y];
    N->A[x][y] = N->A[x-1][y];
    N->A[x-1][y] = t;
    N->r--;
    return 1;
}

int down(State S, State *N){
    *N = S;
    if(N->r == N->m-1)
        return 0;
    int x = N-> r;
    int y = N-> c;
    int t = N->A[x][y];
    N->A[x][y] = N->A[x+1][y];
    N->A[x+1][y] = t;
    N->r++;
    return 1;
}

int left(State S, State *N){
    *N = S;
    if(N->c == 0)
        return 0;
    int x = N-> r;
    int y = N-> c;
    int t = N->A[x][y];
    N->A[x][y] = N->A[x][y-1];
    N->A[x][y-1] = t;
    N->c--;
    return 1;
}

int right(State S, State *N){
    *N = S;
    if(N->c == N->n-1)
        return 0;
    int x = N-> r;
    int y = N-> c;
    int t = N->A[x][y];
    N->A[x][y] = N->A[x][y+1];
    N->A[x][y+1] = t;
    N->c++;
    return 1;
}

int main(){
	State S;
	char *fname, *cmd;
	fname = (char*) malloc(10);
	cmd = (char*) malloc(5);
	scanf("%s", fname);
	init_state(&S, fname);
	while(!is_finished(S)){
		print_state(S);
		scanf("%s", cmd);
		if(strcmp(cmd,"UP") == 0){
			if(!up(S, &S)) printf("Illegal move.\n");
		}
		else if(strcmp(cmd,"DOWN") == 0){
		    if(!down(S, &S)) printf("Illegal move.\n");
		}
		else if(strcmp(cmd,"LEFT") == 0){
			if(!left(S, &S)) printf("Illegal move.\n");
		}
		else if(strcmp(cmd,"RIGHT") == 0){
			if(!right(S, &S)) printf("Illegal move.\n");
		}
		else if(strcmp(cmd, "EXIT") == 0){
			printf("You lose!");
			return 0;
		}
        else printf("Unknown command, please enter: UP, DOWN, LEFT, RIGHT or EXIT\n");
	}
    if(is_finished(S)) printf("You win!");
}
