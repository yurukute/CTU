Cho mô hình một danh sách liên kết đơn các số nguyên như sau:

<img src="../Dslk.png">

Giả sử kiểu dữ liệu List đã được khai báo. 

Viết hàm cho phép chèn phần tử x vào đầu danh sách.

Chẳng hạn danh sách L = [1, 5, 10]

addFirst(-10, &L)

Kết quả L = [-10, 1, 5, 10]

**Nguyên mẫu (Prototype)**
- Tên hàm: addFirst()
- Tham số: 
    - x: Kiểu phần tử - số nguyên
    - pL: con trỏ kiểu List
- Kiểu trả về: không

**Thân hàm (Body)**
- Chèn x vào đầu danh sách chỉ bởi con trỏ pL

**Chú ý**
- Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH

**Gợi ý**
- Gọi p là vị trí đầu tiên
- Thêm x vào vị trí p