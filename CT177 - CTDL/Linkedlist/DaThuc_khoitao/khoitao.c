DaThuc khoitao(){
    DaThuc Header;
    Header = (struct Node*)malloc(sizeof(struct Node));
    Header->Next = NULL;
    return Header;
}
