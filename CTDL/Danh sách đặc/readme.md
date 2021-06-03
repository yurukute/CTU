# Danh sách đặc
Để biểu diễn danh sách đặc các phần tử người ta dùng 1 mảng 1 chiều lưu giữ giá trị các phần tử và một biến số nguyên chỉ số lượng phần tử thực tế được sử dụng trong mảng.

Hình ảnh của danh sách đặc như hình sau:

<img src="./dsdac.png">

Trong đó, Last là biến nguyên chỉ đến số phần tử trong danh sách, Maxlength là số phần tử tối đa trong mảng

Một số phép toán cơ bản trên danh sách đặc:
- makenullList(): Khởi tạo danh sách rỗng
- emptyList(): kiểm tra danh sách có rỗng hay không?
- fullList(): kiểm tra danh sách có đầy hay không?
- insertList(): xen phần tử x vào vị trí p trong danh sách
- deleteList(): xóa phần tử ở vị trí p trong danh sách
- locate(): tìm vị trí xuất hiện đầu tiên của phần tử x trong danh sách
- printList(): hiển thị giá trị các phần tử của danh sách
- readList(): nhập danh sách từ bàn phím