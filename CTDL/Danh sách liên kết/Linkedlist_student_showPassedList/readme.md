Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp bằng một danh sách liên kết. Mỗi sinh viên (cấu trúc Student) là một phần tử trong danh sách liên kết có các thông tin: ID (chuỗi 10 ký tự), Name (chuỗi 50 ký tự), điểm thành phần R1, điểm thành phần R2, điểm thành phần R3 (các điểm này có kiểu float). 

Hình ảnh của danh sách L có dạng như bên dưới

<img src="../Dslk.png">

Cho trước khai báo danh sách List và các phép toán:
- **List getList()** - hàm trả về một danh sách rỗng
- **struct Node* locate(char[] ID, List L)** - trả về vị trí xuất hiện đầu tiên của  mã số ID trong danh sách L.
- **int append(Student s, List *pL)** - Nối sinh viên s vào cuối danh sách chỉ bởi con trỏ pL và trả về 1 nếu mã số sinh viên chưa có; nếu mã số đã có thì kết quả trả về của hàm là 0 mà không thêm sinh viên này vào
- **List readList()**: nhập một danh sách từ bàn phím, kết quả trả về của hàm là danh sách nhập
- void **printList(List L)**: hiển thị danh sách sinh viên lên màn hình, mỗi SV cần hiển thị luôn điểm trung bình với điểm tb = trung bình cộng của R1, R2, R3

Giả sử ta có đoạn chương trình cho phép hiển thị danh sách sinh viên ĐẠT (tức điểm trung bình >= 4)
```cpp
#include<stdio.h>
#include<malloc.h>
#include<string.h>

/*Khai báo danh sách sinh viên và một số hàm cho trước*/
void showPassedList(List L)
{
	//Duyệt qua danh sách L và hiển thị những SV đạt (điểm tb >=4)
	/*Khi hiển thị thì tính luôn điểm tống hợp với điểm tổng hợp là trung bình cộng của R1, R2, R3*/
	...
}
	
int main()
{
	List L;
	//Gọi hàm nhập ds từ bàn phím, gọi hàm hiển thị ds và hàm hiển thị SV ĐẠT
	...
			
     return 0;
}
```

Hãy HOÀN CHỈNH CHƯƠNG TRÌNH TRÊN bằng cách điền các lệnh cần thiết vào các dấu ... để tạo thành 1 chương trình có thể thực thi được.

**Chú ý**
Chỉ viết phần được yêu cầu, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
Ngăn cách các phần tương ứng với các dấu ... bằng dòng
- //-END-SECTION-

Bài này có 2 chỗ ..., vì thế bạn cần chia câu trả lời thành hai phần và ngăn cách chúng bằng dòng //-END-SECTION-, ví dụ:
- Đoạn lệnh Duyệt qua danh sách L và hiển thị những SV đạt (điểm tb >=4)
- //-END-SECTION-
- Gọi hàm nhập ds từ bàn phím, gọi hàm hiển thị ds và hàm hiển thị SV ĐẠT