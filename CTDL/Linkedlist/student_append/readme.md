Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp bằng một danh sách liên kết. Mỗi sinh viên (cấu trúc Student) là một phần tử trong danh sách liên kết có các thông tin: ID (chuỗi 10 ký tự), Name (chuỗi 50 ký tự), điểm thành phần R1, điểm thành phần R2, điểm thành phần R3 (các điểm này có kiểu float). 

Hình ảnh của danh sách L có dạng như bên dướiL

<img src="../Dslk.png">

Cho trước khai báo danh sách List và phép toán struct Node* locate(char[] ID, List L) - trả về vị trí xuất hiện đầu tiên của  mã số ID trong danh sách L.

Hãy viết hàm thêm một sinh viên s vào cuối danh sách cho trước.

**Nguyên mẫu**
- Tên hàm: append()
- Tham số: 
    - s: cấu trúc Student
    - pL: con trỏ danh sách
- Kiểu trả về: số nguyên 

**Thân hàm**
- Nếu mã số của sinh viên cần thêm đã có trong danh sách, trả về kết quả của hàm là 0; ngược lại thêm sinh viên vào cuối danh sách và kết quả trả về của hàm là 1

**Chú ý**
- Chỉ viết khai báo, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH.