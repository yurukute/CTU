void deleteList(Position P, List *L){
    Position temp;
	if (P->Next != NULL) {  
		temp = P->Next; 
		P->Next = temp->Next; 
		free(temp);
	}
}