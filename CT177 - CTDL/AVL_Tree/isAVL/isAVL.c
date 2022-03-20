int isAVL(AVLTree root){
	if(root == NULL)
		return 1;
	if(abs(getBalance(root)) <= 1 && isAVL(root->Left) && isAVL(root->Right))
		return 1;
	return 0;
}
