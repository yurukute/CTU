int indegree(Graph *pG, int u){
    int deg_in = 0;
    for(int i = 1; i <= pG->n; i++){
        deg_in += pG->A[i][u];
    }
    return deg_in;
}
