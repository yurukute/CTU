#include <stdio.h>
#include <stdlib.h>
#include "pqueuelib.h"

typedef int KeyType;
typedef struct AVLNode{	
	KeyType key;
	int bal, height;
    struct AVLNode *left, *right;	
}AVLNode;

typedef AVLNode* AVLTree;

#define BALANCE 0
#define LEFT 	1
#define RIGHT 	2

void makeNullTree(AVLTree *T){
	(*T) = NULL;
}
AVLTree createAVLNode(KeyType x){
	AVLTree T = (AVLTree) malloc(sizeof(AVLNode));
	T->key	  = x;
	T->left	  = T->right  = NULL;
	T->height = 0;
	T->bal 	  = BALANCE;
	return T;
}

int height(AVLNode *node){	
	return (node == NULL) ? -1 : node->height;
}

AVLNode* rotateLeft(AVLNode *pNode){
	AVLNode *newNode = pNode->right;
	pNode->right	 = newNode->left;
	newNode->left	 = pNode;
	int	left		 = height(pNode->left);
	int	right		 = height(pNode->right);
	pNode->height	 = (left > right ? left : right) + 1;
	newNode->height	 = height(newNode->right) + 1;
	if(pNode->height >= newNode->height)
		newNode->height = pNode->height + 1;
	pNode->bal = newNode->bal = 0;
	return newNode;
}

AVLNode* rotateRight(AVLNode *pNode){
	AVLNode *newNode = pNode->left;
	pNode->left		 = newNode->right;
	newNode->right	 = pNode;	
	int	left		 = height(pNode->left);
	int	right		 = height(pNode->right);
	pNode->height	 = (left > right ? left : right) + 1;
	newNode->height	 = height(newNode->left) + 1;
	if(pNode->height >= newNode->height)
		newNode->height = pNode->height + 1;
	pNode->bal = newNode->bal = 0;
	return newNode;	
}

AVLNode* rotateLeftRight(AVLNode *pNode){
	pNode->left = rotateLeft(pNode->left);
	return rotateRight(pNode);
}

AVLNode* rotateRightLeft(AVLNode *pNode){
	pNode->right = rotateLeft(pNode->right);
	return rotateLeft(pNode);
}

AVLTree insertNode(KeyType key, AVLTree root){
	if(root == NULL)
		return createAVLNode(key);
	if(key == root->key)
		return root;
	if (key < root->key)
		root->left = insertNode(key, root->left);
	else
		root->right = insertNode(key, root->right);
	int left = height(root->left);
	int right = height(root->right);
	root->height = (left > right ? left : right) + 1;
	switch(left - right){
		case 0 : root->bal = BALANCE;	break;
		case 1 : root->bal = LEFT;  	break;
		case -1: root->bal = RIGHT;  	break;
		default:
			if (root->bal == LEFT) //cay lech trai
				root = (root->left->bal == LEFT  ? rotateRight(root) : rotateLeftRight(root));
			if(root->bal == RIGHT) //cay lech phai
				root = (root->right->bal == RIGHT ? rotateLeft(root)  : rotateRightLeft(root));			   
			break;
	}
	return root;
}

void levelOrder(AVLTree root){
	if(root == NULL)
		return;
	Queue Q;
	makeNullQueue(&Q);
	enQueue(root->key, &Q);
	while(!emptyQueue(Q)){
		AVLTree temp = root;
		while(temp->key != front(Q)){
			if(front(Q) < temp->key)
				temp = temp->left;
			else temp = temp->right;
		}
		printf("(%d, %d, %d) ", temp->key, temp->bal, temp->height);		
		if(temp->left != NULL)
			enQueue(temp->left->key, &Q);
		if(temp->right != NULL)
			enQueue(temp->right->key, &Q);
		deQueue(&Q);
	}
}
