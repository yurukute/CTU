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

int pi[MAX_N][MAX_N], next[MAX_N][MAX_N];

int floyd_warshall(Graph *G){
    for(int i = 1; i <= G->n; i++){
        pi[i][i] = 0;
        for(int j = 1; j <= G->n; j++){
            if(G->A[i][j] != NO_EDGE){
                pi[i][j]   = G->A[i][j];
                next[i][j] = j;
            } else if(i != j){
                pi[i][j]   = oo;
                next[i][j] = -1;
            }
        }
    }
    for(int k = 1; k <= G->n; k++){
        for(int i = 1; i <= G->n; i++){
            for(int j = 1; j <= G->n; j++){
                if(pi[i][j] > pi[i][k] + pi[k][j]){
                    pi[i][j] = pi[i][k] + pi[k][j];
                    next[i][j] = next[i][k];
                }               
            }
        }
    }
    for (int i = 1; i <= G->n; i++){
        if (pi[i][i] < 0){
            return 1;
        }
    }
    return 0;  
}

int main(){
    Graph G;
    read_graph(&G);
    floyd_warshall(&G) ? printf("YES") : printf("NO");
}
