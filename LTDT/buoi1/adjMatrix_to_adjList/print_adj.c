#include <stdio.h>

#define MAX_N 100

typedef struct{
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n){
	pG->n = n;
	pG->m = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; i <= n; i++)
			pG->A[i][j] = 0;
}

void read_graph(Graph *pG){
    int n, k;
    scanf("%d", &n);
    init_graph(pG, n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &k);
            while(k--){
                pG->A[i][j]++;
                pG->m++;
            }
        }
    }
}

void print_adj(Graph G){
    for(int i = 1; i <= G.n; i++){
        for(int j = 1; j <= G.n; j++){
            while(G.A[i][j]--) printf("%d ", j);
        }
        printf("0\n");
    }
}

int main(){
    Graph G;    
    read_graph(&G);
    print_adj(G);
}
