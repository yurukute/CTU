void chenCuoi(struct SinhVien s, DanhSach *pL){
    if (pL->n == 40){
        printf("Loi! Danh sach day!");
        return;
    }
    pL->A[pL->n] = s;
    pL->n++;
}

void hienthi(DanhSach L){
    for(int i = 0; i <L.n; i++){
        printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2, L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2);
    }
}

void hienthiDat(DanhSach L){
    for(int i = 0; i <L.n; i++){
        if(L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2 >= 4)
            printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2, L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2);
    }
}

int ktRong(DanhSach L){
    return L.n == 0;
}

int tim(char s[], DanhSach L){
    for(int i = 1; i < L.n+1; i++){
        if(strcmp(L.A[i-1].MSSV, s) == 0)
            return i;     
    }
    return L.n+1;
}

DanhSach nhap(){
    DanhSach L;
    dsRong(&L);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        struct SinhVien x;
        char c;
        scanf("%c", &c);
        fgets(x.MSSV, 10, stdin);
        x.MSSV[strlen(x.MSSV) - 1] = '\0';
        fgets(x.HoTen, 50, stdin);
        x.HoTen[strlen(x.HoTen) - 1] = '\0';
        scanf("%f %f %f", &x.DiemLT, &x.DiemTH1, &x.DiemTH2);
        if(tim(x.MSSV, L) == L.n+1)
            chenCuoi(x, &L);
    }
    return L;
}

void xoaTai(int p, DanhSach *pL){
    for(int i = p; i < pL->n; i++){
        pL->A[i-1] = pL->A[i];
    }
    pL->n--;
}

