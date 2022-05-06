#include<stdio.h>

#define MAX_N 50

void readFile(int a[][MAX_N], int *n){
	FILE *f = fopen("tam_giac_so.txt", "r");
	int i = 0;
	while(!feof(f)){
		for(int j = 0; j <= i; j++){
			fscanf(f, "%d", &a[i][j]);			
		}
		i++;
	}
	*n = i;
	fclose(f);
}

void printTriangle(int a[][MAX_N], int n){
	printf("Tam giac so da cho:\n");
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j <= i; j++){
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}

void printResult(int res[], int n){
    printf("Phuong an la duong di qua cac so: \n  ");
    int sum = res[n-1];
    for(int i = 0; i < n-1; i++){
        printf("%d -> ", res[i]);
        sum += res[i];
    }
    printf("%d\n", res[n-1]);
    printf("Tong cac so tren duong di la: %d", sum);
}
    
int colIndex(int F[][MAX_N], int i, int j){
	if (j == 0)
		return (F[i-1][0] > F[i-1][1]) ? 0 : 1;
	if (j == i)
		return i-1;
	if (j == i-1)
		return (F[i-1][i-2] > F[i-1][i-1]) ? i-2 : i-1;
	if (F[i-1][j-1] > F[i-1][j] && F[i-1][j-1] > F[i-1][j+1])
		return j-1;
	if (F[i-1][j] > F[i-1][j-1] && F[i-1][j] > F[i-1][j+1])
		return j;
	return j+1;
}

void createTable(int a[][MAX_N], int n, int F[][MAX_N]){
	F[0][0] = a[0][0];
	F[1][0] = F[0][0] + a[1][0];
	F[1][1] = F[0][0] + a[1][1];
	for(int i = 2; i < n; i++){
		for(int j = 0; j <= i; j++){
			int k = colIndex(F, i, j);
			F[i][j] = F[i-1][k] + a[i][j];
		}
	}
}

void printTable(int F[][MAX_N], int n){
	printf("Bang quy hoach dong:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            printf("%5d", F[i][j]);
        }
        printf("\n");
    }
}

void searchTable(int a[][MAX_N], int n, int F[][MAX_N], int res[]){
    int max = F[n-1][0], k = 0;
    for(int j = 1; j < n; j++){
        if(F[n-1][j] > max){
            max = F[n-1][j];
            k = j;
        }
    }
    for(int i = n-1; i >= 0; i--){
        res[i] = a[i][k];
        k = colIndex(F, i, k);
    }       
}

int main(){
	int a[MAX_N][MAX_N], n = 0, F[MAX_N][MAX_N], res[MAX_N];
	readFile(a, &n);
	printTriangle(a, n);

    createTable(a, n, F);
    printTable(F, n);

    searchTable(a, n, F, res);
    printResult(res, n);
}
