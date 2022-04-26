int is_finished(State S){
	for(int i = 0; i < S.m; i++)
	    for(int j = 0; j < S.n; j++)
		    if(S.A[i][j] != i*S.n + j + 1)
			    return 0;
	return 1;
}