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
Hãy viết hàm `print_state(S)` để in trạng thái của trò chơi ra màn hình.

**Khuôn dạng (Prototype)**
- Tên hàm: print_state
- Tham số:
    - S: kiểu State - trạng thái cần in
- Kiểu trả về: void

**Thân hàm**
In trạng thái S theo mẫu:
- m dòng đầu tiên in bảng số. Ô trống in 2 dấu chấm (.)
- dòng cuối cùng in 2 số nguyên là vị trí hàng và cột của ô trống, cách nhau 1 khoảng trắng

**Chú ý**
- Dữ liệu đầu vào luôn hợp lệ, không cần kiểm tra
- Chỉ viết hàm KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
