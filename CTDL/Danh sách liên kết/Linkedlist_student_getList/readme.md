Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp bằng một danh sách liên kết. Mỗi sinh viên (cấu trúc Student) là một phần tử trong danh sách liên kết có các thông tin: ID (chuỗi 10 ký tự), Name (chuỗi 50 ký tự), điểm thành phần R1, điểm thành phần R2, điểm thành phần R3 (các điểm này có kiểu float). 
```cpp
typedef struct {
   char ID[10];
   char Name[50];
   float R1, R2, R3;
}Student;
```
Hình ảnh của danh sách L có dạng như bên dưới

<img src="../Dslk.png">

Giả sử khai báo kiểu List đã được định nghĩa. Hãy viết 1 hàm trả về 1 danh sách sinh viên rỗng.

**Nguyên mẫu**
- Tên hàm: getList()
- Tham số: không
- Kiểu trả về: List

**Thân hàm**
- Trả về 1 danh sách rỗng

**Chú ý**
- Chỉ viết phần khai báo, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH

**Gợi ý**
- Cấp phát một ô mới (struct Node) và cho L chỉ tới địa chỉ đầu tiên được cấp phát
- Trường Next của ô nhớ chỉ bởi L là NULL
- Trả về kết quả của hàm là L