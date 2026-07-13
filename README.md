# 🍵 DỰ ÁN QUẢN LÝ PHÒNG TRÀ NGHỆ THUẬT & TRÀ CỤ

---

## 📌 HƯỚNG DẪN SỬ DỤNG PHẦN MỀM (TEST CASE)

Hệ thống đã được tích hợp cơ chế tự động khởi tạo dữ liệu mẫu ban đầu. Bạn có thể vận hành thử nghiệm phần mềm theo kịch bản luồng công việc dưới đây để kiểm tra tính năng và khả năng liên kết dữ liệu thời gian thực.

### Bước 1: Kiểm tra cơ sở dữ liệu mẫu có sẵn
Tại menu chính, nhập các số tương ứng để kiểm tra danh sách thực thể hiện tại:
* **Nhập số `1` ➔ Enter:** Xem danh sách Trà trong kho (Ghi nhớ các mã: `T01`, `T02`, `T03`).
* **Nhập số `2` ➔ Enter:** Xem danh sách Ấm Trà/Trà cụ (Ghi nhớ các mã: `A01`, `A02`, `A03`).
* **Nhập số `3` ➔ Enter:** Xem trạng thái các Bàn Trà (Hiện tại cả 5 bàn đều có trạng thái ban đầu là `Trong`).
* **Nhập số `4` ➔ Enter:** Xem danh sách Nhân viên phòng trà (Ghi nhớ các mã: `NV01`, `NV02`, `NV03`).

---

### Bước 2: Thử nghiệm bộ lọc "Tư vấn chọn ấm trà"
Giả sử có một nhóm khách 5 người vào phòng trà nhưng phân vân chưa biết nên sử dụng trà cụ và dung tích bao nhiêu cho phù hợp, hãy kích hoạt bộ lọc thông minh:
1. **Nhập số `7` ➔ Enter.**
2. Hệ thống yêu cầu nhập loại trà: Gõ `Hong Tra` ➔ Enter.
3. Nhập số người uống: Gõ `5` ➔ Enter.
4. Nhập dung tích chén: Gõ `40` ➔ Enter.

> **Kết quả:** Hệ thống tự động tính toán tổng dung tích nước lý tưởng ($5 \times 40\text{ ml} + 40\text{ ml hao hụt} = 240\text{ ml}$) và đưa ra khuyến nghị: *Nên sử dụng ấm dung tích 200ml-250ml, dáng ấm Tây Thi hoặc Chuyết Cầu, chất đất Tử Nê để giữ nhiệt tốt.*

---

### Bước 3: Đặt bàn & Gọi món (Tạo đơn hàng mới)
Khách quyết định gọi món theo tư vấn: Ngồi tại **Bàn số 1**, gọi một suất **Hồng Trà (T01)**, thuê **Ấm Tây Thi (A01)** và yêu cầu nhân viên **NV01** phục vụ.
1. **Nhập số `5` ➔ Enter.**
2. Nhập số bàn: Gõ `1` ➔ Enter.
3. Nhập Mã Trà: Gõ `T01` ➔ Enter.
4. Nhập Mã Ấm Trà: Gõ `A01` ➔ Enter.
5. Nhập Mã Nhân Viên phục vụ: Gõ `NV01` ➔ Enter.

> **Kết quả:** Hệ thống báo tạo hóa đơn thành công. Tổng tiền tạm tính: $45.000\text{ VND} \text{ (Trà)} + 50.000\text{ VND} \text{ (Ấm)} = 95.000\text{ VND}$.  
> 💡 *Mẹo kiểm tra liên kết chéo:* Hãy **nhập lại số `3`**, bạn sẽ thấy **Bàn 1** đã tự động chuyển trạng thái sang `Dang phuc vu` kèm mã nhân viên `NV01`, đồng thời số lượng tồn kho của Trà và Ấm tương ứng đã tự động trừ đi 1 đơn vị.

---

### Bước 4: Thanh toán hóa đơn
Khi khách tại Bàn 1 dùng trà xong và yêu cầu thanh toán để ra về:
1. **Nhập số `6` ➔ Enter.**
2. Nhập số bàn cần thanh toán: Gõ `1` ➔ Enter.

