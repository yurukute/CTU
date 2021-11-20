Tree findElement(DataType x, Tree T){
	if(T == NULL || x == T->Data)
		return T;
	Tree Left = findElement(x, T->Left);
	if(Left != NULL)
	    return Left;
	Tree Right = findElement(x, T->Right);
	if(Right != NULL)
	    return Right;
	return NULL;
}
