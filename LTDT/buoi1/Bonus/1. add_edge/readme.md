Cho cấu trúc dữ liệu đồ thị Graph được cài đặt bằng phương pháp "**Ma trận đỉnh - cung**" dùng để biểu diễn các đồ thị **vô hướng, không chứa khuyên**.
```c
typedef struct {
    int A[100][500];
    int n, m;
} Graph;
```
Viết hàm **add_edge(Graph* pG, int e, int x, int y)** để thêm cung e = (x, y) vào đồ thị pG theo mẫu (prototype).
```c
void add_edge(Graph* pG, int e, int x, int y) {
}
```
