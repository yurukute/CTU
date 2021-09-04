#include <stdio.h>
#include <stdlib.h>

#define MaxLength 100

typedef int ElementType;
typedef int Position; 
typedef struct {
	ElementType Elements[MaxLength];
	Position Last;
} List; 

void makenullList(List *L) {
	L->Last=0;
}

int emptyList(List L) { 
	return (L.Last==0);
}

ElementType retrieve(Position P, List L) {
	return L.Elements[P-1];
} 

Position first(List L) {	
	return 1; 
} 

Position endList(List L) {
	return L.Last+1;
}
 
Position next(Position P, List L){
	if (P<1 || P>L.Last){
		return -1;
	}
	return P+1;
}

Position locate(ElementType X, List L) {
	Position P = first(L);
	int Found = 0;
	while ((P != endList(L)) && (Found == 0))
		if (retrieve(P,L) == X) 
			Found = 1;
		else P = next(P, L);
	return P;
} 

void insertList(ElementType X, Position P, List *L) {
	if (L->Last == MaxLength)
		printf("Danh sach day");	
	else if ((P < 1) || (P > L->Last+1))
	    printf("Vi tri khong hop le");
		else {
			Position Q;
			for(Q = L->Last; Q >= P; Q--)
				L->Elements[Q] = L->Elements[Q-1];
			L->Elements[P-1] = X;
			L->Last++;
		}
} 

void deleteList(Position P,List *L) { 
	if ((P < 1) || (P > L->Last))
		printf("Vi tri khong hop le");
	else if (emptyList(*L))
	    printf("Danh sach rong!");
		else {
			Position Q;
			for(Q = P-1; Q < L->Last-1; Q++)
				L->Elements[Q] = L->Elements[Q+1];
			L->Last--;
		}
}

void printList(List L){
	Position P= first(L);
	while (P != endList(L)){
		printf("%d ", retrieve(P,L));
		P=next(P,L);
	}
	printf("\n");	
}
