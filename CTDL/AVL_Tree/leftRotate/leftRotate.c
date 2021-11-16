 AVLTree leftRotate(AVLTree node){
	AVLTree newNode = node->Right;
	node->Right		= newNode->Left;
	newNode->Left	= node;
	newNode->Height = getHeight(newNode->Right) + 1;
	int left		= getHeight(node->Left);
	int	right		= getHeight(node->Right);
	node->Height	= (left > right ? left : right) + 1;
	if(node->Height > newNode->Height)
		newNode->Height = node->Height + 1;	   
	return newNode;	
}
