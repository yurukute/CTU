Cây cây tìm kiếm nhị phân mỗi khóa là 1 số nguyên được khai báo như sau:

```c
struct Node{
	int Key;
	struct Node *Left, *Right;
};
```
Cho trước các phép toán:
- void insertNode(int x, Tree *pT): thêm khóa x vào cây tìm kiếm nhị phân có gốc chỉ bởi con trỏ pT
- void inOrder (Tree T): duyệt trung tự cây tìm kiếm nhị phân T

Viết hàm xóa một nút có khóa là x trong cây tìm kiếm nhị phân

**Nguyên mẫu (Prototype)**
- Tên hàm: deleteNode()
- Tham số: 
  - x - int
  - pT - **con trỏ Tree**
- Kiểu trả về: không

Thân hàm (Body)
- Tiến hành xóa nút có khóa là x trong cây chỉ bởi con trỏ pT

Chú ý
- Chỉ viết hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
