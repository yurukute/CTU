void doiNhiPhan(int n, NganXep *pS){
    khoitao(pS);
    while(n > 0){
        them(n % 2, pS);
        n /= 2;
    }
}
