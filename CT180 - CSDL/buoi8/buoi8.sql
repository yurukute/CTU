-- Câu 1: Danh sách tất cả các bộ phim có khinh phí lớn hơn 1 triệu
SELECT tua
FROM FILM
WHERE kinhphi > 1000000;

-- Câu 2: Tên Loại của bộ phim tựa 'IMPORTANCE OF BEING ERNEST'
SELECT tenloai
FROM LOAI
JOIN LOAIPHIM ON LOAI.idloai = LOAIPHIM.idLoai
JOIN FILM ON FILM.idFilm = LOAIPHIM.idFilm
WHERE tua = 'IMPORTANCE OF BEING ERNEST';

-- Câu 3: Tựa và kinh phí của các bộ phim thuộc thể loại 'SCIENCE FICTION' và có kinh phí lớn hơn 800,000 và nhỏ hơn 1 triệu. Sắp kết quả tăng dần theo kinh phí.
SELECT tua,
       kinhphi
FROM FILM
JOIN LOAIPHIM ON FILM.idfilm = LOAIPHIM.idfilm
JOIN LOAI ON LOAI.idloai = LOAIPHIM.idloai
WHERE (tenloai = 'SCIENCE FICTION' AND kinhphi > 800000 AND kinhphi < 1000000)
ORDER BY kinhphi;

-- Câu 4: Tên đầy đủ (ghép họ và tên), thù lao của các diễn viên đã tham gia bộ phim 'MARK OF THE DEVIL'. Sắp kết quả giảm dần theo thù lao
SELECT concat (ho, concat (' ', ten)) hoten,
       thulao
FROM CANHAN
JOIN DIENVIEN ON canhan.idcn = DIENVIEN.idcn
JOIN FILM ON FILM.idfilm = DIENVIEN.idfilm
WHERE tua = 'MARK OF THE DEVIL'
ORDER BY thulao DESC;

-- Câu 5: Tên đầy đủ (ghép họ và tên) của người đã thực hiện bộ phim 'ONCE A THIEF'
SELECT concat (ho, concat (' ', ten)) hoten
FROM CANHAN
JOIN FILM ON CANHAN.idCN = FILM.nguoithuchien
WHERE tua = 'ONCE A THIEF';

-- Câu 6: Tên các bộ phim bao gồm từ 'IMPOSSIBLE'
SELECT tua
FROM FILM
WHERE tua LIKE '%IMPOSSIBLE%';

-- Câu 7: Thông tin về các bộ phim do viễn viên 'WILDE CORNEL' đóng. Sắp kết quả tăng dần theo họ và tên người thực hiện.
SELECT idfilm, tua, ho ho_nguoi_thuc_hien, ten ten_nguoi_thuc_hien, kinhphi
FROM FILM
JOIN CANHAN ON FILM.nguoithuchien = CANHAN.idCN
WHERE idfilm IN (
    SELECT idfilm
    FROM DIENVIEN
    WHERE idCN = (
        SELECT idCN
        FROM CANHAN
        WHERE (ho = 'WILDE' AND ten = 'CORNEL')
    )
) ORDER BY ho, ten;

-- Câu 8: Tựa các bộ phim do 'WILSON HUGH'
SELECT tua
FROM FILM
JOIN CANHAN ON FILM.nguoithuchien = CANHAN.idcn
WHERE ho = 'WILSON' AND ten = 'HUGH';

-- Câu 9: Họ tên cá nhân đã tham gia ít nhất 1 bộ phim do họ thực hiện
SELECT ho,
       ten
FROM CANHAN
WHERE idcn IN (
    SELECT idcn
    FROM FILM
    JOIN DIENVIEN ON FILM.idfilm = DIENVIEN.idfilm
    WHERE nguoithuchien = idcn
);

-- Câu 10: Họ tên cá nhân đã tham gia ít nhất 10 bộ phim do họ thực hiện
SELECT ho,
       ten
