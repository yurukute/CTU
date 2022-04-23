#include <stdio.h>

#define MAX_N 100
#define NO_EDGE -1
#define oo 1e9

typedef struct {
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

void init_graph (Graph *G, int n){
    G->n = n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            G->A[i][j] = NO_EDGE;
        }
    }
}

void add_edge(Graph *G, int u, int v, int w){
    G->A[u][v] = w;
    G->m++;
}

int is_valid(int i, int j, int n, int m){
    return (0 <= i && i < n && j >= 0 && j < m);
}

void read_graph(Graph *G){
    int n, m, w;
    scanf("%d %d", &n, &m);
    init_graph(G, n*m);
    int adj[][4]={{-1, 1,  0, 0},
                  { 0, 0, -1, 1}};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &w);
            for(int k = 0; k < 4; k++){
                int adjR = i + adj[0][k];
                int adjC = j + adj[1][k];                
                if(is_valid(adjR, adjC, n, m)){                    
                    add_edge(G, adjR*m+adjC+1, i*m+j+1, w);
                }                
            }
        }
    }
}

int mark[MAX_N], pi[MAX_N], p[MAX_N];

void dijkstra(Graph *G, int u){    
    for(int i = 1; i <= G->n; i++){
        mark[i] = 0;
        pi[i] = oo;
    }
    pi[u] = 0;
    p[u] = -1;
    for (int i = 1; i <= G->n - 1; i++) {
        for(int v = 1; v <= G->n; v++){
            if (G->A[u][v] != NO_EDGE && !mark[v] && pi[u] + G->A[u][v] < pi[v]) {
                pi[v] = pi[u] + G->A[u][v]; 
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
}
    
int main(){
    Graph G;
    read_graph(&G);
    dijkstra(&G, 1);
    printf("%d", pi[G.n]);
}
