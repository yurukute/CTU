typedef int KeyType;
struct Node{	
	KeyType Key;
	int Height;
    struct Node *Left, *Right;	
};

typedef struct Node* AVLTree;
