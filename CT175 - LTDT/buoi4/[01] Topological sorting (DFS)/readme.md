# 001b. Thứ tự topo (chiều rộng hoặc chiều sâu)
Viết chương trình đọc vào một đồ thị có hướng không chu trình G, in các đỉnh của G ra màn hình theo thứ tự topo. Nếu có nhiều thứ tự topo, in một thứ tự bất kỳ.

Đầu vào (Input)
- Dữ liệu đầu vào được nhập từ bàn phím với định dạng:
  - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung.
  - m dòng tiếp theo mỗi dòng chứa 2 số nguyên u, v mô tả cung (u, v).

Đầu ra (Output)
- In các đỉnh ra màn hình theo thứ tự topo. In các đỉnh trên một dòng, cách nhau 1 khoảng trắng.

Gợi ý
- Ngoài giải thuật sắp xếp topo dựa trên phương pháp duyệt theo chiều rộng, ta cũng có thể sắp xếp topo dựa trên duyệt theo chiều sâu.
```c
void dfs(G, u, L) {
    mark[u] = 1;
    for (v là kề của u)
        if (mark[v] == 0)
            dfs(G, v, L);
    push_back(L, u);
}

//Khởi tạo mark[u] = 0 với mọi u = 1,n

for (u = 1; u <= n; u++)
    if (mark[u] == 0)
        dfs(G, u, L);
        
//In ngược các phần tử của L
```
