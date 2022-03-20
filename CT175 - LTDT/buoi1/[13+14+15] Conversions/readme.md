# Chuyển đổi giữa các PP biểu diễn
## Câu 1
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

## Câu 2
Viết chương trình bằng ngôn ngữ C cho phép người nhập vào ma trận kề của một **đồ thị có hướng** và in các cung của nó ra màn hình.

Đầu vào
- Dữ liệu đầu vào được đọc từ dòng nhập chuẩn (stdin, bàn phím) theo định dạng:
  - Dòng đầu tiên chứa 1 số nguyên n mô tả số đỉnh của đồ thị
  - n dòng tiếp theo mô tả ma trận kề của đồ thị. Mỗi dòng có n số nguyên, cách nhau 1 khoảng trắng.

Đầu ra
- In các cung của đồ thị vừa nhập ra màn hình, mỗi cung trên 1 dòng theo mẫu: u v.
- Nếu có 2 cung (u1, v1) và (u2, v2) thì cung nào có u nhỏ sẽ được in ra trước. Nếu u bằng nhau thì cung nào có v nhỏ sẽ được in ra trước.

Chú ý
- Giả sử dữ liệu đầu vào luôn hợp lệ, không cần phải kiểm tra
- Nộp toàn bộ chương trình

Gợi ý
- Đọc n, đọc ma trận kề và lưu trực tiếp vào G.A
- Duyệt qua các ô của ma trận kề G.A. Con số trong ô `G.A[u][v]` cho biết số cung đi từ u đến v.

## Câu 3 + 4
Viết chương trình bằng ngôn ngữ C cho phép người nhập vào ma trận kề của một **đồ thị vô hướng** (**đồ thị có hướng**) và in danh sách kề của các đỉnh ra màn hình.

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

## Câu 5 + 6
Viết chương trình bằng ngôn ngữ C cho phép người nhập vào danh sách kề của các đỉnh trong một **đồ thị vô hướng** (**đồ thị có hướng**) và in ma trận kề của nó màn hình.

Đầu vào
- Dữ liệu đầu vào được đọc từ dòng nhập chuẩn (stdin, bàn phím) theo định dạng:
  - Dòng đầu tiên chứa 1 số nguyên n mô tả số đỉnh của đồ thị
  - n dòng tiếp, mỗi dòng mô tả một danh sách kề. Dòng i chứa danh sách các đỉnh kề của đỉnh i. Các phần tử cách nhau một khoảng trắng. Mỗi dòng đều kết thúc bằng số 0.

Đầu ra
- In ra ma trận kề của đồ thị gồm n dòng, mỗi dòng chứa n phần tử, cách nhau 1 một khoảng trắng.

Chú ý
- Giả sử dữ liệu đầu vào luôn hợp lệ, không cần phải kiểm tra
- Nộp toàn bộ chương trình

Gợi ý
- Đọc n, khởi tạo đồ thị
- Đọc n danh sách kề. Với danh sách kề của đỉnh u, phần tử v của nó cho biết ta đang có cung (u, v). Chú ý, đối với đồ thị vô hướng, cung (u, v) được lưu 2 hai chỗ: v được lưu trong danh sách đỉnh kề của u và đỉnh u được lưu trong đỉnh kề của v.
- Khi đọc danh sách, sử dụng vòng lặp while (1), đọc cho tới khi gặp số 0 thì thoát vòng lặp (break).
