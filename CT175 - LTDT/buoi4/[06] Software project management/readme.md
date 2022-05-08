# 006. Quản lý dự án phần mềm
Khôi là người quản lý dự án của công ty phần mềm Grafity Ltd. Nhiệm vụ của anh là nhận dự án, phân tích và chia phân công các lập trình viên thực hiện nó. Khi nhận được dự án, việc đầu tiên của Khôi là phân chia dự án thành các công việc và ước lượng thời gian hoàn thành từng công việc. Ngoài ra, tùy theo dự án, các công việc này có thể phụ thuộc nhau ví dụ: công việc A cần phải làm xong rồi thì mới có thể thực hiện công việc B.

Sau khi có được danh sách các công việc, thời gian hoàn thành các công việc và sự phụ thuộc giữa chúng. Khôi sẽ ước lượng được cần ít nhất bao nhiêu thời gian để hoàn thành dự án. Làm thủ công khá mất thời gian nên Khôi mới nhờ đến bạn. Hãy lập trình để giúp anh ấy.

Đầu vào (Input)
- Dữ liệu đầu vào được nhập từ bàn phím với định dạng:
  - Dòng đầu tiên chứa 1 số nguyên n là số công việc.
  - Dòng thứ 2 chứa n số nguyên tương ứng với thời gian hoàn thành của n công việc
  - Dòng thứ 3 chứa 1 số nguyên m cho biết số cặp công việc phụ thuộc nhau
  - m dòng tiếp theo, mỗi dòng chứa 2 số nguyên A B nói rằng phải hoàn thành công việc A xong thì mới có thể bắt đầu B..

Đầu ra (Output)
- In ra màn hình một số nguyên duy nhất cho biết tổng thời gian ít nhất để hoàn thành dự án.
