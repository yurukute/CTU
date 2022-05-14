# Bài 5.3. Ứng dụng cây khung
## Câu 1
Cho đồ thị G = <V, E> vô hướng, liên thông và có trọng số. Viết chương trình tìm cách xoá một số cung của G sao cho G vẫn còn liên thông và tổng trọng số của các cung bị xoá là lớn nhất.

Đầu vào
- Dữ liệu đầu vào được nhập từ bàn phím với định dạng
  - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung.
  - m dòng tiếp theo mỗi dòng chứa 3 số nguyên u, v, w mô tả cung (u, v) có trọng số w.

Đầu ra
- In ra màn hình tổng trọng số của các cung bị xoá.
## Câu 2
Cho đồ thị vô hướng, liên thông và có trọng số G = <V, E>. Viết chương trình tìm cây khung có trọng số nhỏ nhất bằng thuật toán Prim. Giả sử ta luôn chọn đỉnh 1 làm đỉnh khởi tạo.

Đầu vào (Input)
- Dữ liệu đầu vào được nhập từ bàn phím với định dạng
  - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung.
  - m dòng tiếp theo mỗi dòng chứa 3 số nguyên u, v, w mô tả cung (u, v) có trọng số w.

Đầu ra (Output)
- In ra màn hình các đỉnh được chọn theo thứ tự của thuật toán Prim, mỗi đỉnh trên 1 dòng.
## Câu 3
> Ngưu Lang là vị thần chăn trâu của Ngọc Hoàng Thượng đế, vì say mê một tiên nữ phụ trách việc dệt vải tên là Chức Nữ nên bỏ bễ việc chăn trâu, để trâu đi nghênh ngang vào điện Ngọc Hư. Chức Nữ cũng vì mê tiếng tiêu của Ngưu Lang nên trễ nải việc dệt vải. Ngọc Hoàng giận dữ, bắt cả hai phải ở cách xa nhau, người đầu sông Ngân, kẻ cuối sông.
>
> Mỗi năm một lần, Sau đó, Ngọc Hoàng thương tình nên ra ơn cho hai người mỗi năm được gặp nhau vào ngày 7 tháng Bảy âm lịch. Khi tiễn biệt nhau, Ngưu Lang và Chức Nữ khóc sướt mướt. Nước mắt của họ rơi xuống trần hóa thành cơn mưa và được người dưới trần gian đặt tên là mưa ngâu." (Theo wikipedia.com)

Để gặp được nhau vào ngày 7/7, Ngưu Lang và Chức Nữ phải nhờ đến bầy quạ đen bắt cầu (gọi là Ô kiều) cho mình đi qua để gặp nhau.

Sông Ngân Hà có n ngôi sao, giả sử được đánh số từ 1 đến n. Ngưu Lang ở tại ngôi sao Ngưu (Altair), được đánh số 1, còn Chức Nữ thì mỗi năm lại ở tại một ngôi sao khác nhau trong các ngôi sao từ 2 đến n. Để bắt được một cây cầu từ ngôi sao này sang ngôi sao kia cần một số lượng quạ nào đó. Một khi con quạ ở cây cầu nào thì phải ở đó cho đến khi Ngưu Lang và Chức Nữ gặp được nhau.

Vì không biết Chức Nữ đang ở ngôi sao nào nên Ngưu Lang cần bắt cầu sao cho từ ngôi sao số 1, anh ta có thể đi đến được tất cả các ngôi sao khác (dĩ nhiên là để tìm Chức Nữ).

Quạ thì càng ngày càng hiếm, mà Ngưu Lang chỉ có đủ tiền để thuê được tối đa k con quạ thôi nên Ngưu Lang phải tính toán sao cho số lượng quạ dùng để bắt cầu ít nhất có thể.

Hãy giúp Ngưu Lang viết chương trình tính xem Ngưu Lang có thể gặp được Chức Nữ không. Nếu thiếu thì thiếu bao nhiêu con quạ.

Đầu vào (Input)
- Dữ liệu đầu vào được nhập từ bàn phím với định dạng:
  - Dòng đầu tiên chứa 3 số nguyên n, m và k, tương ứng là số ngôi sao, số cặp sao có thể bắt cầu và số quạ mà Ngưu Lang có thể thuê.
  - m dòng tiếp theo mỗi dòng chứa 3 số nguyên u v q nói rằng để bắt 1 cây cầu bắt qua hai ngôi sao u và v cần phải tốn q con quạ.

Đầu ra (Output)
- Nếu số quạ cần thiết <= k thì in ra màn hình OK, ngược lại in ra số quạ còn thiếu.
## Câu 4
Lý Thường Kiệt (sinh năm 1019, mất 1105) là một danh tướng đời nhà Lý có công lớn trong việc đánh bại quân nhà Tống vào năm 1075-1077. Ông được cho là đã viết ra bản tuyên ngôn độc lập đầu tiên của dân tộc ("Nam Quốc Sơn Hà").

