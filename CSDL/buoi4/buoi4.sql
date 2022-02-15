CREATE TABLE Khuvuc (
    IP          CHAR(10) PRIMARY KEY,
    tenKhuvuc   VARCHAR(30) NOT NULL,
    tang        SMALLINT
);

CREATE TABLE Phong (
    MP         CHAR(3) PRIMARY KEY,
    tenphong   VARCHAR(30) NOT NULL,
    somay      SMALLINT,
    IP         CHAR(10),
    FOREIGN KEY ( IP )
        REFERENCES Khuvuc ( IP )
);

CREATE TABLE Loai (
    idloai    VARCHAR(4) PRIMARY KEY,
    tenloai   VARCHAR(30) NOT NULL
);

CREATE TABLE May (
    idMay    VARCHAR(10) PRIMARY KEY,
    tenmay   VARCHAR(30) NOT NULL,
    IP       CHAR(10),
    ad       SMALLINT CHECK ( ad >= 0
                   AND ad <= 255 ),
    idloai   VARCHAR(4),
    MP       CHAR(3),
    FOREIGN KEY ( IP )
        REFERENCES Khuvuc ( IP ),
    FOREIGN KEY ( idloai )
        REFERENCES Loai ( idloai ),
    FOREIGN KEY ( MP )
        REFERENCES Phong ( MP )
);

CREATE TABLE Phanmem (
    idPM      VARCHAR(6) PRIMARY KEY,
    tenPM     VARCHAR(30) NOT NULL,
    ngaymua   DATE,
    version   VARCHAR(3),
    idloai    VARCHAR(4),
    gia       INT CHECK ( gia > 0 ),
    FOREIGN KEY ( idloai )
        REFERENCES Loai ( idloai )
);

CREATE TABLE Caidat (
    id        CHAR(3) PRIMARY KEY,
    idMay     VARCHAR(3),
    idPM      VARCHAR(6),
    ngaycai   DATE DEFAULT SYSDATE,
    FOREIGN KEY ( idMay )
        REFERENCES May ( idMay ),
    FOREIGN KEY ( idPM )
        REFERENCES Phanmem ( idPM )
)

INSERT INTO Khuvuc (IP, tenKhuvuc) VALUES ('130.120.80','Brin RDC');
INSERT INTO Khuvuc VALUES ('130.120.81','Brin tang 1','');
INSERT INTO Khuvuc VALUES ('130.120.82','Brin tang 2','');

INSERT INTO Phong VALUES ('s01','Salle 1',3,'130.120.80');
INSERT INTO Phong VALUES ('s02','Salle 2',2,'130.120.80');
INSERT INTO Phong VALUES ('s03','Salle 3',2,'130.120.80');
INSERT INTO Phong VALUES ('s11','Salle 11',2,'130.120.81');
INSERT INTO Phong VALUES ('s12','Salle 12',1,'130.120.81');
INSERT INTO Phong VALUES ('s21','Salle 21',2,'130.120.82');
INSERT INTO Phong VALUES ('s22','Salle 22',0,'130.120.82');
INSERT INTO Phong VALUES ('s23','Salle 23',0,'130.120.82'); /*130.120.80 khong ton tai*/

INSERT INTO Loai VALUES ('TX','Terminal X-Window');
INSERT INTO Loai VALUES ('UNIX','Systeme Unix');
INSERT INTO Loai VALUES ('PCNT','PC Windows NT');
INSERT INTO Loai VALUES ('PCWS','PC Windows');
INSERT INTO Loai VALUES ('NC','Network Computer');

INSERT INTO May VALUES ('p1','Poste 1','130.120.80',01,'TX','s01');
INSERT INTO May VALUES ('p2','Poste 2','130.120.80',02,'UNIX','s01');
INSERT INTO May VALUES ('p3','Poste 3','130.120.80',03,'TX','s01');
INSERT INTO May VALUES ('p4','Poste 4','130.120.80',04,'PCWS','s02');
INSERT INTO May VALUES ('p5','Poste 5','130.120.80',05,'PCWS','s02');
INSERT INTO May VALUES ('p6','Poste 6','130.120.80',06,'UNIX','s03');
INSERT INTO May VALUES ('p7','Poste 7','130.120.80',07,'TX','s03');
INSERT INTO May VALUES ('p8','Poste 8','130.120.81',01,'UNIX','s11');
INSERT INTO May VALUES ('p9','Poste 9','130.120.81',02,'TX','s11');
INSERT INTO May VALUES ('p10','Poste 10','130.120.81',03,'UNIX','s12');
INSERT INTO May VALUES ('p11','Poste 11','130.120.82',01,'PCNT','s21');
INSERT INTO May VALUES ('p12','Poste 12','130.120.82',02,'PCWS','s21');

