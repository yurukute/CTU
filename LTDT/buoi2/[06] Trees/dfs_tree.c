#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key, parent;
} ElementType;

typedef struct Node {
    ElementType Data;
    struct Node *Next;
} Node;

typedef Node *Stack;

void make_null_stack(Stack *pS){
    (*pS) = (Node*)malloc(sizeof(Node));
    (*pS)->Next = NULL;    
}
    
void push(Stack *pS, ElementType x){
    Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->Data = x;
	newNode->Next = (*pS)->Next;
    (*pS)->Next   = newNode;
}

ElementType pop(Stack *pS){
    Node *Temp = (*pS);
    (*pS) = (*pS)->Next;
    free(Temp);
    return (*pS)->Data;
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

void dfs(Graph *pG, int x){
    Stack S;
    make_null_stack(&S);
    ElementType s;
    s.key = x;
    s.parent = -1;
    push(&S, s);
    while (S->Next != NULL){
        ElementType u = pop(&S);
        if (!mark[u.key]){
            mark[u.key] = 1;
            parent[u.key] = u.parent;
            for (int i = pG->n; i >= 1; i--)
                if(pG->A[u.key][i]){
                    ElementType v;
                    v.key = i;
                    v.parent = u.key;
                    push(&S, v);
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
        dfs(&G, i);
    for(int i = 1; i <= G.n; i++)
        printf("%d %d\n", i, parent[i]);
}
