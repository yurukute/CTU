
//Tính trung bình cộng
float getAvg(List L){
    float S = 0;
    for(Position P = 1; P <= L.Last; P++){
        S += L.Elements[P-1];
    }
    return (S ? S / L.Last : -10000);
}

//Kiểm tra x có tồn tại trong L hay không
int member(int x, List L){
    for(Position P = 1; P < L.Last+1; P++){
        if(L.Elements[P-1] == x)
            return 1;
    }
    return 0;
}

// Tính tập hợp hiệu 
void difference(List L1, List L2, List *pL){
	makenullList(pL);
	for(Position P = 1; P < L1.Last + 1; P++){
		if(!member(L1.Element[P-1], L2))
			insertList(L1.Element[P-1], PL)
	}
}

//Chuẩn hóa: xóa các phần tử trùng
void normalize(List *L){
    for(Position P = 1; P <= L->Last; P++){
        Position Q = P + 1;
        while(Q <= L->Last){
            if(L->Elements[P-1] == L->Elements[Q-1])
                deleteList(Q, L);
            else Q++;
        }
    }
}

void printList(List L){
    for(Position P = 1; P < L.Last+1; P++){
        printf("%d ", L.Elements[P-1]);
    }
}

void readList(List *pL){
    makenullList(pL);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        insertList(x,pL->Last+1, pL);
    }
}

void removeAll(int x, List *L){
	while(locate(x, *L) != L->Last+1){
		deleteList(locate(x, *L), L);
	}
}

void sort(List *pL){
    for(Position P = 1; P < pL->Last; P++){
        for(Position Q = P+1; Q < pL->Last+1; Q++){
            if(pL->Elements[P-1] > pL->Elements[Q-1]){
                int t = pL->Elements[P-1];
                pL->Elements[P-1] = pL->Elements[Q-1];
                pL->Elements[Q-1] = t;
            }
        }
    }
}

void intersection(List L1, List L2, List *pL){
    makenullList(pL);
    for(Position P = 1; P < L1.Last+1; p++){
        int x = L1.Elements[p];
        if(member(x, L2) && !member(x, *pL))
            insertSet(x,pL);
    }
}

void unionSet(List L1, List L2, List *pL){
	makenullList(pL);
	for(Position P = 1; P < L1.Last+1; P++){
		insertSet(L1.Elements[P-1], pL);
	}
	for(Position P = 1; P < L2.Last+1; P++){
		if(!member(L2.Elements[P-1], *pL))
            insertSet(L2.Elements[P-1], pL);
	}
}
