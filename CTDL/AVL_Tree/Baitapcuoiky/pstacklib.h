#ifndef TNode
	#include "plistlib.h"
#endif
typedef List Stack;

void makeNullStack(Stack *pS){
	makeNullList(pS);
}
int emptyStack(Stack S){ 
	return emptyList(S);
}

void push(ElementType X, Stack *pS){
		insertList (X, first (*pS), pS);
}

void pop (Stack *pS){	
	deleteList (first (*pS), pS);
}
ElementType top (Stack S){	
	retrieve(first (S), S);
}
void printStack(Stack S){
	printList(S);
}


