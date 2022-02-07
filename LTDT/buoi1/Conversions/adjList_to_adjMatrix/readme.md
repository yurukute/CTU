Viết chương trình bằng ngôn ngữ C cho phép người nhập vào danh sách kề của các đỉnh trong một đồ thị vô hướng và in ma trận kề của nó màn hình.

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
