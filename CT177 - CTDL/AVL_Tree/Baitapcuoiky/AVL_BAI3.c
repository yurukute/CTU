#include "AVL_BAI2_B2012184.h"
#include <stdio.h>

void readAVLTree(AVLTree *pT) {
	makeNullTree(pT);
	FILE *f = fopen("avltest.txt", "r");	
	while(!feof(f)){
		KeyType x;
		fscanf(f, "%d\n", &x);
		*pT = insertNode(x, *pT);
	}
}

int main(){
	AVLTree T;
	readAVLTree(&T);
	levelOrder(T);
}
