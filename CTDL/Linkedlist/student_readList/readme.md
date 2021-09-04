Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp bằng một danh sách liên kết. Mỗi sinh viên (cấu trúc Student) là một phần tử trong danh sách liên kết có các thông tin: ID (chuỗi 10 ký tự), Name (chuỗi 50 ký tự), điểm thành phần R1, điểm thành phần R2, điểm thành phần R3 (các điểm này có kiểu float). 

Hình ảnh của danh sách L có dạng như bên dưới

<img src="../Dslk.png">

Cho trước khai báo danh sách List và các phép toán:
- List getList() - hàm trả về một danh sách rỗng
- struct Node* locate(char[] ID, List L) - trả về vị trí xuất hiện đầu tiên của  mã số ID trong danh sách L.
- int append(Student s, List *pL) - Nối sinh viên s vào cuối danh sách chỉ bởi con trỏ pL và trả về 1 nếu mã số sinh viên chưa có; nếu mã số đã có thì kết quả trả về của hàm là 0 mà không thêm sinh viên này vào

Hãy viết nhập một danh sách sinh viên từ bàn phím.

Giả sử ta có đoạn chương trình cho phép nhập 1 danh sách sinh viên từ bàn phím
```cpp
#include<stdio.h>
#include<malloc.h>
#include<string.h>

/*Khai báo danh sách sinh viên và một số hàm cho trước*/

List readList()
{
	int n,i;
	Student s;
	char st[50];
	List L = getList(); // Khởi tạo danh sách rỗng
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" "); //skip some characters
		fgets(st,10,stdin);
		if (st[strlen(st)-1] == '\n')
			st[strlen(st)-1] = '\0';
		strcpy(s.ID, st);
		fgets(st,50,stdin);
		if (st[strlen(st)-1] == '\n')
			st[strlen(st)-1] = '\0';
		strcpy(s.Name, st);
		scanf("%f%f%f",&s.R1,&s.R2,&s.R3);
		// Nếu mã sinh viên chưa có thì chèn vào danh sách
                ...  
	}
	return L;
}    

int main(){

     return 0;
}
```

Hãy HOÀN CHỈNH CHƯƠNG TRÌNH TRÊN bằng cách điền các lệnh cần thiết vào dấu ... (trong hàm readList()) để tạo thành 1 chương trình có thể thực thi được.

**Nguyên mẫu**
- Tên hàm: readList()
- Tham số: không
- Kiểu trả về: danh sách (List)

**Thân hàm**
- Ban đầu cho danh  sách kết quả là rỗng. Nhập số lượng sinh viên n; sau đó với mỗi sinh viên thứ i, nhập các thông tin cần thiết của họ và gọi hàm append() để nối vào danh sách kết quả. Kết quả của hàm là danh sách kết quả

**Chú ý**
- Chỉ viết phần được yêu cầu, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH