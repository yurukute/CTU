Có n công việc cần thực hiện, các công việc được đánh số từ 1 đến n; Minh Minh được đưa 2 danh sách:
- Danh sách 1 gồm thứ tự các công việc được giao cho Minh Minh
- Danh sách 2 là thứ tự tối ưu các công việc Minh Minh phải thực hiện.

Để thực hiện Minh Minh lấy từng công việc được giao cho mình, nếu công việc được lấy ra trùng với thứ tự tối ưu thì thực hiện công việc đó, nếu không trùng với thứ tự tối ưu thì chuyển công việc đó vào cuối danh sách thứ tự các công việc được giao. Quá trình lặp lại đến khi tất cả các công việc được thực hiện. *Mỗi lần chuyển công việc về cuối hay thực thi mất 1 đơn vị thời gian.*

Tính số đơn vị thời gian cần thiết của Minh Minh để hoàn thành n công việc được giao.

**Đầu vào**
- Dòng đầu tiên là số nguyên dương N
- Dòng thứ 2 là danh sách thứ tự các công việc được giao
- Dòng thứ 3 là danh sách thứ tự tối ưu các công việc cần thực hiện

**Đầu ra**
- Một số nguyên duy nhất là số đơn vị thời gian cần thiết để hoàn thành n công việc được giao 

**Ràng buộc**
- 1 <= N <= 100

**Giải thích ví dụ**

Có 3 công việc, danh sách 1 là 3 2 1; danh sách 2 là 1 3 2. Các bước thực hiện như sau:
- **Bước 1**: Lấy công việc đầu tiên trong danh sách 1, đó là công việc #3. Vì trường hợp tối ưu là công việc #1 được thực hiện đầu tiên, do đó công việc #3 được đưa trở lại cuối danh sách 1. Thời gian dành cho bước 1: 1
- **Bước 2**: Lấy công việc kế tiếp trong danh sách 1, đó là công việc #2. Vì trường hợp tối ưu là công việc #1 phải được thực hiện, do đó công việc #2 được đưa trở lại cuối danh sách 1. Thời gian dành cho bước 2: 1
- **Bước 3**: Lấy công việc kế tiếp trong danh sách 1, đó là công việc #1. Đó cũng là công việc cần thực hiện trong trường hợp tối ưu, do đó, thực hiện công việc #1 và lấy chúng ra khỏi các danh sách. Thời gian dành cho bước 3: 1
- **Bước 4**: Lấy công việc kế tiếp trong danh sách 1, đó là công việc #3. Đó cũng là công việc cần thực hiện trong trường hợp tối ưu, do đó, thực hiện công việc #3 và lấy chúng ra khỏi các danh sách. Thời gian dành cho bước 4: 1
- **Bước 5**: Lấy công việc kế tiếp trong danh sách 1, đó là công việc #2. Đó cũng là công việc cần thực hiện trong trường hợp tối ưu, do đó, thực hiện công việc #2 và lấy chúng ra khỏi các danh sách. Thời gian dành cho bước 5: 1

Tổng thời gian thực hiện: 5

