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

void max_degree(Graph *pG){
    int max = 0, u = 1;
    for(int i = 1; i <= pG->n; i++){
        int deg = degree(pG, i);
        if(deg > max){
            max = deg;
            u = i;
        }        
    }
    printf("%d %d", u, max);
}
    
int main(){
    Graph G;
    int n, m;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&G, u, v);
    }
    max_degree(&G);
}
