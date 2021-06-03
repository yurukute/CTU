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