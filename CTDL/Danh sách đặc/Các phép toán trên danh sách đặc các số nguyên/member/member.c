int member(int x, List L){
    for(Position P = 0; P < L.Last+1; P++){
        if(L.Elements[P-1] == x)
            return 1;
    }
    return 0;
}