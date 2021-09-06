void hienthi(NganXep *pS){
	while(!ktRong(*pS)){
		printf("%d ", giatriDinh(*pS));
		xoa(pS);
	}
}
