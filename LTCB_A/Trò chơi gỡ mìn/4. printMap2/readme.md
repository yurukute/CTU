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
Hãy viết hàm `printMap2()` để in bản đồ mìn theo quy tắc (có quan tâm đến trạng thái đóng/mở của các ô):
- Nếu ô chưa mở => in ký tự ‘#’
- Ngược lại
    - Nếu ô đó chứa mìn => in ‘x’
    - Nếu xung quanh không có mìn => in ‘.’
    - Ngược lại => in giá trị B[i][j] của ô đó 

**Khuôn dạng (prototype)**
- Tên hàm: printMap2
- Tham số: không
- Kiểu trả về: void

**Thân hàm:**
- In bản đồ mìn B theo quy tắc trên.

**Chú ý**
- Dữ liệu đầu vào luôn hợp lệ.
- Chỉ viết HÀM, không viết TOÀN BỘ CHƯƠNG TRÌNH
- Phải in luôn chỉ số hàng và chỉ số cột

**Gợi ý**
- Xem slides
- In hàng đầu (chỉ số cột)
- Dùng vòng lặp in từng hàng, với mỗi hàng in chỉ số hàng, sau đó in theo các giá trị của B[i][j].