#include <stdio.h>

#define MAX_N 100
#define MAX_M 500
#define NO_EDGE -1
#define oo 1e9

typedef struct {
    int u, v, w;
} Edge;

typedef struct {
    int n, m;
    Edge edges[MAX_M];
} Graph;

void init_graph(Graph *G, int n){
    G->n = n;
    G->m = 0;
}

void add_edge(Graph *G, int u, int v, int w){
    G->edges[G->m].u = u;
    G->edges[G->m].v = v;
    G->edges[G->m].w = w;
    G->m++;
}

void read_graph(Graph *G) {
    int n, m;
    scanf("%d %d", &n, &m);
    init_graph(G, n);
    for(int i = 0; i < m; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(G, u, v, w);
    }    
}

int mark[MAX_N], p[MAX_N], pi[MAX_N];

int bellman_ford(Graph *G, int s){
    for(int i = 1; i <= G->n; i++){
        mark[i] = 0;
        pi[i] = oo;
    }
    pi[s] = 0;
    p[s] = -1;
    for (int i = 1; i <= G->n - 1; i++) {
        for (int j = 0; j < G->m; j++){
            Edge e = G->edges[j];
            if(pi[e.u] != oo && pi[e.u] + e.w < pi[e.v]){
                pi[e.v] = pi[e.u] + e.w;
                p[e.v] = e.u;
            }
        }
    }
    for (int j = 0; j < G->m; j++){
        Edge e = G->edges[j];
        if(pi[e.u] != oo && pi[e.u] + e.w < pi[e.v]){
            return 1;
        }
    }
    return 0;
}

int main(){
    Graph G;
    read_graph(&G);
    int s;
    scanf("%d", &s);
    bellman_ford(&G, s) ? printf("YES") : printf("NO");
}
