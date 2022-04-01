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

void bubbleSort(record a[], int n){
	for(int i = 0; i < n-1; i++)
		for(int j = n-1; j > i; j--)
			if(a[j].key < a[i].key)
				swap(&a[i], &a[j]);
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
    for(int i = 0; i < n; i++)
        printf("%3d %5d %8.2f\n", i+1, a[i].key, a[i].other);
}

int main (){
	record a[MAX_N];
	int n = 0;
	printf("Thuat toan Bubble Sort\n");
	readFile(a, &n);
	printf("Du lieu truoc khi sap xep:\n");
	printData(a, n);
	bubbleSort(a, n);
	printf("Du lieu sau khi sap xep:\n");
	printData(a, n);
	return 0;
}
