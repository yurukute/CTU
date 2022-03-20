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
Tree createTree(DataType x,Tree l,Tree r) /* Tạo một cây với: nút gốc có dữ liệu là x, cây con bên trái là l và cây con bên phải là r */
```
Định nghĩa 2 cây nhị phân MT và T là phản chiếu (mirror) của nhau một cách đệ quy như sau:
- Nếu cả hai cây đều rỗng thì MT và T là phản chiếu của nhau
- Nếu chỉ có một trong hai cây rỗng hoặc giá trị tại 2 gốc khác nhau thì MT và T không là phản chiếu của nhau
- Nếu giá trị 2 nút gốc bằng nhau đồng thời con trái của MT là phản chiếu của con phải của T và ngược lại, con phải của MT là phản chiếu của con trái của T thì MT và T là phản chiếu của nhau 

Bằng cách sử dụng kiểu dữ liệu cây nhị phân Tree đã cho, hãy viết hàm `isMirrors()` kiểm tra xem hai cây có là phản chiếu của nhau hay không.

Dữ liệu đầu vào: hai cây nhị phân T1 và T2.

Dữ liệu đầu ra: trả về 1 nếu cây T1 và T2 là phản chiếu của nhau; trả về 0 nếu ngược lại.

Ví dụ 2 cây nhị phân sau là phản chiếu của nhau:

Cây nhị phân T:
```
   12
  /  \
24    7
 \   / \
 10 32 -8
   /  \
  5   48
```
Cây nhị phân MT:
```
     12
    /  \
   7    24
  / \   /
-8  32 10
   /  \
  48   5
```
