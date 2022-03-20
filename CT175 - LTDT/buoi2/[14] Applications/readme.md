# Bài tập 14 - Ứng dụng liên thông mạnh
## Câu 1: Come and Go (nguồn: UVA Online Judge, Problem 11838)
Trong một thành phố có N địa điểm được nối với nhau bằng M con đường 1 chiều và 2 chiều. Yêu cầu tối thiểu của một thành phố là từ địa điểm này bạn phải có thể đi đến một địa điểm khác bất kỳ.

Hãy viết chương trình kiểm tra xem các con đường của thành phố có thoả mãn yêu cầu tối thiểu này không.

Dữ liệu đầu vào có dạng như sau:
```
4 5
1 2 1
1 3 2
2 4 1
3 4 1
4 1 2
```
Trong ví dụ này, có 4 địa điểm và 5 con đường, mỗi con đường có dạng a b p,  trong đó a, b là các địa điểm; và nếu p = 1, con đường đang xét là đường 1 chiều, ngược lại nó là đường 2 chiều.

Đầu vào (Input)
- Dữ liệu đầu vào được nhập từ bàn phím (stdin) với định dạng:
- Dòng đầu tiên chứa 2 số nguyên N và M, tương ứng là số địa điểm và số con đường.
- M dòng tiếp theo mỗi dòng chứa 3 số nguyên a, b, p. Nếu p = 1, con đường (a, b) là con đường 1 chiều, ngược lại nếu p = 2, con đường (a, b) là con đường 2 chiều.

Đầu ra (Output)
- In ra màn hình OKIE nếu các con đường của thành phố có thoả mãn yêu cầu, ngược lại in ra NO.

Gợi ý
- Xây dựng đồ thị có hướng từ dữ liệu các con đường và các địa điểm
- Địa điểm ~ đỉnh
- Đường 1 chiều ~ cung
- Đường 2 chiều ~ 2 cung
- Áp dụng giải thuật kiểm tra đồ thị có liên thông mạnh hay không.

## Câu 2: Trust group (nguồn: UVA Online Judge, Problem 11709)
Phòng nhân sự của tổ chức Association of Cookie Monsters (ACM) nhận thấy rằng gần đây hiệu quả làm việc của các nhân viên có chiều hướng giảm sút. Vì thế họ đã lấy ý kiến các nhân viên và phát hiện ra nguyên nhân của vấn đề này, đó là: sự tin cậy. Một số nhân viên không tin cậy vào các nhân viên khác trong nhóm làm việc của mình. Điều này làm giảm động lực và niềm vui trong công việc của các nhân viên.

Phòng nhân sự muốn giải quyết triệt để vấn đề này nên họ quyết định tổ chức lại các nhóm làm việc sao cho ổn định. Một nhóm làm việc sẽ ổn định khi mà những người trong nhóm tin cậy lẫn nhau. Họ đã hỏi các nhân viên và biết được những người mà một nhân viên tin cậy trực tiếp. Ngoài ra, sự tin cậy có tính bắt cầu: nếu A tin cậy B và B tin cậy C thì A cũng sẽ tin cậy C. Lẽ dĩ nhiên, một nhân viên sẽ tự tin cậy chính bản thân mình. Tuy nhiên, cần chú ý là sự tin cậy lại không có tính đối xứng: A tin cậy B thì không nhất thiết B phải tin cậy A.

Phòng nhân sự muốn tổ chức thành ít nhóm nhất có thể. Hãy lập trình để giúp họ.

Giả sử các nhân viên được đánh số là 1, 2, ..., n.

Đầu vào (Input)
- Dữ liệu đầu vào được nhập từ bàn phím theo định dạng:
  - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số nhân viên và số cặp tin cậy.
  - m dòng tiếp theo, mỗi dòng chứa 2 số nguyên a b, nói rằng người a tin cậy vào người b.

Đầu ra (Output)
- In ra màn hình số lượng nhóm ít nhất mà những người trong nhóm đều tin cậy lẫn nhau
