#include <stdio.h>

#define MAX_N 100

typedef struct {
    int u, v, w;
} Edge;

typedef struct {
    int n, m;
    Edge E[MAX_N];
} Graph;

void init_graph(Graph *G, int n){
    G->n = n;
    G->m = 0;
}

void add_edge(Graph *G, int u, int v, int w){
    Edge e = {u,v,w};
    G->E[G->m] = e;
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

int parent[MAX_N];

int find_root(int u) {
    while (parent[u] != u)
        u = parent[u];
    return u;
}

void sort(Edge e[], int m){
  for(int i = 0; i < m; i++){
      for(int j = i+1; j < m; j++){
          if(e[i].w > e[j].w){
              Edge x = e[i];
              e[i] = e[j];
              e[j] = x;
          }
      }
  }
}


int kruskal(Graph *G, Graph *T){
    sort(G->E, G->m);
    init_graph(T, G->n);
    for(int u = 1; u <= G->n; u++){
        parent[u] = u;
    }
    int sum_w = 0;
    for(int i = 0; i < G->m; i++){
        Edge e = G->E[i];
        int r_u = find_root(e.u);
        int r_v = find_root(e.v);
        if(r_u != r_v){
            if(e.u < e.v){
                add_edge(T, e.u, e.v, e.w);
                parent[r_v] = r_u;
            } else {
                add_edge(T, e.v, e.u, e.w);
                parent[r_u] = r_v;
            }
            sum_w += e.w;
        }
    }
    sort(T->E, T->m);
    return sum_w;
}

int main(){
    Graph G, T;
    read_graph(&G);
    printf("%d\n", kruskal(&G, &T));  
    for(int i = 0; i < T.m; i++){
        Edge e = T.E[i];
        printf("%d %d %d\n", e.u, e.v, e.w);
    }
}
