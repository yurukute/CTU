void print_state(State S){
    for(int i = 0; i < S.m; i++){
		for(int j = 0; j < S.n; j++)
		    if(i != S.r || j != S.c)
			    printf("%2d ", S.A[i][j]);
			else 
			    printf(".. ");
		printf("\n");
	}
	printf("%d %d", S.r, S.c);
}