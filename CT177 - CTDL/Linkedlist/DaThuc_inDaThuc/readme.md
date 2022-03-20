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
Cho trước khai báo của kiểu DaThuc như trên.
- Hàm `DaThuc khoitao()` cũng được cho sẵn để trả về 1 danh sách rỗng.
- Hàm `void chenDonThuc(DonThuc e, DaThuc *pD)`: chèn đơn thức e vào đa thức chỉ bởi con trỏ pD. Hàm này cũng được hỗ trợ.

Hãy viết hàm hiển thị một đa thức lên màn hình.

**Nguyên mẫu**
- Tên hàm: `inDaThuc()`
- Tham số: 
  - d: DaThuc
- Kiểu trả về: không

**Thân hàm**
- Duyệt qua đa thức d và hiển thị từng bộ (hệ số, bậc) lên màn hình

**Chú ý**
- Chỉ viết khai báo, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
