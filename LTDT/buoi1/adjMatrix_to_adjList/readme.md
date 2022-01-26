Viết chương trình bằng ngôn ngữ C cho phép người nhập vào ma trận kề của một đồ thị vô hướng và in danh sách kề của các đỉnh ra màn hình.

Đầu vào
- Dữ liệu đầu vào được đọc từ dòng nhập chuẩn (stdin, bàn phím) theo định dạng:
  - Dòng đầu tiên chứa 1 số nguyên n mô tả số đỉnh của đồ thị
  - n dòng tiếp theo mô tả ma trận kề của đồ thị. Mỗi dòng có n số nguyên, cách nhau 1 khoảng trắng.

Đầu ra
- In ra n dòng, mỗi dòng tương ứng với một danh sách kề.
- Dòng thứ i, in danh sách các đỉnh kề của đỉnh i. Liệt kê các đỉnh kề (có lặp lại) của i theo thứ tự tăng dần, cách nhau 1 khoảng trắng, kết thúc danh sách in thêm số 0, cách phần tử cuối cùng 1 khoảng trắng. Nếu danh sách kề của đỉnh i rỗng, chỉ in số 0 mà thôi.

Chú ý
- Giả sử dữ liệu đầu vào luôn hợp lệ, không cần phải kiểm tra
- Nộp toàn bộ chương trình

Gợi ý
- Đọc n, đọc ma trận kề và lưu trực tiếp vào G.A
- Duyệt qua các ô của ma trận kề G.A. Con số trong ô `G.A[u][v]` cho biết số cung đi từ u đến v.
