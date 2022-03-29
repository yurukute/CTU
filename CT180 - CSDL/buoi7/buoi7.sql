-- Câu 1: Các tác phẩm (NT, tựa)  của tác giả  'Guy de Maupassant'.
-- TACPHAM(tacgia = 'Guy de Maupassant')[NT, tua]
SELECT NT,
       tua
FROM TACPHAM
WHERE tacgia = 'Guy de Maupassant';

-- Câu 2: Các độc giả sống ở địa chỉ  '32 rue des Alouettes, 75003 Paris'. 
SELECT *
FROM DOCGIA
WHERE dchi = '32 rue des Alouettes, 75003 Paris';

-- Câu 3: Tìm tên nhà xuất bản các tác phẩm bao gồm từ 'Fleur'
SELECT nxb
FROM SACH
WHERE NT IN (
    SELECT NT
    FROM TACPHAM
    WHERE tua LIKE '%Fleur%'
);

-- Câu 4: Tìm tên các tác phẩm bắt đầu bằng 'Le'
SELECT tua
FROM TACPHAM
WHERE tua LIKE 'Le%';

-- Câu 5: Tìm tên các độc giả có mượn sách trong trong khoảng thời gian từ ngày 15/9/2007 đến20/09/2007
SELECT ten
FROM DOCGIA
WHERE ND IN (
    SELECT ND
    FROM MUON
    WHERE ngaymuon BETWEEN TO_DATE ('15/09/2007', 'DD/MM/YYYY') AND TO_DATE ('20/09/2007', 'DD/MM/YYYY')
);

-- Câu 6: Số tác phẩm có trong thư viện. 
SELECT COUNT (*)
FROM (
    SELECT DISTINCT NT
    FROM SACH
);

-- Câu 7: Tính Số tác phẩm của mỗi tác giả. 
SELECT tacgia,
       COUNT (nt) AS so_tacpham
FROM TACPHAM
GROUP BY tacgia;

-- Câu 8: Tính Số tác giả có ít nhất hai tác phẩm
SELECT COUNT (*)
FROM (
    SELECT tacgia,
           COUNT (nt) AS so_tacpham
    FROM TACPHAM
    GROUP BY tacgia
    HAVING COUNT (*) >= 2
);

-- Câu 9: Tính Số sách của mỗi tác phẩm. 
SELECT tua,
       COUNT (NS) AS so_sach
FROM SACH
JOIN TACPHAM ON SACH.NT = TACPHAM.NT
GROUP BY tua;

-- Câu 10: Tìm tên tác phẩm có nhiều sách nhất
SELECT tua,
       so_sach
FROM (
    SELECT tua,
           COUNT (NS) AS so_sach
    FROM SACH
    JOIN TACPHAM ON SACH.NT = TACPHAM.NT
    GROUP BY tua
)
WHERE so_sach = (
    SELECT MAX (so_sach)
    FROM (
        SELECT tua,
               COUNT (NS) AS so_sach
        FROM SACH
        JOIN TACPHAM ON SACH.NT = TACPHAM.NT
        GROUP BY tua
    )
);

-- Câu 11: Tên nhà xuất bản xuất bản nhiều sách nhất
SELECT nxb,
       so_sach
FROM (
    SELECT nxb,
           COUNT (NS) AS so_sach
    FROM SACH
    GROUP BY nxb
)
WHERE so_sach = (
    SELECT MAX (so_sach)
    FROM (
        SELECT nxb,
               COUNT (NS) AS so_sach
        FROM SACH
        GROUP BY nxb
    )
);

-- Câu 12: Nhà xuất bản của tác phẩm  tiêu đề 'Germinal'.
SELECT DISTINCT nxb
FROM SACH
WHERE NS = (
    SELECT NS
    FROM TACPHAM
    WHERE tua = 'Germinal '
);

-- Câu 13: Tựa của tác phẩm mà có ít nhất hai quyển sách. 
SELECT tua,
       COUNT (NS) so_sach
FROM SACH
JOIN TACPHAM ON SACH.NT = TACPHAM.NT
GROUP BY tua
HAVING COUNT (NS) >= 2;

-- Câu 14: Tên độc giả đã mượn tác phẩm 'Poésie'.
SELECT ten
FROM DOCGIA
JOIN MUON ON DOCGIA.ND = MUON.ND
JOIN SACH ON SACH.NS = MUON.NS
JOIN TACPHAM ON TACPHAM.NT = SACH.NT
WHERE tua = 'Poésie';

