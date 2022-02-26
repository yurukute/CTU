# CT180 - Bài thực hành  - Buoi 5

Cho lược đồ cơ sở dữ liệu sau:
- Khuvuc(IP, tenKhuvuc, tang )
- Phong (MP, tenphong, somay , IP )
- May (idMay, tenmay, IP, ad, idloai, MP ) 
- Phanmem(idPM, tenPM, ngaymua, version, idloai, gia ) 
- Caidat (id, idMay, idPM, ngaycai)
- Loai (idloai, tenloai ) 

Chạy script đã thực hiện trong bài thực hành buổi truoc để tạo CSDL và thêm dữ liệu cho CSDL vừa tạo. Viết script `masv_buoi5.sql` để trả lời cho các câu hỏi sau: 

1)  Cho biet Loại của máy 'p8' 

2)  Tên của các phần mềm loai 'UNIX' 

3)  Tên phòng, địa chỉ IP phòng, mã phòng của các máy loại 'UNIX' hoặc 'PCWS' 

4)  Tên phòng, địa chỉ IP phòng, mã phòng của các máy loại 'UNIX' hoặc 'PCWS' ở khu vực '130.120.80', sắp xếp kết quả tăng dần theo mã phòng 

5)  Số các phần mềm được cài đặt trên máy 'p6' 

6)  Số các máy đã cài phần mềm 'log1' 

7)  Tên và địa chỉ IP (ví dụ: 130.120.80.1) đầy đủ của các máy loại 'TX' 

8)  Giá trung bình của các phần mềm UNIX

9)  Cho biet tên các phòng có cài phần mềm Oracle

10) Cho biết tên phần mềm đã cài ở phòng Salle 1

11) Cho biết tên các phần mềm đã mua trong năm 1997

12) Cho biết tên các phần mềm cài đặt trên các loại máy UNIX có giá từ 2000 trở lên
