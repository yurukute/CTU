int isMirrors(Tree T, Tree MT){
	if(T == NULL && MT == NULL)
		return 1;
	if(!(T != NULL && MT != NULL) || T->Data != MT->Data)
		return 0;
	return isMirrors(T->Left, MT->Right) && isMirrors(T->Right, MT->Left);
}
