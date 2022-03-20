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

void print_graph (Graph *pG){
    for(int i = 1; i <= pG->n; i++){
        for(int j = 1; j <= pG->n; j++)
            printf("%d ", pG->A[i][j]);
        printf("\n");
    }
}

int mark[MAX_N];

void init_mark(int n){
    for(int i = 1; i <= n; i++){
        mark[i] = 0;
        parent[i] = -1;
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

void print_teams(Graph *pG){
    if(is_bipartite(pG, 1, 1)){
        for(int i = 1; i <= pG->n; i++){
            if(mark[i] == 1)
                printf("%d ", i);
        }
        printf("\n");
        for(int i = 1; i <= pG->n; i++){
            if(mark[i] == 2)
                printf("%d ", i);
        }
    }
    else printf("IMPOSSIBLE");
}

int main (){
    Graph G;    
    read_graph (&G);
    init_mark(G.n);
    print_teams(&G);
}
