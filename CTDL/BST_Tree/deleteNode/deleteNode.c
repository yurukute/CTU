void deleteNode(int x, Tree *pT){   
	if((*pT)->Key > x)
		deleteNode(x, &(*pT)->Left);
	else if((*pT)->Key < x)
		deleteNode(x, &(*pT)->Right);
	else{
		if((*pT)->Left == NULL && (*pT)->Right == NULL)
			(*pT) = NULL;
		else if((*pT)->Left == NULL)
			(*pT) = (*pT)->Right;
		else if((*pT)->Right == NULL)
			(*pT) = (*pT)->Left;
		else{ 
			Tree Temp = (*pT)->Right;
			Tree pTemp = NULL;
			while(Temp->Left != NULL){
				pTemp = Temp;
				Temp = Temp->Left;
			}
			if(pTemp != NULL)
				pTemp->Left = Temp->Right;
			else 
				(*pT)->Right = Temp->Right;
			(*pT)->Key = Temp->Key;
			free(Temp);
		}
	}
}
