#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int w, v, qty;
    char name[25];    
} item;

typedef int table[50][100];

void readFile (item **a, int *n, int *m){    
    FILE *f = fopen("QHD_CaiBalo.inp", "r");
    *a = (item*)malloc(sizeof(item));
    fscanf(f, "%d", m);
    int i = 0;    
    while (!feof(f)){
        (*a) = realloc(*a, sizeof(item)*(i+1));
        fscanf(f, "\n%d %d %[^\r\n]s", &(*a)[i].w, &(*a)[i].v, (*a)[i].name);
        (*a)[i].qty = 0;
        i++;
    }
    *n = i;
    fclose(f);
}

void printResult (item *a, int n, int m){
    int total_val = 0, total_weight = 0;
    printf("Phuong an Cai balo 3 su dung Quy hoach dong:\n");
    printf("|---|---------------------|-----------|-------|---------|\n");
	printf("|%-3s|%-21s|%-11s|%-7s|%-9s|\n", "STT", "     Ten do vat", "Trong luong", "Gia tri", "Phuong an");
	printf("|---|---------------------|-----------|-------|---------|\n");
	for(int i = 0, k = 1; i < n; i++){        
        printf("| %-2d| %-20s|%11d|%7d|%9d|\n", k++, a[i].name, a[i].w, a[i].v, a[i].qty);
        total_val += a[i].v*a[i].qty;
        total_weight += a[i].w*a[i].qty;
	}	
	printf("|---|---------------------|-----------|-------|---------|\n");	
    printf("Trong luong cua ba lo = %5d\n", m);
    printf("Tong trong luong      = %5d\n", total_weight);
    printf("Tong gia tri          = %5d\n", total_val);
}

void createTable(item *a, int n, int m, table F, table X){
    for(int i = 0; i <= m; i++){
        X[0][i] = (i >= a[0].w);
        F[0][i] = X[0][i] * a[0].v;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= m; j++){
            F[i][j] = F[i-1][j];
            X[i][j] = 0;
            if(j >= a[i].w && F[i][j] < a[i].v + F[i-1][j-a[i].w]){
                F[i][j] = a[i].v + F[i-1][j-a[i].w];
                X[i][j] = 1;                
            }
        }
    }
}

void printTable(int n, int m, table F, table X){
    printf("Bang quy hoach dong:\n|---");
    for(int i = 0; i <= m; i++){
        printf("|-------");
    }    
    printf("|\n|k\\V");
    for(int i = 0; i <= m; i++){
        printf("|   %-4d", i);
    }
    printf("|\n|---");
    for(int i = 0; i <= m; i++){
        printf("|-------");
    }    
    printf("|\n");
	for(int i = 0; i < n; i++){
        printf("| %-2d", i+1);
		for(int j = 0; j <= m; j++){
		 	printf("| %2d| %-2d",F[i][j], X[i][j]);
        }
		printf("|\n");
	}
    printf("|---");
    for(int i = 0; i <= m; i++){
        printf("|-------");
    }    
    printf("|\n\n");
}

void searchTable(item *a, int n, int m, table X){
    for(int i = n-1; i >= 0; i--){
        a[i].qty = X[i][m];
        m -= X[i][m]*a[i].w;
    }
}

int main (){
    int n = 0, m = 0;    
    item *a;
    table F, X;
    readFile(&a, &n, &m);
    createTable(a, n, m, F, X);
    printTable(n, m, F, X);
    searchTable(a, n, m, X);
    printResult(a, n, m);
    free(a);
}
