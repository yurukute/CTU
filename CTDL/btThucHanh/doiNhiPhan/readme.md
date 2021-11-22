Cho mô hình một ngăn xếp các số nguyên cài đặt bằng mảng như sau:

<img src="../../Stack/Stack.png">

Trong đó M = SoPhanTu= 100

Giả sử kiểu dữ liệu NganXep đã được khai báo. Các phép toán cơ bản trên ngăn xếp được hỗ trợ:
- `void khoitao(NganXep *pS)`: khởi tạo ngăn xếp chỉ bởi con trỏ pS rỗng
- `int giatriDinh(NganXep S)`: trả về giá trị tại đỉnh ngăn xếp
- `void xoa(NganXep *pS)`: xóa phần tử tại đỉnh ngăn xếp chỉ bởi con trỏ pS
- `int ktRong(NganXep S)`: kiểm tra ngăn xếp có rỗng hay không?
- `int ktDay(NganXep S)`: kiểm tra ngăn xếp có đầy hay không?
- `void them(int x, NganXep *pS)`: thêm phần tử x vào đỉnh ngăn xếp chỉ bởi con trỏ pS

Viết hàm cho phép chuyển đổi số nguyên dương n về dạng nhị phân.

Nguyên mẫu (Prototype)
- Tên hàm: doiNhiPhan()
- Tham số: 
	-  n - số nguyên	
	- pS - con trỏ ngăn xếp
- Kiểu trả về: không

Thân hàm (Body)
- Đổi số nguyên n về dạng nhị phân, kết quả lưu trong ngăn xếp chỉ bởi con trỏ pS

Gợi ý
- Xem phần ghi chú về ngăn xếp và hàng đợi

Chú ý
- Chỉ viết hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
