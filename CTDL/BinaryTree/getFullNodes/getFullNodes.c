int getFullNodes(Tree T){
	if(T == NULL)
		return 0;
	return (T->Left != NULL && T->Right != NULL) + getFullNodes(T->Left) + getFullNodes(T->Right);
}
