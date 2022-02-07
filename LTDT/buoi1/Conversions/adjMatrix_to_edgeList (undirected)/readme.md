Viết chương trình bằng ngôn ngữ C cho phép người nhập vào ma trận kề của một **đồ thị vô hướng** và in các cung của nó ra màn hình.

Đầu vào
- Dữ liệu đầu vào được đọc từ dòng nhập chuẩn (stdin, bàn phím) theo định dạng:
  - Dòng đầu tiên chứa 1 số nguyên n mô tả số đỉnh của đồ thị
  - n dòng tiếp theo mô tả ma trận kề của đồ thị. Mỗi dòng có n số nguyên, cách nhau 1 khoảng trắng.

Đầu ra
- In các cung của đồ thị vừa nhập ra màn hình, mỗi cung trên 1 dòng theo mẫu: u v (u≤v).
- Nếu có 2 cung (u1, v1) và (u2, v2) thì cung nào có u nhỏ sẽ được in ra trước. Nếu u bằng nhau thì cung nào có v nhỏ sẽ được in ra trước.

Chú ý
- Giả sử dữ liệu đầu vào luôn hợp lệ, không cần phải kiểm tra
- Nộp toàn bộ chương trình

Gợi ý
- Đọc n, đọc ma trận kề và lưu trực tiếp vào G.A
- Duyệt qua các ô của tam giác trên của ma trận kề G.A. Con số trong ô `G.A[u][v]` cho biết số cung đi từ u đến v.