-- Câu 15: Những độc giả nào đã mượn tác phẩm Les 'Fleurs du mal'
SELECT ten
FROM DOCGIA
JOIN MUON ON DOCGIA.ND = MUON.ND
JOIN SACH ON SACH.NS = MUON.NS
JOIN TACPHAM ON TACPHAM.NT = SACH.NT
WHERE tua = 'Les Fleurs du mal';

-- Câu 16: Tìm số lần mượn sách của mỗi độc giả theo năm
SELECT to_char (ngaymuon, 'YYYY') nam,
       ten,
       COUNT (*)
FROM MUON
JOIN DOCGIA ON MUON.ND = DOCGIA.ND
GROUP BY ten,
         to_char (ngaymuon, 'YYYY');
 
-- Câu 17: Tìm tựa sách, tên độc giả của các độc giả chưa trả sách
SELECT tua tua_sach,
       ten ten_doc_gia
FROM TACPHAM
JOIN SACH ON TACPHAM.NT = SACH.NT
JOIN MUON ON MUON.NS = SACH.NS
JOIN DOCGIA ON DOCGIA.ND = MUON.ND
WHERE ngaytra IS NULL;

-- Câu 18: Tìm các tựa sách, tên độc giả của các độc giả trả sách quá thời hạn cho phép
SELECT tua tua_sach,
       ten ten_doc_gia
FROM TACPHAM
JOIN SACH ON TACPHAM.NT = SACH.NT
JOIN MUON ON MUON.NS = SACH.NS
JOIN DOCGIA ON DOCGIA.ND = MUON.ND
WHERE ngaytra > hantra;

-- Câu 19: Tìm các tựa sách, tên độc giả của các độc giả trả sách trước thời hạn20)
SELECT tua tua_sach,
       ten ten_doc_gia
FROM TACPHAM
JOIN SACH ON TACPHAM.NT = SACH.NT
JOIN MUON ON MUON.NS = SACH.NS
JOIN DOCGIA ON DOCGIA.ND = MUON.ND
WHERE ngaytra < hantra;

-- Câu 20: Tìm tựa tác phẩm có nhiều người mượn nhất
SELECT tua_sach,
       so_lan_muon
FROM (
    SELECT tua       tua_sach,
           COUNT (*) so_lan_muon
    FROM TACPHAM
    JOIN SACH ON TACPHAM.NT = SACH.NT
    JOIN MUON ON MUON.NS = SACH.NS
    GROUP BY tua
)
WHERE so_lan_muon = (
    SELECT MAX (so_lan_muon)
    FROM (
        SELECT tua       tua_sach,
               COUNT (*) so_lan_muon
        FROM TACPHAM
        JOIN SACH ON TACPHAM.NT = SACH.NT
        JOIN MUON ON MUON.NS = SACH.NS
        GROUP BY tua
    )
);

-- Câu 21: Tìm tựa tác phẩm có ít người mượn nhất
SELECT tua_sach
FROM (
    SELECT tua       tua_sach,
           COUNT (*) so_lan_muon
    FROM TACPHAM
    JOIN SACH ON TACPHAM.NT = SACH.NT
    JOIN MUON ON MUON.NS = SACH.NS
    GROUP BY tua
)
WHERE so_lan_muon = (
    SELECT MIN (so_lan_muon)
    FROM (
        SELECT tua       tua_sach,
               COUNT (*) so_lan_muon
        FROM TACPHAM
        JOIN SACH ON TACPHAM.NT = SACH.NT
        JOIN MUON ON MUON.NS = SACH.NS
        GROUP BY tua
    )
);

-- Câu 22: Tìm độc giả mượn nhiều tác phẩm nhất
SELECT ten
FROM (
    SELECT ten,
           COUNT (*) so_tac_pham_muon
    FROM DOCGIA
    JOIN (
        SELECT DISTINCT ND,
                        tua
        FROM MUON
        JOIN SACH ON SACH.NS = MUON.NS
        JOIN TACPHAM ON TACPHAM.NT = SACH.NT
    ) temp ON temp.ND = DOCGIA.ND
    GROUP BY ten
)
WHERE so_tac_pham_muon = (
    SELECT MAX (so_tac_pham_muon)
    FROM (
        SELECT ten,
               COUNT (*) so_tac_pham_muon
        FROM DOCGIA
        JOIN (
            SELECT DISTINCT ND,
                            tua
            FROM MUON
            JOIN SACH ON SACH.NS = MUON.NS
            JOIN TACPHAM ON TACPHAM.NT = SACH.NT
        ) temp ON temp.ND = DOCGIA.ND
        GROUP BY ten
    )
);

