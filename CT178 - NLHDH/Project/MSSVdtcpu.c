#include <stdio.h>

#define MAX_N 1000
#define INF 9999;

typedef struct {
    int id, x, y, wt, tat;
} process;

void sort_by_atime(int n, process p[]){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(p[i].x > p[j].x){
                process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }       
        }
    }
}

void sort_by_btime(int n, process p[]){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(p[i].y > p[j].y){
                process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }       
        }
    }
}

void sort_by_id(int n, process p[]){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(p[i].id > p[j].id){
                process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }       
        }
    }
}

void FCFS(int n, process p[]){
    printf("************************************************\n");  
    printf("Dinh thoi FCFS\n");
    sort_by_atime(n, p); // sap xep theo tgian den
    p[0].wt = p[0].x;
    p[0].tat = p[0].y;
    float W = p[0].wt, R = W, T = p[0].tat;
    int max_tat = 0;
    for(int i = 1; i < n; i ++){
        p[i].wt = p[i-1].tat;
        p[i].tat = p[i].y + p[i].wt;
        if(p[i].tat > max_tat)
            max_tat = p[i].tat;
        W = R = W + p[i].wt - p[i].x;
        T += p[i].tat - p[i].x;
    }
    sort_by_id(n, p);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < p[i].x; j++)
            printf("-");
        for(int j = p[i].x; j < p[i].wt; j++)            
            printf("W");
        for(int j = p[i].wt; j < p[i].tat; j++)
            printf("R");
        for(int j = p[i].tat; j < max_tat; j++)
            printf("-");
        printf("\n");
    }
    printf("AVGW=%.2f\tAVGR=%.2f\tAVGT=%.2f\n",W/n,R/n,T/n);
}

void SJF(int n, process p[]){
    printf("************************************************\n");  
    printf("Dinh thoi SJF khong trung dung\n");
    sort_by_btime(n, p); // sap xep theo tgian chiem dung cpu
    p[0].wt = p[0].x;
    p[0].tat = p[0].y;
    float W = p[0].wt, R = W, T = p[0].tat;
    int max_tat = 0;
    for(int i = 1; i < n; i ++){
        p[i].wt = p[i-1].tat;
        p[i].tat = p[i].y + p[i].wt;
        if(p[i].tat > max_tat)
            max_tat = p[i].tat;
        W = R = W + p[i].wt - p[i].x;
        T += p[i].tat - p[i].x;
    }
    sort_by_id(n, p);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < p[i].x; j++)
            printf("-");
        for(int j = p[i].x; j < p[i].wt; j++)            
            printf("W");
        for(int j = p[i].wt; j < p[i].tat; j++)
            printf("R");
        for(int j = p[i].tat; j < max_tat; j++)
            printf("-");
        printf("\n");
    }
    printf("AVGW=%.2f\tAVGR=%.2f\tAVGT=%.2f\n",W/n,R/n,T/n);
}

void SRTF(int n, process p[]){
    printf("************************************************\n");  
    printf("Dinh thoi SJF trung dung\n");
    sort_by_atime(n, p);
    float W = 0, R = 0, T = 0;
    int r_time[MAX_N+1], ganttc[MAX_N], k = 0;
    r_time[n] = INF;
    for(int i = 0; i < n; i++){
        r_time[i] = p[i].y; // remain time: tgian con lai cua tien trinh
    }
    for(int count = 0, time = 0; count < n;){
        int min = n;
        for(int i = 0; i < n; i++)
            if(p[i].x <= time && r_time[i] > 0 && r_time[i] < r_time[min])
                min = i;
        r_time[min]--;
        time++;
        ganttc[k++] = p[min].id;
        if(r_time[min] == 0){
            count++;
            p[min].tat = time - p[min].x;
            p[min].wt  = p[min].tat - p[min].y;
            W += p[min].wt;
            T += p[min].tat;
        }
    }
    for(int i = 0; i < k; i++)
        printf("%d", ganttc[i]);
    printf("\n");
    sort_by_id(n, p);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < p[i].x; j++)
            printf("-");
        int flag = 0, oldR = R;
        for(int j = p[i].x; j < p[i].tat + p[i].x; j++)
            if(ganttc[j] == p[i].id){
                if(!flag && oldR == R){
                    flag = 1;
                    R += j - p[i].x;
                }
                printf("R");
            }
            else printf("W");
        for(int j = p[i].tat + p[i].x; j < k; j++)
            printf("-");
        printf("\n");
    }
    printf("AVGW=%.2f\tAVGR=%.2f\tAVGT=%.2f\n",W/n,R/n,T/n);
}

void RR(int n, process p[], int q){
    printf("************************************************\n");  
    printf("Dinh thoi Round Robin\n");
    if (q == 0){
        printf("Loi: quantum = 0!");
        return;
    }
    sort_by_atime(n, p);
    int r_time[MAX_N], ganttc[MAX_N], k = 0;
    for(int i = 0; i < n; i++){
        r_time[i] = p[i].y; // remain time: tgian con lai cua tien trinh
    }
    float W = 0, R = 0, T = 0;
    for(int i = 0, count = 0, time = 0; count < n;){
        if(r_time[i] > 0){
            if(r_time[i] <= q){
                for(int j = 0; j < r_time[i]; j++)
                    ganttc[k++] = p[i].id;
                time += r_time[i];
                r_time[i] = 0;
                count++;
                p[i].tat = time - p[i].x;
                p[i].wt = p[i].tat - p[i].y;
                W += p[i].wt;
                T += p[i].tat;
            }
            else {
                time += q;
                r_time[i] -= q;
                for(int j = 0; j < q; j++){
                    ganttc[k++] = p[i].id;
                }
            }            
        }
        if (i == n-1)
            i = 0;
        else if(p[i].x <= time)
            i++;
    }
    sort_by_id(n, p);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < p[i].x; j++)
            printf("-");
        int flag = 0, oldR = R;
        for(int j = p[i].x; j < p[i].tat + p[i].x; j++)
            if(ganttc[j] == p[i].id){
                if(!flag && oldR == R){
                    flag = 1;
                    R += j - p[i].x;
                }
                printf("R");
            }
            else printf("W");
        for(int j = p[i].tat + p[i].x; j < k; j++)
            printf("-");
        printf("\n");
    }
    printf("AVGW=%.2f\tAVGR=%.2f\tAVGT=%.2f\n",W/n,R/n,T/n);
}

int main(){
    int n, q;
    process p[MAX_N];
    scanf("%d %d", &n, &q);       
    for(int i = 0; i < n; i++){
        p[i].id = i+1;
        scanf("%d %d", &p[i].x, &p[i].y);
    }
    FCFS(n, p);
    SJF(n, p);
    SRTF(n, p);
    RR(n, p, q);
}
