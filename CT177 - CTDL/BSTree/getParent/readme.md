Cây cây tìm kiếm nhị phân mỗi khóa là 1 số nguyên được khai báo như sau:
```c
struct Node{

      int Key;

      struct Node *Left, *Right;

};
```
Cho trước các phép toán:
- `void insertNode(int x, Tree *pT)`: thêm khóa x vào cây tìm kiếm nhị phân có gốc chỉ bởi con trỏ pT

Viết hàm tìm kiếm nút cha của nút có khóa x trong cây tìm kiếm nhị phân

**Nguyên mẫu (Prototype)**
- Tên hàm: getParent()
- Tham số: 
	- x - int
	- T - Tree
- Kiểu trả về: Tree

**Thân hàm (Body)**
- Nếu x có trong cây T, trả về con trỏ chỉ đến nút cha của x (nếu x là gốc kết quả trả về là NULL); ngược lại (x không có), kết quả trả về là NULL

**Chú ý**
- Chỉ viết hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
