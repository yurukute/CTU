#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

typedef int ElementType;

typedef struct Node {
    ElementType Data;
    struct Node *Next;
} Node;

typedef Node *Stack;

void make_null_stack(Stack *pS){
    (*pS) = (Node*)malloc(sizeof(Node));
    (*pS)->Next = NULL;    
}
    
void push(Stack *pS, int x){
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

void init_mark (int n){
    for(int i = 1; i <= n; i++){
        mark[i] = 0;
    }
}

int dfs(Graph *pG, int s){
    int nodes_count = 0;
    Stack S;
    make_null_stack(&S);
    push(&S, s);
    while (S->Next != NULL){
        int u = pop(&S);
        if (!mark[u]){
            mark[u] = 1;
            nodes_count++;
            for (int v = pG->n; v >= 1; v--)
                if (pG->A[u][v])
                    push(&S,v);
        }            
    }
    return nodes_count;
}

int main (){
    Graph G;    
    read_graph (&G);
    // Cau 1
    init_mark(G.n);
    int connected_comps = 0;
    for (int i = 1; i <= G.n; i++){
        if(!mark[i]){
            dfs(&G, i);
            connected_comps++;
        }
    }    
    printf("%d", connected_comps);
    // Cau 2
    init_mark(G.n);
    printf("%d", dfs(&G,1));

    // Cau 3
    init_mark(G.n);
    int s;
    scanf("%d", &s);
    printf("%d", dfs(&G,s));

    // Cau 4
    int max = 0;
    for(int i = 1; i <= G.n; i++){
        int nodes = dfs(&G, i);
        if (nodes > max)
            max = nodes;
    }
    printf("%d", max);
}
