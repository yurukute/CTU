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

List intersection(List A, List B){
    List C;
    makenullList(&C);
    for(Position P = 1; P < A.Last+1; P++){
        for(Position Q = 1; Q < B.Last+1; Q++){
            if(A.Elements[P-1] == B.Elements[Q-1])
                insertList(A.Elements[P-1], endList(C), &C);
        }
    }
    return C;
}

int main(){
    List A, B;
    readList(&A);
    readList(&B);
    normalize(&A);
    normalize(&B);
    printList(A);
    printList(B);
    List C = intersection(A, B);
    printList(C);
}