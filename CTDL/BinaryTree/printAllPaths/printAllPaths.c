void printAllPaths(Tree T, DataType path[], int len, int pathlen){
	if(T == NULL)
		return;
	path[len] = T->Data;
	len++;
	if(T->Left == NULL && T->Right == NULL && len == pathlen+1)
		printArray(path, len);
	else{
		printAllPaths(T->Left, path, len, pathlen);
		printAllPaths(T->Right, path, len, pathlen);
	}
}
