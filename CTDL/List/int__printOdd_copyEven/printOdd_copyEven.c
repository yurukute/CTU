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

void printOdd(List L){
    for(Position P = 1; P <= L.Last; P++){
        if(L.Elements[P-1] % 2)
            printf("%d ", L.Elements[P-1]);
    }
    print("\n");
}

void copyEven(List *L2, List L1){
    makenullList(L2);
    for(Position P = 1; P <= L1.Last; P++){
        if(L1.Elements[P-1] % 2 == 0)
            insertList(L1.Elements[P-1], endList(*L2), L2);
    }
}

int main(){
    List L;
    readList(&L);
    printList(L);
    printOdd(L);
    copyEven(&L, L);
    printList(L);
}