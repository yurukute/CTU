int hNode(int x, Tree T){
	if(T == NULL)
	    return -1;
	if(x < T->Key)
	    return hNode(x, T->Left);
	if (x > T->Key)
	    return hNode(x, T->Right);
	int left = (T->Left != NULL) ? hNode(T->Left->Key, T->Left) : -1;
	int right = (T->Right != NULL) ? hNode(T->Right->Key, T->Right) : -1;
	return (left > right ? left : right) + 1;
}
