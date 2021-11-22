Cây cây tìm kiếm nhị phân mỗi khóa là 1 số nguyên được khai báo như sau:
```c
struct Node{

      int Key;

      struct Node *Left, *Right;

};
```
Cho trước các phép toán:
- `void insertNode(int x, Tree *pT)`: thêm khóa x vào cây tìm kiếm nhị phân có gốc chỉ bởi con trỏ pT

Viết hàm tính chiều cao của nút có khóa x trong cây T

Nguyên mẫu (Prototype)
- Tên hàm: hNode()
- Tham số: 
	- x - int
	- T -  Tree
- Kiểu trả về: int

Thân hàm (Body)
- Nếu x không có trong cây, kết quả trả về là -1, ngược lại kết quả trả về là chiều cao của nút có khóa là x

Chú ý
- Chỉ viết hàm, KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH

Gợi ý: Chiều cao một nút là độ dài đường đi từ nút đó đến nút lá xa nhất
