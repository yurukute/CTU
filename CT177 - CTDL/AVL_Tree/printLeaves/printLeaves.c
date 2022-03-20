void printLeaves(AVLTree root){
	if(root->Left == NULL && root->Right == NULL)
		printf("%d ", root->Key);
	else {
		if(root->Left != NULL)
			printLeaves(root->Left);
		if(root->Right != NULL)
			printLeaves(root->Right);
	}
}
