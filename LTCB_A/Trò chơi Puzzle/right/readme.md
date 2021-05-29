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
Hãy viết hàm `right(S, N)` đẩy ô trống đi qua phải.

**Khuôn dạng (Prototype)**
- Tên hàm: right
- Tham số:
    - S: kiểu State - trạng thái hiện tại
    - N: kiểu con trỏ State. *N dùng để lưu tữ trạng thái mới
- Kiểu trả về: int

**Thân hàm**
- Di chuyển ô trống qua phải 1 ô. Lưu trạng thái mới vào cấu trúc trạng thái mà N trỏ đến.
- Nếu di chuyển được trả về 1, nếu không trả về 0.

**Chú ý**
- Dữ liệu đầu vào luôn hợp lệ, không cần kiểm tra
- Chỉ viết hàm KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
- Xem thêm mẫu in ra trong phần For example.

**Gợi ý**
- Kiểm tra vị trí cột của ô trống trước khi di chuyển
- Copy nội dung của S vào *N. Thực hiện di chuyển trên *N.