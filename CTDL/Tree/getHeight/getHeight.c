int getHeight(Tree T){
	if(T == NULL)
		return -1;
	int left = getHeight(T->Left);
	int right = getHeight(T->Right);
	return (left > right ? left : right) + 1;
}
