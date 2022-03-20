#include <stdio.h>
#ifndef TNode
	#include "plistlib.h"
#endif
typedef struct{
	Position Front, Rear;  
} Queue; 

// initialization of queue
void makeNullQueue(Queue *pQ){
   Position Header;
   Header=(Node*)malloc(sizeof(Node)); //Cấp phát Header
   Header->Next=NULL;
   pQ->Front=Header;
   pQ->Rear=Header;
} 

// Check queue is empty or not
int emptyQueue(Queue Q){
		return (Q.Front==Q.Rear);
} 

// check queue is full or not
int fullQueue(Queue Q){
	 return 0;
} 

// return the first element of queue
ElementType front(Queue Q){
 	if (emptyQueue (Q))       
	 	printf ("Hang rong");
    else  
       return (Q.Front)->Next->Element;
} 

// delete the first element of queue
void deQueue(Queue *pQ){
	if (!emptyQueue(*pQ)){
		Position Tempt;
		Tempt=pQ->Front;
		pQ->Front=pQ->Front->Next;
		free(Tempt);
	}else 
		printf("Loi : Hang rong");
 } 


// add value x to queue
void enQueue(ElementType X, Queue *pQ){ 
	 pQ->Rear->Next=(Node*)malloc(sizeof(Node)); // thêm 1 Phan tu vào sau Rear
	 pQ->Rear=pQ->Rear->Next;  // Tra Rear den phan tu moi
	 pQ->Rear->Element=X; //Dat gia tri them vao cho Rear
	 pQ->Rear->Next=NULL; // Gan Next cua Rear (o moi) toi Null
} 

void printQueue(Queue Q)
{
	Position p=Q.Front;
	while (p!=Q.Rear){
		printf("%d ", (p->Next)->Element);
		p=p->Next;
	}
}
