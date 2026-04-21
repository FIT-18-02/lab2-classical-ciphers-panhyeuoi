# Report 1 Page – FIT4012 Lab 2

## 1. Mục tiêu
Tóm tắt ngắn gọn mục tiêu của bài lab.
Thực hiện và hiểu hai kỹ thuật mã hóa cổ điển:
- Caesar Cipher (mã hóa thay thế)
- Rail Fence Cipher (mã hóa hoán vị)
Đồng thời rèn luyện kỹ năng lập trình C++, kiểm thử và tổ chức code trên GitHub.

## 2. Cách làm
- Hoàn thiện Caesar Cipher cho chữ thường, dấu cách và giải mã.
- Hoàn thiện Rail Fence Cipher cho giải mã, giữ dấu cách, kiểm tra đầu vào và đọc file.
- Chạy thử trên nhiều test casekhác nhau để kiểm tra tính đúng đắn.


## 3. Kết quả chính
### 3.1 Caesar Cipher
| Input | Key | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 3 | L OVEH BRX | Giữ nguyên dấu cách, mã hóa đúng |
| hello world | 5 | mjqqt btwqi | Xử lý đúng chữ thường |
| LORYH BRX | 3 | I LOVE YOU | Giải mã chính xác |

### 3.2 Rail Fence Cipher
| Input | Rails | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 2 | IOEOLVYU | Mã hóa đúng dạng zigzag |
| I LOVE YOU | 4 | IYLOEUOV | Thay đổi số ray cho kết quả khác |
| IOEOLVYU | 2 | ILOVEYOU |  Giải mã chính xác |

### 3.3 Input validation / file input
- Trường hợp đầu vào không hợp lệ:
  Input: `HELLO123` → Output: `Invalid input`
  → Chương trình kiểm tra đúng định dạng.

- Kết quả đọc từ `data/input.txt`:
  Ví dụ nội dung file: `HELLO WORLD`  
  → Output: `MJQQT BTWQI` (với key = 5)

## 4. Kết luận
Nêu ngắn gọn em học được gì từ bài lab, khó khăn lớn nhất là gì, và điều gì giúp em hiểu rõ hơn về Caesar hoặc Rail Fence Cipher.
- Cách hoạt động của mã hóa thay thế (Caesar Cipher)
- Cách sắp xếp zigzag trong mã hóa hoán vị (Rail Fence Cipher)

Khó khăn lớn nhất là:
- Xử lý giữ nguyên dấu cách
- Cài đặt giải mã cho Rail Fence

Bài lab giúp em hiểu rõ hơn cách xử lý chuỗi trong C++ và cách kiểm thử chương trình với nhiều trường hợp khác nhau.
