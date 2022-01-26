#include <stdio.h>

#define MAX_N 100

typedef struct{
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n){
	pG->n = n;
	pG->m = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; i <= n; i++)
			pG->A[i][j] = 0;
}

void add_edge(Graph *pG, int u, int v) {
	pG->A[u][v]++;
	pG->m++;
}

void read_graph(Graph *pG){
    int n, k;
    scanf("%d", &n);
    init_graph(pG, n);
    for(int i = 1; i <= n; i++){
        while(1){
            scanf("%d", &k);
            if(k == 0)
                break;
            add_edge(pG, i, k);
        }
    }
}

void print_graph(Graph G){
    for (int i = 1; i <= G.n; i++) {
        for(int j = 1; j <= G.n; j++) {
            printf("%d ", G.A[i][j]);           
        }
        printf("\n");
    }
}

int main(){
    Graph G;    
    read_graph(&G);
    print_graph(G);
}
