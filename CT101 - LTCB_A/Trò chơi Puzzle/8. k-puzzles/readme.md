Hãy tổng hợp các chương trình con đã viết trong các bài tập trước đó để viết chương trình mô phỏng trò chơi đẩy ô số (k-puzzles).

Chương trình này sẽ lần lượt làm các công việc sau:
- Khai báo biến `S`, `N` là 2 trạng thái, `fname`, `cmd`: kiểu chuỗi ký tự.
- Đọc một tên tập tin `fname` từ bàn phím (giả sử tên tập tin không chứa khoảng trắng).
- Khởi tạo trạng thái bắt đầu `S` của trò chơi bằng cách đọc nội dung của tập tin fname.
- **while** (`S` chưa phải là trạng thái kết thúc)
    - In trạng thái `S` ra màn hình sử dụng hàm print_state trong bài tập trước.
    - Đọc một lệnh điều khiển từ người dùng vào biến `cmd` (giả sử người dùng có thể nhập lện bất kỳ)
    - Nếu lệnh nhập vào là "UP" thì di chuyển ô trống lên trên và gán `S` bằng trạng thái mới. Nếu di chuyển không được thì in ra câu "**Illegal move.**"
    - Xử lý tương tự cho các lệnh "DOWN", "LEFT", "RIGHT"
    - Nếu lệnh nhập vào là "EXIT" thì in ra câu "**You lose!**" và break để thoát khỏi vòng lặp.
    - Các trường hợp khác, in ra câu "**Unknown command, please enter: UP, DOWN, LEFT, RIGHT or EXIT**"
- Kiểm tra nếu S là trạng thái kết thúc, in ra câu "**You win!**"


**Đầu vào**
- Dữ liệu được đọc từ bàn phím, dòng đầu tiên chứa tên file đầu vào (tên file không có khoảng trắng, chiều dài tối đa 10 ký tự).
- Các dòng tiếp theo mỗi dòng chứa 1 lệnh
- Dòng cuối cùng chứa lệnh EXIT
Test mẫu: [puzzle1.txt](./puzzle1.txt), [puzzle2.txt](./puzzle2.txt)

**Đầu ra**
- Trong vòng lặp, in trạng thái hiện tại S và xử lý các lệnh đọc vào.

**Chú ý**
- Dữ liệu đầu vào luôn hợp lệ, không cần kiểm tra
- Nếu bạn thắng trước khi xử lý hết lệnh thì bỏ qua phần lệnh còn lại
- Chỉ viết hàm KHÔNG VIẾT TOÀN BỘ CHƯƠNG TRÌNH
- Xem thêm mẫu in ra trong phần For example.

**Gợi ý**
- Sử dụng **fgets** để đọc các lệnh, xử lý ký tự '\n' ở cuối chuỗi (nếu có).
- Sử dụng lệnh **strcmp** để so sánh 2 chuỗi ký tự.