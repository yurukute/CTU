void normalize(List *L){
    for(Position P = 1; P <= L->Last; P++){
        Position Q = P + 1;
        while(Q <= L->Last){
            if(L->Elements[P-1] == L->Elements[Q-1])
                deleteList(Q, L);
            else Q++;
        }
    }
}