# Bài tập 2. DSC: hàm add\_edge() cơ bản
Cho cấu trúc dữ liệu đồ thị Graph được cài đặt bằng phương pháp "Danh sách cung" như sau:
```c
typedef struct  {
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
void init_graph(Graph *pG, int n){
    pG->n = n;
    pG->m = 0;
}
```
Viết hàm add_edge(Graph *pG, int u, int v) để thêm cung (u, v) vào đồ thị pG theo mẫu (prototype):
```c
void add_edge(Graph *pG, int u, int v) {
}
```
Chú ý
- Các tham số của hàm add_edge() luôn hợp lệ (1≤u,v≤n), bạn không cần kiểm tra.
- Không nộp toàn bộ chương trình, chỉ nộp phần định nghĩa hàm add_edge().
