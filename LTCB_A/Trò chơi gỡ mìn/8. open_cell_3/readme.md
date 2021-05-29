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
Hãy viết hàm **ĐỆ QUY** `open_cell_3(r, c)` để mở ô r, c theo quy tắc 3:
- Nếu ô (r, c) đã mở => return
- Ngược lại:
    - Mở ô (r, c)
    - Nếu B[r][c] == 0 (có nghĩa là 8 ô xung quanh nó không có mìn) gọi đệ quy mở 8 ô xung quanh nó theo quy tắc 3.

**Khuôn dạng (prototype)**
- Tên hàm: open_cell_3
- Tham số:
    - r: int
    - c: int
- Kiểu trả về: void

**Thân hàm:**
- Mở ô (r, c) và gọi để quy để mở 8 ô xung quanh nó.

**Chú ý**
- Dữ liệu đầu vào luôn hợp lệ.
- Chỉ viết HÀM, không viết TOÀN BỘ CHƯƠNG TRÌNH