#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int w, v, qty, max_qty;
    float ppu; //price per unit
    char name[25];    
} item;

void swap (item *a, item* b){
    item temp = *a;
    *a = *b;
    *b = temp;
}

void sort (item *a, int n){
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(a[i].ppu < a[j].ppu)
                swap(&a[i], &a[j]);
}

void readFile (item **a, int *n, int *m){    
    FILE *f = fopen("CaiBalo2.txt", "r");
    *a = (item*)malloc(sizeof(item));
    fscanf(f, "%d", m);
    int i = 0;    
    while (!feof(f)){
        (*a) = realloc(*a, sizeof(item)*(i+1));
        fscanf(f, "\n%d %d %d %[^\r\n]s", &(*a)[i].w, &(*a)[i].v, &(*a)[i].max_qty, (*a)[i].name);
        (*a)[i].ppu = (float)(*a)[i].v / (*a)[i].w;
        (*a)[i].qty = 0;
        i++;
    }
    *n = i;
    *a = (*a);
}

void printChart (item *a, int n){
    int total_val = 0, total_weight = 0;
	printf("|---|---------------------|-----------|-------|-------|---------|\n");
	printf("|%-3s|%-21s|%-11s|%-7s|%-7s|%-9s|\n", "STT", "     Ten do vat", "Trong luong", "Gia tri", "Don gia","Phuong an");
	printf("|---|---------------------|-----------|-------|-------|---------|\n");
	for(int i = 0, k = 1; i < n; i++){
        printf("| %-2d| %-20s|%11d|%7d|%7.2f|%9d|\n", k++, a[i].name, a[i].w, a[i].v, a[i].ppu, a[i].qty);
        total_val += a[i].v*a[i].qty;
        total_weight += a[i].w*a[i].qty;
	}	
	printf("|---|---------------------|-----------|-------|-------|---------|\n");
	printf("Phuong an (theo thu tu DG giam dan): X(");
	for(int i=0; i<n-1; i++){
		printf("%d,", a[i].qty);
	}	
	printf("%d)\n", a[n-1].qty);
	printf("Tong trong luong = %5d\n", total_weight);
    printf("Tong gia tri     = %5d\n", total_val);
}

int min (int a, int b){
    return a < b ? a : b;
}

void greedy(item *a, int n, int m){
    for(int i = 0; i < n; i++){
        a[i].qty = min(m/a[i].w, a[i].max_qty);
        m -= a[i].w*a[i].qty;
    }
}

int main (){
    int n = 0, m = 0;
    item *a;
    readFile(&a, &n, &m);
    sort(a, n);
    greedy(a, n, m);
    printChart(a, n);    
}
