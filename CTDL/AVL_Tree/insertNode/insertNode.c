AVLTree insertNode(KeyType key, AVLTree root){
	if(root == NULL){
		root = (AVLTree)malloc(sizeof(struct Node));
		root->Key	 = key;
		root->Height = 0;
		root->Left	 = root->Right = NULL;
		return root;
	}
	if(key == root->Key)
		return root;
	else if (key < root->Key)
		root->Left = insertNode(key, root->Left);
	else
		root->Right = insertNode(key, root->Right);	
	int balance	 = getBalance(root);
	if(balance > 1)  root = (key < root->Left->Key  ? rightRotate(root) : leftrightRotate(root));	
	if(balance < -1) root = (key > root->Right->Key ? leftRotate(root)  : rightleftRotate(root));
	int left = getHeight(root->Left), right = getHeight(root->Right);
	root->Height = (left > right ? left : right) + 1;
	return root;
}
