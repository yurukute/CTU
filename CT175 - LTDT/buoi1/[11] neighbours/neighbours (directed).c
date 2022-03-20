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

void neighbours(Graph *pG, int u){
    for(int i = 1; i <= pG->n; i++){
        if(pG->A[u][i])
            printf("%d ", i);
    }    
}

int main(){
    Graph G;
    read_graph(&G);
    for(int i = 1; i <= G.n; i++){
        printf("neighbours(%d) = ", i);
        neighbours(&G, i);
        printf("\n");
    }
}
