Giả sử kiểu dữ liệu cây nhị phân Tree đã được khai báo và các phép toán trên cây nhị phân cũng đã được cài đặt:
```c
typedef int DataType;
struct Node {
    DataType     Data;
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
struct Node* createNode(ElementType x) /* Tạo một nút có dữ liệu là */
Tree createTree(DataType x,Tree l,Tree r) /* Tạo một cây với: nút gốc có dữ liệu là x, cây con bên trái là l và cây con bên phải là r */
```
Ngoài ra, hàm `printArray()` in nội dung của một mảng path có độ dài len cũng đã được cài đặt.
```
void printArray(int path[], int len){
 int i;
 for(i=0;i<len;i++)
    printf("%d",path[i]);
    printf("\n");
}
```
Bằng cách sử dụng kiểu dữ liệu cây nhị phân Tree đã cho, hãy viết hàm printAllPaths() hiển thị tất cả các đường đi (từ nút gốc đến nút lá) và có độ dài đường đi bằng một giá trị cho trước .
Dữ liệu đầu vào: một cây nhị phân T, một mảng path lưu các giá trị nút của đường đi, kích thước của mảng len lưu số nút của đường đi, độ dài đường đi cần tìm pathlen. 

Khởi đầu mảng path chưa có giá trị nào và len= 0, trong quá trình thức hiện, khi thêm một giá trị vào path thì tăng len lên một đơn vị.

Dữ liệu đầu ra: không.

Ví dụ:

Cho cây nhị phân T:
```
  12
 /  \
24   7
\   / \
10 32 -8
  /  \
 5   48
```						 
Cần tìm các đường đi từ nút gốc đến nút lá và có độ dài bằng 2?

Các đường đi từ nút gốc đến nút lá có độ dài bằng 2 là:
- 12 24 10
- 12 7 -8
