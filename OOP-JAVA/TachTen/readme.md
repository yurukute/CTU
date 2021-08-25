Viết chương trình nhập vào 1 chuỗi họ tên. Hiển thị ra tên của họ tên đó. Nên thiết kế chương trình gồm 1 hàm dùng để tách tên và hàm main.

**Quy ước đặt tên**
- Tên lớp: TachTen
- Hàm tách tên: public static String layTen(String hoten)
- Hàm main: public static void main(String[] args)

**Đầu vào**
- Họ và tên nằm trên một dòng. Có thể có khoảng trắng đầu và cuối họ và tên. 

**Đầu ra**
- In ta tên.

**Chú ý**
- Phải khai báo lớp và hàm theo quy ước đăt tên
- Dữ liệu đầu vào luôn hợp lệ bạn không cần kiểm tra.
- Không cần in ra ca câu giới thiệu, ví dụ: "Nhập họ tên:", trước khi đọc dữ liệu.

**Gợi ý**
- Sử dụng trim(), lastIndexOf() và substring().