FROM CANHAN
WHERE idcn IN (
    SELECT idcn
    FROM FILM
    JOIN DIENVIEN ON FILM.idfilm = DIENVIEN.idfilm
    WHERE nguoithuchien = idcn
    GROUP BY idcn
    HAVING COUNT (*) >= 10
);

-- Câu 11: Tổng thù lao đã trả cho bộ phim 'TALE OF TWO CITIES'
SELECT SUM (thulao)
FROM DIENVIEN
JOIN FILM ON DIENVIEN.idfilm = FILM.idfilm
WHERE tua = 'TALE OF TWO CITIES';

-- Câu 12: Số phim mỗi thể loại
SELECT tenloai,
       COUNT (*)
FROM LOAIPHIM
JOIN LOAI ON LOAIPHIM.idloai = LOAI.idloai
GROUP BY tenloai;

-- Câu 13: Tên loại có nhiều phim nhất
SELECT tenloai
FROM LOAI
JOIN LOAIPHIM ON LOAI.idloai = LOAIPHIM.idloai
GROUP BY tenloai
HAVING COUNT (*) = (
    SELECT MAX (COUNT (*))
    FROM LOAI
    JOIN LOAIPHIM ON LOAI.idloai = LOAIPHIM.idloai
    GROUP BY tenloai
);

-- Câu 14: Kinh phí trung bình của phim theo người thực hiện
SELECT ho,
       ten,
       AVG (kinhphi)
FROM FILM
JOIN CANHAN ON FILM.nguoithuchien = CANHAN.idcn
GROUP BY ho,
         ten;

-- Câu 15: Họ tên người thực hiện đã thực hiện hơn 50 bộ phim
SELECT ho,
       ten
FROM FILM
JOIN CANHAN ON FILM.nguoithuchien = CANHAN.idcn
GROUP BY ho,
         ten
HAVING COUNT (*) > 50;

-- Câu 16: Họ tên người thực hiện thực hiện nhiều phim nhất
SELECT ho,
       ten
FROM FILM
JOIN CANHAN ON FILM.nguoithuchien = CANHAN.idcn
GROUP BY ho,
         ten
HAVING COUNT (*) = (
    SELECT MAX (COUNT (*))
    FROM FILM
    JOIN CANHAN ON FILM.nguoithuchien = CANHAN.idcn
    GROUP BY nguoithuchien
);

-- Câu 17: Họ tên diễn viên đã tham gia hơn 50 bộ phim
SELECT ho,
       ten
FROM FILM
JOIN DIENVIEN ON FILM.idfilm = DIENVIEN.idfilm
JOIN CANHAN ON DIENVIEN.idcn = CANHAN.idcn
GROUP BY ho,
         ten
HAVING COUNT (*) > 50;

-- Câu 18: Họ tên diễn viên tham gia nhiều phim nhất
SELECT ho,
       ten
FROM FILM
JOIN DIENVIEN ON FILM.idfilm = DIENVIEN.idfilm
JOIN CANHAN ON DIENVIEN.idcn = CANHAN.idcn
GROUP BY ho,
         ten
HAVING COUNT (*) = (
    SELECT MAX (COUNT (*))
    FROM FILM
    JOIN DIENVIEN ON FILM.idfilm = DIENVIEN.idfilm
    JOIN CANHAN ON DIENVIEN.idcn = CANHAN.idcn
    GROUP BY ho,
             ten
);

-- Câu 19: Tên bộ phim có kinh phí thực hiện cao nhất
SELECT tua
FROM FILM
WHERE kinhphi = (
    SELECT MAX (kinhphi)
    FROM FILM
);

-- Câu 20: Tên bộ phim có kinh phí thực hiện tháp nhất
SELECT tua
FROM FILM
WHERE kinhphi = (
    SELECT MIN (kinhphi)
    FROM FILM
);

