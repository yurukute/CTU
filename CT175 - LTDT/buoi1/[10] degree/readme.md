# Bài tập 10. MTK: hàm degree
## Câu 1
Cho cấu trúc dữ liệu đồ thị Graph được cài đặt bằng phương pháp "**Ma trận kề**" dùng để lưu trữ các **đồ thị vô hướng (có thể chứa đa cung và chứa khuyên)**.
```c
#define MAX_N 100
typedef struct {
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;
```
Viết hàm `int degree(Graph *pG, int u)` để tính bậc của đỉnh theo mẫu (prototype):
```c
int degree(Graph *pG, int u) {
}
```
Chú ý
- Các tham số của hàm degree() luôn hợp lệ (1≤u≤n), bạn không cần kiểm tra.
- Không nộp toàn bộ chương trình, chỉ nộp phần định nghĩa hàm degree().

## Câu 2
Cho cấu trúc dữ liệu đồ thị Graph được cài đặt bằng phương pháp "**Ma trận kề**" dùng để lưu trữ các **đồ thị có hướng (có thể chứa đa cung và chứa khuyên)**.
```c
#define MAX_N 100
typedef struct {
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;
```
Viết hàm `int degree(Graph *pG, int u)` để tính bậc của đỉnh theo mẫu (prototype):
```c
int degree(Graph *pG, int u) {
}
```
Chú ý
- Các tham số của hàm degree() luôn hợp lệ (1≤u≤n), bạn không cần kiểm tra.
- Không nộp toàn bộ chương trình, chỉ nộp phần định nghĩa hàm degree().

## Câu 3
Cho cấu trúc dữ liệu đồ thị Graph được cài đặt bằng phương pháp "**Ma trận kề**" dùng để lưu trữ các **đồ thị có hướng (có thể chứa đa cung và chứa khuyên)**.
```c
#define MAX_N 100
typedef struct {
    int n, m;
    int A[MAX_N][MAX_N];
} Graph;
```
Viết hàm `int indegree(Graph *pG, int u)` để tính bậc vào của đỉnh theo mẫu (prototype):
```c
int indegree(Graph *pG, int u) {
}
```
Chú ý
- Các tham số của hàm indegree() luôn hợp lệ (1≤u≤n), bạn không cần kiểm tra.
- Không nộp toàn bộ chương trình, chỉ nộp phần định nghĩa hàm indegree().

## Câu 4
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
