AVLTree search(KeyType key, AVLTree root){
	if (root == NULL) 
		return NULL;
 	else if (key == root->Key)
		return root;
 	else if (key < root->Key)
		return search(key, root->Left);
  	else 
		return search(key, root->Right);
}
