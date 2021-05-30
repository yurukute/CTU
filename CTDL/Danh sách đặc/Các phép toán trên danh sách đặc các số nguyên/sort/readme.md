Cho mô hình một danh sách các số nguyên List như sau:

<img src="../dsdac2.png">

Hãy viết hàm sắp xếp danh sách 
- Tên hàm (function name): sort()
- Tham số (parameters):
    - pL - con trỏ kiểu List
- Kiểu trả về: Không

**Thân hàm (Body)**
- Sắp xếp tăng dần danh sách chỉ bởi con trỏ pL

**Chú ý**
- Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH

**Gợi ý**
- Lặp ∀p=1, *Sau vị trí cuối cùng*
    - Lặp ∀q = p+1, *Sau vị trí cuối cùng*
        - Nếu (phần tử tại vị trí p > phần tử tại vị trí q)
            - Đổi chỗ giá trị 2 phần tử này cho nhau