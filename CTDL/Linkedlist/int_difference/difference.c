#include<stdio.h>
#include<stdlib.h>

struct Node{
    int Element;
    struct Node* Next;
};

typedef struct Node* Position;
typedef Position List;

void makenullList(List *Header){
    (*Header)=(struct Node*)malloc(sizeof(struct Node));
    (*Header)->Next = NULL;
}

void insertList(int x, Position P, List *pL){
    Position newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->Element = x;
    newNode->Next = P->Next;
    P->Next = newNode;
}

Position locate(int x, List L){
    Position P = L;
    int found = 0;
    while(P->Next != NULL && found == 0){
        if(P->Next->Element == x)
            found = 1;
        else P = P->Next;
    }
    return P;
}

void getList(List *pL){
    makenullList(pL);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        if(locate(x, *pL)->Next == NULL){
            Position P = *pL;
            insertList(x, P, pL);
        }
    }
}

void printList(List L){
    Position P = L;
    while(P->Next != NULL){
        printf("%d ", P->Next->Element);
        P = P->Next;
    }
    printf("\n");
}

List difference(List L1, List L2){
    List L;
    makenullList(&L);
    Position P = L1;
    while(P->Next != NULL){
        if(locate(P->Next->Element, L2)->Next == NULL){
            Position Q = L;
            while(Q->Next != NULL)
                Q = Q->Next;
            insertList(P->Next->Element, Q, &L);
        }
        P = P->Next;
    }
    return L;
}

int main(){
    List A;
    getList(&A);
    List B;
    getList(&B);
    printList(A);
    printList(B);
    List H = difference(A, B);
    printList(H);
}