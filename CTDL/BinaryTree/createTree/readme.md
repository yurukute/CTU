Giả sử kiểu dữ liệu cây nhị phân Tree đã được khai báo và các phép toán cơ bản trên cây nhị phân cũng đã được cài đặt:
```c
typedef char DataType;
struct Node {
    DataType Data;
    struct Node *Left,*Right;
 };
typedef struct Node* Tree;
void makenullTree(Tree* pT) 
int emptyTree(Tree T)
Tree
leftChild(Tree n)
Tree rightChild(Tree n)
int isLeaf(Tree n)
int getLeaves(Tree T) /* hàm trả về số nút lá trên cây */
void preOrder(Tree T)
void inOrder(Tree T)
void postOrder(Tree T)
```
Ngoài ra, `hàm findIndex()` tìm chỉ mục của một ký tự  x trong chuỗi biểu thức trung tự in bắt đầu từ vị trí star đến vị trí end cũng đã được cài đặt:
```c
int findIndex(DataType x, char in[], int star, int end){
    int i=star;
    while (i<=end){
         if (x==in[i])
             return i;
         else
             i++;
   }
   return i;
}
```
Bằng cách sử dụng kiểu dữ liệu cây nhị phân Tree đã cho, hãy viết hàm createTree() cho phép dựng một cây nhị phân từ các biểu thức duyệt tiền tự và trung tự.

Dữ liệu đầu vào: 
- Chuỗi chứa biểu thức tiền tự. Ví dụ: "DBEAFC".
- Chuỗi chứa biểu thức trung tự. Ví dụ: "ABDECF".
- Chỉ số bắt đầu của phần chuỗi trung tự được xét. Ví dụ: 0
- Chỉ số kết thúc của phần chuỗi trung tự được xét: Ví dụ: 5

Dữ liệu đầu ra: con trỏ trỏ đến nút gốc của cây nhị phân được tạo ra từ hai biểu thức tiền tự và trung tự.

Gợi ý:
- Gọi pre và in lần lượt là biểu thức duyệt tiền tự và biểu thức duyệt hậu tự, gọi Start va End là chỉ số đầu và chỉ số cuối của biểu thức duyệt trung tự.
- Khai báo một biến toàn cục preIndex lưu chỉ số đang xét của chuỗi tiền tự. Khởi đầu đặt preIndex= 0.
- Thân hàm `Tree createTree(char pre[], char in[], int Start, int End)` như sau:
  - Khai báo một biến kiểu Tree N, đặt N=NULL;
  - Nếu Start <= End thì
  	- Cấp phát bộ nhớ cho nút mới N;
   	- Cho N->Data= pre[preIndex];
	- Tăng preIndex lên 1 đơn vị
	- Nếu Start == End thì đặt N là nút lá
	- Ngược lai:
   		- Tìm inIdex là chỉ số của N->Data trong chuỗi biểu thức trung tự in
		- N->Left=createTree(pre, in, Start, inIndex-1);
		- N->Right=createTree(pre, in, inIndex+1, End);
  - Trả về N
