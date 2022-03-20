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
Định nghĩa 2 cây nhị phân MT và T là phản chiếu (mirror) của nhau một cách đệ quy như sau:
- Nếu cả hai cây đều rỗng thì MT và T là phản chiếu của nhau
- Nếu chỉ có một trong hai cây rỗng hoặc giá trị tại 2 gốc khác nhau thì MT và T không là phản chiếu của nhau
- Nếu giá trị 2 nút gốc bằng nhau đồng thời con trái của MT là phản chiếu của con phải của T và ngược lại, con phải của MT là phản chiếu của con trái của T thì MT và T là phản chiếu của nhau 

Bằng cách sử dụng kiểu dữ liệu cây nhị phân Tree đã cho, hãy viết hàm `convertTree()` để chuyển đổi một cây nhị phân sang cây phản chiếu của nó.

Dữ liệu đầu vào: một cây nhị phân T.

Dữ liệu đầu ra: cây phản chiếu của T.

Ví dụ

Cho cây nhị phân T:
```
   12
  /  \
24    7
 \   / \
 10 32 -8
   /  \
  5   48
```
Cây phản chiếu của T:
```
     12
    /  \
   7    24
  / \   /
-8  32 10
   /  \
  48   5
```
