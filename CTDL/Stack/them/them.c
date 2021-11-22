void them(int x, NganXep *pS){
    if(!ktDay(*pS)){
        pS->Dinh--;
        pS->DuLieu[pS->Dinh] = x;
    }
}
