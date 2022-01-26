int outdegree(Graph *pG, int u){
    int deg_out = 0;
    for(int i = 1; i <= pG->n; i++){
        deg_out += pG->A[u][i];
    }
    return deg_out;
}
