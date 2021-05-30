#include<stdio.h>
#include"AListLib.c"

void readList(List *pL){
    makenullList(pL);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        insertList(x,pL->Last+1, pL);
    }
}

void printList(List L){
    for(Position P = 1; P <= L.Last; P++){
        printf("%d ", L.Elements[P-1]);
    }
    printf("\n");
}

void removeAll(int x, List *L){
	while(locate(x, *L) != L->Last+1){
		deleteList(locate(x, *L), L);
	}
}

int main(){
    List L;
    readList(&L);
    printList(L);
    int x;
    scanf("%d", &x);
    removeAll(x, &L);
    printList(L);
}