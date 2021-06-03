Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một danh sách đặc. Mỗi sinh viên (cấu trúc SinhVien) là một phần tử trong danh sách đặc có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (float).

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

Giả sử khai báo kiểu DanhSach đã được định nghĩa.  Hãy viết 1 hàm hiển thị danh sách sinh viên

**Nguyên mẫu**
- Tên hàm: hienthi()
- Tham số: 
    - L: danh sách
- Kiểu trả về: không

**Thân hàm**
- Hiển thị danh sách sinh viên L lên màn hình (mỗi sinh viên khi hiển thị thì tính luôn tổng điểm của sinh viên đó). 

        Tổng điểm = Điểm lý thuyết + Điểm thực hành 1 + Điểm thực hành 2

Xem ví dụ để biết chi tiết về việc hiển thị

**Chú ý**
Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH