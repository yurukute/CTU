Giả sử kiểu dữ liệu cây tìm kiếm nhị phân cân bằng về chiều cao AVLTree đã được khai báo và các phép toán cơ bản trên cây cũng đã được cài đặt:
```c
typedef int KeyType;
struct Node{
	KeyType	Key;
	int		Height;
	struct Node *Left, *Right;
};
typedef struct Node* AVLTree;
/* Liet ke (Key,Height) cua cac nut tren cay theo cach duyet tien tu */ 
void printNLR(AVLTree root)
/* Liet ke (Key,Height)cua cac nut tren cay theo cach duyet hau tu */
void printLRN(AVLTree root)
int max(int a,int b)
/* Tim chieu cao cua mot nut */
int getHeight(AVLTree node)
/* Tinh he so can bang cua mot nut */
int getBalance(AVLTree node)
/* Quay don qua trai cho truong hop mat can bang ben phai cua con phai */
AVLTree leftRotate(AVLTree node)
/* Quay don qua phai cho truong hop mat can bang ben trai cua con trai */
AVLTree rightRotate(AVLTree node)
/* Quay kep phai, trai cho truong hop mat can bang ben trai cua con phai */
AVLTree rightleftRotate(AVLTree node)
/* Quay kep trai, phai cho truong hop mat can bang ben phai cua con trai */
AVLTree leftrightRotate(AVLTree node)
/* Them nut co khoa key vao cay */
AVLTree insertNode(KeyType key,AVLTree root)
```
Viết hàm kiểm tra xem một cây có là cây AVL hay không

**Nguyên mẫu (Prototype)**
- Tên hàm: isAVL()
- Tham số: 
  - root - AVLTree
- Kiểu trả về: int

**Chú ý**
- Chỉ viết hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
