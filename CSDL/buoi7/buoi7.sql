-- Cau 1
SELECT NT,
       tua
FROM TACPHAM
WHERE tacgia = 'Guy de Maupassant';

-- Cau 2
SELECT *
FROM DOCGIA
WHERE dchi = '32 rue des Alouettes, 75003 Paris';

-- Cau 3
SELECT nxb
FROM SACH
WHERE NT IN (
    SELECT NT
    FROM TACPHAM
    WHERE tua LIKE '%Fleur%'
);

-- Cau 4
SELECT tua
FROM TACPHAM
WHERE tua LIKE 'L  e%';

-- Cau 5
SELECT ten
FROM DOCGIA
WHERE ND IN (
    SELECT ND
    FROM MUON
    WHERE ngaymuon BETWEEN TO_DATE ('15/09/2007', 'DD/MM/YYYY') AND TO_DATE ('20/09/2007', 'DD/MM/YYYY')
);

-- Cau 6
SELECT COUNT (*)
FROM (
    SELECT DISTINCT NT
    FROM SACH
);

-- Cau 7
SELECT tacgia,
       COUNT (nt) AS so_tacpham
FROM TACPHAM
GROUP BY tacgia;

-- Cau 8
SELECT COUNT (*)
FROM (
    SELECT tacgia,
           COUNT (nt) AS so_tacpham
    FROM TACPHAM
    GROUP BY tacgia
    HAVING COUNT (*) >= 2
);

-- Cau 9
SELECT tua,
       COUNT (NS) AS so_sach
FROM SACH
JOIN TACPHAM ON SACH.NT = TACPHAM.NT
GROUP BY tua;

-- Cau 10
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

-- Cau 11
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

-- Cau 12
SELECT DISTINCT nxb
FROM SACH
WHERE NS = (
    SELECT NS
    FROM TACPHAM
    WHERE tua = 'Germinal '
);

-- Cau 13
SELECT tua,
       COUNT (NS) so_sach
FROM SACH
JOIN TACPHAM ON SACH.NT = TACPHAM.NT
GROUP BY tua
HAVING COUNT (NS) >= 2;

-- Cau 14
SELECT ten
FROM DOCGIA
JOIN MUON ON DOCGIA.ND = MUON.ND
JOIN SACH ON SACH.NS = MUON.NS
JOIN TACPHAM ON TACPHAM.NT = SACH.NT
WHERE tua = 'Poésie';

-- Cau 15
SELECT ten
FROM DOCGIA
JOIN MUON ON DOCGIA.ND = MUON.ND
JOIN SACH ON SACH.NS = MUON.NS
JOIN TACPHAM ON TACPHAM.NT = SACH.NT
WHERE tua = 'Les Fleurs du mal';

-- Cau 16
SELECT to_char (ngaymuon, 'YYYY') nam,
       ten,
       COUNT (*)
FROM MUON
JOIN DOCGIA ON MUON.ND = DOCGIA.ND
GROUP BY ten,
         to_char (ngaymuon, 'YYYY');
 
-- Cau 17
SELECT tua tua_sach,
       ten ten_doc_gia
FROM TACPHAM
JOIN SACH ON TACPHAM.NT = SACH.NT
JOIN MUON ON MUON.NS = SACH.NS
JOIN DOCGIA ON DOCGIA.ND = MUON.ND
WHERE ngaytra IS NULL;

-- Cau 18
SELECT tua tua_sach,
       ten ten_doc_gia
FROM TACPHAM
JOIN SACH ON TACPHAM.NT = SACH.NT
JOIN MUON ON MUON.NS = SACH.NS
JOIN DOCGIA ON DOCGIA.ND = MUON.ND
WHERE ngaytra > hantra;

-- Cau 19
SELECT tua tua_sach,
       ten ten_doc_gia
FROM TACPHAM
JOIN SACH ON TACPHAM.NT = SACH.NT
JOIN MUON ON MUON.NS = SACH.NS
JOIN DOCGIA ON DOCGIA.ND = MUON.ND
WHERE ngaytra < hantra;

-- Cau 20
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

-- Cau 21
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

-- Cau 22
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

-- Cau 23
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

-- Cau 24
SELECT DISTINCT ten
FROM DOCGIA
JOIN MUON ON MUON.ND = DOCGIA.ND
JOIN SACH ON SACH.NS = MUON.NS
JOIN TACPHAM ON TACPHAM.NT = SACH.NT
WHERE tacgia = 'Victor Hugo';

-- Cau 25 
SELECT ten,
       tua
FROM MUON
JOIN DOCGIA ON DOCGIA.ND = MUON.ND
JOIN SACH ON SACH.NS = MUON.NS
JOIN TACPHAM ON TACPHAM.NT = SACH.NT
WHERE to_char (ngaymuon, 'YYYY') = 2007;

-- Cau 26
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

-- Cau 27
select * from SACH join TACPHAM on SACH.NT = TACPHAM.NT order by tua;

-- Cau 28 
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

-- Cau 29
SELECT nxb
FROM SACH
WHERE NS IN (
    SELECT NS
    FROM SACH
    EXCEPT
    SELECT NS
    FROM MUON
);

-- Cau 30 
SELECT tua,
       COUNT (*)
FROM TACPHAM
JOIN SACH ON TACPHAM.NT = SACH.NT
GROUP BY tua
HAVING COUNT (*) >= 3;

-- Cau 31
SELECT *
FROM DOCGIA
WHERE ND IN (
    SELECT ND
    FROM MUON
    WHERE NS IN (
        SELECT NS
        FROM SACH
        JOIN TACPHAM ON SACH.NT = TACPHAM.NT
        WHERE tua = 'Madame Bovary'
    )
    GROUP BY ND
    HAVING COUNT (*) = (
        SELECT COUNT (*)
        FROM (
            SELECT NS
            FROM SACH
            JOIN TACPHAM ON SACH.NT = TACPHAM.NT
            WHERE tua = 'Madame Bovary'
        )
    )
);

-- Cau 32
SELECT *
FROM DOCGIA
WHERE ND IN (
    SELECT ND
    FROM MUON
    WHERE NS IN (
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