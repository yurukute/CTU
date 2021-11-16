Cây tìm kiếm nhị phân cân bằng về chiều cao AVL có khóa tại mỗi nút là 1 số nguyên được khai báo như sau:
```c
typedef int KeyType;
struct Node{
	KeyType	Key;
	int		Height;
	struct Node *Left, *Right;
};
typedef struct Node* AVLTree;
```
Cho trước phép toán AVLTree insertNode(KeyType k, AVLTree T) thêm một nút có khóa k vào cây .
```
AVLTree insertNode( KeyType k, AVLTree T){
   ...
}
```
Viết hàm in kết quả duyệt tiền tự cây AVL

**Nguyên mẫu (Prototype)**
- Tên hàm: printNLR()
- Tham số: T - AVLTree
- Kiểu trả về: không

**Thân hàm (Body)**
- Liệt kê khóa và chiều cao của các nút trên cây T theo cách duyệt tiền tự

**Chú ý**
- Chỉ viết hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
