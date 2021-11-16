void printNLR(AVLTree T){
	printf("(%d - %d); ", T->Key, T->Height);
	if(T->Left != NULL)
		printNLR(T->Left);
	if(T->Right != NULL)
		printNLR(T->Right);
}
