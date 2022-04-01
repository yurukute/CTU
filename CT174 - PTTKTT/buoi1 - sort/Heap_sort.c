#include<stdio.h>

#define MAX_N 100

typedef int keytype;
typedef float othertype;

typedef struct {
	keytype key;
	othertype other;
}record;

void swap(record *a, record *b){
	record temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void pushDown(record a[], int first, int last){ 
	int f = first;
	while (f <= (last-1)/2){
		int L = 2*f+1, R = 2*f+2;
		if (last == L) { 
			if (a[f].key > a[L].key) 
				swap(&a[f], &a[L]);			
			return;
		}
        if ((a[f].key>a[L].key) && (a[L].key<=a[R].key)){
			swap(&a[f], &a[L]);
			f = L;
		}
        else if ((a[f].key>a[R].key) && (a[R].key<a[L].key)){
			swap(&a[f],&a[R]);
			f = R;
		}
        else return;
	}
}

void heapSort(record a[], int n){
	int i;
	for(i = (n-2)/2; i >= 0; i--)
		pushDown(a, i, n-1);
	for(i = n-1; i >= 2; i--){
		swap(&a[0], &a[i]);
		pushDown(a, 0, i-1);
	}
	swap(&a[0], &a[1]);
}

void readFile (record a[], int *n){    
	FILE *f = fopen("data.txt","r");
	if(f!=NULL)
        while (!feof(f)){
            fscanf(f,"%d%f",&a[*n].key , &a[*n].other);
            (*n)++;
        }
    else printf("loi moi file\n ");
	fclose(f);
}

void printData(record a[], int n, int m){
    if(n < m)
        for(int i = n; i < m; i++)
            printf("%3d %5d %8.2f\n", i+1, a[i].key, a[i].other);
    else
        for(int i = n-1; i >= m; i--)
            printf("%3d %5d %8.2f\n", n-i, a[i].key, a[i].other);
}

int main (){
	record a[MAX_N];
	int n = 0;
	printf("Thuat toan Heap Sort\n");
	readFile(a, &n);
	printf("Du lieu truoc khi sap xep:\n");
	printData(a, 0, n);
	heapSort(a, n);
	printf("Du lieu sau khi sap xep:\n");
	printData(a, n, 0);
	return 0;
}
