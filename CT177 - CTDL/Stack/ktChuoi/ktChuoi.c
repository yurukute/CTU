int ktChuoi(){
    char str[100];
    fgets(str,100, stdin);
    Stack S;
    makenullStack(&S);
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == '(')
            push(str[i], &S);
        else if(str[i] == ')'){
            if(emptyStack(S))
                return 0;
            else pop(&S);
        }
    }
    return emptyStack(S);
}
