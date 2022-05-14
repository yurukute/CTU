# 
Viết chương trình đọc đồ thị vô hướng liên thông và tìm cây khung có trọng số nhỏ nhất bằng thuật toán Kruskal.

Đầu vào
- Dữ liệu đầu vào được nhập từ bàn phím với định dạng:
  - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung.
  - m dòng tiếp theo mỗi dòng chứa 3 số nguyên u, v, w mô tả cung (u, v) có trọng số w.

Đầu ra
- In ra màn hình trọng số của cây khung tìm được và danh sách các cung theo thứ tự tăng dần của trọng số.
- Các cung được in theo định dạng:
```
  u v w
```
với (u < v), mỗi cung trên 1 dòng. Nếu hai cung có trọng số bằng nhau thì cung nào có u nhỏ hơn sẽ được in trước. Nếu có trọng số bằng nhau và u giống nhau thì cung nào có v nhỏ hơn sẽ in trước.

