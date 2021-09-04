int left(State S, State *N){
    *N = S;
    if(N->c == 0)
        return 0;
    int x = N-> r;
    int y = N-> c;
    int t = N->A[x][y];
    N->A[x][y] = N->A[x][y-1];
    N->A[x][y-1] = t;
    N->c--;
    return 1;
}