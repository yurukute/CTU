void removeAll(int x, List *pL){
    Position P = locate(x, *pL);
    while(P->Next != NULL){
        deleteList(P, pL);
        P = locate(x, *pL);
    }
}