// Cau 1. undirected graph
void init_graph(Graph *pG, int n) {
    pG->n = n;
    pG->m = 0;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            pG->A[u][v] = 0;
}

void add_edge(Graph *pG, int u, int v) {
    pG->A[u][v] += 1;
    if (u != v)
        pG->A[v][u] += 1;
    
    pG->m++;
}

// Cau 2. undirected multigraph
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

// Cau 3. directed multigraph
void init_graph(Graph *pG, int n){
	pG->n = n;
	pG->m = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; i < n; i++)
			pG->A[i][j] = 0;
}

void add_edge(Graph *pG, int u, int v) {
	pG->A[u][v]++;
	pG->m++;
}
