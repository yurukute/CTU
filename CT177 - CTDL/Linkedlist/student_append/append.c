int append(Student s, List *pL){
    struct Node* P = locate(s.ID, *pL);
    if(P->Next != NULL)
        return 0;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->Element = s;
    newNode->Next = NULL;
    P->Next = newNode;
    return 1;
}