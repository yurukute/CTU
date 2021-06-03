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
 
Position next(Position P, List L) {	
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

//Các phép toán

//Tính trung bình cộng
float getAvg(List L){
    float S = 0;
    for(Position P = 1; P <= L.Last; P++){
        S += L.Elements[P-1];
    }
    return (S ? S / L.Last : -10000);
}

//Kiểm tra x có tồn tại trong L hay không
int member(int x, List L){
    for(Position P = 1; P < L.Last+1; P++){
        if(L.Elements[P-1] == x)
            return 1;
    }
    return 0;
}

//Chuẩn hóa: xóa các phần tử trùng
void normalize(List *L){
    for(Position P = 1; P <= L->Last; P++){
        Position Q = P + 1;
        while(Q <= L->Last){
            if(L->Elements[P-1] == L->Elements[Q-1])
                deleteList(Q, L);
            else Q++;
        }
    }
}

void printList(List L){
    for(Position P = 1; P < L.Last+1; P++){
        printf("%d ", L.Elements[P-1]);
    }
}

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

void removeAll(int x, List *L){
	while(locate(x, *L) != L->Last+1){
		deleteList(locate(x, *L), L);
	}
}

void sort(List *pL){
    for(Position P = 1; P < pL->Last; P++){
        for(Position Q = P+1; Q < pL->Last+1; Q++){
            if(pL->Elements[P-1] > pL->Elements[Q-1]){
                int t = pL->Elements[P-1];
                pL->Elements[P-1] = pL->Elements[Q-1];
                pL->Elements[Q-1] = t;
            }
        }
    }
}