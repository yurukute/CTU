# Bài tập 4. DSC: hàm adjacent()
## Câu 1
Cho cấu trúc dữ liệu đồ thị Graph được cài đặt bằng phương pháp "**Danh sách cung**" dùng để biểu diễn các **đồ thị vô hướng**.
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

Viết hàm adjacent() để kiểm tra đỉnh u có kề với đỉnh v không theo mẫu (prototype):
```c
int adjacent(Graph *pG, int u, int v) {
}
```
Trả về 1, nếu u kề với v, ngược lại trả về 0.

Chú ý
- Trong đồ thị vô hướng G, u kề với v khi G có cung (u, v) hoặc cung (v, u).
- Giả sử các tham số của hàm adjacent() luôn hợp lệ, không cần phải kiểm tra.
- Không nộp toàn bộ chương trình, chỉ nộp phần định nghĩa hàm adjacent().

## Câu 2
Cho cấu trúc dữ liệu đồ thị Graph được cài đặt bằng phương pháp "Danh sách cung" dùng để biểu diễn các **đơn đồ thị có hướng** như sau:
```c
#define MAX_M 500
typedef struct {
    int u v;
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
Viết hàm `add_edge(Graph *pG, int u, int v)` để thêm cung (u, v) vào đồ thị G theo mẫu:
```c
void add_edge(Graph *pG, int u, int v) {
}
```

Chú ý
- Vì pG là đơn đồ thị có hướng nên nếu cung (u, v) đã có trong đồ thị rồi thì bỏ qua, không thêm vào nữa.
- Giả sử các tham số của hàm đều hợp lệ (1 ≤ u,v ≤ n), không cần phải kiểm tra.
- Không nộp toàn bộ chương trình, chỉ nộp phần định nghĩa hàm add_edge().
