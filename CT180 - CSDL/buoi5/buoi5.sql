-- Câu 1: Cho biet Loại của máy 'p8'
SELECT idloai
FROM May
WHERE idMay = 'p8';

-- Câu 2: Tên của các phần mềm loai 'UNIX'
SELECT tenPM
FROM Phanmem
WHERE idloai = 'UNIX';

-- Câu 3: Tên phòng, địa chỉ IP phòng, mã phòng của các máy loại 'UNIX' hoặc 'PCWS'
SELECT tenphong,
       P.IP,
       P.MP
FROM Phong   P,
     May     M
WHERE P.IP = M.IP AND ( M.idloai = 'UNIX' OR M.idloai = 'PCWS' );

-- Câu 4: Tên phòng, địa chỉ IP phòng, mã phòng của các máy loại 'UNIX' hoặc 'PCWS' ở khu vực '130.120.80', sắp xếp kết quả tăng dần theo mã phòng
SELECT tenphong,
       P.IP,
       P.MP
FROM Phong   P,
     May     M
WHERE P.IP = M.IP AND ( M.idloai = 'UNIX' OR M.idloai = 'PCWS' ) AND P.IP='130.120.80'
ORDER BY M.idMay;

-- Câu 5: Số các phần mềm được cài đặt trên máy 'p6'
SELECT COUNT(id) AS so_phanmem FROM Caidat WHERE idmay = 'p6';

-- Câu 6: Số các máy đã cài phần mềm 'log1'
SELECT COUNT(idMay) AS so_may FROM Caidat WHERE idPM = 'log1';

-- Câu 7: Tên và địa chỉ IP (ví dụ: 130.120.80.1) đầy đủ của các máy loại 'TX'
SELECT tenmay, IP FROM May WHERE idloai = 'TX';

-- Câu 8: Giá trung bình của các phần mềm UNIX
SELECT AVG(gia) as gia_tb FROM Phanmem WHERE idloai = 'UNIX';

-- Câu 9: Cho biết tên các phòng có cài phần mềm Oracle
SELECT tenPhong
FROM Phong
WHERE MP IN (
    SELECT MP
    FROM May
    WHERE idMay IN (
        SELECT idMay
        FROM caidat
        WHERE idPM IN (
            SELECT idPM
            FROM Phanmem
            WHERE tenPM LIKE 'Oracle %'
        )
        GROUP BY idMay
        HAVING COUNT (*) >= 1
    )
);

-- Câu 10: Cho biết tên phần mềm đã cài ở phòng Salle 1
SELECT tenPM
FROM Phanmem
WHERE idPM IN (
    SELECT idPM
    FROM Caidat
    WHERE idMay IN (
        SELECT idMay
        FROM May
        WHERE MP = (
            SELECT MP
            FROM Phong
            WHERE tenPhong = 'Salle 1'
        )
    )
);

-- Câu 11: Cho biết tên các phần mềm đã mua trong năm 1997
SELECT tenPM,
       ngaymua
FROM Phanmem
WHERE to_char (ngaymua,'YYYY') = '1997';

-- Câu 12: Cho biết tên các phần mềm cài đặt trên các loại máy UNIX có giá từ 2000 trở lên
SELECT tenPM
FROM Phanmem
WHERE idPM IN (
    SELECT idPM
    FROM Caidat
    WHERE idMay IN (
        SELECT idMay
        FROM May
        WHERE idLoai = 'UNIX'
    )
) AND gia >= 2000;
