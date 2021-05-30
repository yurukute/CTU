Cho mô hình một danh sách các số nguyên List như sau:

<img src="../dsdac2.png">

Hãy viết hàm tính trung bình cộng giá trị các phần tử trong danh sách.
- Tên hàm (function name): getAvg()
- Tham số (parameters):
    - L - kiểu List
- Kiểu trả về: float

**Thân hàm (Body)**
- Trả về trung bình cộng giá trị các phần tử trong danh sách, nếu danh sách - không có phần tử nào thì kết quả trả về của hàm là -10000.0000

**Chú ý**
- Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH

**Gợi ý**
- Gọi S là tổng của tất cả giá trị các phần tử, ban đầu S=0
- Duyệt qua danh sách L, tại mỗi phần tử tính lại S = S + giá trị phần tử đó
- Trung bình cộng = S/(Số phần tử trong danh sách)
