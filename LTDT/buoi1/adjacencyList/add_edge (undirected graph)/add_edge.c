void add_edge(Graph *pG, int u, int v) {
    for (int i = 0; i < pG->m; i++){
        if ((pG->edges[i].u == u && pG->edges[i].v == v) || (pG->edges[i].u == v && pG->edges[i].v == u)){
            return;
		}
	}
    pG->edges[pG->m].u = u;
    pG->edges[pG->m].v = v;
    pG->m++;
}