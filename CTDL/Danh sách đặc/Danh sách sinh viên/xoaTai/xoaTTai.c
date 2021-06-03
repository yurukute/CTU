void xoaTai(int p, DanhSach *pL){
    for(int i = p; i < pL->n; i++){
        pL->A[i-1] = pL->A[i];
    }

    pL->n--;
}