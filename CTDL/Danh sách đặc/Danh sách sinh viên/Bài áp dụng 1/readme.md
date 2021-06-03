Người ta cần quản lý điểm thi môn Cấu trúc dữ liệu của các sinh viên trong lớp (tối đa 40 sinh viên) bằng một danh sách đặc. Mỗi sinh viên (cấu trúc SinhVien) là một phần tử trong danh sách đặc có các thông tin: mã số sinh viên (chuỗi 10 ký tự), họ và tên (chuỗi 50 ký tự), điểm thi lý thuyết, điểm thi thực hành 1, điểm thi thực hành 2 (float).

Khi biểu diễn bằng danh sách đặc DanhSach, người ta dùng một cấu trúc có 2 trường:
   - Mảng A chứa các sinh viên
   - Số phần tử trong danh sách: n

Một sinh viên gọi là ĐẠT nếu tổng điểm (Điểm LT + Điểm TH1 + Điểm TH2) >= 4.0.

Bằng cách sử dụng những phép toán đã định nghĩa trên danh sách sinh viên. Hãy viết chương trình nhập và hiển thị danh sách sinh viên. Sau đó liệt kê những sinh viên KHÔNG ĐẠT.

Gợi ý
- Khai báo kiểu DanhSach
- Định nghĩa các hàm nhập và hiển thị danh sách sinh viên
- Định nghĩa hàm chép những sinh viên không đạt sang danh sách kết quả
- Gọi thực thi các hàm trên trong hàm main()