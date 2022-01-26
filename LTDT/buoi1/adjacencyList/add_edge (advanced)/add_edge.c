void add_edge(Graph *pG, int u, int v){
	if(u < 1 || u > pG->n || v < 1 || v > pG->n){
		return;
	}
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}
