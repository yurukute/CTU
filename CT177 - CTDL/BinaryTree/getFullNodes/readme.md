Giả sử kiểu dữ liệu cây nhị phân Tree đã được khai báo và các phép toán trên cây nhị phân cũng đã được cài đặt:
```c
typedef int DataType;
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
struct Node* createNode(ElementType x) /* Tạo một nút có dữ liệu là x */
```
Bằng cách sử dụng kiểu dữ liệu cây nhị phân Tree đã cho, hãy viết hàm `getFullNodes()` đếm số nút có đủ hai con.

Dữ liệu đầu vào: một cây tìm kiếm nhị phân.

Dữ liệu đầu ra: số nút có đủ hai con.
