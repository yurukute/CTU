#include<stdio.h>
#include <malloc.h>

#define MAX_N 100

typedef struct {
	float w;
	int first, last;
} edge;

void swap(edge *a, edge *b){
	edge temp = *a;
	*a = *b;
	*b = temp;
}

void sort(edge *e, int n){
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(e[i].w > e[j].w)
				swap(&e[i], &e[j]);
		}
	}
}

void readFile(edge **e, int *n){    
	FILE *f = fopen("TSP.txt", "r");
    *e = (edge*)malloc(sizeof(edge));
	fscanf(f, "%d", n);    
	int k = 0;
	for(int i = 0; i < *n; i++){
		for(int j = 0; j < *n; j++){
			if(j < i){
                *e = (edge*)realloc(*e, sizeof(edge)*(k+1));                
				fscanf(f, "%f", &(*e)[k].w);
				(*e)[k].first = j;
				(*e)[k].last = i;
				k++;
			} 
			else {
				float temp;
				fscanf(f, "%f", &temp);	
			}
		}	
	}
}

void printList(edge *e, int n){	
	for(int i = 0; i < n; i++){
		printf ("%3d   %c%c   %5.2f\n", i+1, e[i].first+97, e[i].last+97, e[i].w);
	}
}

void initForest(int parent[], int n){
	for(int i = 0; i < n; i++)
		parent[i] = i;
}

int findRoot(int parent[], int u){
	while(u != parent[u])
		u = parent[u];
	return u;
}

int isCycle (int r_u, int r_v){
	return r_u == r_v;
}

int threeLevelNode(edge *t, int n, edge newEdge){
    int countF = 1, countL = 1;
	for(int i = 0; i < n; i++){
		if(t[i].first == newEdge.first || t[i].last == newEdge.first)
			countF++;
		if(t[i].first == newEdge.last || t[i].last == newEdge.last)
			countL++;
        if(countF == 3 || countL == 3)
            return 1;
	}
    return 0;
}

void greedy(edge *e, int n, int m){
	edge *t;
    float price = 0;
	t = (edge*)malloc(sizeof(edge));
	int parent[MAX_N];
	initForest(parent, n);
    int k = 0;
    for(int i = 0; i < m && k < n; i++){		
        if(!threeLevelNode(t, k, e[i])){
            int r_u = findRoot(parent, e[i].first);
            int r_v = findRoot(parent, e[i].last);
            if(!isCycle(r_u, r_v) || (isCycle(r_u, r_v) && k == n-1)){
                t = (edge*)realloc(t, sizeof(edge)*(k+1));
                t[k++] = e[i];
                parent[r_v] = r_u;
                price += e[i].w;
            }
        }
	}
	printList(t, k);
    printf("Tong do dai cac canh: %.2f", price);
}

int main(){
	int n = 0;
	edge *e;
	readFile(&e, &n);
	int m = n*(n-1)/2;
	printf("Cac canh da cho:\n");
	printList(e, m);
	sort(e, m);
	printf("\nCac canh sau khi sap xep:\n");	
	printList(e, m);	
	printf("\nPhuong an:\n");	
	greedy(e, n, m);
    free(e);
}
