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
FROM Phong   P,
     May     M
WHERE P.IP = M.IP AND ( M.idloai = 'UNIX' OR M.idloai = 'PCWS' );

-- Cau 4
SELECT tenphong,
       P.IP,
       P.MP
FROM Phong   P,
     May     M
WHERE P.IP = M.IP AND ( M.idloai = 'UNIX' OR M.idloai = 'PCWS' ) AND P.IP='130.120.80'
ORDER BY M.idMay;

-- Cau 5
SELECT COUNT(id) AS so_phanmem FROM Caidat WHERE idmay = 'p6';

-- Cau 6
SELECT COUNT(idMay) AS so_may FROM Caidat WHERE idPM = 'log1';

-- Cau 7
SELECT tenmay, IP FROM May WHERE idloai = 'TX';

-- Cau 8
SELECT AVG(gia) as gia_tb FROM Phanmem WHERE idloai = 'UNIX';

-- Cau 9
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

-- Cau 10
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

-- Cau 11
SELECT tenPM,
       ngaymua
FROM Phanmem
WHERE to_char (ngaymua,'YYYY') = '1997';

-- Cau 12
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