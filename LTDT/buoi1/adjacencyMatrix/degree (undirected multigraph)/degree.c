int degree(Graph *pG, int u){ 
    int deg_u = 0;
    for(int i = 1; i <= pG->n; i++){
        if(pG->A[u][i])
            deg_u += pG->A[u][i];
    }
    return deg_u + pG->A[u][u];
}
