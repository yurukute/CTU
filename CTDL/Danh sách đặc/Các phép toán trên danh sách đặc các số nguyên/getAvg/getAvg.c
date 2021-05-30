float getAvg(List L){
    float S = 0;
    for(Position P = 1; P <= L.Last; P++){
        S += L.Elements[P-1];
    }
    return (S ? S / L.Last : -10000);
}