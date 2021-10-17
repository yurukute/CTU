Cây cây tìm kiếm nhị phân mỗi khóa là 1 số nguyên được khai báo như sau:
```c
struct Node{

      int Key;

      struct Node *Left, *Right;

};
```
Viết hàm kiểm tra cây có gốc là T có rỗng hay không?

**Nguyên mẫu (Prototype)**
- Tên hàm: isEmpty()
- Tham số: T - Tree
- Kiểu trả về: int

**Thân hàm (Body)**
- Nếu cây T rỗng, kết quả trả về là 1, ngược lại kết quả trả về là 0

**Chú ý**
- Chỉ viết hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
