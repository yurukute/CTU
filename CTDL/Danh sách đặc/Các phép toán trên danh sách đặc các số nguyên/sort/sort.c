void sort(List *pL){
    for(Position P = 1; P < pL->Last; P++){
        for(Position Q = P+1; Q < pL->Last+1; Q++){
            if(pL->Elements[P-1] > pL->Elements[Q-1]){
                int t = pL->Elements[P-1];
                pL->Elements[P-1] = pL->Elements[Q-1];
                pL->Elements[Q-1] = t;
            }
        }
    }
}