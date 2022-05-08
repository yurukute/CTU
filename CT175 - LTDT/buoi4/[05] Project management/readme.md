# 005. Quản lý dự án
Cho một dự án gồm n công việc. Mỗi công việc u có một thời gian hoàn thành d[u] và một danh sách các công việc phải hoàn thành trước khi thực hiện u. Hãy tính thời gian sớm nhất và thời gian trễ nhất để bắt đầu các công việc.

Đầu vào (Input)
- Dữ liệu đầu vào được nhập từ bàn phím với định dạng:
  - Dòng đầu tiên chứa 1 số nguyên n là số công việc.
  - n dòng tiếp theo, dòng thứ u chứa số nguyên d[u] là thời gian cần thiết để hoàn thành công việc u và một danh sách các công việc cần phải hoàn thành trước khi bắt đầu công việc u. Danh sách được kết thúc bằng số 0.
  
Đầu ra (Output)
- In ra màn hình n dòng, dòng thứ u gồm 2 số nguyên t[u] (thời gian sớm nhất để bắt đầu công việc u) và T[u] (thời gian trễ nhất để bắt đầu công việc u).
