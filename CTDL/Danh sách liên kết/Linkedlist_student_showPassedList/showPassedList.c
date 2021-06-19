List K = getList();
    int count = 0;
    struct Node* P = L;
    while(P->Next != NULL){
        Student s = P->Next->Element;
        if((s.R1 + s.R2 + s.R3)/3 >= 4){
            append(s, &K);
            count++;
        }
    P = P->Next;
    }
    printList(K);
    printf("%d students in total\n", count);
//-ENDSECTION//
List L;
    L = readList();
    printList(L);
    printf("\n");
    showPassedList(L);