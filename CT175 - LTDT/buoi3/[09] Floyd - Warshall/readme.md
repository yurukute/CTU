# Bài tập 9 - Thuật toán Floyd - Warshall (đường đi ngắn nhất giữa các cặp đỉnh)
## Câu 1
Viết chương trình đọc vào một đơn đồ thị có hướng, có trọng số. Áp dụng thuật toán Floyd - Warshall để tìm đường đi ngắn nhất giữa các cặp đỉnh.

Đầu vào (Input)
- Dữ liệu đầu vào được nhập từ bàn phím với định dạng:
  - Dòng đầu tiên chứa 2 số nguyên n và m (0 < n < 100; 0 < m < 500).
  - m dòng tiếp theo mỗi dòng chứa 3 số nguyên u, v, w mô tả cung (u, v) có trọng số w (-100 < w < 100).
  - Dữ liệu được đảm bảo không tồn tại chu trình âm.

Đầu ra (Output)
- In ra màn hình chiều dài đường đi ngắn nhất giữa các cặp đỉnh theo mẫu bên dưới. Nếu không có đường đi in ra NO PATH.
  ```
  u -> v: chiều dài
  ```
- Liệt kê các cặp theo thứ tự tăng dần của u và v
## Câu 2
Viết chương trình đọc vào một đơn đồ thị có hướng, có trọng số. Áp dụng thuật toán Floyd - Warshall để tìm đường đi ngắn nhất giữa các cặp đỉnh.

Đầu vào (Input)
- Dữ liệu đầu vào được nhập từ bàn phím với định dạng:
  - Dòng đầu tiên chứa 2 số nguyên n và m (0 < n < 100; 0 < m < 500).
  - m dòng tiếp theo mỗi dòng chứa 3 số nguyên u, v, w mô tả cung (u, v) có trọng số w (-100 < w < 100).
  - Dữ liệu được đảm bảo không tồn tại chu trình âm.

Đầu ra (Output)
- In ra màn hình đường đi từ ngắn nhất giữa các cặp đỉnh theo mẫu bên dưới. Nếu không có đường đi in ra NO PATH.
  ```
  path(u, v): u -> x1 -> ... -> v
  ```
- Liệt kê các cặp theo thứ tự tăng dần của u và v
