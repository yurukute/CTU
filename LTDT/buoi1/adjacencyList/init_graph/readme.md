Cho một chương trình cài đặt cấu trúc dữ liệu đồ thị Graph theo phương pháp "Danh sách cung" như bên dưới.

Hãy viết hàm `void init_graph(Graph *pG, int n)` vào chỗ trống để khởi tạo đồ thị (*pG) có số đỉnh bằng n và số cung bằng 0.

Chú ý
- Không nộp toàn bộ chương trình, chỉ nộp phần định nghĩa hàm init_graph().
```c
#include <stdio.h>

#define MAX_M 500
typedef struct {
    int u, v;
} Edge;
typedef struct {
    int n, m;
    Edge edges[MAX_M];
} Graph;

/* Viết mã lệnh của bạn ở đây */
//Định nghĩa hàm void init_graph(Graph *pG, int n)



/* Hết phần mã lệnh của bạn */

//Chương trình chính
int main() {
    Graph G;
    init_graph(&G, 5);
    printf("Do thi co %d dinh va %d cung.", G.n, G.m);
    return 0;
}
```
