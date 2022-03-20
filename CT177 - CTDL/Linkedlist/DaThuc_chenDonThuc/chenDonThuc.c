void chenDonThuc(DonThuc s, DaThuc *pD){
	Position P = *pD;
	while(P->Next != NULL){	   
		if(P->Next->e.bac == s.bac){
			P->Next->e.he_so += s.he_so;
			return;
		}
		if(P->Next->e.bac < s.bac)
			break;
		P = P->Next;
	}
		
	Position newNode = (Position)malloc(sizeof(Position));
	newNode->Next = P->Next;
	newNode->e = s;
	P->Next = newNode;
}
