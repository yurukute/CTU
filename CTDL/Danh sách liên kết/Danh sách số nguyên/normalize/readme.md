Cho mô hình một danh sách các số nguyên List như sau:

<img src="../Dslk.png">

Cho trước các phép toán sau:
- Xóa phần tử ở vị trí p trong danh sách deleteList()
- Bên cạnh đó phép toán append(x, &L): nối phần tử x vào danh sách cũng được hỗ trợ để thêm dữ liệu cho các test cases.

Hãy viết hàm chuẩn hóa một danh sách, tức các phần tử trong danh sách nếu trùng nhau thì chỉ giữ lại 1 phần tử, các phần tử khác bị xóa bỏ
- Tên hàm (function name): normalize()
- Tham số (parameters):
    - pL - con trỏ kiểu List
- Kiểu trả về: Không

**Thân hàm (Body)**
- Các phần tử trùng nhau trong danh sách chỉ bởi con trỏ pL bị xóa bở chỉ giữ lại 1 phần tử đầu tiên

**Chú ý**
- Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH


Gợi ý

p = vị trí đầu tiên trong danh sách
Trong khi  (p != Sau vị trí cuối cùng)
          - q = p+1

          - Trong khi (q != Sau vị trí cuối cùng)

                + Nếu (phần tử tại vị trí p == phần tử tại vị trí q) 

                          Xóa phần tử tại vị trí q

                + Ngược lại q= vị trí kế của q

          - p = vị trí kế của p