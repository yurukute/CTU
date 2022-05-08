#include <stdio.h>

#define MAX_N 100

typedef int ElementType;
typedef struct {
    ElementType data[MAX_N];
    int size;
} List;

void make_null(List* L) {
    L->size = 0;
}

void push_back(List* L, ElementType x) {
    L->data[L->size] = x;
    L->size++;
}

ElementType element_at(List* L, int i) {
    return L->data[i-1];
}

typedef struct {
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *G, int n){
    G->n = n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            G->A[i][j] = 0;
        }
    }
}

void add_edge(Graph *G, int u, int v) {
    G->A[u][v] = 1;
    G->m++;
}

void read_graph(Graph *G){
    int n, m;
    scanf("%d %d", &n, &m);
    init_graph(G, n);
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(G, u, v);
    }
}

int deg_in(Graph *G, int v){
    int deg = 0;
    for(int u = 1; u <= G->n; u++){
        if(G->A[u][v])
            deg++;
    }
    return deg;
}

int mark[MAX_N];

void topo_sort(Graph *G, int u, List *pL){
    if (!mark[u]){
        mark[u] = 1;
        for (int v = 1; v <= G->n; v++){
            if(G->A[u][v]){                    
                topo_sort(G, v, pL);
            }
        }
        push_back(pL, u);
    }   
}

int main(){
    Graph G;
    read_graph(&G);
    List L;
    make_null(&L);
    for(int i = 1; i <= G.n; i++){
        mark[i] = 0;
        topo_sort(&G, i, &L);    
    }    
    for(int i = 1; i <= G.n; i++){
        printf("%d\n", element_at(&L, G.n-i+1));
    }
}
