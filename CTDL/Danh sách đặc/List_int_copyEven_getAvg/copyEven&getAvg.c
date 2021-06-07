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

void normalize(List *L){
    for(Position P = 1; P <= L->Last; P++){
        Position Q = P + 1;
        while(Q <= L->Last){
            if(retrieve(P,*L) == retrieve(Q,*L))
                deleteList(Q, L);
            else Q++;
        }
    }
}

void copyEven(List *L2, List L1){
    makenullList(L2);
    for(Position P = 1; P <= L1.Last; P++){
        if(L1.Elements[P-1] % 2 == 0)
            insertList(L1.Elements[P-1], endList(*L2), L2);
    }
}

float getAvg(List L){
    float S = 0;
    for(Position P = 1; P <= L.Last; P++){
        S += L.Elements[P-1];
    }
    return (S ? S / L.Last : -10000);
}

int main(){
    List L;
    readList(&L);
    printList(L);
    copyEven(&L, L);
    printList(L);
    printf("%.3f", getAvg(L));
}