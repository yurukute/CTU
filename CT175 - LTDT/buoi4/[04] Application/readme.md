# 004. Ứng dụng xếp hạng
## Câu 1
Cô giáo Trang chuẩn bị kẹo để phát cho các bé mà cô đang giữ. Dĩ nhiên môi bé đều có một tên gọi rất dễ thương ví dụ: Mạnh Phát, Diễm Quỳnh, Đăng Khoa, ... Tuy nhiên, để đơn giản vấn đề ta có thể giả sử các em được đánh số từ 1 đến n.

Cô giáo muốn rằng tất cả các em đều phải có kẹo. Cô lại biết thêm rằng có một số bé có ý muốn hơn bạn mình một chút vì thế các em ấy muốn kẹo của mình nhiều hơn của bạn.

Hãy viết chương trình giúp cô tính xem mỗi em cần được chia ít nhất bao nhiêu kẹo và tổng số kẹo ít nhất mà cô phải chuẩn bị là bao nhiêu.

Đầu vào (Input):
- Dữ liệu đầu vào được nhập từ bàn phím với định dạng:
  - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số bé và số cặp bé mà trong đó có 1 bé muốn có kẹo hơn bạn mình.
  - m dòng tiếp theo mỗi dòng chứa 2 số nguyên a, b nói rằng bé a muốn có kẹo nhiều hơn bé b.

Đầu ra (Output)
- In ra màn hình số kẹo ít nhất của từng em, mỗi em trên một dòng.
- Dòng cuối cùng in tổng số kẹo ít nhất mà cô giáo Trang cần phải chuẩn bị.
## Câu 2
Trong một giải đấu bóng đá gồm n đội bóng, đánh số từ 1 đến n. Mỗi trận đấu có hai đội thi đấu với nhau cho đến khi phân biệt thắng thua (ví dụ: hiệp phụ, đá luân lưu). Sau khi giải đấu kết thúc, ban tổ chức muốn xếp hạng các đội theo quy tắc sau:

- Hạng được tính từ 1, 2, 3, ...
- Đội không thua trận nào xếp hạng 1
- Nếu đội A đá thắng đội B thì hạng của đội A nhỏ hơn hạng của đội B.
- Nếu một đội có thể nhận nhiều hạng khác nhau thì chọn hạng nhỏ nhất.

Hoặc bạn cũng có thể sử dụng định nghĩa sau: `Hạng(v) = max {Hạng(u) } + 1` với u là đội thắng v.

Hãy giúp ban tổ chức viết chương trình xếp hạng cho các đội. Giả sử không xảy ra trường hợp A thắng B, B thắng C ,..., Z thắng A.

Đầu vào (Input):
- Dữ liệu đầu vào được nhập từ bàn phím với định dạng:
  - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đội và số trận đấu.
  - m dòng tiếp theo mỗi dòng chứa 2 số nguyên u v mô tả kết quả trận đấu: u thắng, v thua.

Đầu ra (Output):
- In ra màn hình hạng của các đội bóng theo số thứ tự của đội trên cùng 1 dòng, mỗi đội cách nhau 1 khoảng trắng.
```
<Hạng đội 1> <Hạng đội 2> ... <Hạng đội n>
```
