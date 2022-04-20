# Buổi 2: Thuật toán Tham ăn

## Bài tập 1: Bài toán trả tiền của máy ATM
Yêu cầu: Cài đặt bài toán trả tiền của máy ATM bằng thuật toán Tham ăn, với cách trả tiền bằng các tờ tiền giấy mệnh giá đang lưu hành ở nước ta hiện nay.
- Chương trình nhận vào số tiền cần rút và hiển thị ra màn hình tổng số tờ tiền phải trả cùng với danh sách số tờ tiền phải trả theo từng mệnh giá.
- Chương trình phải chứa các thủ tục: Đọc file dữ liệu mệnh giá, Sắp xếp mệnh giá giảm dần, thực hiện thuật toán, In kết quả ra màn hình.

File dữ liệu có tên ATM.txt có dạng như sau:
```
1000 Mot ngan dong
2000 Hai ngan dong
5000 Nam ngan dong
10000 Muoi ngan dong
20000 Hai muoi ngan dong
50000 Nam muoi ngan dong
100000 Mot tram ngan dong
200000 Hai tram ngan dong
500000 Nam tram ngan dong
```
## Bài tập 2: Bài toán Đường đi người giao hàng (TSP)
Yêu cầu: Cài đặt bài toán đường đi người giao hàng bằng thuật toán Tham ăn. 

Chương trình phải chứa các thủ tục: Đọc file dữ liệu, Sắp xếp độ dài cạnh tăng dần, Xét chọn cạnh vào chu trình theo ý tưởng thuật toán, In kết quả ra màn hình bao gồm: phương án và tổng độ dài các cạnh trong chu trình.

File dữ liệu có tên TSP.txt có dạng như sau:

{Dòng đầu tiên: số 6 là số thành phố (số đỉnh n) trên đồ thị <br>
n dòng tiếp theo, mỗi dòng có n cột là ma trận chứa trọng số các cạnh}
```
6
0     5.00  7.07  16.55 15.52 18.00
5.00  0     5.00  11.70 11.05 14.32
7.07  5.00  0     14.00 14.32 18.38
16.55 11.70 14.00 0     3.00  7.62
15.52 11.05 14.32 3.00  0     5.00
18.00 14.32 18.38 7.62  5.00  0
```
## Bài tập 3: Bài toán Cái ba lô 
Yêu cầu: Cài đặt bài toán Cái ba lô bằng thuật toán Tham ăn. 

Chương trình phải bao gồm các hàm : Định nghĩa các kiểu cấu trúc dữ liệu phù hợp để lưu trữ dữ liệu, đọc dữ liệu từ tập tin, sắp xếp theo đơn giá giảm dần, xây dựng phương án; hàm main thực hiện chương trình và hiển thị ra màn hình: phương án, tổng trọng lượng và tổng giá trị của balô.
### Cái ba lô 1: Số lượng đồ vật không giới hạn
File dữ liệu CaiBalo1.txt có dạng như sau:

{Dòng đầu tiên: số 37 là trọng lượng của ba lô <br>
4 dòng tiếp theo, mỗi dòng biểu diễn một đồ vật bao gồm: trọng lượng, giá trị và tên đồ vật}
```
37
15 30 Gao Mot bui
10 25 Nep cai hoa vang
2  2  Gao Nang huong
4  6  Gao Tai nguyen
```
### Cái ba lô 2: Mỗi đồ vật chỉ có một số lượng xác định
File dữ liệu CaiBalo2.txt có dạng như sau:
{Dòng đầu tiên: số 40 là trọng lượng của ba lô <br>
5 dòng tiếp theo, mỗi dòng biểu diễn một đồ vật bao gồm: trọng lượng, giá trị, số lượng và tên đồ vật}
```
47
15 30 5 Gao Mot bui
10 25 1 Nep cai hoa vang
2  2  3 Gao Nang huong
4  6  2 Gao Tai nguyen
8  24 2 Gao ST25
```
### Cái ba lô 3: Mỗi đồ vật chỉ có 1 cái
File dữ liệu CaiBalo3.txt có dạng như sau:
*{Dòng đầu tiên: số 30 là trọng lượng của ba lô <br>
5 dòng tiếp theo, mỗi dòng biểu diễn một đồ vật bao gồm: trọng lượng, giá trị và tên đồ vật}*
```
30
15 30 Gao Mot bui
10 25 Nep cai hoa vang
2  2  Gao Nang huong
4  6  Gao Tai nguyen
8  24 Gao ST25 
```
