float getAvg(List L){
    float S = 0;
    for(int i = 0; i < L.Last; i++){
        S += L.Elements[i];
    }
    return (S ? S / L.Last : -10000);
}