#include <stdio.h>
#include <malloc.h>

#define MAX_N 100

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
        if(G->A[u][v] && u != v)
            deg++;
    }
    return deg;
}

int r[MAX_N];

void ranking(Graph *G) {    
    int d[MAX_N];   
    for(int i = 1; i <= G->n; i++){
        d[i] = deg_in(G, i);
    }
    Queue Q, Q2;
    make_null_queue(&Q);
    for (int u = 1; u <= G->n; u++){
        if(d[u] == 0){
            enqueue(&Q, u);
        }
    }
    int k = 0;
    while(Q.Front != Q.Rear){
        make_null_queue(&Q2);
        while(Q.Front != Q.Rear){
            int u = dequeue(&Q);
            r[u] = k;
            for(int v = 1; v <= G->n; v++){
                if(G->A[u][v] && --d[v] == 0){
                    enqueue(&Q2, v);
                }
            }
        }
        Q = Q2;
        k++;
    }
}

int main(){
    Graph G;
    read_graph(&G);
    for(int i = 1; i <= G.n; i++){
        ranking(&G);
    }
    for(int i = 1; i <= G.n; i++)
        printf("r[%d] = %d\n", i, r[i]);
}
