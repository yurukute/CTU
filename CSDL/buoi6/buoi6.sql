-- Câu 1: Loại của máy 'p8'
SELECT idloai
FROM May
WHERE idMay = 'p8';

-- Câu 2: Tên của các phần mềm 'UNIX'
SELECT tenPM
FROM Phanmem
WHERE idloai = 'UNIX';

-- Câu 3: Tên phòng, địa chỉ IP phòng, mã phòng của các máy loại 'UNIX' hoặc 'PCWS'
SELECT tenphong,
       P.IP,
       P.MP
FROM Phong P,
     May   M
WHERE P.IP = M.IP AND (M.idloai = 'UNIX' OR M.idloai = 'PCWS');

-- Câu 4: Tên phòng, địa chỉ IP phòng, mã phòng của các máy loại 'UNIX' hoặc 'PCWS' ở khuvực '130.120.80', sắp xếp kết quả tăng dần theo mã phòng
SELECT tenphong,
       P.IP,
       P.MP
FROM Phong P,
     May   M
WHERE P.IP = M.IP AND (M.idloai = 'UNIX' OR M.idloai = 'PCWS') AND P.IP = '130.120.80'
ORDER BY P.MP;

-- Câu 5: Số các phần mềm được cài đặt trên máy 'p6'
SELECT COUNT (id) so_phanmem
FROM Caidat
WHERE idmay = 'p6';

-- Câu 6: Số các máy đã cài phần mềm 'log1'
SELECT COUNT (idMay) so_may
FROM Caidat
WHERE idPM = 'log1';

-- Câu 7: Tên và địa chỉ IP (ví dụ: 130.120.80.1) đầy đủ của các máy loại 'TX'
SELECT tenmay,
       IP
FROM May
WHERE idloai = 'TX';

-- Câu 8: Tính số phần mềm đã cài đặt trên mỗi máy
SELECT idMay,
       COUNT (*) so_phanmem
FROM Caidat
GROUP BY idMay;

-- Câu 9: Tính số máy mỗi phòng
SELECT MP,
       COUNT (*) so_may
FROM May
GROUP BY MP;

-- Câu 10: Tính số cài lần cài đặt của mỗi phần mềm trên các máy khác nhau
SELECT idMay,
       COUNT (*) so_phanmem
FROM Caidat
GROUP BY idMay;

-- Câu 11: Giá trung bình của các phần mềm UNIX
SELECT AVG (gia) AS gia_tb
FROM Phanmem
WHERE idloai = 'UNIX';

-- Câu 12: Ngày mua phần mềm gần nhất
SELECT MAX (ngaymua) ngay_mua_gan_nhat
FROM Phanmem;

-- Câu 13: Số máy có ít nhất 2 phần mềm
SELECT idmay,
       COUNT (*) so_pm
FROM Caidat
GROUP BY idMay
HAVING COUNT (*) >= 2;

-- Câu 14: Số máy có ít nhất 2 phần mềm, sử dụng một select con trong mệnh đề FROM
SELECT COUNT (*) so_may
FROM (
    SELECT idmay,
           COUNT (*) so_pm
    FROM Caidat
    GROUP BY idmay
    HAVING COUNT (*) >= 2
);

-- Các câu 15) và 17) viết bằng 2 cách : SELECT con và OUTER JOIN
-- Câu 15: Tìm các loại không thuộc loại máy 
SELECT idLoai
FROM Loai
MINUS
SELECT idLoai
FROM May;

SELECT L.idLoai
FROM Loai L
LEFT JOIN May  M ON L.idLoai = M.idLoai
WHERE M.idLoai IS NULL;

-- Câu 16: Tìm các loại thuộc cả hai loại máy và loại phần mềm
SELECT idLoai
FROM May
INTERSECT
SELECT idLoai
FROM Phanmem;

-- Câu 17: Tìm các loại máy không phải là loại phần mềm
SELECT idLoai
FROM May
MINUS
SELECT idLoai
FROM Phanmem;

SELECT DISTINCT M.idLoai
FROM May     M
LEFT JOIN Phanmem PM ON M.idLoai = PM.idLoai
WHERE PM.idLoai IS NULL;

-- Viết các câu từ 18) đến 22) sử dụng SELECT lồng nhau
-- Câu 18: Địa chỉ IP đầy đủ của các máy cài phần mềm 'log6'
SELECT IP
FROM May
WHERE idMay IN (
    SELECT idMay
    FROM Caidat
    WHERE idPM = 'log6'
);

