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

int member(int x, List L){
    for(Position P = 1; P <= L.Last; P++)
        if(L.Elements[P-1] == x)
            return 1;
    return 0;
}

List unionSet(List A, List B){
    List C;
    makenullList(&C);
    for(Position P = 1; P <= A.Last; P++)
        insertList(A.Elements[P-1], endList(C), &C);        
    for(Position P = 1; P <= B.Last; P++)
        if(!member(B.Elements[P-1], C))
            insertList(A.Elements[P-1], endList(C), &C);
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
    List C = unionSet(A, B);
    printList(C);
}