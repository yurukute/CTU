Giả sử kiểu dữ liệu ngăn xếp Stack đã được khai báo. Các phép toán cơ bản trên ngăn xếp được hỗ trợ:
```c
void makenullStack(Stack *pS)
int emptyStack(Stack S)	
ElementType top(Stack S) 
void pop(Stack *pS) 
void push(ElementType x, Stack *pS) 
```
Hãy viết hàm ktChuoi() kiểm tra một chuỗi có các dấu '(' và ')' có tạo thành một chuỗi ngoặc đúng hay không.

Gợi ý
- Định nghĩa hàm ktChuoi() kiểm tra một chuỗi ngoặc có là chuỗi ngoặc đúng hay không. 
  - Hàm ktChuoi không có tham số đầu vào; 
  - Kết quả trả về là 0 nếu chuỗi ngoặc không đúng và 1 nếu ngược lại. 
  - Hàm ktChuoi() phải sử dụng kiểu Stack đã được cài đặt. 
  	- Nhập vào một chuỗi có các dấu '(' và ')' .
	- Với từng ký tự trong chuỗi: 
   		- Nếu ký tự là '(' thì đưa vào ngăn xếp; 
		- Nếu ký tự là ')' và ngăn xếp không rỗng thì xóa bỏ phần tử trên đỉnh ngăn xếp. Nếu ngăn xếp rỗng thì dừng thực thi và trả về 0;
	- Nếu ngăn xếp rỗng thì chuỗi ngoặc đúng; ngược lại là chuỗi ngoặc không đúng. 
