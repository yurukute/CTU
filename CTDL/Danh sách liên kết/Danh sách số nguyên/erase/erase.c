void erase(int x, List *pL){
    Position P = locate(x, *pL);
    if(P->Next != NULL)
        deleteList(P, pL);
    else printf("Not found %d\n", x);
}