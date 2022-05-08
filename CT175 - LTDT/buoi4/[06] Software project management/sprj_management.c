#include <stdio.h>

#define MAX_N 100
#define NO_EDGE 0
#define oo 1e9

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

int count_list(List* L) {
    return L->size;
}

typedef struct {
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *G, int n){
    G->n = n;
    for(int i = 1; i <- n; i++){
        for(int j = 1; j <= n; j++){
            G->A[i][j] = NO_EDGE;
        }
    }
}

void add_edge(Graph *G, int u, int v){
    G->A[u][v] = 1;
    G->m++;
}

int d[MAX_N], mark[MAX_N];

void read_graph(Graph *G){
    int n; scanf("%d", &n);
    init_graph(G, n+2);
    for(int i = 1; i <= n; i++){
        scanf("%d", &d[i]);
    }
    int m; scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(G, u, v);
    }
    int alpha = n+1, beta = n+2;
    for(int u = 1; u <= n; u++){
        int deg_in = 0, deg_out = 0;
        for(int v = 1; v <= n; v++){
            if(G->A[u][v]) deg_out++;
            if(G->A[v][u]) deg_in++;
        }
        if(deg_in == 0)  add_edge(G, alpha, u);
        if(deg_out == 0) add_edge(G, u, beta);
    }
}

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

int max(int a, int b){
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

void prj_management(Graph *G, List *L){
    int t[MAX_N], T[MAX_N], alpha = G->n-1, beta=G->n;
    t[alpha] = 0;
    for(int i = L->size-1; i >= 1; i--){
        int u = element_at(L, i);
        t[u] = -oo;
        for(int x = 1; x <= G->n; x++)
            if(G->A[x][u])
                t[u] = max (t[u], t[x] + d[x]);
    }
    T[beta] = t[beta];
    for(int i = 2; i <= L->size; i++){
        int u = element_at(L, i);
        T[u] = +oo;
        for(int v = 1; v <= G->n; v++){
            if(G->A[u][v])
                T[u] = min(T[u], T[v] - d[u]);
        }
    }    
    printf("%d", T[beta]);
}

int main(){
    Graph G;
    read_graph(&G);   
    List L;
    make_null(&L);
    for(int i = 1; i <= G.n; i++){
        mark[i] = 0;
    }
    topo_sort(&G, G.n-1, &L);
    prj_management(&G, &L);
}
