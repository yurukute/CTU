CREATE TABLE SANPHAM (
    MaSP  CHAR(4) PRIMARY KEY,
    tenSP VARCHAR(30) NOT NULL,
    DVT   VARCHAR(4) NOT NULL
);

CREATE TABLE Nhanvien (
    MaNV    CHAR(4) PRIMARY KEY,
    HotenNV VARCHAR(30) NOT NULL,
    DT      CHAR(10) NOT NULL,
    Email   VARCHAR(30) NULL
);

CREATE TABLE Khachhang (
    MaKH    CHAR(4) PRIMARY KEY,
    HotenKH VARCHAR(30) NOT NULL,
    DT      CHAR(10) NOT NULL,
    Email   VARCHAR(30) NULL
);

CREATE TABLE PhieuXuat (
    SoPX    CHAR(5) PRIMARY KEY,
    MaNV    CHAR(4),
    MaKH    CHAR(4),
    Ngayban DATE,
    FOREIGN KEY ( MaNV )
        REFERENCES Nhanvien ( MaNV ),
    FOREIGN KEY ( MaKH )
        REFERENCES Khachhang ( MaKH )
);

CREATE TABLE ChitietPX (
    SoPX    CHAR (5),
    MaSP    CHAR (4),
    Soluong INT CHECK (Soluong > 0),
    Giaban  INT CHECK (Giaban > 0),
    PRIMARY KEY (SoPX,
                 MaSP),
    FOREIGN KEY (SoPX)
        REFERENCES PHIEUXUAT (SoPX),
    FOREIGN KEY (MaSP)
        REFERENCES SANPHAM (MaSP)
);

INSERT INTO SANPHAM VALUES ('SP01','Bot Chien Min 100g','Goi');
INSERT INTO SANPHAM VALUES ('SP02','Bot Chien Xu 100g','Goi');
INSERT INTO SANPHAM VALUES ('SP03','Dau Cai Lan 1l','Chai');
INSERT INTO SANPHAM VALUES ('SP04','Hat Nem 3 ngot 900g','Goi');
INSERT INTO SANPHAM VALUES ('SP05','Hat Nem Aji Ngon 200g','Goi');
INSERT INTO SANPHAM VALUES ('SP06','Hay Nem Knorr 200g','Goi');
INSERT INTO SANPHAM VALUES ('SP07','My Chinh AJINOMOTO 150kg','Goi');
INSERT INTO SANPHAM VALUES ('SP08','My Chinh Ajinomoto 2kg','Goi');
INSERT INTO SANPHAM VALUES ('SP09','My Chinh Ajinomoto 400g','Goi');
INSERT INTO SANPHAM VALUES ('SP10','Nestcafe hop','Hop');
INSERT INTO SANPHAM VALUES ('SP11','Nuoc mam De Nhi','Chai');
INSERT INTO SANPHAM VALUES ('SP12','Nuoc mam Nam Ngu 500ML','Chai');
INSERT INTO SANPHAM VALUES ('SP13','Sua Bavi 110ml','Hop');
INSERT INTO SANPHAM VALUES ('SP14','Sua Bavi 180ml','Hop');
INSERT INTO SANPHAM VALUES ('SP15','Sua co gai Ha Lan Socola','Hop');
INSERT INTO SANPHAM VALUES ('SP16','Sua Izzi 110ml','Hop');
INSERT INTO SANPHAM VALUES ('SP17','Sua Izzi 180ml','Hop');
INSERT INTO SANPHAM VALUES ('SP18','Sua Moc Chau 110ml','Hop');
INSERT INTO SANPHAM VALUES ('SP19','Sua Moc Chau 180ml','Hop');
INSERT INTO SANPHAM VALUES ('SP20','Sua TH Truemilk 110ml','Hop');

INSERT INTO Nhanvien VALUES ('NV01', 'Phan Thanh Duy', '0913244123', 'phanthanhduy@gmail.com');
INSERT INTO Nhanvien VALUES ('NV02', 'Lam Dai Ngoc', '0913455988', 'lamdaingoc@gmail.com');
INSERT INTO Nhanvien VALUES ('NV03', 'Tran Chau Khoa', '0908111222', 'tranchaukhoa@gmail.com');
INSERT INTO Nhanvien VALUES ('NV04', 'Le Chi Kien', '0123456123', 'lechikien@gmail.com');
INSERT INTO Nhanvien VALUES ('NV05', 'Phan Thanh Tam', '097899233', 'phanthanhtam@gmail.com');
INSERT INTO Nhanvien VALUES ('NV06', 'Mai Thi Luu', '0971224551', 'maithiluu@gmail.com');
INSERT INTO Nhanvien VALUES ('NV07', 'Dao Thi Hong', '0839970944', 'daothihong@gmail.com');
INSERT INTO Nhanvien VALUES ('NV08', 'Phan Thanh Nhan', '0839770941', 'phanthanhnhan@gmail.com');
INSERT INTO Nhanvien VALUES ('NV09', 'Phan Nguyen Anh Duong', '0918183444', 'anhduong@gmail.com');
INSERT INTO Nhanvien VALUES ('NV10', 'Phan Nguyen Anh Nguyet', '0918183404', 'phannguyenanhnguyet@gmail.com');

