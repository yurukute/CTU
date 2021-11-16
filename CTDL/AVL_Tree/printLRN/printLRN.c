void printLRN(AVLTree T){
	if(T->Left != NULL)
		printLRN(T->Left);
	if(T->Right != NULL)
		printLRN(T->Right);
	printf("(%d - %d); ", T->Key, T->Height);
}
