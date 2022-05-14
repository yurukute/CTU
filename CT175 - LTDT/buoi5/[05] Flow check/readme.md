# Bài 5.5. Kiểm tra luồng hợp lệ
Cho mạng được biểu diễn bằng đồ thị n đỉnh, m cung. Đỉnh phát s = 1 và đỉnh thu t = n. Mỗi cung (u, v) có khả năng thông qua là `C[u][v]` và luồng đi qua nó là `F[u][v]`. Để tìm luồng lớn nhất trên mạng bằng giải thuật Ford - Fulkerson, ta phải khởi tạo một luồng hợp lệ nào đó trên mạng và sau đó tìm cách tăng luồng.

Luồng hợp lệ phải thoả mãn các yêu cầu sau:
- 0 <= `F[u][v]` <= `C[u][v]`, với mọi cung (u, v)
- Tổng luồng đi ra khỏi đỉnh s = Tổng luồng đi vào đỉnh t
- Tổng luồng đi vào đỉnh u = Tổng luồng đi ra khỏi u (u khác s và u khác t)

Luồng tầm thường (trivial flow) là luồng có `F[u][v] = 0` với mọi cung (u,v). Dĩ nhiên luồng tầm thường là luồng hợp lệ.

Giả sử người ta đã khởi tạo giá trị cho các luồng `F[u][v]` trên mạng, hãy viết chương trình kiểm tra xem luồng khởi tạo có hợp lệ không.

Đầu vào (Input)
- Dữ liệu đầu vào được nhập từ bàn phím với định dạng:
  - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung.
  - m dòng tiếp theo mỗi dòng chứa 3 số nguyên u v c f mô tả cung (u, v) có khả năng thông qua c và luồng khởi tạo f.

Đầu ra (Output):
- Nếu luồng khởi tạo của mạng hợp lệ, in ra màn hình YES, ngược lại in ra NO.
