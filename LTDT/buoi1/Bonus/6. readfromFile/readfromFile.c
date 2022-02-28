#include <stdio.h>

typedef struct {
    int u, v;    
} Edge;

typedef struct{
    int n, m;
    Edge edges[500];
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

void print_graph(Graph *pG) {
    int A[pG->n][pG->n];
    for(int i = 1; i <= pG->n; i++){
        for(int j = 1; j <= pG->n; j++){
            A[i][j] = 0;
        }        
    }    
    for(int i = 0; i < pG->m; i++){
        A[pG->edges[i].u][pG->edges[i].v] = 1;
        A[pG->edges[i].v][pG->edges[i].u] = 1;
    }    
    for(int i = 1; i <= pG->n; i++){
        for(int j = 1; j <= pG->n; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main(){
    freopen("dt1.txt", "r", stdin);
    Graph G;
    int n, m;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }
    print_graph(&G);
}

