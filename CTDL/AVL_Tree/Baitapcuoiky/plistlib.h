#include <stdio.h>
//#include <conio.h>
#include <malloc.h>


#ifndef ElementType
	typedef int ElementType;  // define type of elements
#endif
#ifndef  TNode
  #define TNode
  typedef struct Node {
        ElementType Element;
        struct Node * Next;
  }Node ;
#endif        

typedef Node* Position; 		// Position type
typedef Position List;

// List initialization
void makeNullList(List *pL){
	(*pL)=(Node*) malloc(sizeof(Node));
	(*pL)->Next= NULL;
}

//Check list is empty or not
int emptyList(List L){
	return (L->Next==NULL);
}
// return the first position of list
Position first(List L){
	return L;
}

// return the lastest position of list
Position endList(List L){
	Position p;
	p=first(L);
	while (p->Next!=NULL) p=p->Next;
	return p;
} 


// return the next position of position P
Position next(Position p, List L){
	return p->Next;
}

// Return the value of elements[P] of list
ElementType retrieve(Position p, List L){
	if (p->Next!=NULL)
		return p->Next->Element;
}

void insertList(ElementType x, Position p, List *pL){
	Position t;
	t=(Node*)malloc(sizeof(Node));
	t->Element=x;
	t->Next=p->Next;
	p->Next=t;
}

void deleteList(Position p, List *pL){ 
	Position temp;
	if (p->Next!=NULL){  
		temp=p->Next; 
		p->Next=temp->Next; 
		free(temp);
	  }
} 

Position locate(ElementType x, List L){	
	Position p;
	int found = 0;
	p = first(L);
	while ((next(p,L) != NULL) && (found == 0))
		if (retrieve(p,L) == x) found = 1;
		else p = next(p,L);
	return p;
} 

Position previous(Position p, List L){
	Position q=first(L);
	while ((next(q,L)!= NULL) && (next(q,L)!=p))
		q = next(q,L); 	  
	return q;
}

void swap(Position p, Position q, List *pL){
	ElementType temp;
	temp=retrieve(p,*pL);
	p->Next->Element=retrieve(q,*pL);
	q->Next->Element=temp;	
}
void printList(List L){
	Position p;
	p = first(L);
	while (next(p,L) != NULL)
	{
		printf("%d ", retrieve(p,L));
		p = next(p, L);
	}
	printf("\n");
}



