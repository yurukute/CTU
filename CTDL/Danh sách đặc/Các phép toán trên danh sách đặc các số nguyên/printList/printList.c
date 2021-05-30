void printList(List L){
    for(Position P; P < L->Last+1; P++){
        printf("%d ", L.Elements[P-1]);
    }
}