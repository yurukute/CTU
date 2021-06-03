void normalize(List *pL){
    Position P = *pL;
    while(P->Next != NULL){
        Position Q = P->Next;
        while (Q->Next !=NULL){
            if(P->Next->Element == Q->Next->Element)
                deleteList(Q, pL);
            else Q = Q->Next;
        }
        P = P->Next;        
    }
}