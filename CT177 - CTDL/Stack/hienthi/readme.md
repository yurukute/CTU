Cho mô hình một ngăn xếp các số nguyên cài đặt bằng mảng như sau:

<img src="../Stack.png">

Trong đó M = SoPhanTu= 100

Giả sử kiểu dữ liệu NganXep đã được khai báo. Các phép toán cơ bản trên ngăn xếp được hỗ trợ:
- `int giatriDinh(NganXep S)`: trả về giá trị tại đỉnh ngăn xếp
- `void xoa(NganXep *pS)`: xóa phần tử tại đỉnh ngăn xếp chỉ bởi con trỏ pS
- `int ktRong(NganXep S)`: kiểm tra ngăn xếp có rỗng hay không?

Viết hàm hiển thị 1 ngăn xếp lên màn hình

**Nguyên mẫu (Prototype)**
- Tên hàm: hienthi()
- Tham số: 
	- pS - con trỏ ngăn xếp
- Kiểu trả về: không

**Thân hàm (Body)**
- Hiển thị toàn bộ ngăn xếp lên màn hình

**Gợi ý**
- Dùng giải thuật duyệt qua ngăn xếp như sau:
  
  Lặp khi (ngăn xếp chưa rỗng)
	- Xử lý phần tử tại đỉnh ngăn xếp
	- Xóa phần tử tại đỉnh ngăn xếp

**Chú ý**
- Chỉ viết hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
