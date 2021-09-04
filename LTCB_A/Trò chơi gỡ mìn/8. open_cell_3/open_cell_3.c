void open_cell_3(int r, int c){
    if(T[r][c])
        return;
    T[r][c] = 1;
    if(B[r][c] == 0){
        if(r && c)              open_cell_3(r-1,c-1);
        if(r)                   open_cell_3(r-1,c);
        if(r && c+1 < N)        open_cell_3(r-1,c+1);
        if(c)                   open_cell_3(r,c-1);
        if(c+1 < N)             open_cell_3(r,c+1);
        if(r+1 < M && c)        open_cell_3(r+1,c-1);
        if(r+1 < M)             open_cell_3(r+1,c);
        if(r+1 < M && c+1 < N)  open_cell_3(r+1,c+1);
    }
}