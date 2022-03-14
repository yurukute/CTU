#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key, parent;
} ElementType;

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

typedef struct{
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph (Graph *pG, int n){
	pG->n = n;
	pG->m = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; i <= n; i++)
			pG->A[i][j] = 0;
}

void add_edge (Graph *pG, int u, int v) {
	pG->A[u][v] = 1;
    pG->A[v][u] = 1;
	pG->m++;
}

void read_graph (Graph *pG){
    int n, m;
    scanf ("%d %d", &n, &m);
    init_graph (pG, n);
    for (int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(pG, u, v);
    }
}

int mark[MAX_N];
int parent[MAX_N];

void bfs(Graph *pG, int x){
    Queue Q;
    make_null_queue(&Q);
    ElementType s;
    s.key = x;
    s.parent = -1;
    enqueue(&Q, s);
    while (Q.Front != Q.Rear){
        ElementType u = dequeue(&Q);
        if (!mark[u.key]){
            mark[u.key] = 1;
            parent[u.key] = u.parent;
            for (int i = 1; i <= pG->n; i++)
                if (pG->A[u.key][i]){
                    ElementType v;
                    v.key = i;
                    v.parent = u.key;                    
                    enqueue(&Q, v);
                }
        }
    }
}

int main (){
    Graph G;    
    read_graph (&G);
    for(int i = 1; i <= G.n; i++){
        mark[i] = 0;
        parent[i] = -1;
    }
    for(int i = 1; i <= G.n; i++)
        bfs(&G, i);
    for(int i = 1; i <= G.n; i++)
        printf("%d %d\n", i, parent[i]);
}