> **Kết quả:** Hệ thống in ra hóa đơn chi tiết trị giá `95.000 VND` và xác nhận thanh toán thành công.  
> 💡 *Mẹo kiểm tra liên kết chéo:* Tiếp tục **nhập lại số `3`**, bạn sẽ thấy **Bàn 1** đã được dọn dẹp sạch sẽ, tự động quay về trạng thái `Trong` để sẵn sàng đón lượt khách tiếp theo.

---

### Bước 5: Nhập thêm hàng mới vào kho
Khi phòng trà nhập thêm nguyên liệu mới chưa có sẵn trong danh mục:
1. **Nhập số `8` ➔ Enter.**
2. Chọn loại hàng cần thêm: Nhập `1` (Thêm Trà).
3. Nhập lần lượt thông tin:
   * Mã trà: `T04`
   * Tên trà: `Tra Oloong`
   * Số lượng: `10`
   * Giá bán: `55000`

> **Kết quả:** Hệ thống báo thêm thành công. Khi **nhập lại số `1`**, `Tra Oloong (T04)` sẽ xuất hiện ở cuối danh sách kho và được lưu trữ vĩnh viễn.

---

### Bước 6: Thoát chương trình
* **Nhập số `0` ➔ Enter:** Hệ thống gửi lời chào kết thúc, tự động đóng toàn bộ cổng file và thoát chương trình an toàn.

---

## 💾 CƠ CHẾ LƯU TRỮ DỮ LIỆU VĨNH VIỄN (FILE HANDLING)

Phần mềm đã được nâng cấp lên kiến trúc lưu trữ dữ liệu bền vững (Persisted Data). Toàn bộ thao tác nghiệp vụ, thay đổi kho hàng hay trạng thái bàn trà sẽ được đồng bộ thời gian thực xuống các file văn bản (`.txt`). Khi tắt máy hoặc khởi động lại phần mềm, dữ liệu cũ vẫn được giữ nguyên vẹn.

Hệ thống quản lý dữ liệu thông qua 3 file cơ sở dữ liệu độc lập tại thư mục gốc:
* **`kho_tra.txt`**: Lưu trữ danh mục các loại trà, số lượng tồn kho và đơn giá.
* **`am_tra.txt`**: Lưu trữ danh mục trà cụ, dáng ấm, chất đất, dung tích và giá thuê.
* **`ban_tra.txt`**: Lưu trữ số bàn, trạng thái hoạt động và mã nhân viên đang trực bàn.

> ℹ️ **Cơ chế tự khởi tạo (Auto-Seed):** Trong lần đầu tiên chạy phần mềm, nếu hệ thống phát hiện chưa có các file `.txt` này, module tương ứng sẽ tự động tạo file và nạp vào các hàng dữ liệu mẫu tiêu chuẩn để phần mềm sẵn sàng vận hành ngay lập tức.

---

## 🛠 CẤU TRÚC THƯ MỤC & FILE DỰ ÁN

Dự án sử dụng mô hình Lập trình cấu trúc đa file (Multi-file Structured Programming) nhằm phân rã cấu trúc hệ thống thành các module độc lập, giúp tối ưu hóa làm việc nhóm:

```text
PRF_PROJECT/
│
├── kho_tra.txt             # Cơ sở dữ liệu lưu trữ thông tin các loại Trà
├── am_tra.txt              # Cơ sở dữ liệu lưu trữ thông tin các loại Ấm Trà
├── ban_tra.txt             # Cơ sở dữ liệu lưu trữ trạng thái các Bàn Trà
│
├── ĐƠN HÀNG & TƯ VẤN/
│   ├── Order.h             # Định nghĩa cấu trúc đơn hàng & hàm tư vấn
│   └── Order.cpp           # Xử lý logic đặt món, thanh toán và đồng bộ dữ liệu kho
│
├── NHÂN SỰ & BÀN TRÀ/
│   ├── RoomService.h       # Định nghĩa cấu trúc bàn trà & nhân sự
│   └── RoomService.cpp     # Đọc/Ghi file 'ban_tra.txt', cập nhật trạng thái bàn
│
├── QUẢN LÝ KHO/
│   ├── Material.h          # Định nghĩa cấu trúc vật tư (Trà & Ấm)
│   └── Material.cpp        # Đọc/Ghi file 'kho_tra.txt', 'am_tra.txt' khi cập nhật kho
│
└── System/
    └── main.cpp            # Điều phối Menu chính, nạp dữ liệu từ file lên RAM khi khởi động
```
