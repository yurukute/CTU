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

void add_edge(Graph *pG, int u, int v) {
	pG->A[u][v]++;
	pG->m++;
}

void read_matrix(Graph *pG){
    int n, k;
    scanf("%d", &n);
    init_graph(pG, n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &k);
            while(k--)
                pG->A[i][j]++;
        }
    }
}

void print_edges(Graph G){
    for(int i = 1; i <= G.n; i++){
        for(int j = i; j <= G.n; j++){
            while(G.A[i][j]--)
                printf("%d %d\n", i, j);
        }
    }
}

int main(){
    Graph G;    
    read_matrix(&G);
    print_edges(G);
}
