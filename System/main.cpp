#include <iostream>
#include "../QUẢN LÝ KHO/Material.h"
#include "../NHÂN SỰ & BÀN TRÀ/RoomService.h"
#include "../ĐƠN HÀNG & TƯ VẤN/Order.h"

using namespace std;

int main() {
    Tra dsTra[100];       int nTra = 0;
    AmTra dsAm[100];     int nAm = 0;
    NhanVien dsNV[50];    int nNV = 0;
    BanTra dsBan[20];     int nBan = 0;
    DonHang dsDon[200];   int nDon = 0;

    // THAY ĐỔI QUAN TRỌNG: Tự động nạp dữ liệu từ các file văn bản khi mở phần mềm
    docFileTra(dsTra, nTra);
    docFileAm(dsAm, nAm);
    docFileBan(dsBan, nBan);
    khoiTaoNhanVienMao(dsNV, nNV);

    int luaChon;
    do {
        cout << "\n======================================================\n";
        cout << "   HE THONG QUAN LY PHONG TRA (LUU TRU FILE vINH VIEN)   \n";
        cout << "======================================================\n";
        cout << "1. Xem danh sach cac loai TRA trong kho\n";
        cout << "2. Xem danh sach AM TRA (Tra cu) trong kho\n";
        cout << "3. Xem trang thai cac BAN TRA\n";
        cout << "4. Xem danh sach NHAN VIEN\n";
        cout << "5. Dat ban & Goi mon (Tao don hang moi)\n";
        cout << "6. Thanh toan hoa don cho ban\n";
        cout << "7. Su dung bo loc TU VAN CHON AM TRA\n";
        cout << "8. Nhap them hang vao kho (Tra / Am moi)\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "------------------------------------------------------\n";
        cout << "Nhap lua chon cua ban (0-8): ";
        cin >> luaChon;

        switch (luaChon) {
            case 1: hienThiDanhSachTra(dsTra, nTra); break;
            case 2: hienThiDanhSachAm(dsAm, nAm); break;
            case 3: hienThiDanhSachBan(dsBan, nBan); break;
            case 4: hienThiDanhSachNhanVien(dsNV, nNV); break;
            case 5: taoDonHang(dsDon, nDon, dsBan, nBan, dsTra, nTra, dsAm, nAm); break;
            case 6: {
                int sb; cout << "Nhap so ban can thanh toan: "; cin >> sb;
                thanhToanDonHang(dsDon, nDon, dsBan, nBan, sb);
                break;
            }
            case 7: tuVanChonAmVaTra(); break;
            case 8: {
                int subChon; cout << "1. Them Tra | 2. Them Am. Chon: "; cin >> subChon;
                if (subChon == 1) themTraMoi(dsTra, nTra);
                else if (subChon == 2) themAmMoi(dsAm, nAm);
                break;
            }
            case 0: cout << "=> Dang thoat. Du lieu da duoc luu an toan!\n"; break;
            default: cout << "=> Chon sai, nhap lai!\n";
        }
    } while (luaChon != 0);

    return 0;
}