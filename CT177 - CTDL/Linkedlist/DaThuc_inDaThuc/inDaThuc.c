void inDaThuc(DaThuc d){
    Position P = d;
    while(P->Next != NULL){
        DonThuc f = P->Next->e;
        printf("%.3fX^%d", f.he_so, f.bac);
        P = P->Next;
        if(P->Next != NULL)
            printf(" + ");
    }
}
