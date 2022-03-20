DataType findMax(Tree T){
	DataType max = T->Data;	
	DataType left = T->Left != NULL ? findMax(T->Left) : 0;
	DataType right = T->Right != NULL ? findMax(T->Right) : 0;
	if(max < left || max < right)
		max = left > right ? left : right;
	return max;
}
