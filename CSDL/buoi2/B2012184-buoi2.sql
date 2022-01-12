CREATE TABLE PHICONG (
    MPC     SMALLINT PRIMARY KEY,
    hoten   VARCHAR(30) NOT NULL,
    dchi    VARCHAR(30),
    quocgia VARCHAR(20)
);

CREATE TABLE CONGTY (
    MCT     SMALLINT PRIMARY KEY,
    tencty  VARCHAR(30) UNIQUE,
    quocgia VARCHAR(20)
);

CREATE TABLE LOAIMAYBAY (
    loai  VARCHAR(20) PRIMARY KEY,
    NXS   VARCHAR(50),
    socho INT
);

CREATE TABLE MAYBAY (
    MMB  SMALLINT PRIMARY KEY,
    loai VARCHAR(20),
    MCT  SMALLINT,
    FOREIGN KEY ( loai )
        REFERENCES LOAIMAYBAY ( loai ),
    FOREIGN KEY ( MCT )
        REFERENCES CONGTY ( MCT )
);

CREATE TABLE CHUYENBAY (
    SOCB       VARCHAR(10) NOT NULL,
    ngaybay    DATE,
    MPC        SMALLINT NOT NULL,
    MMB        SMALLINT NOT NULL,
    noidi      VARCHAR(20) DEFAULT 'Can Tho',
    noiden     VARCHAR(20) DEFAULT 'Ha Noi',
    khoangcach INT CHECK ( khoangcach > 0
                           AND khoangcach <= 1000 ),
    giodi      CHAR(5),
    gioden     CHAR(5),
    PRIMARY KEY ( SOCB,
                  ngaybay ),
    CONSTRAINT fk_MPC FOREIGN KEY ( MPC )
        REFERENCES PHICONG ( MPC ),
    FOREIGN KEY ( MMB )
        REFERENCES MAYBAY ( MMB )
);

CREATE TABLE LAMVIEC (
    MPC    SMALLINT NOT NULL,
    MCT    SMALLINT NOT NULL,
    ngayBD DATE NOT NULL,
    songay INT,
    PRIMARY KEY ( MPC,
                  MCT,
                  ngayBD ),
    FOREIGN KEY ( MPC )
        REFERENCES PHICONG ( MPC ),
    FOREIGN KEY ( MCT )
        REFERENCES CONGTY ( MCT )
);

INSERT INTO PHICONG VALUES (
    1,
    'Phung Phung Phi',
    'Can Tho',
    'Viet Nam'
);

INSERT INTO PHICONG VALUES (
    2,
    'Tao Tung Thieu',
    'Bac Ninh',
    'Viet Nam'
);

INSERT INTO CONGTY VALUES (
    1,
    'Vietnam Airlines',
    'Viet Nam'
);

INSERT INTO CONGTY VALUES (
    2,
    'VietJet Air',
    'Viet Nam'
);

INSERT INTO LOAIMAYBAY VALUES (
    'A320',
    'Airbus',
    180
);

INSERT INTO LOAIMAYBAY VALUES (
    'A321',
    'Airbus',
    184
);

INSERT INTO MAYBAY VALUES (
    1,
    'A320',
    2
);

INSERT INTO MAYBAY VALUES (
    2,
    'A321',
    2
);

INSERT INTO CHUYENBAY (
    SOCB,
    ngaybay,
    MPC,
    MMB,
    khoangcach,
    giodi,
    gioden
) VALUES (
    'CB01',
    '1-JAN-22',
    1,
    2,
    700,
    '03:00',
    '06:00'
);

INSERT INTO CHUYENBAY VALUES (
    'CB02',
    '14-FEB-22',
    2,
    2,
    'Ha Noi',
    'Can Tho',
    700,
    '03:00',
    '06:00'
);

INSERT INTO LAMVIEC VALUES (
    1,
    2,
    '1-JAN-22',
    31
);

INSERT INTO LAMVIEC VALUES (
    2,
    2,
    '1-FEB-22',
    31
);