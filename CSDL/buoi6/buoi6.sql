-- Cau 1
SELECT idloai
FROM May
WHERE idMay = 'p8';

-- Cau 2
SELECT tenPM
FROM Phanmem
WHERE idloai = 'UNIX';

-- Cau 3
SELECT tenphong,
       P.IP,
       P.MP
FROM Phong P,
     May   M
WHERE P.IP = M.IP AND (M.idloai = 'UNIX' OR M.idloai = 'PCWS');

-- Cau 4
SELECT tenphong,
       P.IP,
       P.MP
FROM Phong P,
     May   M
WHERE P.IP = M.IP AND (M.idloai = 'UNIX' OR M.idloai = 'PCWS') AND P.IP = '130.120.80'
ORDER BY P.MP;

-- Cau 5
SELECT COUNT (id) so_phanmem
FROM Caidat
WHERE idmay = 'p6';

-- Cau 6
SELECT COUNT (idMay) so_may
FROM Caidat
WHERE idPM = 'log1';

-- Cau 7
SELECT tenmay,
       IP
FROM May
WHERE idloai = 'TX';

-- Cau 8
SELECT idMay,
       COUNT (*) so_phanmem
FROM Caidat
GROUP BY idMay;

-- Cau 9
SELECT MP,
       COUNT (*) so_may
FROM May
GROUP BY MP;

-- Cau 10
SELECT idMay,
       COUNT (*) so_phanmem
FROM Caidat
GROUP BY idMay;

-- Cau 11
SELECT AVG (gia) AS gia_tb
FROM Phanmem
WHERE idloai = 'UNIX';

-- Cau 12
SELECT MAX (ngaymua) ngay_mua_gan_nhat
FROM Phanmem;

-- Cau 13
SELECT idmay,
       COUNT (*) so_pm
FROM Caidat
GROUP BY idMay
HAVING COUNT (*) >= 2;

-- Cau 14
SELECT COUNT (*) so_may
FROM (
    SELECT idmay,
           COUNT (*) so_pm
    FROM Caidat
    GROUP BY idmay
    HAVING COUNT (*) >= 2
);

-- Cau 15
SELECT idLoai
FROM Loai
MINUS
SELECT idLoai
FROM May;

SELECT L.idLoai
FROM Loai L
LEFT JOIN May  M ON L.idLoai = M.idLoai
WHERE M.idLoai IS NULL;

-- Cau 16
SELECT idLoai
FROM May
INTERSECT
SELECT idLoai
FROM Phanmem;

-- Cau 17
SELECT idLoai
FROM May
MINUS
SELECT idLoai
FROM Phanmem;

SELECT DISTINCT M.idLoai
FROM May     M
LEFT JOIN Phanmem PM ON M.idLoai = PM.idLoai
WHERE PM.idLoai IS NULL;

-- Cau 18
SELECT IP
FROM May
WHERE idMay IN (
    SELECT idMay
    FROM Caidat
    WHERE idPM = 'log6'
);

-- Cau 19
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

-- Cau 20
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

-- Cau 21
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

-- Cau 22
SELECT tenPM
FROM phanmem
WHERE ngaymua = (
    SELECT MAX (ngaymua) ngay_mua_gan_nhat
    FROM Phanmem
);

-- Cau 23
SELECT IP
FROM May
JOIN Caidat ON May.idMay = Caidat.idmay
WHERE idPM = 'log6';

-- Cau 24
SELECT IP
FROM May JOIN Caidat  ON May.idMay   = Caidat.idmay
         JOIN Phanmem ON Caidat.idPM = Phanmem.idPM
WHERE tenPM = 'Oracle 8';

-- Cau 25
SELECT tenKhuvuc
FROM Khuvuc
JOIN May ON May.IP = Khuvuc.IP
WHERE May.idloai = 'TX'
GROUP BY tenKhuvuc
HAVING COUNT (*) = 3;

-- Cau 26
SELECT tenPhong
FROM Phong 
    JOIN May     ON May.MP       = Phong.MP
    JOIN Caidat  ON Caidat.idMay = May.idMay
    JOIN Phanmem ON Phanmem.idPM = Caidat.idPM
WHERE tenPM = 'Oracle 6'
GROUP BY tenPhong
HAVING COUNT (*) >= 1;

-- Cau 27
SELECT idMay
FROM Caidat
WHERE idMay != 'p6' AND idPM IN (
    SELECT idPM
    FROM Caidat
    WHERE idMay = 'p6'
);

-- Cau 28
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

-- Cau 29
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

-- Cau 30
SELECT idMay
FROM Caidat
WHERE idMay != 'p6' AND idPM IN (
    SELECT idPM
    FROM caidat
    WHERE idMay = 'p6'
);

-- Cau 31
SELECT idMay
FROM Caidat
WHERE idPM IN (
    SELECT idPM
    FROM Caidat
    WHERE idMay = 'p2'
)
GROUP BY idMay
HAVING COUNT (*) = (
    SELECT COUNT (*)
    FROM (
        SELECT idPM
        FROM Caidat
        WHERE idMay = 'p2'
    )
);