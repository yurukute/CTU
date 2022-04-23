# Bài tập 6 - Thuật toán Bellman - Ford
## Câu 1
Viết chương trình đọc một **đơn đồ thị có hướng, có trọng số (có thể âm)** từ bàn phím và in ra chiều dài đường đi ngắn nhất từ đỉnh s đến đỉnh t (s và t cũng được đọc từ bàn phím).

Đầu vào (Input)
- Dữ liệu đầu vào được nhập từ bàn phím với định dạng:
  - Dòng đầu tiên chứa 2 số nguyên n và m (1 ≤ n < 100; 0 ≤ m < 500)
  - m dòng tiếp theo mỗi dòng chứa 3 số nguyên u, v, w mô tả cung (u, v) có trọng số w (0 ≤ w ≤ 100).
  - Dòng cuối cùng chứa 2 số nguyên s và t.
  - Dữ liệu đầu vào được đảm bảo là đồ thị không chứa chu trình âm.

Đầu ra (Output)
- In ra màn hình chiều dài của đường đi ngắn nhất từ s đến t. Nếu không có đường đi từ 1 đến n, in ra -1.

Gợi ý
- Khi xét cung (u, v) nếu pi[u] = oo thì bỏ qua cung này, không xét.
- Sau khi kết thúc thuật toán nếu pi[u] = oo thì có nghĩa là không có đường đi từ s đến t.

## Câu 2
Viết chương trình đọc một **đơn đồ thị có hướng, có trọng số (có thể âm)** từ bàn phím và in ra đường đi ngắn nhất từ đỉnh s đến đỉnh t (s và t cũng được đọc từ bàn phím).

Đầu vào (Input)
- Dữ liệu đầu vào được nhập từ bàn phím với định dạng:
  - Dòng đầu tiên chứa 2 số nguyên n và m (1 ≤ n < 100; 0 ≤ m < 500)
  - m dòng tiếp theo mỗi dòng chứa 3 số nguyên u, v, w mô tả cung (u, v) có trọng số w (0≤w≤100).
  - Dòng cuối cùng chứa 2 số nguyên s và t.
  - Dữ liệu đầu vào được đảm bảo là đồ thị không chứa chu trình âm.
  - Luôn có đường đi từ s đến t.

Đầu ra (Output)
- In đường đi ngắn nhất từ s đến t theo mẫu:
```
s -> u1 -> u2 -> ... -> t
```

Gợi ý
- Lần ngược theo p[u] để có được đường đi ngắn nhất.