ALTER SESSION SET NLS_DATE_FORMAT = 'YYYY-MM-DD';

INSERT INTO Phanmem VALUES ('log1','Oracle 6','1995-05-13','6.2','UNIX',3000);
INSERT INTO Phanmem VALUES ('log2','Oracle 8','1995-09-15','8i','UNIX',5600);
INSERT INTO Phanmem VALUES ('log3','SQL Server','1998-04-12','7','PCNT',2700);
INSERT INTO Phanmem VALUES ('log4','Front Page','1997-06-03','5','PCWS',500);
INSERT INTO Phanmem VALUES ('log5','WinDev','1997-05-12','5','PCWS',750);
INSERT INTO Phanmem VALUES ('log6','SQL*Net','','2.0','UNIX',500);
INSERT INTO Phanmem VALUES ('log7','I. I. S.','2002-04-12','2','PCNT',810);
INSERT INTO Phanmem VALUES ('log8','DreamWeaver','2003-09-21','2.0','PCWS',1400); /*BeOS khong ton tai*/

UPDATE Khuvuc
SET
    tang =
        CASE
            WHEN IP = '130.120.80' THEN 0
            WHEN IP = '130.120.81' THEN 1
            WHEN IP = '130.120.82' THEN 2
        END;

UPDATE Phanmem
SET
    gia = gia * 0.9
WHERE idloai = 'PCNT';

ALTER TABLE May ADD nbLog SMALLINT;

ALTER TABLE Phanmem ADD nbInstall SMALLINT;

UPDATE Phanmem
SET
    nbInstall =
        CASE
            WHEN idPM = 'log1' THEN 2
            WHEN idPM = 'log2' THEN 2
            WHEN idPM = 'log3' THEN 1
            WHEN idPM = 'log4' THEN 1
            WHEN idPM = 'log5' THEN 1
            WHEN idPM = 'log6' THEN 2
            WHEN idPM = 'log7' THEN 2            
        END;
        
UPDATE May
SET
    nbLog =
        CASE
            WHEN idMay = 'p1'  THEN 0
            WHEN idMay = 'p2'  THEN 2
            WHEN idMay = 'p3'  THEN 0
            WHEN idMay = 'p4'  THEN 1
            WHEN idMay = 'p5'  THEN 0
            WHEN idMay = 'p6'  THEN 2
            WHEN idMay = 'p7'  THEN 1
            WHEN idMay = 'p8'  THEN 2
            WHEN idMay = 'p9'  THEN 0
            WHEN idMay = 'p10' THEN 0
            WHEN idMay = 'p11' THEN 2
            WHEN idMay = 'p12' THEN 1
        END;

CREATE TABLE PhanmemUNIX (
    idPM    VARCHAR(6) NOT NULL,
    tenPM   VARCHAR(30) NOT NULL,
    ngaymua DATE,
    version VARCHAR(3)
);

ALTER TABLE PhanmemUnix ADD PRIMARY KEY ( idPM );

ALTER TABLE PhanmemUnix ADD gia INT CHECK ( gia > 0 );

ALTER TABLE PhanmemUnix MODIFY (
    version VARCHAR(15),
    tenPM unique
);


INSERT INTO PhanmemUnix (
    idPM,
    tenPM,
    ngaymua,
    version,
    gia
)
    SELECT idPM,
           tenPM,
           ngaymua,
           version,
           gia
    FROM Phanmem
    WHERE idloai = 'UNIX';
    
ALTER TABLE PhanmemUnix DROP COLUMN version;

DELETE FROM Phanmem WHERE gia > 5000; /*Xoa hang thu 2*/

DELETE FROM PhanmemUnix WHERE gia > 5000; /*Xoa hang thu 2*/

DROP TABLE Phanmem; /*Khong the xoa vi khoa chinh duoc tham chieu boi khoa ngoai trong bang Caidat*/

DROP TABLE PhanmemUnix; /*Xoa binh thuong vi khong co bang nao tham chieu den no*/

ALTER TABLE may DROP COLUMN nbLog;

ALTER TABLE Phanmem DROP COLUMN nbInstall;
