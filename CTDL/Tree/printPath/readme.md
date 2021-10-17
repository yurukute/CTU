Cây cây tìm kiếm nhị phân mỗi khóa là 1 số nguyên được khai báo như sau:
```c
struct Node{

      int Key;

      struct Node *Left, *Right;

};
```
Cho trước các phép toán:
- `void insertNode(int x, Tree *pT)`: thêm khóa x vào cây tìm kiếm nhị phân có gốc chỉ bởi con trỏ pT

Viết hàm liệt kê (in) các giá trị khóa trên đường đi của việc tìm kiếm một khóa x trong cây tìm kiếm nhị phân

**Nguyên mẫu (Prototype)**
- Tên hàm: printPath()
- Tham số: 
	- x - int
	- T - Tree
- Kiểu trả về: không

**Thân hàm (Body)**
- Áp dụng giải thuật tìm kiếm trên cây tìm kiếm nhị phân, mỗi khi đi tới một nút trên theo giải thuật tìm, in giá trị khóa tại nút đó lên màn hình

**Chú ý**
- Chỉ viết hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
