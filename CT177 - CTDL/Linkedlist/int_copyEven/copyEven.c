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

void printOddNumbers(List L){
    Position P = L;
    while(P->Next != NULL){
        if(P->Next->Element % 2)    
            printf("%d ", P->Next->Element);
        P = P->Next;
    }
	printf("\n");
}

void copyEvenNumbers(List L1, List *pL2){
    makenullList(pL2);
    Position P = L1;
    while(P->Next != NULL){
        if(P->Next->Element % 2 == 0)
            append(P->Next->Element, pL2);
        P = P->Next;
    }
}

int main(){
    List L;
    getList(&L);
    printList(L);
    printOddNumbers(L);
	List L2;
	copyEvenNumbers(L, &L2);
    printList(L2);
}