-- Câu 19: Địa chỉ IP đầy đủ của các máy cài phần mềm tên 'Oracle 8'
SELECT idMay,
       IP
FROM May
WHERE idMay IN (
    SELECT idMay
    FROM Caidat
    WHERE idPM IN (
        SELECT idPM
        FROM Phanmem
        WHERE tenPM = 'Oracle 8'
    )
);

-- Câu 20: Tên của các khu vực có chính xác 3 máy loại 'TX'
SELECT tenKhuvuc,
       IP
FROM (
    SELECT IP,
           COUNT (*)
    FROM May
    WHERE (idloai = 'TX')
    GROUP BY IP
    HAVING COUNT (*) = 3
);

-- Câu 21: Tên phòng có ít nhất một máy cài phần mềm tên 'Oracle 6'
SELECT tenPhong
FROM Phong
WHERE MP IN (
    SELECT MP
    FROM May
    WHERE idMay IN (
        SELECT idMay
        FROM caidat
        WHERE idPM = (
            SELECT idPM
            FROM Phanmem
            WHERE tenPM = 'Oracle 6'
        )
        GROUP BY idMay
        HAVING COUNT (*) >= 1
    )
);

-- Câu 22: Tên phần mềm được mua gần nhất (sử dụng câu 12)
SELECT tenPM
FROM phanmem
WHERE ngaymua = (
    SELECT MAX (ngaymua) ngay_mua_gan_nhat
    FROM Phanmem
);

-- Viết các câu từ 18) đến 21) sử dụng JOIN, đánh số cho các câu hỏi này từ 23) đến 26)
-- Câu 23: Địa chỉ IP đầy đủ của các máy cài phần mềm 'log6'
SELECT IP
FROM May
JOIN Caidat ON May.idMay = Caidat.idmay
WHERE idPM = 'log6';

-- Câu 24: Địa chỉ IP đầy đủ của các máy cài phần mềm tên 'Oracle 8'
SELECT IP
FROM May JOIN Caidat  ON May.idMay   = Caidat.idmay
         JOIN Phanmem ON Caidat.idPM = Phanmem.idPM
WHERE tenPM = 'Oracle 8';

-- Câu 25: Tên của các khu vực có chính xác 3 máy loại 'TX'
SELECT tenKhuvuc
FROM Khuvuc
JOIN May ON May.IP = Khuvuc.IP
WHERE May.idloai = 'TX'
GROUP BY tenKhuvuc
HAVING COUNT (*) = 3;

-- Câu 26: Tên phòng có ít nhất một máy cài phần mềm tên 'Oracle 6'
SELECT tenPhong
FROM Phong 
    JOIN May     ON May.MP       = Phong.MP
    JOIN Caidat  ON Caidat.idMay = May.idMay
    JOIN Phanmem ON Phanmem.idPM = Caidat.idPM
WHERE tenPM = 'Oracle 6'
GROUP BY tenPhong
HAVING COUNT (*) >= 1;

-- Câu 27: Tên của máy có ít nhất một phần mềm chung với máy 'p6'
SELECT idMay
FROM Caidat
WHERE idMay != 'p6' AND idPM IN (
    SELECT idPM
    FROM Caidat
    WHERE idMay = 'p6'
);

-- Câu 28: Tên của phần mềm PCNT có giá lớn hơn bất kỳ giá của một phần mềm UNIX nào
SELECT tenPM,
       gia
FROM Phanmem
WHERE (idloai = 'PCNT' 
    AND gia > (
        SELECT MIN (gia)
        FROM Phanmem
        WHERE idloai = 'UNIX'
    )
);

-- Câu 29: Tên của phần mềm UNIX có giá lớn hơn tất cả các giá của các phần mềm PCNT
SELECT tenPM,
       gia
FROM Phanmem
WHERE (idloai = 'UNIX' 
    AND gia > (
        SELECT MAX (gia)
        FROM Phanmem
        WHERE idloai = 'PCNT'
    )
);

-- Câu 30: Tên của các máy có cùng phần mềm như máy 'p6' (có thể nhiều phần mềm hơn máy'p6')
SELECT idMay
FROM Caidat
WHERE idMay != 'p6' AND idPM IN (
    SELECT idPM
    FROM caidat
    WHERE idMay = 'p6'
);

-- Câu 31: Tên của các máy có chính xác các phần mềm như máy 'p2'
SELECT idMay
FROM Caidat
WHERE idPM = ALL (
    SELECT idPM
    FROM Caidat
    WHERE idMay = 'p2'
);
