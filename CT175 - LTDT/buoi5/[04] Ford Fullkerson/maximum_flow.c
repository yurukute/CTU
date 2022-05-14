#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node {
    ElementType Data;
    struct Node *Next;
} Node;

typedef struct {
    Node *Front, *Rear;
} Queue;

void make_null_queue (Queue *pQ){
    Node *Header = (Node*)malloc(sizeof(Node));
    Header->Next = NULL;
    pQ->Front = Header;
    pQ->Rear = Header;
}

void enqueue (Queue *pQ, ElementType x){
    pQ->Rear->Next =  (Node*)malloc (sizeof (Node));
    pQ->Rear = pQ->Rear->Next;
    pQ->Rear->Data = x;
    pQ->Rear->Next = NULL;
}

ElementType dequeue (Queue *pQ){
    Node *Temp;
    Temp = pQ->Front;
    pQ->Front = pQ->Front->Next;
    free(Temp);
    return pQ->Front->Data;
}

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
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        G->C[u][v] = c;
    }
}

label lb[MAX_N];

void reset(Graph *G){
    for(int u = 1; u <= G->n; u++){
        for(int v = 1; v <= G->n; v++){
            G->F[u][v] = 0;
        }
    }
}

int min(int a, int b){
    return a < b ? a : b;
}

int edmonds_karp(Graph *G, int s, int t){
    for(int u = 1; u <= G->n; u++)
        lb[u].d = 0;
    lb[s].d = 1;
    lb[s].p = s;
    lb[s].s = oo;
    Queue Q;
    make_null_queue(&Q);
    enqueue(&Q, s);
    while(Q.Front != Q.Rear) {
        int u = dequeue(&Q);
        for(int v = 1; v <= G->n; v++){
            if(G->C[u][v] != NO_EDGE && !lb[v].d && G->F[u][v] < G->C[u][v]){
                lb[v].d = 1;
                lb[v].p = u;
                lb[v].s = min(lb[u].s, G->C[u][v] - G->F[u][v]);
                enqueue(&Q, v);
            }
        }
        for(int x = 1; x <= G->n; x++){
            if(G->C[x][u] != NO_EDGE && !lb[x].d && G->F[x][u]){
                lb[x].d = 1;
                lb[x].p = u;
                lb[x].s = min(lb[u].s, G->F[x][u]);
                enqueue(&Q, x);
            }
        }
        if (lb[t].d) return 1;
    }
    return 0;
}

int ford_fullkerson(Graph *G, int s, int t){
    reset(G);
    int max_flow = 0;
    while(edmonds_karp(G, s, t)){
        int sigma = lb[t].s, u = t;
        while(u != s){
            int p = lb[u].p;
            if(lb[u].d > 0)
                G->F[p][u] += sigma;
            if(lb[u].d < 0)
                G->F[u][p] -= sigma;
            u = p;
        }
        max_flow += sigma;
    }
    return max_flow;
}

int main(){
    Graph G;    
    read_graph(&G);
    printf("Max flow: %d\n", ford_fullkerson(&G, 1, G.n));
    printf("S: ");
    for(int u = 1; u <= G.n; u++){
        if(lb[u].d)
            printf("%d ", u);
    }
    printf("\nT: ");
    for(int u = 1; u <= G.n; u++){
        if(!lb[u].d)
            printf("%d ", u);
    }
}