-- Câu 21: Tên bộ phim đã trả thu lao cao nhất cho một diễn viên nào đó
SELECT tua
FROM FILM
JOIN DIENVIEN ON FILM.idFILM = DIENVIEN.idfilm
WHERE idCN = (
    SELECT idCN
    FROM DIENVIEN
    WHERE thulao = (
        SELECT MAX (thulao)
        FROM DIENVIEN
    )
);

-- Câu 22: Tên phim, kinh phí thực hiện và tổng thù lao đã trả cho các diễn viên của mỗi phim
SELECT tua,
       kinhphi,
       SUM (thulao) AS tong_thu_lao
FROM FILM
JOIN DIENVIEN ON FILM.idfilm = DIENVIEN.idfilm
GROUP BY tua,
         kinhphi;
         
-- Câu 23: Họ tên, số lần tham gia và tổng thù lao đã nhận của mỗi diên viên có tổng thù lao lớn hơn 800.000
SELECT ho,
       ten,
       COUNT (*) so_lan_tgia,
       SUM (thulao) tong_thu_lao
FROM DIENVIEN
JOIN CANHAN ON DIENVIEN.idCN = CANHAN.idCN
GROUP BY ho, ten
HAVING SUM (thulao) > 800000;

-- Câu 24: Tìm tên thể loại và trung bình khinh phí của mỗi thể loại mà có trung bình kinh phí lớn hơn 500 triệu
SELECT tenloai,
       AVG (kinhphi) kinh_phi_tb
FROM LOAI
JOIN LOAIPHIM ON LOAI.idLoai = LOAIPHIM.idLoai
JOIN FILM ON LOAIPHIM.idfilm = FILM.idfilm group by tenloai having avg(kinhphi) > 500000000;

-- Câu 25: Cho mỗi phim mà 'BALIN MIREILLE' đã tham gia đóng phim, hãy cho biết tổng thù lao đã trả cho các diễn viên
SELECT tua,
       SUM (thulao) AS tong_thu_lao
FROM FILM
JOIN DIENVIEN ON FILM.idfilm = DIENVIEN.idfilm
WHERE idCN = (
    SELECT idCN
    FROM CANHAN
    WHERE (ho = 'BALIN' AND ten = 'MIREILLE')
)
GROUP BY tua;

-- Câu 26: Tìm họ tên các diễn viên, họ tên người thực hiện của bộ phim 'RESULTADO FINAL'
SELECT ho,
       ten
FROM CANHAN
WHERE idCN IN (
    SELECT idCN
    FROM FILM
    JOIN DIENVIEN ON FILM.idfilm = DIENVIEN.idfilm
    WHERE tua = 'RESULTADO FINAL'
)
UNION
SELECT ho,
       ten
FROM CANHAN
WHERE idCN = (
    SELECT nguoithuchien
    FROM film
    WHERE tua = 'RESULTADO FINAL'
);

-- Câu 27: Họ tên diễn viên được trả thù lao cao nhất từ một bộ phim nào đó
SELECT ho,
       ten
FROM CANHAN
JOIN DIENVIEN ON CANHAN.idCN = DIENVIEN.idCN
JOIN FILM ON DIENVIEN.idfilm = FILM.idfilm
WHERE thulao = (
    SELECT MAX (thulao)
    FROM DIENVIEN
);

-- Câu 28: Họ tên diễn viên có tổng thu lao thấp nhất
SELECT ho,
       ten
FROM CANHAN
JOIN DIENVIEN ON CANHAN.idCN = DIENVIEN.idCN
JOIN FILM ON DIENVIEN.idfilm = FILM.idfilm
GROUP BY ho,
         ten
HAVING SUM (thulao) = (
    SELECT MIN (SUM (thulao))
    FROM DIENVIEN
    GROUP BY idCN
);

-- Câu 29: Tính số cá nhân đã tham gia đóng phim
SELECT COUNT (*)
FROM (
    SELECT DISTINCT idCN
    FROM DIENVIEN
);

