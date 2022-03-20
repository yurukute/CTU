AVLTree rightleftRotate(AVLTree node){
	node->Right = rightRotate(node->Right);
	return leftRotate(node);
}
