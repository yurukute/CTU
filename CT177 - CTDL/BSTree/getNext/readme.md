Cây cây tìm kiếm nhị phân mỗi khóa là 1 số nguyên được khai báo như sau:

```c
struct Node{

      int Key;

      struct Node *Left, *Right;

};
```
Cho trước các phép toán:
- `void insertNode(int x, Tree *pT)`: thêm khóa x vào cây tìm kiếm nhị phân có gốc chỉ bởi con trỏ pT

Viết hàm trả về con trỏ của nút đứng sau nút có khóa x cho trước trong phép duyệt trung tự (giả sử x chắc chắn có trong cây T)

**Nguyên mẫu (Prototype)**
- Tên hàm: getNext()
- Tham số: 
	- x - int
	- T - Tree
- Kiểu trả về: Tree

**Thân hàm (Body)**
- Trả về con trỏ của nút đứng sau nút có khóa x trong cây TKNP trong phép duyệt trung tự; nếu x là khóa phải nhất của cây thì kết quả trả về là NULL

**Chú ý**
- Chỉ viết hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH

**Ví dụ**
```
   27
  /  \
12    40
     /
    30
```
Nút  27 đứng sau 12

Nút  40 đứng sau 30

Nút 40 không có nút đứng sau
