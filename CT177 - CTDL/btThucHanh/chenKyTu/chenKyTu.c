void chenKyTu(char c, Cau *pd){
    Cau lastNode = *pd;
    while(lastNode->Next != NULL)
        lastNode = lastNode->Next;
    Cau newNode = (Cau)malloc(sizeof(Cau));
    newNode->KyTu = c;
    newNode->Next = NULL;
    lastNode->Next = newNode;
}
