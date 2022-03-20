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
Cho trước khai báo của kiểu DaThuc như trên. Hàm `DaThuc khoitao()` cũng được cho sẵn để trả về 1 danh sách rỗng.

Hãy viết hàm chèn một đơn thức vào 1 đa thức cho trước. Lưu ý là hàm chèn này phải đảm bảo các bậc của đơn thức được lưu trữ giảm dần.

**Nguyên mẫu**
- Tên hàm: `chenDonThuc()`
- Tham số: 
	- s: DonThuc
	- pD: con trỏ DaThuc
- Kiểu trả về: không

**Thân hàm**
- Chèn đơn thức s vào đa thức chỉ bởi con trỏ pD sao cho các bậc của các đơn thức được lưu trữ giảm dần trong đa thức.

**Chú ý**
- Chỉ viết khai báo, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH

**Gợi ý**
- Tìm vị trí p cần thêm đơn thức s vào. Vị trí p này là vị trí đầu tiên trong đa thức mà ở đó có bậc <= bậc của đơn thức s.
- Nếu tìm thấy vị trí p như trên, có 2 khả năng:
	- Bậc tại p == bậc đơn thức s --> Gom hệ số lại
	- Bậc tại p < bậc đơn thức s -> chèn s vào vị trí p
- Nếu tìm không thấy vị trí p  -> chèn x vào vị trí p trả về khi thực hiện tìm kiếm ở trên.
