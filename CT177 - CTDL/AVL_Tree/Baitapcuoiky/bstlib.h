#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef struct TNode{	
	KeyType Key;
    struct TNode *Left, *Right;
}TNode;

typedef TNode* Tree;

void MakeNullTree(Tree *T){ 
	(*T)=NULL; 
}

int EmptyTree(Tree T){
	return T==NULL;
}

//Xac dinh con trai 
Tree LeftChild(Tree n){ 	
	if (n!=NULL) return n->Left;
	else return NULL; 
} 
// xac dinh con phai
Tree RightChild(Tree n){	
	if (n!=NULL) return n->Right;
	else return NULL;
}

// kiem tra co phai la nut la
int IsLeaf(Tree n){
	if(n!=NULL)
		return(LeftChild(n)==NULL)			
			&&(RightChild(n)==NULL);
	else return 0;
} 

// duyet tien tu
void PreOrder(Tree T){ 
	printf("%d ",T->Key);
  	if (LeftChild(T)!=NULL)   
  		PreOrder(LeftChild(T));
  	if(RightChild(T)!=NULL)
    	PreOrder(RightChild(T));
}
 
// duyet trung tu
void InOrder(Tree T){
	if (LeftChild(T)!=NULL)
		InOrder(LeftChild(T));
  	printf("%d ",T->Key);
  	if(RightChild(T)!=NULL) 
		InOrder(RightChild(T));
} 

// duyet hau tu
void PosOrder(Tree T){
	if(LeftChild(T)!=NULL) 
		PosOrder(LeftChild(T));
  	if(RightChild(T)!=NULL)
		PosOrder(RightChild(T));
 	printf("%d ",T->Key);
}

// xac dinh so nut tren cay
int nb_nodes(Tree T){
  	if(EmptyTree(T)) 
		return 0;
  	else 
		return 1 
			+ nb_nodes(LeftChild(T))
			+ nb_nodes(RightChild(T));
} 

// tao cay tu 02 cay co san
Tree Create2(KeyType v,Tree L,Tree R){
	Tree N;
	N=(TNode*)malloc(sizeof(TNode));
	N->Key=v;
	N->Left=L;
	N->Right=R;
	return N; 
}

// tim x trong BST
Tree Search(KeyType x,Tree Root){
	if (Root == NULL) //không tìm thay x 
		return NULL;
 	else if (Root->Key == x) // tìm thay khoá x 
		return Root;
 	else if (Root->Key < x)
      	//tìm tiep trên cây bên phai            
      	return Search(x,Root->Right);	
  	else 
		//tìm tiep trên cây bên trái
		return Search(x,Root->Left);
}

// them nut co gia tri x vao cay
int InsertNode(KeyType X, Tree *T)
{
	static int added=0;    
  	if((*T) == NULL)
		{
			(*T)      = (TNode*)malloc(sizeof(TNode));
			(*T)->Key = X;
			(*T)->Left = NULL;
			(*T)->Right = NULL;
			added =1;
		}
  	else
		if((*T)->Key == X){
			printf("Da ton tai khoa %d \n",X);
			added= -1;
		}	
		else
			if( (*T)->Key > X)
				{
					InsertNode(X,&(*T)->Left);
			
				}
			
			else{
				InsertNode(X,&(*T)->Right);
			
			}
	return added;
			
	
}

// Xoa nut co khoa nho nhat trong cay (cuc trai cua cay con phai)
KeyType DeleteMin(Tree *T)
{
 	KeyType k;
 	if((*T)->Left == NULL)
		{
			k = (*T)->Key;
			(*T) = (*T)->Right;
			return k;
		}
 	else return DeleteMin(&(*T)->Left);
}


// Xoa nut co khoa lon nhat trong cay (cuc phai cua cay con trai)
KeyType DeleteMax(Tree *T)
{
	KeyType k;
	if((*T)->Right == NULL)
		{
			k = (*T)->Key;
			(*T) = (*T)->Left;
			return k;
		}
	else return DeleteMax(&(*T)->Right);
}

// Xoa nut trong cay BST
void DeleteNode(KeyType X, Tree *T)
{
	if((*T)!=NULL) //Kiem tra cay khac rong
		if(X < (*T)->Key) //Hy vong X nam ben trai cua nut
			DeleteNode(X,&(*T)->Left);
		else
			if(X > (*T)->Key) //Hy vong X nam ben phai cua nut
				DeleteNode(X,&(*T)->Right);
			else // Tim thay khoa X tren cay
				if(((*T)->Left==NULL)&&((*T)->Right==NULL))//X la nut la
					(*T)=NULL; // Xoa nut X
				else // X co it nhat mot con
					if((*T)->Left==NULL) //Chac chan co con phai
						(*T) = (*T)->Right;
					else
						if((*T)->Right==NULL) //Chac chan co con trai
							(*T) = (*T)->Left;
						else  // X co hai con
							(*T)->Key = DeleteMin(&(*T)->Right);
}




