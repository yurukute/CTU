Tree createTree(char pre[], char in[], int Start, int End){
	static int preIndex=0;
	Tree N = NULL;
	if(Start <= End){
		N = (Tree)malloc(sizeof(struct Node));
		N->Data = pre[preIndex];
		preIndex++;
		if(Start != End){
			int inIndex = findIndex(N->Data, in, 0, strlen(in)-1);
			N->Left = createTree(pre, in, Start, inIndex - 1);
			N->Right = createTree(pre, in, inIndex + 1, End);
		}
	}
	return N;
}
