int height(Tree T){
	if(T == NULL)
		return 0;
	int left = height(T->Left);
	int right = height(T->Right);
	return (left > right ? left : right)+1;
}

void getDiameter(Tree T, int *diameter){
	if(T == NULL){
		*diameter = 0;
		return;
	}
	int leftD, rightD;
	getDiameter(T->Left, &leftD);
	getDiameter(T->Right, &rightD);
	*diameter = max(height(T->Left) + height(T->Right) + 1, max(leftD, rightD));
}
