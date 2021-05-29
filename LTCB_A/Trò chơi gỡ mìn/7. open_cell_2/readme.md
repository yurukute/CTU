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
Hãy viết hàm `open_cell_2(r, c)` để mở ô r, c theo quy tắc 2:
- Mở ô (r, c).
- Nếu B[r][c] == 0 (có nghĩa là 8 ô xung quanh nó không có mìn) thì mở luôn 8 ô xung quanh nó.

**Khuôn dạng (prototype)**
- Tên hàm: open_cell_2
- Tham số:
    - r: int
    - c: int
- Kiểu trả về: void

**Thân hàm:**
- Mở ô (r, c) và xét để mở 8 ô xung quanh nó.

**Chú ý**
- Dữ liệu đầu vào luôn hợp lệ.
- Chỉ viết HÀM, không viết TOÀN BỘ CHƯƠNG TRÌNH
