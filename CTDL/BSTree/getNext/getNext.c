Tree getNext(int x, Tree T){
	Tree succ = NULL;
	while(T != NULL){
		if(T->Key > x){			
			succ = T;
			T = T->Left;
		}
		else T = T->Right;
	}
	return succ;
}
