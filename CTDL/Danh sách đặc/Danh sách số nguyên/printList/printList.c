void printList(List L){
    for(Position P = 1; P < L->Last+1; P++){
        printf("%d ", L.Elements[P-1]);
    }
}