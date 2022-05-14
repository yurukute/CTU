#include <stdio.h>

#define MAX_N 100
#define NO_EDGE 0
#define oo 1e9

typedef struct {
    int d, p, s;
} label;

typedef struct {
    int n;
    int C[MAX_N][MAX_N], F[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *G, int n){
    G->n = n;
    for(int u = 1; u <= n; u++){
        for(int v = 1; v <= n; v++){
            G->C[u][v] = NO_EDGE;
        }
    }
}

void read_graph(Graph *G){
    int n, m;
    scanf("%d %d", &n, &m);
    init_graph(G, n);
    for(int i = 0; i <= m; i++){
        int u, v, c, f;
        scanf("%d %d %d %d", &u, &v, &c, &f);
        G->C[u][v] = c;
        G->F[u][v] = f;
    }
}

int flow_check(Graph *G, int s, int t){
    int out_s = 0, in_t = 0; 
    for(int u = 1; u <= G->n; u++){
        int out_u = 0, in_u = 0;
        for(int v = 1; v <= G->n; v++){
            if(0 > G->F[u][v] || G->F[u][v] > G->C[u][v])
                return 0;
            if(G->C[u][v] != NO_EDGE){
                out_u += G->F[u][v];
                if(u == s){
                    out_s += G->F[u][v];
                }
            }
            if(G->C[v][u] != NO_EDGE){
                in_u += G->F[v][u];
                if(u == t){
                    in_t += G->F[v][u];
                }
            }
        }
        if (u != s && u != t && in_u != out_u)
            return 0;
    }
    return out_s == in_t;
}

int main(){
    Graph G;    
    read_graph(&G);
    flow_check(&G, 1, G.n) ? printf("YES") : printf("NO");
}
