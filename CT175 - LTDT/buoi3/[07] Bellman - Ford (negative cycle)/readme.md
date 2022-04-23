# Bài tập 7 - Thuật toán Bellman - Ford (kiểm tra chu trình âm)
Viết chương trình đọc vào một đơn đồ thị có hướng, có trọng số, áp dụng thuật toán Bellman – Ford kiểm tra xem nó có chứa chu trình âm hay không khi ta tìm đường đi ngắn nhất từ đỉnh s đến các đỉnh còn lại.

Đầu vào (Input)
- Dữ liệu đầu vào được nhập từ dòng nhập chuẩn (bàn phím, stdin) với định dạng:
  - Dòng đầu tiên chứa 2 số nguyên n và m tương ứng là số đỉnh và số cung.
  - m dòng tiếp theo mỗi dòng chứa 3 số nguyên u, v, w nói rằng cung (u, v) có trọng số w.
  - Dòng cuối cùng chứa đỉnh s.

Đầu ra (Output)
- In ra màn hình YES nếu phát hiện có chu trình âm, ngược lại in ra NO.

Chú ý
- Nếu không có đường đi từ s đến u thì không tính các chu trình âm chứa u.
