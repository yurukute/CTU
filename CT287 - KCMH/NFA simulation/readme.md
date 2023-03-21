Viết chương trình mô phỏng hoạt động của 1 NFA (without ϵ) với chuỗi nhập đầu vào. 

Đầu vào
- Dòng đầu tiên là một chuỗi, tên tập tin json chứa định nghĩa về NFA
- Dòng thứ 2 là một số nguyên dương n - số chuỗi nhập cần kiểm tra
- n dòng kế tiếp, mỗi dòng là một chuỗi nhập thứ i cần kiểm tra có được chấp nhận bởi NFA hay không?

Đầu ra
- n dòng, mỗi dòng là YES nếu chuỗi thứ i được chấp nhận, NO nếu chuỗi thứ i không được chấp nhận

Gợi ý

Thiết kế lớp NFA với các thuộc tính (Q, Σ, q0, F, δ) trong đó:
- Q: tập các trạng thái
- Σ: tập các ký hiệu nhập
- q0: trạng thái bắt đầu
- F: tập trạng thái kết thúc
- δ: các phép chuyển trạng thái