-- Câu 23: Tìm tên tên độc giả mượn ít tác phẩm nhất
SELECT ten
FROM (
    SELECT ten,
           COUNT (*) so_tac_pham_muon
    FROM DOCGIA
    JOIN (
        SELECT DISTINCT ND,
                        tua
        FROM MUON
        JOIN SACH ON SACH.NS = MUON.NS
        JOIN TACPHAM ON TACPHAM.NT = SACH.NT
    ) temp ON temp.ND = DOCGIA.ND
    GROUP BY ten
)
WHERE so_tac_pham_muon = (
    SELECT MIN (so_tac_pham_muon)
    FROM (
        SELECT ten,
               COUNT (*) so_tac_pham_muon
        FROM DOCGIA
        JOIN (
            SELECT DISTINCT ND,
                            tua
            FROM MUON
            JOIN SACH ON SACH.NS = MUON.NS
            JOIN TACPHAM ON TACPHAM.NT = SACH.NT
        ) temp ON temp.ND = DOCGIA.ND
        GROUP BY ten
    )
);

-- Câu 24: Tên độc giả đã mượn tác phẩm của 'Victor Hugo'
SELECT DISTINCT ten
FROM DOCGIA
JOIN MUON ON MUON.ND = DOCGIA.ND
JOIN SACH ON SACH.NS = MUON.NS
JOIN TACPHAM ON TACPHAM.NT = SACH.NT
WHERE tacgia = 'Victor Hugo';

-- Câu 25: Tên độc giả và các tác phẩm đã được mượn năm 2007
SELECT ten,
       tua
FROM MUON
JOIN DOCGIA ON DOCGIA.ND = MUON.ND
JOIN SACH ON SACH.NS = MUON.NS
JOIN TACPHAM ON TACPHAM.NT = SACH.NT
WHERE to_char (ngaymuon, 'YYYY') = 2007;

-- Câu 26: Tìm tên tác phẩm có ít nhất một quyển sách không ai mượn
SELECT DISTINCT tua
FROM TACPHAM
JOIN SACH ON SACH.NT = TACPHAM.NT
WHERE NS IN (
    SELECT NS
    FROM SACH
    EXCEPT
    SELECT NS
    FROM MUON
);

-- Câu 27: Tìm tên tác phẩm có tất cả các quyển sách đều được mượn
SELECT tua
FROM TACPHAM
EXCEPT
SELECT tua
FROM TACPHAM
LEFT JOIN SACH ON TACPHAM.NT = SACH.NT
LEFT JOIN MUON ON SACH.NS = MUON.NS
WHERE MUON.NS IS NULL;

-- Câu 28: Tìm họ tên độc giả chưa mượn quyển sách nào
SELECT ho,
       ten
FROM DOCGIA
WHERE ND IN (
    SELECT ND
    FROM DOCGIA
    EXCEPT
    SELECT ND
    FROM MUON
);

-- Câu 29: Tìm thông tin về nhà suất bản của quyển sách mà chưa được ai mượn
SELECT nxb
FROM SACH
WHERE NS IN (
    SELECT NS
    FROM SACH
    EXCEPT
    SELECT NS
    FROM MUON
);

-- Câu 30: Tìm tên tác phẩm có ít nhất 3 sách
SELECT tua,
       COUNT (*)
FROM TACPHAM
JOIN SACH ON TACPHAM.NT = SACH.NT
GROUP BY tua
HAVING COUNT (*) >= 3;

-- Câu 31: Tìm thông tin về độc giả có mượn tất cả các quyển sách của tác phẩm 'Madame Bovary'
SELECT *
FROM DOCGIA
WHERE ND = ALL (
    SELECT ND
    FROM MUON
    WHERE NS IN (
        SELECT NS
        FROM SACH
        JOIN TACPHAM ON SACH.NT = TACPHAM.NT
        WHERE tua = 'Madame Bovary'
    )
);

-- Câu 32: Tìm thông tin về độc giả có mượn các quyển sách giống như độc giả 'Raymond Carole' 
SELECT *
FROM DOCGIA
WHERE ND IN (
    SELECT ND
    FROM MUON
    WHERE NS = ALL (
        SELECT NS
        FROM MUON
        JOIN DOCGIA ON DOCGIA.ND = MUON.ND
        WHERE ho = 'Raymond' AND ten = 'Carole'
    )
    EXCEPT
    SELECT ND
    FROM DOCGIA
    WHERE ho = 'Raymond' AND ten = 'Carole'
);
