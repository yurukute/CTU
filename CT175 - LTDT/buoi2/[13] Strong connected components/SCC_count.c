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
    //pG->A[v][u] = 1;
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

void print_graph (Graph *pG){
    for(int i = 1; i <= pG->n; i++){
        for(int j = 1; j <= pG->n; j++)
            printf("%d ", pG->A[i][j]);
        printf("\n");
    }
}

int num[MAX_N], min_num[MAX_N], on_stack[MAX_N], k = 1;
Stack S;

int min(int a, int b){ return a < b ? a : b; }

int scc_count = 0;

void SCC(Graph *pG, int u){
    num[u] = min_num[u] = k;
    k++;
    push(&S, u);
    on_stack[u] = 1;
    for(int v = 1; v <= pG->n; v++)
        if(pG->A[u][v]){
            if(num[v] < 0){
                SCC(pG, v);
                min_num[u] = min(min_num[u], min_num[v]);
            }
            else if (on_stack[v])
                min_num[u] = min(min_num[u], num[v]);
        }
    
    if(num[u] == min_num[u]){
        scc_count++;
        int x = pop(&S);        
        while (x != u){            
            x = pop(&S);
        }
    }
}

int main (){
    Graph G;    
    read_graph (&G);
    make_null_stack(&S);
    for(int i = 1; i <= G.n; i++){
        num[i] = -1;
        on_stack[i] = 0;
    }
    for(int i = 1; i <= G.n; i++)
        if(num[i] == -1)
            SCC(&G, i);
    printf("%d", scc_count);
}
