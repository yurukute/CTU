// Cau 1. Undirected
int degree(Graph *pG, int u){ 
    int deg_u = 0;
    for(int i = 1; i <= pG->n; i++){
        if(pG->A[u][i])
            deg_u += pG->A[u][i];
    }
    return deg_u + pG->A[u][u];
}

// Cau 2. Directed
int degree(Graph *pG, int u){ 
    int deg_u = 0;
    for(int i = 1; i <= pG->n; i++){
        deg_u += pG->A[u][i] + pG->A[i][u];
    }
    return deg_u;
}

// Cau 3
int indegree(Graph *pG, int u){
    int deg_in = 0;
    for(int i = 1; i <= pG->n; i++){
        deg_in += pG->A[i][u];
    }
    return deg_in;
}

// Cau 4
int outdegree(Graph *pG, int u){
    int deg_out = 0;
    for(int i = 1; i <= pG->n; i++){
        deg_out += pG->A[u][i];
    }
    return deg_out;
}
