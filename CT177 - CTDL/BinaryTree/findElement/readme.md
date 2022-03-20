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
Bằng cách sử dụng kiểu dữ liệu cây nhị phân Tree đã cho, hãy viết hàm `findElement()` xác định xem x có là giá trị của một nút trong cây nhị phân hay không.

Dữ liệu đầu vào: một giá trị x có kiểu DataType và một cây nhị phân T.

Dữ liệu đầu ra: trả về cây có nút gốc có dữ liệu bằng với x nếu tìm thấy hoặc cây rỗng nếu không tìm thấy.

Gợi ý:
- Xét các tình huống cây rỗng, cây không rỗng.
- Nếu cây không rỗng thì tiếp tục xét các tình huống có thể xảy ra: giá trị của nút gốc bằng với x cần tìm; tìm x ở cây con bên trái; tìm x ở cây con bên phải. 
