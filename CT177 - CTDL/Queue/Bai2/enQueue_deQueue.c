#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;    
typedef struct Node{
	ElementType Element;
	struct Node * Next;
} Node;
typedef Node* Position;
typedef struct{
	Position Front, Rear;  
} Queue; 

void makeNullQueue(Queue *pQ){
	Position Header;
	Header = (Node*)malloc(sizeof(Node)); 
	Header->Next = NULL;
	pQ->Front = Header;
	pQ->Rear = Header;
} 

int emptyQueue(Queue Q){
	return (Q.Front == Q.Rear);
}

int deQueue(Queue *pQ){
	if (emptyQueue(*pQ))
		return -1;	
	Position Tempt;
	Tempt = pQ->Front;
	pQ->Front = pQ->Front->Next;
	int x = Tempt->Next->Element;
	free(Tempt);
	return x;   
}

void enQueue(ElementType X, Queue *pQ){ 
	pQ->Rear->Next  =  (Node*)malloc(sizeof(Node)); 
	pQ->Rear = pQ->Rear->Next;  
	pQ->Rear->Element = X; 
	pQ->Rear->Next = NULL; 
} 

int main(){
	Queue Q;
	makeNullQueue(&Q);
	int n, size = 0;
	scanf("%d", &n);
	while (n--) {
		char c;	scanf("%c", &c);
		scanf("%c", &c);
		if(c == 'E'){
			int x;
			scanf("%d", &x);
			enQueue(x, &Q);
			printf("%d\n", ++size);			
		}
		else printf("%d %d\n", deQueue(&Q), size == 0 ? 0 : --size);
	}
}
