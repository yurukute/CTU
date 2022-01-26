void init_graph(Graph *pG, int n){
	pG->n = n;
	pG->m = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; i < n; i++)
			pG->A[i][j] = 0;
}

void add_edge(Graph *pG, int u, int v) {
	pG->A[u][v]++;
	if(u != v)
	    pG->A[v][u]++;
	pG->m++;
}
