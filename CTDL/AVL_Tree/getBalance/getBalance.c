int getBalance(AVLTree T){
	if (T == NULL)
		return 0;
	else return getHeight(T->Left) - getHeight(T->Right);
}
