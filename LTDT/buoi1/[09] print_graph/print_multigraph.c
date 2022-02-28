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
    if(u != v){
        pG->A[v][u]++;
    }
	pG->m++;
}

void print_graph(Graph G){
    for (int i = 1; i <= G.n; i++) {
        for(int j = 1; j <= G.n; j++) {
            printf("%d ", G.A[i][j]);           
        }
        printf("\n");
    }
}

void read_graph(Graph *pG){
    int n, m;
    scanf("%d %d", &n, &m);
    init_graph(pG, n);
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(pG, u, v);
    }
}
int main(){
    Graph G;
    read_graph(&G);
    printf("Ma tran ke:\n");
    print_graph(G);
}
