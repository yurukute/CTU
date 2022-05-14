#include <stdio.h>

#define MAX_N 100
#define NO_EDGE 0
#define oo 1e9

typedef struct {
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *G, int n){
    G->n = n;
    for(int u = 1; u <= n; u++){
        for(int v = 1; v <= n; v++){
            G->A[u][v] = NO_EDGE;
        }
    }
}

void add_edge(Graph *G, int u, int v, int w){
    G->A[u][v] = w;
    G->A[v][u] = w;
    G->m++;
}

void read_graph(Graph *G){
    int n, m;
    scanf("%d %d", &n, &m);
    init_graph(G, n);
    for(int i = 0; i <= m; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(G, u, v, w);
    }
}

int pi[MAX_N], p[MAX_N], mark[MAX_N];
int prim(Graph *G, Graph *T, int u){
    for(int i = 1; i <= G->n; i++){
        pi[i] = oo;
        p[i] = -1;
        mark[i] = 0;
    }
    pi[u] = 0;
    for(int i = 0; i < G->n-1; i++){        
        for(int v = 1; v <= G->n; v++){            
            if(G->A[u][v] != NO_EDGE && mark[v] == 0 && G->A[u][v] < pi[v]){
                pi[v] = G->A[u][v];
                p[v] = u;
            }
        }
        mark[u] = 1;
        int min_pi = oo;        
        for (int j = 1; j <= G->n; j++){
            if (!mark[j] && pi[j] < min_pi) {
                min_pi = pi[j];
                u = j;
            }                
        }
    }
    int sum_w = 0;
    init_graph(T, G->n);
    for(int u = 1; u <= G->n; u++){
        if (p[u] != -1){
            add_edge(T, p[u], u, G->A[p[u]][u]);
            sum_w += G->A[p[u]][u];
        }
    }
    return sum_w;
}

int main(){
    Graph G, T;
    read_graph(&G);
    printf("%d\n", prim(&G, &T, 1));
    for(int u = 1; u <= T.n; u++){
        for(int v = u; v <= T.n; v++){
            if(T.A[u][v] != NO_EDGE){
                printf("%d %d %d\n", u, v, T.A[u][v]);
            }
        }
    }
}