INSERT INTO Khachhang VALUES ('KH01', 'Nguyen Dinh An', '0902069548', NULL);
INSERT INTO Khachhang VALUES ('KH02', 'Nguyen Nguyen Bach', '0912123521', NULL);
INSERT INTO Khachhang VALUES ('KH03', 'Huynh Cong Bang', '0971236547', NULL);
INSERT INTO Khachhang VALUES ('KH04', 'Tran Bao Toan', '0378073268', NULL);
INSERT INTO Khachhang VALUES ('KH05', 'Ho Minh Tan', '0348953499', NULL);
INSERT INTO Khachhang VALUES ('KH06', 'Vo Hoai Van', '0393142588', NULL);
INSERT INTO Khachhang VALUES ('KH07', 'Phan Tinh Vu', '0346180470', NULL);
INSERT INTO Khachhang VALUES ('KH08', 'Ly Vu An','0867797366', NULL);
INSERT INTO Khachhang VALUES ('KH09', 'Phung Phung Phi', '0394801066', NULL);
INSERT INTO Khachhang VALUES ('KH10', 'Tao Tung Thieu', '0399482442', NULL);

INSERT INTO PhieuXuat VALUES ('PX001','NV02','KH01','03-MAY-13');
INSERT INTO PhieuXuat VALUES ('PX002','NV03','KH02','12-MAY-13');
INSERT INTO PhieuXuat VALUES ('PX003','NV01','KH03','10-MAY-13');
INSERT INTO PhieuXuat VALUES ('PX004','NV05','KH08','15-MAY-13');
INSERT INTO PhieuXuat VALUES ('PX005','NV06','KH07','01-JUN-13');
INSERT INTO PhieuXuat VALUES ('PX006','NV02','KH05','15-JUN-13');
INSERT INTO PhieuXuat VALUES ('PX007','NV07','KH10','22-JUN-13');
INSERT INTO PhieuXuat VALUES ('PX008','NV10','KH04','23-JUN-13');
INSERT INTO PhieuXuat VALUES ('PX009','NV09','KH09','25-JUN-13');
INSERT INTO PhieuXuat VALUES ('PX010','NV02','KH10','26-JUN-13');
INSERT INTO PhieuXuat VALUES ('PX011','NV08','KH07','26-JUN-13');
INSERT INTO PhieuXuat VALUES ('PX012','NV04','KH04','26-JUN-13');

INSERT INTO ChitietPX VALUES ('PX001','SP01',12,160000);
INSERT INTO ChitietPX VALUES ('PX001','SP02',150,15000);
INSERT INTO ChitietPX VALUES ('PX002','SP03',2,50000);
INSERT INTO ChitietPX VALUES ('PX002','SP07',20,18000);
INSERT INTO ChitietPX VALUES ('PX003','SP06',2,250000);
INSERT INTO ChitietPX VALUES ('PX003','SP10',20,3600);
INSERT INTO ChitietPX VALUES ('PX004','SP07',25,18000);
INSERT INTO ChitietPX VALUES ('PX004','SP15',5,100000);
INSERT INTO ChitietPX VALUES ('PX005','SP06',10,250000);
INSERT INTO ChitietPX VALUES ('PX005','SP20',16,15000);
INSERT INTO ChitietPX VALUES ('PX006','SP01',23,160000);
INSERT INTO ChitietPX VALUES ('PX006','SP10',10,3600);
INSERT INTO ChitietPX VALUES ('PX007','SP04',56,26000);
INSERT INTO ChitietPX VALUES ('PX007','SP13',12,75000);
INSERT INTO ChitietPX VALUES ('PX007','SP15',3,100000);
INSERT INTO ChitietPX VALUES ('PX008','SP02',80,15000);
INSERT INTO ChitietPX VALUES ('PX008','SP09',5,5000000);
INSERT INTO ChitietPX VALUES ('PX009','SP04',5,26000);
INSERT INTO ChitietPX VALUES ('PX009','SP17',80,22000);
INSERT INTO ChitietPX VALUES ('PX010','SP16',500,5000);
INSERT INTO ChitietPX VALUES ('PX011','SP18',7,98000);
INSERT INTO ChitietPX VALUES ('PX012','SP19',2,7800000);

UPDATE ChitietPX
SET
    Giaban = 5100000
WHERE (SoPX = 'PX008' AND MaSP = 'SP09');

DELETE FROM ChitietPX
WHERE (SoPX = 'PX004' AND MaSP = 'SP07');

ALTER TABLE ChitietPX MODIFY Giaban Numeric(12,1);
