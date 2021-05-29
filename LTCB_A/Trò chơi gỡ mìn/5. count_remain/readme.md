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
Hãy viết hàm `count_remain()` để đếm số ô chưa mở

**Khuôn dạng (prototype)**
- Tên hàm: count_remain
- Tham số: không
- Kiểu trả về: int

**Thân hàm:**
- Đếm và trả về số ô chưa mở (ô chưa mở là ô có T[i][j] == 0).

**Chú ý**
- Dữ liệu đầu vào luôn hợp lệ.
- Chỉ viết HÀM, không viết TOÀN BỘ CHƯƠNG TRÌNH