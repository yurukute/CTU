Cài đặt lớp Point biểu diễn các điểm trong không gian 2 chiều gồm các thuộc tính và phương thức sau:
- Thuộc tính:
    - x, y: kiểu số nguyên (int), kiểu truy cập private
- Các phương thức: kiểu truy cập public
    - Hàm xây dựng mặc định: `Point()`
        - Gán x = 0, y = 1
    - Hàm xây dựng có 2 tham số: `Point(int x, int y)`
        - Gán hai tham số tương ứng cho x và y.
    - Nhập tọa độ cho điểm từ bàn phím: `void read()`
        - Đọc 2 số nguyên từ bàn phím và lưu vào x và y.
        - Dữ liệu đầu vào có dạng: x y, ví dụ: -50 100
    - Hiển thị dữ liệu ra màn hình: `void print()`
        - Hiển thị tọa độ của điểm theo dạng (x, y), ví dụ: (-50, 100)
        - Chú ý: sau dấu phẩy có 1 khoảng trắng, in xong, **xuống dòng**.
    - Dời điểm đi 1 độ dời (dx, dy): `void move(int dx, int dy)`
        - Di chuyển tọa độ của điểm đến vị trí mới cách chỗ cũ một khoảng (dx, dy).
        - Sau khi di chuyển, tọa độ mới của điểm là (x + dx, y + dy).
    - Lấy ra giá trị hoành độ của điểm: `int getX()`
        - Trả về tọa độ x của điểm
    - Lấy ra giá trị tung độ của điểm: `int getY()`
        - Trả về tọa độ y của điểm
    - Tính khoảng cách từ điểm đó đến gốc tọa độ: `double distance()`
        - Trả về khoảng cách từ điểm đang xét (this) đến gốc tọa độ
    - Tính khoảng cách từ điểm đó đến 1 điểm khác: d`ouble distance(Point P)`
        - Trả về khoảng cách từ điểm đang xét (this) đến điểm P.

**Chú ý**
- Chỉ cài đặt lớp Point, không viết thêm lớp khác, không viết hàm main() trong lớp này.
- Chương trình đã khai báo sẵn một scanner tên `MyUtil.scanner`. Bạn hãy dùng scanner này để đọc dữ liệu, không tạo thêm scanner khác.