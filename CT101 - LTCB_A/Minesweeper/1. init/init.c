void init(){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            B[i][j] = T[i][j] = 0;   
        }
    }
    B[1][2] = MINE;
    B[3][1] = MINE;
}