Cho cấu trúc dữ liệu đồ thị **Graph** được cài đặt bằng phương pháp "**Danh sách cung**" như sau:
```c
#define MAX_M 500
typedef struct {
    int u, v;
} Edge;
typedef struct {
    int n, m;
    Edge edges[MAX_M];
} Graph;
```
Các cung được lưu trong danh sách edges với chỉ số từ 0, 1, 2, ..., m-1

Hàm khởi tạo đồ thị:
```c
void init_graph(Graph *pG, int n) {
    G->n = n;
    G->m = 0;
}
```
Viết hàm `add_edge(Graph *pG, int u, int v)` để thêm cung (u, v) vào đồ thị pG theo mẫu:
```c
void add_edge(Graph *pG, int u, int v) {
}
```
Chú ý
- Nếu cung (u, v) không hợp lệ (ví dụ: u < 1 hoặc v > n, ...) thì bỏ qua không làm gì cả.
- Không nộp toàn bộ chương trình, chỉ nộp phần định nghĩa hàm `add_edge()`.
