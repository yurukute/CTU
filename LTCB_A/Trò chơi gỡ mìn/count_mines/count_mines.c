void count_mines(){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(B[i][j] != MINE){
                int count = 0;
                if(i && j && B[i-1][j-1] == MINE)
                    count++;
                if(i && B[i-1][j] == MINE)
                    count++;
                if(i && j+1 < N && B[i-1][j+1] == MINE)
                    count++;
                if(j && B[i][j-1] == MINE)
                    count++;
                if(j+1 < N && B[i][j+1] == MINE)
                    count++;
                if(i+1 < M && j && B[i+1][j-1] == MINE)
                    count++;
                if(i+1 < M && B[i+1][j] == MINE)
                    count++;
                if(i+1 < M && j+1 < N && B[i+1][j+1] == MINE)
                    count++;
                B[i][j] = count;
            }
        }
    }
}