void add_edge(Graph* pG, int e, int x, int y){
    pG->A[x][e] = 1;
    pG->A[y][e] = 1;
}
