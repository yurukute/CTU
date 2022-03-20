# Bài thực hành buổi 2
## Cơ bản về lập trình SHELL

### Bài 2 
Viết một script hiển thị các thông tin theo định dạng như sau:
```
\****************************************\ 
Today is: 
<thông tin ngày giờ hiện tại> 
Hello <tên người dùng đang đăng nhập> !!! 
Your current working directory: <thư mục hiện hành> 
Your home directory: <thư mục cá nhân> 
Please press any key to finish: <chờ nhận một phím>
                     Thank you very much!!
\****************************************\ 
```
### Bài 3
Viết một script cho phép truyền vào 2 số nguyên như tham số của shell, sau đó thực hiện phép cộng, trừ, nhân, chia và chia lấy dư của 2 số và in ra kết quả theo định dạng như sau: 
```
Tham so ban da truyen vao la 2 so: x  va  y 
Tong: x + y = <x+y> 
Hieu: x – y = <x-y> 
Tich: x * y = <x*y> 
Thuong: x / y = <x/y> 
So du: x % y = <x%y> 
```
### Bài 4
Viết một script tên `taothumuc` cho phép người dùng nhập vào tên thư mục muốn tạo và thực hiện việc tạo thư mục. Trường hợp tạo không thành công thì in ra câu thông báo: `Khong the tao duoc thu muc!!!`. 

*(ghi chú: sử dụng thêm lệnh if trong bài thực hành buổi 3)*

### Bài 5
Viết một script với tên `thuchien` nhận vào 2 tham số `cmd1` và `arg1`. Trong đó `cmd1` là lệnh cần thực hiện và `arg1` là tham số của lệnh. Khi script được thực hiện thì lệnh `cmd1` sẽ được thực hiện. 

Ví dụ: thuchien mkdir aaa sẽ thực hiện tạo thư mục aaa. 
