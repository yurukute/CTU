DaThuc tinhDaoHam(DaThuc D){
    DaThuc res = khoitao();
    Position P = D;
    while(P->Next != NULL){
        DonThuc e = P->Next->e;
        e.he_so *= e.bac;
        e.bac--;
        chenDonThuc(e, &res);
        P = P->Next;
    }
    return res;
}
