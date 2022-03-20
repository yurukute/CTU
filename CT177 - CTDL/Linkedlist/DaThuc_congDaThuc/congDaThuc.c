DaThuc congDaThuc(DaThuc D1, DaThuc D2){
	DaThuc D3 = khoitao();
	Position P = D1;
	while(P->Next != NULL){
		chenDonThuc(P->Next->e, &D3);
		P = P->Next;
	}
	P = D2;
	while(P->Next != NULL){
		chenDonThuc(P->Next->e, &D3);
		P = P->Next;
	}
	return D3;
}
