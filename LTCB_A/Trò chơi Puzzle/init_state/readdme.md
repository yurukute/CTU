Trong trò chơi đẩy ô, ta khai báo cấu trúc State để lưu trạng thái của trò chơi như sau:
```cpp
#define MAX_M 100
#define MAX_N 100

typedef struct {
	int m, n;
	int A[MAX_M][MAX_N];
	int r, c;
} State;
```
Hãy viết hàm `init_state(S, fname)` để đọc trạng thái của trò chơi từ một tập tin (tên fname) và lưu vào trong biến trạng thái S.

**Khuôn dạng (Prototype)**
- Tên hàm: init_state
- Tham số:
    - S: con trỏ trỏ đến State - lưu trữ trạng thái
    - fname: chuỗi ký tự - tên file đầu vào
- Kiểu trả về: void

**Thân hàm**

Đọc dữ liệu từ file văn bản fname và lưu vào cấu trúc mà S trỏ đến. Định dạng file đầu vào như sau:
- Dòng đầu tiên chứa 2 số nguyên m, n cách nhau 1 khoảng trắng - kích thước bảng số.
- m dòng tiếp theo, mỗi dòng chứa n con số - tương ứng với bảng ô số
- Dòng cuối cùng chứa 2 số nguyên r, c cách nhau một khoảng trắng - hàng và cột của ô trống (ô chứa số m*n)

**Chú ý**
- Dữ liệu đầu vào luôn hợp lệ, không cần kiểm tra
- Chỉ viết hàm KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
