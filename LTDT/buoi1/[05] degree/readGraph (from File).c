#include <stdio.h>

#define MAX_M 500

typedef struct {
	int u, v;
} Edge;

typedef struct {
	int n, m;
	Edge edges[MAX_M];
} Graph;

void init_graph(Graph *pG, int n){
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph *pG, int u, int v){	
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

int degree(Graph *pG, int u){
	int deg_u = 0;
	for(int i = 0; i < pG->m; i++){
		if(pG->edges[i].u == u)
			deg_u++;
		if(pG->edges[i].v == u)
			deg_u++;		
	}
	return deg_u;
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
	freopen("dt.txt", "r", stdin);
    read_graph(&G);
    for(int i = 1; i <= G.n; i++){
        printf("deg(%d) = %d\n", i, degree(&G, i));
    }
}

