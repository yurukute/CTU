void addFirst(int x, List *pL){
    Position P = *pL;
    Position newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->Element = x;
    newNode->Next = P->Next;
    P->Next = newNode;
}
