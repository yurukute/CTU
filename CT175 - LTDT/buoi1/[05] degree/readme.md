# Bài tập 5. DSC: tổng hợp
## Câu 1
Cho chương trình có hàm main() như bên dưới. Hãy viết thêm khai báo CTDL Graph (biểu diễn đồ thị bằng phương pháp danh sách cung) và cài đặt các hàm cần thiết vào chỗ ba chấm (...) để có được chương trình hoàn chỉnh, chạy được.
```c
#include <stdio.h>

/* Bổ sung khai báo CTDL Graph và cài đặt các hàm cần thiết */
...
/* Hết phần mã lệnh của bạn */

//Hàm main()
int main() {
    Graph G;
    int n = 4, u;

    //Khởi tạo đồ thị
    init_graph(&G, n);
    //Thêm cung vào đồ thị
    add_edge(&G, 1, 2);
    add_edge(&G, 1, 3);
    add_edge(&G, 1, 3);
    add_edge(&G, 3, 4);
    add_edge(&G, 1, 4);

    //In bậc của các đỉnh
    for (u = 1; u <= n; u++)
        printf("deg(%d) = %d\n", u, degree(&G, u));
    return 0;
}
```
Chú ý
- Không nộp toàn bộ chương trình, chỉ nộp phần bạn viết.

## Câu 2
Viết chương trình bằng ngôn ngữ C cho phép người dùng nhập dữ liệu của một đồ thị và in bậc của các đỉnh ra màn hình.

Đầu vào
- Dữ liệu đầu vào được đọc từ dòng nhập chuẩn (stdin, bàn phím) theo định dạng:
  - Dòng đầu tiên chứa 2 số nguyên n và m cách nhau một khoảng trắng, n: số đỉnh, m: số cung
  - m dòng tiếp theo, mỗi dòng chứa 2 số nguyên u v cách nhau 1 khoảng trắng mô tả cung (u, v).

Đầu ra
- In ra n dòng, dòng thứ i in bậc của đỉnh i, theo mẫu: `deg(2) = 3`

Chú ý
- Giả sử dữ liệu đầu vào luôn hợp lệ, không cần phải kiểm tra
- Nộp toàn bộ chương trình

## Câu 3
Viết chương trình bằng ngôn ngữ C cho phép đọc dữ liệu của một đồ thị từ tập tin và in bậc của các đỉnh ra màn hình.

Đầu vào
- Dữ liệu đầu vào được đọc từ tập tin dt.txt (cùng thư mục với chương trình thực thi) theo định dạng:
  - Dòng đầu tiên chứa 2 số nguyên n và m cách nhau một khoảng trắng, n: số đỉnh, m: số cung
  - m dòng tiếp theo, mỗi dòng chứa 2 số nguyên u v cách nhau 1 khoảng trắng mô tả cung (u, v).

Đầu ra
- In ra n dòng, dòng thứ i in bậc của đỉnh i, theo mẫu: deg(2) = 3

Chú ý
- Giả sử dữ liệu đầu vào luôn hợp lệ, không cần phải kiểm tra
- Nộp toàn bộ chương trình