-- Câu 30: Tính số cá nhân đã thực hiện phim
SELECT COUNT (*)
FROM (
    SELECT DISTINCT nguoithuchien
    FROM FILM
);

-- Câu 31: Tính số cá nhân vừa đóng phim vừa thực hiện phim
SELECT COUNT (*)
FROM (
    SELECT DISTINCT idCN
    FROM DIENVIEN
    INTERSECT
    SELECT nguoithuchien
    FROM FILM
);

-- Câu 32: Tính số cá nhân chỉ đóng phim
SELECT COUNT (*)
FROM (
    SELECT idCN
    FROM DIENVIEN
    EXCEPT
    SELECT nguoithuchien
    FROM FILM
);

-- Câu 33: Tính số cá nhân chỉ thực hiện phim
SELECT COUNT (*)
FROM (
    SELECT nguoithuchien
    FROM FILM
    EXCEPT
    SELECT idCN
    FROM DIENVIEN    
);

-- Câu 34: Tính số cá nhân không đóng phim cũng không thực hiện phim
SELECT COUNT (*)
FROM (
    SELECT idCN
    FROM CANHAN
    EXCEPT
    SELECT idCN
    FROM DIENVIEN
    EXCEPT
    SELECT nguoithuchien
    FROM FILM
);

-- Câu 35: Những diễn viên nào đã tham gia ít nhất là một phim giống như diễn viên 'LANCASTER BURT'
SELECT DISTINCT ho,
                ten
FROM CANHAN
JOIN DIENVIEN ON CANHAN.idCN = DIENVIEN.idCN
WHERE idfilm = ANY (
    SELECT idfilm
    FROM DIENVIEN
    JOIN CANHAN ON DIENVIEN.idCN = CANHAN.idCN
    WHERE (ho = 'LANCASTER' AND ten = 'BURT')
) AND NOT (ho = 'LANCASTER' AND ten = 'BURT');

-- Câu 36: Những diễn viên nào đã tham gia ít nhất là tất cả các phim mà diễn viên 'RIVAEMMANUELLE' đã tham gia đóng phim
SELECT ho,
       ten
FROM CANHAN
JOIN DIENVIEN ON DIENVIEN.idCN = CANHAN.idCN
JOIN FILM ON FILM.IDFILM = DIENVIEN.IDFILM
WHERE film.idfilm IN (
    SELECT film.idfilm
    FROM FILM
    JOIN DIENVIEN ON FILM.IDFILM = DIENVIEN.IDFILM
    JOIN CANHAN ON CANHAN.idCN = DIENVIEN.idCN
    WHERE (ho = 'RIVA' AND ten = 'EMMANUELLE')
) AND NOT (ho = 'RIVA' AND ten = 'EMMANUELLE')
GROUP BY ho,
         ten
HAVING COUNT (*) = (
    SELECT COUNT (*)
    FROM FILM
    JOIN DIENVIEN ON FILM.IDFILM = DIENVIEN.IDFILM
    JOIN CANHAN ON CANHAN.idCN = DIENVIEN.idCN
    WHERE (ho = 'RIVA' AND ten = 'EMMANUELLE')
);

-- Câu 37: Ai đã tham gia tất cả các phim do 'BIVEL' thực hiện
SELECT ho,
       ten
FROM CANHAN
JOIN DIENVIEN ON CANHAN.idCN = DIENVIEN.idCN
WHERE idfilm IN (
    SELECT idfilm
    FROM FILM
    WHERE nguoithuchien = (
        SELECT idCN
        FROM CANHAN
        WHERE ho = 'BIVEL'
    )
)
GROUP BY ho,
         ten
HAVING COUNT (*) > (
    SELECT COUNT (*)
    FROM (
        SELECT idfilm
        FROM FILM
        WHERE nguoithuchien = (
            SELECT idCN
            FROM CANHAN
            WHERE ho = 'BIVEL'
        )
    )
);
