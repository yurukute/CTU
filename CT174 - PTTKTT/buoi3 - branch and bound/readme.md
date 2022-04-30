# Buổi 3: Thuật toán nhánh cận (Branch and Bound)
## Bài tập 1: Bài toán Đường đi người giao hàng (TSP)
Yêu cầu: Cài đặt bài toán đường đi người giao hàng bằng thuật toán Nhánh cận.

Chương trình phải bao gồm các thủ tục: Định nghĩa các kiểu cấu trúc dữ liệu phù hợp để lưu trữ dữ liệu, đọc dữ liệu từ tập tin, xây dựng phương án phân nhánh và tính cận; hàm main thực hiện chương trình và hiển thị ra màn hình các dữ liệu đã cho, phương án và tổng độ dài các cạnh trong chu trình.

File dữ liệu có tên `TSP1.txt` có dạng như sau:

{Dòng đầu tiên: số 5 là số thành phố (số đỉnh n) trên đồ thị 

n dòng tiếp theo, mỗi dòng có n cột là ma trận chứa trọng số các cạnh}
```
5
0 3.00 4.00 2.00 7.00
3.00 0 4.00 6.00 3.00
4.00 4.00 0 5.00 8.00
2.00 6.00 5.00 0 6.00
7.00 3.00 8.00 6.00 0
```
## Bài tập 2: Bài toán Cái ba lô 
Yêu cầu: Cài đặt bài toán Cái ba lô bằng thuật toán Nhánh cận.

Chương trình phải bao gồm các thủ tục: Định nghĩa các kiểu cấu trúc dữ liệu phù hợp để lưu trữ dữ liệu, đọc dữ liệu từ tập tin, sắp xếp theo đơn giá giảm dần, xây dựng phương án phân nhánh và tính cận; hàm main thực hiện chương trình và hiển thị ra màn hình các dữ liệu đã cho, phương án, tổng trọng lượng và tổng giá trị của đồ vật.
### Cái ba lô 1: Số lượng đồ vật không giới hạn
File dữ liệu `CaiBalo1.txt` có dạng như sau:

{Dòng đầu tiên: số 37 là trọng lượng của ba lô

4 dòng tiếp theo, mỗi dòng biểu diễn một đồ vật bao gồm: trọng lượng, giá trị và tên đồ vật}
```
37
15 30 Gao Mot bui
10 25 Nep cai hoa vang
2 2 Gao Nang huong
4 6 Gao Tai nguyen
```
### Cái ba lô 2: Mỗi đồ vật chỉ có một số lượng xác định
File dữ liệu `CaiBalo2.txt` có dạng như sau:

{Dòng đầu tiên: số 40 là trọng lượng của ba lô

5 dòng tiếp theo, mỗi dòng biểu diễn một đồ vật bao gồm: trọng lượng, giá trị, số lượng và tên đồ vật}
```
47
15 30 5 Gao Mot bui
10 25 1 Nep cai hoa vang
2 2 3 Gao Nang huong
4 6 2 Gao Tai nguyen
8 24 2 Gao ST25
```
### Cái ba lô 3: Mỗi đồ vật chỉ có 1 cái
File dữ liệu `CaiBalo3.txt` có dạng như sau:

{Dòng đầu tiên: số 30 là trọng lượng của ba lô

5 dòng tiếp theo, mỗi dòng biểu diễn một đồ vật bao gồm: trọng lượng, giá trị và tên đồ vật}
```
30
15 30 Gao Mot bui
10 25 Nep cai hoa vang
2 2 Gao Nang huong
4 6 Gao Tai nguyen
8 24 Gao ST25
```
