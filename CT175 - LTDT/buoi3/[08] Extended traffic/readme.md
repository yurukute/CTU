# Bài tập 8 - Extended traffic
Extended traffic (sửa lại từ: https://lightoj.com/problem/extended-traffic )

Thành phố Dhaka ngày càng đông dân và ồn ào hơn. Một số con đường luôn đông nghẹt và kẹt xe. Để thuyết phục người dân tránh đi các tuyến đường ngắn nhất để giảm tải cho các con đường, thị trưởng thành phố đã lập một kế hoạch như sau. Mỗi giao lộ u của thành phố được gán 1 con số nguyên dương (không quá 20)  cho biết mức độ bận rộn (busy-ness) của giao lộ này, kí hiệu là b[u]. Mỗi khi một người dân đi từ giao lộ u đến một giao lộ v, thành phố sẽ có thêm một lượng bận rộn là (b[v]−b[u])<sup>3<sup>.

Thị trưởng nhờ bạn kiểm tra xem nếu một người đi từ giao lộ s đến giao lộ t, anh ta sẽ làm tăng thêm một lượng bận rộn ít nhất là bao nhiêu.

Đầu vào (Input)
- Dữ liệu đầu vào được nhập từ dòng nhập chuẩn (bàn phím, stdin) với định dạng:
  - Dòng đầu tiên chứa 2 số nguyên n và m tương ứng là số giao lộ và số con đường nối hai giao lộ lại với nhau.
  - Dòng thứ hai chứa n số nguyên mô tả độ bận rộn b[u] của các giao lộ.
  - m dòng tiếp theo mỗi dòng chứa 2 số nguyên u, v nói rằng có một con đường nối hai giao lộ u và v. Tất cả các con đường đều là đường 1 chiều.
  - Dòng cuối cùng chứa 2 số nguyên s và t.

Đầu ra (Output)
- In ra màn hình lượng bận rộn ít nhất khi 1 người đi từ giao lộ s đến giao lộ t. Nếu không có đường đi thì in ra ?

Gợi ý
- Đưa bài toán về đồ thị có hướng có trọng số
- Tìm đường đi ngắn nhất từ s đến t
