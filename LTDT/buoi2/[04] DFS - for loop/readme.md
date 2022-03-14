# Bài tập 4. DFS - Duyệt theo chiều rộng TOÀN BỘ đồ thị
## Câu 1
Cho một đồ thị **vô hướng đơn**. Hãy in ra các đỉnh theo thứ tự duyệt khi duyệt đồ thị **theo chiều sâu** bắt đầu từ đỉnh 1.

Quy ước:
- Các đỉnh kề của 1 đỉnh được liệt kê theo thứ tự tăng dần
- Nếu cài đặt dùng ngăn xếp hãy đưa các đỉnh kề của đỉnh u vào ngăn xếp theo thứ tự **từ lớn đến nhỏ**

Đầu vào (Input)
- Dữ liệu đầu vào được nhập từ bàn phím với định dạng:
  - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung
  - m dòng tiếp theo mỗi dòng chứa 2 số nguyên u v mô tả cung (u, v)

Đầu ra (Output)
- In ra các đỉnh theo thứ tự duyệt, mỗi đỉnh trên 1 dòng

## Câu 2
Cho một đồ thị **có hướng đơn**. Hãy in ra các đỉnh theo thứ tự duyệt khi duyệt đồ thị theo chiều rộng bắt đầu từ đỉnh 1.

Nếu vẫn còn đỉnh chưa duyệt sau khi duyệt xong lần 1, tìm đỉnh có chỉ số nhỏ nhất chưa duyệt mà duyệt nó, và cứ tiếp tục như thế cho đến khi tất cả các đỉnh đều được duyệt.

Quy ước:
- Các đỉnh kề của 1 đỉnh được liệt kê theo thứ tự tăng dần
- Nếu cài đặt dùng ngăn xếp hãy đưa các đỉnh kề của đỉnh u vào ngăn xếp theo thứ tự **từ lớn đến nhỏ**

Đầu vào (Input)
- Dữ liệu đầu vào được nhập từ bàn phím với định dạng:
  - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung
  - m dòng tiếp theo mỗi dòng chứa 2 số nguyên u v mô tả cung (u, v)

Đầu ra (Output)
- In ra các đỉnh theo thứ tự duyệt, mỗi đỉnh trên 1 dòng
