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
Cho trước khai báo của kiểu DaThuc như trên. Các hàm sau đây cũng được cho trước:
- void inDaThuc(DaThuc d): hiển thị đa thức d lên màn hình
- DaThuc khoitao(): khởi tạo và trả về một đa thức rỗng
- void chenDonThuc(DonThuc x, DaThuc *pD): chèn đơn thức x vào đa thức chỉ bởi con trỏ pD
- DaThuc nhapDaThuc(): trả về 1 đa thức nhập từ bàn phím

Viết hàm cho phép tính đạo hàm 1 đa thức

**Nguyên mẫu (Prototype)**
- Tên hàm: tinhDaoHam()
- Tham số: 
  - D: DaThuc
- Kiểu trả về: DaThuc

**Thân hàm (Body)**
- Trả về đa thức đạo hàm của đa thức D

**Chú ý**
- Chỉ viết phần hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH

**Gợi ý**
- Khởi tạo đa thức kết quả là rỗng
- Duyệt qua đa thức D
  - Giả sử mỗi lần ta được 1 đơn thức e của đa thức D
  - Tính lại hệ số và bậc của đơn thức e trong đa thức đạo hàm (hệ số mới = hệ số cũ * bậc; bậc giảm 1); rồi chèn đơn thức e vào đa thức kết quả
