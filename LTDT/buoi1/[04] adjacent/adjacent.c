// Cau 1
int adjacent(Graph *pG, int u, int v){
	for(int i = 0; i < pG->m; i++){
		if((pG->edges[i].u == u && pG->edges[i].v == v) || (pG->edges[i].u == v && pG->edges[i].v == u))
			return 1;
	}
	return 0;
}

// Cau 2
int adjacent(Graph *pG, int u, int v){
	for(int i = 0; i < pG->m; i++){
		if(pG->edges[i].u == u && pG->edges[i].v == v)
			return 1;
	}
	return 0;
}
