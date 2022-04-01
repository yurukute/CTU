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

int findPivot(record a[], int i, int j){
	int k = i+1;
	keytype firstkey = a[i].key;	
	while((k<=j) && (a[k].key == firstkey))
		k++;
	if(k > j)
		return -1;
	return a[k].key > firstkey ? k : i;
}

int partition(record a[], int L, int R, keytype pivot){
	while(L <= R){
		while(a[L].key < pivot)
			L++;
		while(a[R].key >= pivot)
			R--;
		if(L < R)
			swap(&a[L], &a[R]);
	}
	return L;
}

void quickSort(record a[], int i, int j){
	int pivotidx = findPivot(a,i,j);
	if(pivotidx != -1){		
		int k = partition(a,i,j, a[pivotidx].key);
		quickSort(a, i, k-1);
		quickSort(a, k, j);
	}	
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

void printData(record a[], int n){
	for(int i=0; i < n; i++)
		printf("%3d %5d %8.2f\n", i+1, a[i].key, a[i].other);
}

int main (){
	record a[MAX_N];
	int n = 0;
	printf("Thuat toan Quick Sort\n");
	readFile(a, &n);
	printf("Du lieu truoc khi sap xep:\n");
	printData(a, n);
	quickSort(a, 0, n-1);
	printf("Du lieu sau khi sap xep:\n");
	printData(a, n);
	return 0;
}
