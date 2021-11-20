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
Tree createTree(char preOrde[], char inOrder[]) /* Dựng cây nhị phân từ các biểu thức tiền tự và trung tự */
```
Bằng cách sử dụng kiểu dữ liệu cây nhị phân Tree đã cho, hãy viết hàm findMax() tìm giá trị lớn nhất trong cây nhị phân.

Dữ liệu đầu vào: cây nhị phân

Dữ liệu đầu ra: giá trị lớn nhất trong cây nhị phân.

Gợi ý:
- Xét các tình huống cây rỗng, cây không rỗng.
- Gọi đệ quy hàm tìm giá trị lớn nhất cây con bên trái, cây con bên phải và so sánh với giá trị nút gốc. 
