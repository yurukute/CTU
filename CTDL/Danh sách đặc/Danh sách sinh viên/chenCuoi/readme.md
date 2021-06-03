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

Giả sử khai báo kiểu DanhSach đã được định nghĩa. Hãy viết 1 hàm cho phép thêm đầy đủ thông tin của 1 sinh viên (struct SinhVien) vào cuối danh sách cho trước

**Nguyên mẫu**
- Tên hàm: chenCuoi()
- Tham số: 
    - s: struct SinhVien
    - pL: con trỏ danh sách
- Kiểu trả về: không

**Thân hàm**
- Thêm s vào cuối danh sách chỉ bởi con trỏ pL nếu còn có thể thêm được

**Chú ý**
Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH

**Gợi ý**
- Nếu còn có thể thêm được thì đưa s vào chỉ số n trong mảng A của danh sách; sau đó tăng số phần tử lên 1