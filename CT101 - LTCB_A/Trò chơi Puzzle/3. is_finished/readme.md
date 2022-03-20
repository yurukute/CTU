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
Hãy viết hàm `is_finished(S)` để kiểm tra S có phải là trạng thái kết thúc không.

**Khuôn dạng (Prototype)**
- Tên hàm: is_finished
- Tham số:
    - S: kiểu State - trạng thái kiểm tra
- Kiểu trả về: int

**Thân hàm**
- Nếu S là trạng thái kết thúc trả về 1, ngược lại trả về 0.

**Chú ý**
- Dữ liệu đầu vào luôn hợp lệ, không cần kiểm tra
- Chỉ viết hàm KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH

**Gợi ý**
- Kiểm tra xem ô (i, j) có phải đang chứa giá trị i*n + j + 1 không.
