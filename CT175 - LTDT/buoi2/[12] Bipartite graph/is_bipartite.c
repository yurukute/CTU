#include <stdio.h>

#define MAX_N 100

typedef struct{
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph (Graph *pG, int n){
	pG->n = n;
	pG->m = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; i <= n; i++)
			pG->A[i][j] = 0;
}

void add_edge (Graph *pG, int u, int v) {
	pG->A[u][v] = 1;
    pG->A[v][u] = 1;
	pG->m++;
}

void read_graph (Graph *pG){
    int n, m;
    scanf ("%d %d", &n, &m);
    init_graph (pG, n);
    for (int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(pG, u, v);
    }
}

int mark[MAX_N];

void init_mark(int n){
    for(int i = 1; i <= n; i++){
        mark[i] = 0;
    }
}

int is_bipartite(Graph *pG, int u, int c){
    mark[u] = c;
    for(int v = 1; v <= pG->n; v++){
        if(pG->A[u][v]){
            if(!mark[v])
                is_bipartite(pG, v, 3-c);
            else if (mark[u] == mark[v])
                return 0;
        }
            
    }
    return 1;
}

int main (){
    Graph G;    
    read_graph (&G);
    init_mark(G.n);
    printf(is_bipartite(&G, 1, 1) ? "YES" : "NO");
}
