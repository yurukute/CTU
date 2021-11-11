# Bài thực hành buổi 4
## Quản lý tiến trình, tín hiệu và đồng bộ

### Bài 7
Tạo một shell script có tên `uncount` hiển thị dãy chữ số :

6         5         4         3         2         1

trong các khoãng thời gian 5 giây (hiển thị một số/5giây), mà nếu ta gõ phím `DEL` thì nó sẽ hiển thị chữ số kế tiếp 

### Bài 11
Hãy viết shell script :   `LisFileDel  file1    file2`

Chức năng: 
- hiển thị nội dung các tập tin có tên trong danh sách đối số
- nếu gõ phím `DEL`, bỏ qua tập tin đang hiển thị, bắt đầu tập tin kế tiếp 
- khôi phục chức năng mặc định của phím `DEL` khi kết thúc 

### Bài 12
Hãy viết shell script :   `trap2` 

Chức năng: 
- thực hiện một chu trình hiển thị một thông báo: `Shutdown in n minutes` n có giá trị từ 5 đến 1 
- mỗi khi gõ phím DEL, lập tức hiển thị thông báo tiếp theo 
- khôi phục chức năng mặc định của phím `DEL` khi kết thúc 
