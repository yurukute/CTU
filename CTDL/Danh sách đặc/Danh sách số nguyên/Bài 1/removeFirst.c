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
    for(Position P = 1; P < L.Last+1; P++){
        printf("%d ", L.Elements[P-1]);
    }
    printf("\n");
}

void removeFirst(int x, List *L){
    if(locate(x, *L) != L->Last+1)
        deleteList(locate(x, *L), L);
}

int main(){
    List L;
    readList(&L);
    printList(L);
    int x;
    scanf("%d", &x);
    removeFirst(x, &L);
    printList(L);
}