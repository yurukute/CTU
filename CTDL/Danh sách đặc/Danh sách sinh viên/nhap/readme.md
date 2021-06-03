Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một danh sách đặc. Mỗi sinh viên (cấu trúc **SinhVien**) là một phần tử trong danh sách đặc có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (**float**).

Cho cấu trúc SinhVien dùng để lưu trữ một sinh viên như sau:
```cpp
struct SinhVien{
   char MSSV[10];
   char HoTen[50];
   float DiemLT, DiemTH1, DiemTH2;
};
```

Khi biểu diễn bằng danh sách đặc DanhSach, người ta dùng một cấu trúc có 2 trường:
   - Mảng A chứa các sinh viên
   - Số phần tử trong danh sách: n

Giả sử khai báo kiểu DanhSach và một số các phép toán sau đã được định nghĩa:
  - Thêm sinh viên s vào cuối danh sách - chenCuoi()
  - Tìm kiếm vị trí sinh viên có mã số cho trước - tim()
  - Khởi tạo và trả về 1 danh sách rỗng - dsRong()

Hãy viết 1 hàm nhập danh sách sinh viên từ bàn phím. Chú ý nếu một mã số sinh viên đã có thì không thêm thông tin của sinh viên đó vào danh sách.

**Nguyên mẫu**
- Tên hàm: nhap()
- Tham số: không
- Kiểu trả về: danh sách

**Thân hàm**
- Nhập thông tin của từng sinh viên thứ i, thêm vào danh sách. Cuối cùng trả về danh sách sau khi thêm sinh viên

**Chú ý**
Chỉ viết phần khai báo, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH

**Gợi ý**
- Khởi tạo 1 danh sách L rỗng
- Nhập số phần tử
- Nhập thông tin của từng sinh viên thứ i, nếu mã số vừa đưa vào không có trong danh sách nhập trước đó thì thêm sinh viên vào cuối danh sách kết quả
- Danh sách L là kết quả trả về của hàm