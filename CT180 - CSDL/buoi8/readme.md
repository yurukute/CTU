# Bài thực hành số 4
Cho lược đồ cơ sở dữ liệu về phim như sau:
- CANHAN (idCN , ho, ten)
- FILM (idFilm, tua, nguoithuchien, kinhphi)
- DIENVIEN (idFilm, idCN, thulao)
- LOAI (idLoai, tenloai) ;
- LOAIPHIM (idFilm, idLoai)

## Câu 1
Chạy script CSDLFilm.sql để tạo CSDL và thêm dữ liệu cho CSDL vừa tạo.
## Câu 2
Viết script hoten_bt4.sql bao gồm các câu trả lời cho các câu hỏi sau:

1. Danh sách tất cả các bộ phim có khinh phí lớn hơn 1 triệu
2. Tên Loại của bộ phim tựa 'IMPORTANCE OF BEING ERNEST'
3. Tựa và kinh phí của các bộ phim thuộc thể loại 'SCIENCE FICTION' và có kinh phí lớn
hơn 800,000 và nhỏ hơn 1 triệu. Sắp kết quả tăng dần theo kinh phí.
4. Tên đầy đủ (ghép họ và tên), thù lao của các diễn viên đã tham gia bộ phim 'MARK OF
THE DEVIL'. Sắp kết quả giảm dần theo thù lao
5. Tên đầy đủ (ghép họ và tên. của người đã thực hiện bộ phim 'ONCE A THIEF'
6. Tên các bộ phim bao gồm từ 'IMPOSSIBLE'
7. Thông tin về các bộ phim do viễn viên 'WILDE CORNEL' đóng. Sắp kết quả tăng dần
theo họ và tên người thực hiện.
8. Tựa các bộ phim do 'WILSON HUGH'
9. Họ tên cá nhân đã tham gia ít nhất 1 bộ phim do họ thực hiện
10. Họ tên cá nhân đã tham gia ít nhất 10 bộ phim do họ thực hiện
11. Tổng thù lao đã trả cho bộ phim 'TALE OF TWO CITIES'
12. Số phim mỗi thể loại
13. Tên loại có nhiều phim nhất
14. Kinh phí trung bình của phim theo người thực hiện
15. Họ tên người thực hiện đã thực hiện hơn 50 bộ phim
16. Họ tên người thực hiện thực hiện nhiều phim nhất
17. Họ tên diễn viên đã tham gia hơn 50 bộ phim
18. Họ tên diễn viên tham gia nhiều phim nhất
19. Tên bộ phim có kinh phí thực hiện cao nhất
20. Tên bộ phim có kinh phí thực hiện thấp nhất
21. Tên bộ phim đã trả thu lao cao nhất cho một diễn viên nào đó
22. Tên phim, kinh phí thực hiện và tổng thù lao đã trả cho các diễn viên của mỗi phim
23. Họ tên, số lần tham gia và tổng thù lao đã nhận của mỗi diên viên có tổng thù lao lớn
hơn 800.000
24. Tìm tên thể loại và trung bình khinh phí của mỗi thể loại mà có trung bình kinh phí lớn
hơn 500 triệu
25. Cho mỗi phim mà 'BALIN MIREILLE' đã tham gia đóng phim, hãy cho biết tổng thù lao
đã trả cho các diễn viên
26. Tìm họ tên các diễn viên, họ tên người thực hiện của bộ phim 'RESULTADO FINAL'
27. Họ tên diễn viên được trả thù lao cao nhất từ một bộ phim nào đó
28. Họ tên diễn viên có tổng thu lao thấp nhất
29. Tính số cá nhân đã tham gia đóng phim
30. Tính số cá nhân đã thực hiện phim
31. Tính số cá nhân vừa đóng phim vừa thực hiện phim
32. Tính số cá nhân chỉ đóng phim
33. Tính số cá nhân chỉ thực hiện phim
34. Tính số cá nhân không đóng phim cũng không thực hiện phim
35. Những diễn viên nào đã tham gia ít nhất là một phim giống như diễn viên
'LANCASTER BURT'
36. Những diễn viên nào đã tham gia ít nhất là tất cả các phim mà diễn viên 'RIVA
EMMANUELLE' đã tham gia đóng phim
37. Ai đã tham gia tất cả các phim do 'BIVEL' thực hiện
