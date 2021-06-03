void copyEvenNumbers(List L1, List *pL2){
    makenullList(pL2);
    Position P = L1;
    while(P->Next != NULL){
        if(P->Next->Element % 2 == 0)
            append(P->Next->Element, pL2);
        P = P->Next;
    }
}