AVLTree leftrightRotate(AVLTree node){
	node->Left = leftRotate(node->Left);
	return rightRotate(node);
}
