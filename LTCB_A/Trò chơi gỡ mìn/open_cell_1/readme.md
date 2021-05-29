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
Hãy viết hàm `open_cell_1(r, c)` để mở ô r, c theo quy tắc 1: chỉ quan tâm đến ô này, không quan tâm đến các ô khác.

**Khuôn dạng (prototype)**
- Tên hàm: open_cell_1
- Tham số:
    - r: int
    - c: int
- Kiểu trả về: void

**Thân hàm:**
- Kiểm tra trạng thái ô (r, c) và đặt trạng thái nó là mở.

**Chú ý**
- Dữ liệu đầu vào luôn hợp lệ.
- Chỉ viết HÀM, không viết TOÀN BỘ CHƯƠNG TRÌNH