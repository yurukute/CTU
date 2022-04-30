#include <stdio.h>
#include <malloc.h>

#define MAX_N 100
#define MIN_F 3.4e38

typedef struct {
    float length;
    int first, last, mark;
} Edge;

typedef struct {
    int n;
    Edge E[MAX_N][MAX_N];
} Graph;

void readFile(Graph *G){
    FILE *f = fopen("../CTU/CT174 - PTTKTT/buoi3 - branch and bound/TSP1.txt", "r");
    fscanf(f,"%d", &G->n);
    for(int i = 0; i < G->n; i++){
        for(int j = 0; j < G->n; j++){
            fscanf(f, "%f", &G->E[i][j].length);
            G->E[i][j].first = i;
            G->E[i][j].last  = j;
            G->E[i][j].mark  = 0;
        }
    }
    fclose(f);
}

void printGraph(Graph *G){
    printf("Ma tran trong so cua do thi:\n");
    for(int i = 0; i < G->n; i++){
        for(int j = 0; j < G->n; j++){
            printf(" %c%c =%5.2f  ", G->E[i][j].first+97, G->E[i][j].last+97, G->E[i][j].length);
        }
        printf("\n");
    }
}

void printResult(Edge x[], int n){
    printf("Phuong an tim duoc:\n");
    for(int i = 0; i < n; i++){
        printf("  Canh %c%c = %5.2f\n", x[i].first+97, x[i].last+97, x[i].length);        
    }
    float sum = 0;
    printf("Chu trinh:\n  ");
    for(int i = 0; i < n; i++){
        printf("%c -> ", x[i].first+97);
        sum += x[i].length;
    }
    printf("%c\n", x[0].first+97);
    printf("Tong do dai cac canh cua chu trinh = %5.2f\n\n", sum);
}

int isCycle(Edge x[], int n, int next){
    int i = 0;
    while(i < n){
        if(next == x[i].first)
            return 1;
        i++;
    }
    return 0;
}

float lowerBound(Graph *G, float cost, int level){
    float min_Edge = MIN_F;
    for(int i = 0; i < G->n; i++){
        for(int j = 0; j < G->n; j++){
            if(i != j && !G->E[i][j].mark && G->E[i][j].length < min_Edge)
                min_Edge = G->E[i][j].length;
        }
    }
    return cost+(G->n - level)*min_Edge;
}

Edge result[MAX_N];

void updateResult(Graph *G, float cost, float *final_cost, Edge x[]){
    int n = G->n;
    x[n-1] = G->E[x[n-2].last][x[0].first];
    cost += x[n-1].length;
    if(cost < *final_cost){
        *final_cost = cost;
        for(int i = 0; i < n; i++){
            result[i] = x[i];
        }
    }
}

void solve(Graph *G, int i, int current, float p_cost, float *final_cost, Edge x[]){    
    int n = G->n;
    for(int next = 0; next < n; next++){
        if(current != next && !G->E[current][next].mark && !isCycle(x, i, next)){
            float cost, lbound;
            cost = p_cost + G->E[current][next].length;
            lbound = lowerBound(G, cost, i+1);
            if(lbound < *final_cost){
                x[i] = G->E[current][next];
                G->E[current][next].mark = 1;
                G->E[next][current].mark = 1;
                if(i == n-2)
                    updateResult(G, cost, final_cost, x);
                else
                    solve(G, i+1, next, cost, final_cost, x);
            }
            G->E[current][next].mark = 0;
            G->E[next][current].mark = 0;
        }
    }
}

void reset(Graph *G){
    for(int i = 0; i < G->n; i++){
        for(int j = 0; j < G->n; j++){
            G->E[i][j].mark = 0;
        }
    }
}

int main(){
    Graph G;
    readFile(&G);    
    printf("TSP su dung thuat toan NHANH CAN:\n\n");
    Edge x[MAX_N];    
    while(1){
        printGraph(&G);
        reset(&G);
        float final_cost = MIN_F;
        char s;
        do {
            printf("Chon thanh pho xuat phat (a,.., e): ");
            scanf("\n%c", &s);
        } while (s < 'a' || s > 'e');
        solve(&G, 0, s-97, 0, &final_cost, x);
        printResult(result, G.n);        
        do{
            printf("Tiep tuc (Y/N)? ");
            scanf("\n%c", &s);
            if(s == 'n' || s == 'N')
                return 0;
        } while(s != 'y' && s != 'Y');
     
    }
        
}
