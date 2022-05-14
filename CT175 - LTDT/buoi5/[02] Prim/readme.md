
# Bài 5.2. tìm cây khung có trọng lượng nhỏ nhất bằng giải thuật Prim
Viết chương trình đọc một đồ thị vô hướng liên thông và tìm cây khung có trọng số nhỏ nhất bằng thuật toán Prim.

Đầu vào (Input)
- Dữ liệu đầu vào được nhập từ bàn phím với định dạng
  - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung.
  - m dòng tiếp theo mỗi dòng chứa 3 số nguyên u, v, w mô tả cung (u, v) có trọng số w.

Đầu ra (Output)
- In ra màn hình theo định dạng sau:
  - Dòng đầu tiên in trọng số của cây khung tìm được
  - n - 1 dòng kế tiếp in ra các cung của cây tìm tìm được theo định dạng: u v w. Cung (u1, v1) sẽ được in ra trước cung (u2, v2) nếu (u1 < u2) hoặc (u1 = u2 và v1 < v2).
