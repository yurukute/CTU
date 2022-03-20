# Bài tập 3. DSC: add_edge() nâng cao
## Câu 1
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

## Câu 2
Cho cấu trúc dữ liệu đồ thị Graph được cài đặt bằng phương pháp "**Danh sách cung**" dùng để biểu diễn các **đơn đồ thị có hướng** như sau:
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
```
void add_edge(Graph *pG, int u, int v) {
}
```
Chú ý
- Vì pG là đơn đồ thị có hướng nên nếu cung (u, v) đã có trong đồ thị rồi thì bỏ qua, không thêm vào nữa.
- Giả sử các tham số của hàm đều hợp lệ (1≤u,v≤n), không cần phải kiểm tra.
- Không nộp toàn bộ chương trình, chỉ nộp phần định nghĩa hàm add_edge().

## Câu 3
Cho cấu trúc dữ liệu đồ thị Graph được cài đặt bằng phương pháp "**Danh sách cung**" dùng để biểu diễn các **đơn đồ thị vô hướng** như sau:
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
Viết hàm `add_edge(Graph *pG, int u, int v)` để thêm cung (u, v) vào đồ thị G theo mẫu:
```
void add_edge(Graph *pG, int u, int v) {
}
```
- Vì pG là đơn đồ thị vô hướng nên nếu cung (u, v) hoặc cung (v, u) đã có trong đồ thị rồi thì bỏ qua, không thêm vào nữa.
- Giả sử các tham số của hàm đều hợp lệ (1≤u,v≤n), không cần phải kiểm tra.
- Không nộp toàn bộ chương trình, chỉ nộp phần định nghĩa hàm add_edge().
