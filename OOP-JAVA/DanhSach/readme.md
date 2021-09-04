Viết chương trình thực hiện các công việc sau:
- Nhập vào 1 danh sách các số nguyên.
- Nhập vào 1 số nguyên x bất kỳ. Đếm xem trong danh sách có bao nhiêu số x.
- Sắp xếp danh sách theo thứ tự tăng dần.
- Hiển thị danh sách đã sắp xếp ra màn hình.

**Đầu vào**
- Dòng đầu tiên chứa số nguyên n - số phần tử của danh sách (0 < n < 1000).
- Dòng thứ hai chứa n số nguyên, các số cách nhau 1 khoảng trắng.
- Dòng thứ ba chứ số nguyên x. 

**Đầu ra**
- In số phần tử có giá trị x trong danh sách.
- In danh sách các số đã sắp xếp theo thứ tự tăng dần trên cùng một dòng, các số cách nhau một khoảng trắng.

**Chú ý**
- Phải có hàm main(String[] args)
- Dữ liệu đầu vào luôn hợp lệ bạn không cần kiểm tra.
- Không cần in ra ca câu giới thiệu, ví dụ: "Nhập n:", trước khi đọc dữ liệu.

**Gợi ý**
- Sử dụng thuật toán sắp xếp nào cũng được.
- Ví dụ: thuật toán sắp xếp nổi bọt (bubble sort)
```
for (int i = 0; i < n; i++)
    for (int j = n-1; j > i; j--)
        if (A[j] < A[j - 1])
            Đổi chổ A[j] và A[j - 1]
```