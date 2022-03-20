Giả sử kiểu dữ liệu cây nhị phân Tree đã được khai báo và các phép toán trên cây nhị phân cũng đã được cài đặt:
```c
typedef char DataType;
struct Node {
    DataType Data;
    struct Node *Left,*Right;
 };
typedef struct Node* Tree;
void makenullTree(Tree* pT) 
int emptyTree(Tree T)
Tree leftChild(Tree n)
Tree rightChild(Tree n)
int isLeaf(Tree n)
void preOrder(Tree T)
void inOrder(Tree T)
void postOrder(Tree T)
struct Node* createNode(DataType x) /* Tạo một nút chứa dữ liệu x */
```
Ngoài ra, hàm `max()` trả về giá trị lớn nhất của hai tham số a, b cũng đã được cài đặt.
```c
int max(int a, int b)
```
Bằng cách sử dụng kiểu dữ liệu cây nhị phân Tree đã cho, hãy viết hàm `getDiameter()` tính bán kính của một cây nhị phân.

Bán kính của một cây là số nút trên đường đi dài nhất giữa hai nút lá của cây.

Gợi ý: sử dụng ý tưởng của hàm tính chiều cao của một cây và có thêm tham số (truyền con trỏ) để lưu giữ bán kính lớn nhất.
