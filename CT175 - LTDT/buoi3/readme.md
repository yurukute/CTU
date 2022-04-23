# Thuật toán Moore - Dijkstra

Thuật toán Moore - Dijkstra cho bài toán tìm đường đi ngắn nhất từ đỉnh s đến các đỉnh khác trên đồ thị.

Mô tả thuật toán (làm bài tập tý thuyết chỉ cần đọc hiểu phần mô tả này là đủ)

- Khởi tạo:
  - Tất cả các đỉnh đều chưa đánh dấu
  - Với mọi u != s, 𝜋[u] = oo
  - 𝜋[s] = 0
- Lặp i từ 1 đến n - 1:
  - Tìm u chưa đánh dấu có pi[u] nhỏ nhất.
  - Đánh dấu u
  - Xét các đỉnh kề v của u, nếu v chưa đánh dấu và (𝜋[u] + trọng số cung (u,v) < 𝜋[v]) thì cập nhật:
    - 𝜋[v] = 𝜋[u] + trọng số cung (u, v)
    - p[v] = u


Cài đặt bằng ngôn ngữ C (thực hành cần hiểu được phần cài đặt này)
- Giả sử đồ thị được biểu diễn bằng phương pháp "Ma trận trọng số":

```c
typedef struct {
    int A[MAX_N][MAX_N];
    int m, n;
} Graph;

//Các biến hỗ trợ
int pi[MAX_N];
int p[MAX_N];
int mark[MAX_N];
Hàm Dijkstra:

void Dijkstra(Graph *pG, int s) {
    //Khởi tạo
    for (int u = 1; u <= pG->n; u++)
        mark[u] = 0;
        pi[u] = oo; //Vô cung lớn, ví dụ: 9999999
    }
    pi[s] = 0;
    
    //Lặp i từ 1 đến n - 1
    for (int i = 1; i <= pG->n - 1; i++) {
        //1. Tìm u
        int min_pi = oo;
        int u = -1;
        for (int j = 1; j <= pG->n; j++)
            if (!mark[j] && pi[j] < min_pi) {
                min_pi = pi[j];
                u = j;
            }
        if (u == -1) //không tìm được u
            break;
            
        //2. Đánh dấu u
        mark[u] = 1;

        //3. Xét các đỉnh kề v của u để cập nhật (nếu thỏa điều kiện)
        for (int v = 1; v <= pG->n; v++)
            if (pG->A[u][v] != NO_EDGE && !mark[v] && pi[u] + pG->A[u][v] < pi[v]) {
                pi[v] = pi[u] + pG->A[u][v]; //pG->A[u][v] là trọng số của cung (u,v)
                p[v] = u;
            }
    }
}
```
