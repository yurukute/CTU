void chenCuoi(struct SinhVien s, DanhSach *pL){
    if (pL->n == 40){
        printf("Loi! Danh sach day!");
        return;
    }
    pL->A[pL->n] = s;
    pL->n++;
}