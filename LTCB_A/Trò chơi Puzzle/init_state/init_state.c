void init_state(State *S, char *fname){
    FILE *f = fopen(fname, "r");
    fscanf(f, "%d %d", &S->m, &S->n);
    for(int i = 0; i < S->m; i++){
        for(int j = 0; j < S->n; j++){
            fscanf(f, "%d", &S->A[i][j]);
        }
    }
    fscanf(f, "%d %d", &S->r, &S->c);
}