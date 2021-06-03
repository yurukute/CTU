void removeAll(int x, List *L){
	while(locate(x, *L) != L->Last+1){
		deleteList(locate(x, *L), L);
	}
}