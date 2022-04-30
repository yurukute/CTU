#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX_N 100

typedef struct {
    int w, v, qty;
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
    FILE *f = fopen("CaiBalo3.txt", "r");
    *a = (item*)malloc(sizeof(item));
    fscanf(f, "%d", m);
    int i = 0;    
    while (!feof(f)){
        (*a) = realloc(*a, sizeof(item)*(i+1));
        fscanf(f, "\n%d %d %[^\r\n]s", &(*a)[i].w, &(*a)[i].v, (*a)[i].name);
        (*a)[i].ppu = (float)(*a)[i].v / (*a)[i].w;
        (*a)[i].qty = 0;
        i++;
    }
    *n = i;
}

void printChart (item *a, int n, int m){
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
	printf("Trong luong cua ba lo = %5d\n",m);
    printf("Tong trong luong      = %5d\n", total_weight);
    printf("Tong gia tri          = %5d\n", total_val);
}

void solve(item *a, int n, int p_val, int m, int x[], int i, float *final_res){
	for(int j = (m/a[i].w > 0); j >= 0; j--){
		float cur_val, remain, ubound;
		cur_val= p_val + j*a[i].v;
		remain = m - j*a[i].w;
		ubound = cur_val + remain*a[i+1].ppu;
		if(ubound > *final_res){
			x[i] = j;			
			if((i == n-1 || remain == 0) && cur_val > *final_res){
				*final_res = cur_val;
				for(int k = 0; k < n; k++){
					a[k].qty = x[k];
				}		
			}
			else
				solve(a, n, cur_val, remain, x, i+1, final_res);
		}		
		x[i] = 0;	
	}
}

int main (){
	item *a;
	int n, m, x[MAX_N];
    float final_res = 0;
	readFile(&a, &n, &m);
	sort(a, n);
	solve(a, n, 0, m, x, 0, &final_res);
	printChart(a, n, m);
}
