# Buổi 4: Thuật toán Quy hoạch động (Dynamic Programming)
## Bài tập 1: Bài toán Tam giác số 
Yêu cầu: Cài đặt bài toán Tam giác số bằng thuật toán Quy hoạch động.

Chương trình phải bao gồm các thủ tục đọc dữ liệu từ tập tin, xây dựng phương án theo công thức truy hồi, tạo và tra bảng dữ liệu; hàm main thực hiện chương trình và hiển thị ra màn hình **tam giác số, bảng số liệu F, phương án và tổng giá trị các số** trên đường đi từ dòng đầu đến dòng cuối.

File dữ liệu có tên `tam_giac_so.txt` kích thước n = 5 chứa các số nguyên như sau:
```
7
5 4
8 9 7
5 1 7 6
8 4 5 3 7
```
## Bài tập 2: Bài toán Cái ba lô 
Yêu cầu: Cài đặt bài toán Cái ba lô bằng thuật toán Quy hoạch động.

Chương trình đọc dữ liệu từ tập tin dữ liệu, xây dựng phương án theo công thức truy hồi, tạo và tra bảng dữ liệu, hàm main thực hiện chương trình và hiển thị ra màn hình **các dữ liệu đã cho, bảng số liệu [F, X], phương án viết dưới dạng danh sách X(x1,... , xn), tổng giá trị và tổng trọng lượng** đồ vật.
### Cái ba lô 1: Số lượng đồ vật không giới hạn
File dữ liệu `QHD_CaiBalo.txt` như sau:

{Dòng đầu tiên: số 9 có nghĩa là trọng lượng ba lô là 9

5 dòng tiếp theo, mỗi dòng biểu diễn một đồ vật bao gồm: trọng lượng, giá trị và tên}
```
9
3 4 Gao Mot bui
4 5 Nep cai hoa vang
5 6 Gao Nang huong
2 3 Gao Tai nguyen
1 1 Gao ST25
```
### Cái ba lô 2: Mỗi đồ vật chỉ có một số lượng xác định
File dữ liệu `QHD_CaiBalo2.txt` như sau:

{Dòng đầu tiên: số 9 có nghĩa là trọng lượng ba lô là 9

5 dòng tiếp theo, mỗi dòng biểu diễn một đồ vật bao gồm: trọng lượng, giá trị và tên}
```
9
3 4 1 Gao Mot bui
4 5 3 Nep cai hoa vang
5 6 2 Gao Nang huong
2 3 2 Gao Tai nguyen
1 1 2 Gao ST25
```
### Cái ba lô 3: Mỗi đồ vật chỉ có 1 cái
File dữ liệu `QHD_CaiBalo.txt`
