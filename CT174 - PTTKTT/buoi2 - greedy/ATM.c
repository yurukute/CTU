#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int val, qty;
    char s[25];    
} money;

void swap (money *a, money *b){
    money temp = *a;
    *a = *b;
    *b = temp;
}

void sort (money *m, int n){
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(&m[i].val < &m[j].val)
                swap(&m[i], &m[j]);    
}

void readFile (money **m, int *n){
    FILE *f = fopen("ATM.txt", "r");
    *m = (money*)malloc(sizeof(money));
    int i = 0;
    while(!feof(f)){
        *m = (money*)realloc(*m, sizeof(money)*(i+1));
        fscanf(f, "%d %[^\r\n]s", &(*m)[i].val, (*m)[i].s);
        (*m)[i].s[strlen((*m)[i].s) - 1] = '\0';
        (*m)[i].qty = 0;
        i++;
    }
    *n = i;
}

void printChart (money *m, int n, int t){
    int total = 0;
	printf("|---|---------------------|----------|-------|----------|\n");
	printf("|%-3s|%-21s|%-10s|%-7s|%-10s|\n", "STT", "      Loai tien", " Menh Gia", " So to", "Thanh tien");
	printf("|---|---------------------|----------|-------|----------|\n");
	for(int i = 0, k = 1; i < n; i++){
        if(m[i].qty){
            printf("| %-2d| %-20s| %9d|   %-4d| %9d|\n", k++, m[i].s, m[i].val, m[i].qty, m[i].val*m[i].qty);
            total += m[i].val*m[i].qty;
        }
	}	
	printf("|---|---------------------|----------|-------|----------|\n");
    printf("So tien can rut  = %9d\n", t);
    printf("So tien da tra   = %9d\n", total);
    printf("So tien chua tra = %9d", t - total);
}

void greedy (money *m, int n, int t){    
    int i = 0;
    while (i < n && t > 0) {
        m[i].qty = t / m[i].val;
        t -= m[i].qty*m[i].val;
        i++;
    }    
}

int main() {
    money *m;
    int n = 0, t;
    readFile(&m, &n);    
    printf("Nhap so tien can rut: ");
    scanf("%d", &t);
    sort(m, n);
    greedy(m, n, t);
    printChart(m, n, t);
    free(m);
}
