Viết chương trình mô phỏng hoạt động của 1 DFA với một chuỗi nhập đầu vào.

Đầu vào
- Dòng đầu tiên gồm 2 số nguyên n, m -  số trạng thái và số lượng ký tự nhập của tập Σ
- Dòng kế tiếp gồm n số nguyên, mỗi số cách nhau khoảng trắng - các trạng thái của DFA
- Dòng kế tiếp gồm m ký tự, mỗi ký tự cách nhau khoảng trắng - tập ký tự nhập Σ
- Dòng kế tiếp gồm các số nguyên cách nhau khoảng trắng - tập trạng thái kết thúc
- nxm dòng kế tiếp, mỗi dòng có có dạng `<nstart> <input> <ndestination>` mô tả một phép chuyển từ trạng thái `<nstart>` trên ký hiệu nhập `<input>` sang trạng thái `<ndestination>`
- Dòng cuối cùng là chuỗi nhập cần kiểm tra

Đầu ra
- YES nếu chuỗi được chấp nhận bởi DFA; ngược lại NO

Chú ý: 
- Trạng thái đầu tiên của tập các trạng thái được quy ước là trạng thái bắt đầu

Gợi ý
- Thiết kế lớp DFA với các thuộc tính (Q, Σ, q0, F, δ) trong đó:
  - Q : tập các trạng thái
  - Σ : tập các ký hiệu nhập
  - q0: trạng thái bắt đầu
  - F : tập trạng thái kết thúc
  - δ : các phép chuyển trạng thái

Định nghĩa phương thức xử lý chuỗi nhập trong lớp DFA