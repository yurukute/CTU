List difference(List L1, List L2){
    List L;
    makenullList(&L);
    Position P = L1;
    while(P->Next != NULL){
        if(!member(P->Next->Element, L2))
            append(P->Next->Element, &L);
        P = P->Next;
    }
    return L;
}