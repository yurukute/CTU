#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node* NodeType;

struct Node {
	ElementType Element;
	NodeType	Next;
};

typedef NodeType Position;
typedef Position List;

void makenullList(List *Header){
    (*Header) = (struct Node*) malloc(sizeof(struct Node));
    (*Header)->Next = NULL;
}

void readList(List *pL){
    int n;
    scanf("%d", &n);
    makenullList(pL);
    Position P = *pL;
    for(int i = 0; i <n; i++){
        int x;
        scanf("%d", &x);
        Position newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->Element = x;
        newNode->Next = NULL;
        P->Next = newNode;
        P = P->Next;
    }
}

Position locate(ElementType x, List L){
    Position P = L;
    int found = 0;
    while(P->Next != NULL && found == 0){
        if(P->Next->Element == x)
            found = 1;
        else P = P->Next;
    }
    return P;
}

void deleteList(Position P, List *L){
    P->Next = P->Next->Next;
}

void erase(int x, List *pL){
    Position P = locate(x, *pL);
    if(P->Next != NULL)
        deleteList(P, pL);
    else printf("Not found %d\n", x);
}

void removeAll(int x, List *pL){
    Position P = locate(x, *pL);
    while(P->Next != NULL){
        deleteList(P, pL);
        P = locate(x, *pL);
    }
}

void append(int x, List *pL){
    Position P = *pL;
    while(P->Next != NULL)
        P = P->Next;
    Position newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->Element = x;
    newNode->Next = NULL;
    P->Next = newNode;
}

void addFirst(int x, List *pL){
    Position P = *pL;
    Position newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->Element = x;
    newNode->Next = P->Next;
    P->Next = newNode;
}

void insertList(int x, Position P, List *pL){
    Position newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->Element = x;
    newNode->Next = P->Next;
    P->Next = newNode;
}

void normalize(List *pL){
    Position P = *pL;
    while(P->Next != NULL){
        Position Q = P->Next;
        while (Q->Next !=NULL){
            if(P->Next->Element == Q->Next->Element)
                deleteList(Q, pL);
            else Q = Q->Next;
        }
        P = P->Next;        
    }
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

int member(int x, List L){
    return locate(x, L)->Next != NULL;
}

List difference(List L1, List L2){
    List L;
    makenullList(&L);
    Position P = L1;
    while(P->Next != NULL){
        if(!member(P->Next->Element, L2))
            append(P->Next->Element, &L);
        P = P->Next;
    }
    return L;
}

List intersection(List L1, List L2){
    List L;
    makenullList(&L);
    Position P = L1;
    while(P->Next != NULL){
        if(member(P->Next->Element, L2))
            append(P->Next->Element, &L);
        P = P->Next;
    }
    return L;
}

float getAvg(List L){
    float s=0, count = 0;
    Position P = L;
    while(P->Next != NULL){
        s += P->Next->Element;;
        count++;
        P = P->Next;
    }
    return (count ? s/count : -10000);
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
