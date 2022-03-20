void printHeight(int height, AVLTree root){
	if(root->Height == height)
		printf("%d ", root->Key);
	if(root->Left != NULL)
		printHeight(height, root->Left);
	if(root->Right != NULL)
		printHeight(height, root->Right);		
}
