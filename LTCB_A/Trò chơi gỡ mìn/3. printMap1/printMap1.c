void printMap1(){
    printf("  ");
    for(int i = 0; i < N; i++)
        printf("%d ", i);
    printf("\n");
    for(int i = 0; i < M; i++){
        printf("%d ", i);
        for(int j = 0; j < N; j++){
            if(B[i][j] == MINE)
                printf("x ");
            else if(B[i][j] == 0)
                printf(". ");
            else printf("%d ", B[i][j]);
        }
        printf("\n");
    }
}