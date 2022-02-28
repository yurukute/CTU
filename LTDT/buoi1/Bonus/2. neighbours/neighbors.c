List neighbors(Graph *pG, int u){
    List L;
    make_null(&L);
    for(int v = 1; v <= pG->n; v++){
        for(int e = 0; e < pG->m; e++){        
            if(pG->A[u][e] && pG->A[v][e] && u != v){
                push_back(&L, v);
                break;
            }
        }
    }
    return L;
}
