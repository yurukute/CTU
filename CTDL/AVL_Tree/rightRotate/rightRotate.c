 AVLTree rightRotate(AVLTree node){
	AVLTree newNode = node->Left;
	node->Left		= newNode->Right;
	newNode->Right	= node;
	newNode->Height = getHeight(newNode->Left) + 1;
	int left		= getHeight(node->Left);
	int	right		= getHeight(node->Right);
	node->Height	= (left > right ? left : right) + 1;
	if(node->Height > newNode->Height)
		newNode->Height = node->Height + 1;	   
	return newNode;	
}
