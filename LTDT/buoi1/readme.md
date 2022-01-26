# Buổi 1. Biểu diễn đồ thị
Mục đích:
- Biểu diễn đồ thị trên máy tính
- Cài đặt cấu trúc dữ liệu đồ thị (Graph) và một số phép toán cơ bản trên đồ thị

Yêu cầu: 
- Biết sử dụng ngôn ngữ lập trình C. Ngôn ngữ thực hành chính thức là ngôn ngữ C
- Biết cài đặt các cấu trúc dữ liệu cơ bản

## Cấu trúc dữ liệu đồ thị và các phép toán
Để có thể lưu trữ đồ thị vào máy tính, ta phải xác định những thông tin cần thiết để biểu diễn đồ thị và các số phép toán trên đồ thị cần phải hỗ trợ.

Cho đồ thị G = <V, E> có n đỉnh, m cung. Các thông tin cần lưu trữ của đồ thị bao gồm:
- Đỉnh: tên/nhãn đỉnh và các thông tin khác liên quan đến đỉnh (vị dụ vị trí đỉnh)
- Cung: hai đỉnh đầu mút (endpoints) của cung, nhãn của cung (tên cung/trọng số cung/chiều dài cung) và các thông tin khác liên quan tới cung (ví dụ: hình dạng cung)

Các phép toán cơ bản trên đồ thị bao gồm:
- `init_graph(G, n, m)`: khởi tạo đồ thị có n đỉnh (và m cung)
- `adjacent (G, u, v)`: kiểm tra xem v có phải là đỉnh kề của u không(u kề với v)
- `neighbors(G, u)`: trả về danh sách các đỉnh kề của u, hoặc liệt kê các đỉnh của u
- `add_edge(G, u, v)`: thêm cung (u, v) vào đồ thị nếu có chưa tồn tại
- `remove_edge(G, u, v)`: xoá cung (u, v) ra khỏi đồ thị
- `degree(G, u)`: trả về bậc của đỉnh u

### Danh sách cung (edge list)
```c
#define MAX_N 500
typedef struct{
	int u, v;
} Edge;

typedef struct{ 
	int n, m;
	Edge edges[MAX_M];} Graph;
```
### Ma trận đỉnh - đỉnh (ma trận kề)
```c
#define MAX_N 100
typedef struct{
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;
```
