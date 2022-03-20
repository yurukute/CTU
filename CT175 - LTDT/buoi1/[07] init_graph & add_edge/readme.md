# Bài tập 7. MTK: hàm init\_graph() & add\_edge()
## Câu 1
Cho cấu trúc dữ liệu đồ thị **Graph** được cài đặt bằng phương pháp “**Ma trận kề**” dùng để lưu trữ các **đơn đồ thị vô hướng.** Hãy hoàn chỉnh chương trình bên dưới để đọc đồ thị từ bàn phím và in ra ma trận kề của đồ thị ra màn hình.
```c
//Khai báo thư viện và hằng
#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

//Viết mã lệnh của bạn ở đây
...
//Hết phần mã lệnh của bạn

//Hàm main()
int main() {
    Graph G;
    int n, m;
    
    //Đọc số đỉnh, số cung và khởi tạo đồ thị n đỉnh, 0 cung
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    //Đọc m cung và thêm vào đồ thị
    for (int e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    
    //In ma trận kề của đồ thị
    for (int u = 1; u <= G.n; u++) {
        for (int v = 1; v <= G.n; v++)
            printf("%d \n", G.A[u][v]);
        printf("\n");	
    }	
    return 0;
}
```
Viết mã lệnh của bạn (hàm init\_graph() và hàm add\_edge()) vào chỗ ba chấm (...).

Chú ý
- Giả sử dữ liệu đầu vào luôn hợp lệ, không cần phải kiểm tra.
- Không nộp toàn bộ chương trình, chỉ nộp phần mã lệnh của bạn.

## Câu 2
Cho cấu trúc dữ liệu đồ thị Graph được cài đặt bằng phương pháp “**Ma trận kề**” dùng để lưu trữ các **đồ thị vô hướng (có thể chứa đa cung và chứa khuyên)**. Hãy hoàn chỉnh chương trình bên dưới để đọc đồ thị từ bàn phím và in ra ma trận kề của đồ thị ra màn hình.
```c
//Khai báo thư viện và hằng
#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

//Viết mã lệnh của bạn ở đây
...
//Hết phần mã lệnh của bạn

//Hàm main()
int main() {
    Graph G;
    int n, m;
    
    //Đọc số đỉnh, số cung và khởi tạo đồ thị n đỉnh, 0 cung
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    //Đọc m cung và thêm vào đồ thị
    for (int e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    
    //In ma trận kề của đồ thị
    for (int u = 1; u <= G.n; u++) {
        for (int v = 1; v <= G.n; v++)
            printf("%d \n", G.A[u][v]);
        printf("\n");	
    }	
    return 0;
}
```
Viết mã lệnh của bạn (hàm init\_graph() và hàm add\_edge()) vào chỗ ba chấm (...).

Chú ý
- Giả sử dữ liệu đầu vào luôn hợp lệ, không cần phải kiểm tra.
- Không nộp toàn bộ chương trình, chỉ nộp phần mã lệnh của bạn.

## Câu 3
Cho cấu trúc dữ liệu đồ thị Graph được cài đặt bằng phương pháp “**Ma trận kề**” dùng để lưu trữ các **đồ thị có hướng (có thể chứa đa cung và chứa khuyên)**. Hãy hoàn chỉnh chương trình bên dưới để đọc đồ thị từ bàn phím và in ra ma trận kề của đồ thị ra màn hình.
```c
//Khai báo thư viện và hằng
#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

//Viết mã lệnh của bạn ở đây
...
//Hết phần mã lệnh của bạn

//Hàm main()
int main() {
    Graph G;
    int n, m;
    
    //Đọc số đỉnh, số cung và khởi tạo đồ thị n đỉnh, 0 cung
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    //Đọc m cung và thêm vào đồ thị
    for (int e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    
    //In ma trận kề của đồ thị
    for (int u = 1; u <= G.n; u++) {
        for (int v = 1; v <= G.n; v++)
            printf("%d \n", G.A[u][v]);
        printf("\n");	
    }	
    return 0;
}
```
Viết mã lệnh của bạn (hàm init\_graph() và hàm add\_edge()) vào chỗ ba chấm (...).

Chú ý
- Giả sử dữ liệu đầu vào luôn hợp lệ, không cần phải kiểm tra.
- Không nộp toàn bộ chương trình, chỉ nộp phần mã lệnh của bạn.
