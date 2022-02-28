Cho cấu trúc dữ liệu đồ thị được cài đặt bằng phương pháp "**Ma trận đỉnh - cung**" dùng để biểu diễn các đồ thị **vô hướng, không chứa khuyên**.
```c
typedef struct {
    int A[100][500];
    int n, m;
} Graph;
```
Viết hàm List neighbors(Graph* pG, int u) trả về danh sách các đỉnh kề của u theo mẫu (prototype):
```c
List neighbors(Graph* pG, int u) {
}
```
Chú ý: các đỉnh kề của x được sắp xếp theo thứ tự tăng dần và không trùng nhau. Ví dụ: nếu các đỉnh kề của 1 là 4 và 2 thì danh sách trả về chứa: 2 và 4.

Cấu trúc dữ liệu List được định nghĩa như bên dưới:
```c
#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct {
    ElementType data[MAX_ELEMENTS];
    int size;
} List;

/* Tạo danh sach rỗng */
void make_null(List* L) {
    L->size = 0;
}

/* Thêm một phần tử vào cuối danh sách */
void push_back(List* L, ElementType x) {
    L->data[L->size] = x;
    L->size++;
}

/* Lấy phần tử tại vị trí i, vị trí tính từ 1 */
ElementType element_at(List* L, int i) {
    return L->data[i-1];
}

/* Trả về số phần tử của danh sách */
int count_list(List* L) {
    return L->size;
}
```
