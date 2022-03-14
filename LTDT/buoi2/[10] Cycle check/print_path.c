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
    //pG->A[v][u] = 1; // Uncomment for undirected graph
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

int mark[MAX_N],  parent[MAX_N], start;

void init_mark(int n){
    for(int i = 1; i <= n; i++){
        mark[i] = 0;
        parent[i] = -1;
    }
}

int cycle_check (Graph *pG, int u, int p){
    if (!mark[u]){
        mark[u] = 1;
        parent[u] = p;
        for (int v = 1; v <= pG->n; v++){
            if(pG->A[u][v]){
                if(!mark[v])
                    return cycle_check(pG, v, u);
                else if (mark[v] == 1 && v != p){
                    parent[v] = u;
                    start = u;
                    return 1;
                }
            }
        }
    }
    mark[u] = 2;
    return 0;
}

void print_path(Graph *pG){
    int path[pG->n], length = 0;
    if(cycle_check(pG, 1, -1)){
        for(int i = 0; path[0] != start; i++){
            path[i] = start;
            start = parent[start];
            length = i;
        }
        path[++length] = start;
        for(int i = length; i >= 0; i--)
            printf("%d ", path[i]);       
    }
    else printf("-1");   
}

int main (){
    Graph G;    
    read_graph (&G);
    init_mark(G.n);
    print_path(&G);
}
