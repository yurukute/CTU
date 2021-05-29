Cho 2 mảng toàn cục B và T dùng để lưu bản đồ mìn và trạng thái đóng/mở của các ô trong trò chơi MineSweeper.
```cpp
#define M 5
#define N 5
#define MINE -1
/*Mảng B lưu bảng đồ mìn*/
int B[M][N];
/*Mảng T lưu trạng thái các ô*/
int T[M][N];
```
Hãy viết hàm `count_mines()` để đếm số ô chứa mìn xung quanh các ô của bảng B.

Ví dụ: giả sử bảng đồ mìn B được khởi tạo như sau:

<img src="https://github.com/yurukute/CTU/blob/main/LTCB_A/Trò chơi gỡ mìn/images/init.png" width="250">

thì kết quả của việc đếm số mìn trong 8 ô xung quanh của mỗi ô sẽ như bên dưới:

<img src="https://github.com/yurukute/CTU/blob/main/LTCB_A/Trò chơi gỡ mìn/images/count-mine.png" width="250">

Trong 8 ô xung quanh ô (2, 1) có 2 trái mìn (ở ô (3,1) và (-1,2))

**Khuôn dạng (prototype)**
- Tên hàm: count_mines
- Tham số: không
- Kiểu trả về: void

**Thân hàm:**
- Đếm số mìn trên mảng B và ghi kết quả vào mảng B luôn.

**Chú ý**
- Dữ liệu đầu vào luôn hợp lệ.
- Chỉ viết HÀM, không viết TOÀN BỘ CHƯƠNG TRÌNH