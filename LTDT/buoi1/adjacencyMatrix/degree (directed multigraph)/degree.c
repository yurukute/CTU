int degree(Graph *pG, int u){ 
    int deg_u = 0;
    for(int i = 1; i <= pG->n; i++){
        deg_u += pG->A[u][i] + pG->A[i][u];
    }
    return deg_u;
}
