void open_cell_2(int r, int c){
    T[r][c] = 1;
    if(B[r][c] == 0){
        if(r && c)              T[r-1][c-1] = 1;
        if(r)                   T[r-1][c]   = 1;
        if(r && c+1 < N)        T[r-1][c+1] = 1;
        if(c)                   T[r][c-1]   = 1;
        if(c+1 < N)             T[r][c+1]   = 1;
        if(r+1 < M && c)        T[r+1][c-1] = 1;
        if(r+1 < M)             T[r+1][c]   = 1;
        if(r+1 < M && c+1 < N)  T[r+1][c+1] = 1;
    }
}