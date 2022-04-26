int down(State S, State *N){
    *N = S;
    if(N->r == N->m-1)
        return 0;
    int x = N-> r;
    int y = N-> c;
    int t = N->A[x][y];
    N->A[x][y] = N->A[x+1][y];
    N->A[x+1][y] = t;
    N->r++;
    return 1;
}