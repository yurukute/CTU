Tree convertTree(Tree T){
	if(T == NULL)
		return T;
	Tree MT = (Tree)malloc(sizeof(struct Node));
	MT->Data = T->Data;
	MT->Left = convertTree(T->Right);
	MT->Right = convertTree(T->Left);
	return MT;
}