> "Tháng 3 năm 1076, nhà Tống sai tuyên phủ sứ Quảng Nam là Quách Quỳ làm chiêu thảo sứ, Triệu Tiết làm phó, đem quân 9 tướng, hẹn với Chiêm Thành và Chân Lạp sang xâm lấn Đại Việt, ... Quân Tống tràn xuống, theo đường tắt qua dãy núi Đâu Đỉnh, tới phía tây bờ sông Phú Lương; trong khi đó, một cánh quân tách ra, vòng sang phía đông đánh bọc hậu quân Nam ở Giáp Khẩu (Chi Lăng) và thẳng tới sông Cầu.

Để đối phó với quân Tống trong tình hình này Lý Thường Kiệt lập chiến luỹ sông Như Nguyệt để chống Tống."

Chiến luỹ sông Như Nguyệt có n điểm trọng yếu cần phải bảo vệ, giả sử được đánh số từ 1 đến n. Lý Thường Kiệt cần phải bố trí các con đường an toàn để điều động quân lính từ một điểm trọng yếu này đến một điểm trọng yếu khác. Để xây dựng một con đường an toàn từ một điểm trọng yếu u này đến một điểm trọng yếu v cần một lượng đất đá là w(u, v) sọt.

Hãy giúp Lý Thường Kiệt tìm cách xây dựng các con đường an toàn sao cho từ bất kỳ một điểm trọng yếu nào cũng đều có thể đi đến một điểm trọng yếu khác bằng cách sử dụng các con đường an toàn và tổng số đất đá được sử dụng là ít nhất.

Đầu vào (Input)
- Dữ liệu đầu vào được nhập từ bàn phím với định dạng:
  - Dòng đầu tiên chứa 2 số nguyên n, m tương ứng là số điểm trọng yếu, số con đường an toàn có thể xây dựng.
  - m dòng tiếp theo mỗi dòng chứa 3 số nguyên u v w nói rằng để xây dựng 1 con đường an toàn nối 2 điểm trọng yếu u và v cần phải tốn w sọt đất đá.

Đầu ra (Output)
- In ra tổng số sọt đất đá được sử dụng.
## Câu 5
Hoàng là thợ điện. Anh được thuê sửa lại hệ thống điện cho một căn nhà. Tình trạng hiện tại của hệ thống điện như sau: nguồn điện chính được cung cấp từ đồng hồ điện. Chủ nhà muốn lấy điện từ nguồn điện chính để cấp điện cho n - 1 vị trí trong nhà bằng cách sử dụng dây điện (dĩ nhiên là phải dùng dây điện để dẫn điện rồi smile ). Để đơn giản hoá vấn đề ta có thể xem nguồn điện chính là vị trí 1, các vị trí cần lấy điện được đánh số lần lượt là 2, 3, ..., n. Hoàng có thể dùng dây điện để nối hai vị trí lại với nhau. Ngoài ra, Hoàng còn phải quan tâm đến loại dây điện sử dụng để nối hai vị trí này. Mỗi loại dây lại có một giá thành khác nhau.

Bài toán đặt ra cho Hoàng là sử dụng đây điện và nối dây như thế nào để tất cả các vị trí đều có điện với giá thành mua dây điện rẻ nhất.

Hãy lập trình để giúp Hoàng, anh ta sẽ cảm ơn bạn nhiều lắm!

Đầu vào
- Dữ liệu đầu vào được nhập từ bàn phím với định dạng
  - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số vị trí (kể cả nguồn điện chính) và số cặp vị trí có thể nối dây điện với nhau.
  - m dòng tiếp theo mỗi dòng chứa 4 số nguyên u, v, s, d nói rằng để nối hai vị trí u và v lại với nhau cần tốn s (mét) dây, mỗi mét có giá là d (đơn vị tiền).

Đầu ra:
- In ra màn hình tổng số tiền ít nhất để mua dây điện.
## Câu 6
Trong một khu rừng nọ, có một bầy nai và n bãi cỏ. Để đi từ bãi cỏ này sang bãi cỏ kia, bầy nai sẽ đi theo những con đường mòn được tạo ra từ trước. Sau một thời gian, bầy nai nhận ra rằng chúng chỉ cần một số đường mòn là có thể đi từ một bãi cõ bất kỳ đến một bãi cỏ khác. Trên mỗi con đường mòn có một số nguy rình rập bầy nai (ví dụ có hổ, sói, ...). Để đơn giản ta có thể giả sử độ nguy hiểm của mỗi con đường là 1 số nguyên từ 1 (ít nguy hiểm nhất) đến 100 (nhiều nguy hiểm nhất).

Hãy viết chương trình giúp bầy nai tìm các con đường mòn cần thiết sao cho tổng độ nguy hiểm thấp nhất.

Đầu vào
- Dữ liệu đầu vào được nhập từ bàn phím với định dạng
  - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số bãi cỏ và số con đường mòn.
  - m dòng tiếp theo mỗi dòng chứa 3 số nguyên u, v, w mô tả con đường mòn (u, v) với độ nguy hiểm w.

Đầu ra
- In ra màn hình tổng độ nguy hiểm thấp nhất.
