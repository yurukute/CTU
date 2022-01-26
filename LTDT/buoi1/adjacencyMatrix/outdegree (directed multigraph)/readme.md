Cho cấu trúc dữ liệu đồ thị Graph được cài đặt bằng phương pháp "**Ma trận kề**" dùng để lưu trữ các **đồ thị có hướng (có thể chứa đa cung và chứa khuyên)**.
```c
#define MAX_N 100
typedef struct {
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;
```
Viết hàm `int outdegree(Graph *pG, int u)` để tính bậc vào của đỉnh theo mẫu (prototype):
```c
int outdegree(Graph *pG, int u) {
}
```
Chú ý
- Các tham số của hàm outdegree() luôn hợp lệ (1≤u≤n), bạn không cần kiểm tra.
- Không nộp toàn bộ chương trình, chỉ nộp phần định nghĩa hàm outdegree().
