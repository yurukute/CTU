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

void append(int x, List *pL){
    Position P = *pL;
    while(P->Next != NULL)
        P = P->Next;
    Position newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->Element = x;
    newNode->Next = NULL;
    P->Next = newNode;
}

void getList(List *pL){
    makenullList(pL);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        append(x, pL);
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

void sort(List *pL){
    Position P = *pL;
    while(P->Next != NULL){
        Position Q = P->Next;
        while(Q->Next != NULL){
            if(P->Next->Element > Q->Next->Element){
                int x = P->Next->Element;
                P->Next->Element = Q->Next->Element;
                Q->Next->Element = x;
            }
            else Q = Q->Next;
        }
        P = P->Next;
    }
}

int main(){
    List L;
    getList(&L);
    printList(L);
    sort(&L);
    printList(L);
}