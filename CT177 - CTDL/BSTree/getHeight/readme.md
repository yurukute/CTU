Cây cây tìm kiếm nhị phân mỗi khóa là 1 số nguyên được khai báo như sau:
```c
struct Node{

      int Key;

      struct Node *Left, *Right;

};
```
Cho trước các phép toán:
- `void insertNode(int x, Tree *pT)`: thêm khóa x vào cây tìm kiếm nhị phân có gốc chỉ bởi con trỏ pT

Viết hàm tính chiều cao cây T

**Nguyên mẫu (Prototype)**
- Tên hàm: getHeight()
- Tham số: 
	- T -  Tree
- Kiểu trả về: int

**Thân hàm (Body)**
- Nếu T rỗng kết quả trả về là -1, ngược lại kết quả trả về là chiều cao của nút gốc của cây

**Chú ý**
- Chỉ viết hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
