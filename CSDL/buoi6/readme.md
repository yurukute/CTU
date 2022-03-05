# Bài thực hành số 2
Cho lược đồ cơ sở dữ liệu sau:
- Khuvuc(**IP**, tenKhuvuc, tang)
- Phòng (**MP**, tenphong, somay , IP )
- May (**idMay**, tenmay, IP, ad, idloai, MP )Phanmem(idPM,  tenPM, ngaymua, version, idloai, gia )
- Caidat (**id**, idMay, idPM, ngaycai)
- Loai (**idloai**,   tenloai )

Chạy script đã thực hiện trong bài thực hành số 1 để tạo CSDL và thêm dữ liệu cho CSDL vừatạo. Viết script `hoten_bt2.sql` bao gồm các câu trả lời cho các câu hỏi sau:

1) Loại của máy 'p8'

2) Tên của các phần mềm 'UNIX'

3) Tên phòng, địa chỉ IP phòng, mã phòng của các máy loại 'UNIX' hoặc 'PCWS'

4) Tên phòng, địa chỉ IP phòng, mã phòng của các máy loại 'UNIX' hoặc 'PCWS' ở khu vực '130.120.80', sắp xếp kết quả tăng dần theo mã phòng

5) Số các phần mềm được cài đặt trên máy 'p6'

6) Số các máy đã cài phần mềm 'log1'

7) Tên và địa chỉ IP (ví dụ: 130.120.80.1) đầy đủ của các máy loại 'TX'

8) Tính số phần mềm đã cài đặt trên mỗi máy

9) Tính số máy mỗi phòng

10) Tính số cài lần cài đặt của mỗi phần mềm trên các máy khác nhau

11) Giá trung bình của các phần mềm UNIX

12) Ngày mua phần mềm gần nhất

13) Số máy có ít nhất 2 phần mềm

14) Số máy có ít nhất 2 phần mềm, sử dụng một select con trong mệnh đề FROM

**Các câu 15) và 17) viết bằng 2 cách : `SELECT con` và `OUTER JOIN`**

15) Tìm các loại không thuộc loại máy 

16) Tìm các loại thuộc cả hai loại máy và loại phần mềm

17) Tìm các loại máy không phải là loại phần mềm

**Viết các câu từ 18) đến 22) sử dụng `SELECT` lồng nhau**

18) Địa chỉ IP đầy đủ của các máy cài phần mềm 'log6'

19) Địa chỉ IP đầy đủ của các máy cài phần mềm tên 'Oracle 8'

20) Tên của các khu vực có chính xác 3 máy loại 'TX'

21) Tên phòng có ít nhất một máy cài phần mềm tên 'Oracle 6'

22) Tên phần mềm được mua gần nhất (sử dụng câu 12)

**Viết các câu từ 18) đến 21) sử dụng `JOIN`, đánh số cho các câu hỏi này từ 23) đến 26)**

27) Tên của máy có ít nhất một phần mềm chung với máy 'p6' -> kq: p2, p8, p1

28) Tên của phần mềm PCNT có giá lớn hơn bất kỳ giá của một phần mềm UNIX nào

29) Tên của phần mềm UNIX có giá lớn hơn tất cả các giá của các phần mềm PCNT

30) Tên của các máy có cùng phần mềm như máy 'p6' (có thể nhiều phần mềm hơn máy'p6') -> kq: p2, p8

31) Tên của các máy có chính xác các phần mềm như máy 'p2' ->  kq: p8
