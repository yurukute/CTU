# Bài 5.4. Tìm luồng cực đại trong mạng
Viết chương trình tìm luồng cực đại trên mạng bằng thuật toán Ford - Fulkerson (duyệt theo chiều rộng).

Đầu vào (Input)
- Dữ liệu đầu vào được nhập từ bàn phím với định dạng:
  - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung.
  - m dòng tiếp theo mỗi dòng chứa 3 số nguyên u, v, w mô tả cung (u, v) có trọng số w.

Đầu ra (Output)
- In ra màn hình theo định dạng sau:
  - Dòng đầu tiên in luồng cực đại theo dạng: Max flow: f với f là giá trị luồng cực đại
  - Dòng thứ hai in các đỉnh của S theo dạng: S: x1 x2 ..., mỗi đỉnh cách nhau 1 khoảng trắng. In các đỉnh theo thứ tự từ nhỏ đến lớn.
  - Dòng thứ ba in các đỉnh của T theo dạng: T: y1 y2 ..., mỗi đỉnh cách nhau 1 khoảng trắng. In các đỉnh theo thứ tự từ nhỏ đến lớn.
