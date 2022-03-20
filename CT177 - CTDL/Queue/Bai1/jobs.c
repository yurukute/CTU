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
	Header=(Node*)malloc(sizeof(Node)); 
	Header->Next=NULL;
	pQ->Front=Header;
	pQ->Rear=Header;
} 

int emptyQueue(Queue Q){
	return (Q.Front==Q.Rear);
} 

ElementType front(Queue Q){		
    return (Q.Front)->Next->Element;
} 

void deQueue(Queue *pQ){
	if (!emptyQueue(*pQ)){
		Position Tempt;
		Tempt=pQ->Front;
		pQ->Front=pQ->Front->Next;
		free(Tempt);
	}
}

void enQueue(ElementType X, Queue *pQ){ 
	pQ->Rear->Next=(Node*)malloc(sizeof(Node)); 
	pQ->Rear=pQ->Rear->Next;  
	pQ->Rear->Element=X; 
	pQ->Rear->Next=NULL; 
} 

int main(){
	int n;
	scanf("%d", &n);
	Queue jobs, priority;
	makeNullQueue(&jobs);
	makeNullQueue(&priority);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		enQueue(x, &jobs);
	}
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		enQueue(x, &priority);
	}
	int time = 0;
	while(!emptyQueue(jobs)){
		if(front(jobs) != front(priority))
			enQueue(front(jobs), &jobs);		
		else deQueue(&priority);
		deQueue(&jobs);
		time++;
	}
	printf("%d", time);
}
