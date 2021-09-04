Đa thức là một biểu thức đại số gồm nhiều đơn thức, ví dụ:

2x3+5x2−3x+1 

Như thế, để biểu diễn một đa thức ta cần lưu các đơn thức có trong đa thức này.

Cho cấu trúc DonThuc dùng để lưu trữ một đơn thức như sau:
```cpp
typedef struct {
    double he_so;
    int bac;
} DonThuc;
```
Ta có thể biểu diễn một đa thức bằng một danh sách liên kết các đơn thức. Trong danh sách này các đơn thức được lưu trữ theo thứ tự giảm dần của bậc. Khi đó đa thức là một kiểu dữ liệu có khai báo như sau:
```cpp
struct Node{
    DonThuc e;
    struct Node* Next;
};
typedef struct Node* Position;
typedef Position DaThuc;
```
Cho trước khai báo của kiểu DaThuc như trên. Viết hàm khởi tạo và trả về một đa thức rỗng.

**Nguyên mẫu (Prototype)**
- Tên hàm: khoitao()
- Tham số: không
- Kiểu trả về: DaThuc

**Thân hàm (Body)**
- Khai báo một đa thức d, khởi tạo đa thức này và trả về kết quả cho hàm

**Chú ý**
- Chỉ viết khai báo, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
- Xem thêm chi tiết trong phần For example.

**Gợi ý**
- Cấp phát 1 vùng nhớ mới và cho trường liên kết (Next) của vùng nhớ này chỉ tới NULL.

**Chú ý**
- Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
