# Bài tập buổi 2
Tạo CSDL minh họa trong slides, lưu ý phải có các ràng buộc khóa chính, khóa ngoại, kiểm tra, not null, default.


Nhập vào ít nhất 2 dòng cho mỗi bảng.


| PHICONG(**MPC**, hoten, dchi, quocgia)                                             |
| CONGTY (**MCT**, tencty, quocgia)                                                  |
| LOAIMAYBAY(**loai**, NSX, socho)                                                   |
| MAYBAY(**MMB**, *loai, MCT*)                                                       |
| CHUYENBAY(**SOCB, ngaybay**, *MPC, MMB*, noidi, noiden, khoangcach, giodi, gioden) |
| LAMVIEC(***MPC, MCT*, ngayBD**, songay)                                            |
