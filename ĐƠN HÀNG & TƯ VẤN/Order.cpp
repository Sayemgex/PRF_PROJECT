#include <iostream>
#include <iomanip>
#include "Order.h"

using namespace std;

void tuVanChonAmVaTra() {
    cout << "\n================ HE THONG TU VAN TRA DAO ================\n";
    string loaiTra; int soNguoi; int dungTichChen;
    cout << "Nhap loai tra muon pha (Goi y: Hong Tra, Luc Tra, Pho Nhi): ";
    cin.ignore(); getline(cin, loaiTra);
    cout << "Nhap so luong nguoi uong: "; cin >> soNguoi;
    cout << "Nhap dung tich chen cua ban (ml): "; cin >> dungTichChen;

    int dungTichLyTuong = (soNguoi * dungTichChen) + 40;
    cout << "\n---------------- KET QUA TU VAN ----------------\n";
    cout << "+ Dung tich am phu hop nhat: Khoang " << dungTichLyTuong << "ml.\n";

    if (loaiTra == "Hong Tra" || loaiTra == "Pho Nhi" || loaiTra == "Hong tra" || loaiTra == "Pho nhi") {
        cout << "+ Chat dat khuyen nghi: Tu ne (Tu sa) hoac Dai hong bao.\n";
        cout << "+ Dang am goi y: Tay Thi, Chuyet Cau, Truyen Lo (Dang am cao, giu nhiet tot).\n";
    } else {
        cout << "+ Chat dat khuyen nghi: Doan Ne (Thoat nhiet nhanh, thoang khi).\n";
        cout << "+ Dang am goi y: Thach Bieu, Bien Phuc (Dang am det, giu huong thien nhien).\n";
    }
    cout << "=========================================================\n";
}

void taoDonHang(DonHang dsDonHang[], int &nDon, BanTra dsBan[], int nBan, Tra dsTra[], int nTra, AmTra dsAm[], int nAm) {
    cout << "\n--- TAO DON HANG TAI BAN ---\n";
    int soBan; cout << "Nhap so ban muon goi mon: "; cin >> soBan;

    int indexBan = -1;
    for (int i = 0; i < nBan; i++) {
        if (dsBan[i].soBan == soBan) { indexBan = i; break; }
    }
    if (indexBan == -1) { cout << "=> So ban khong ton tai!\n"; return; }
    if (dsBan[indexBan].trangThai == "Dang") { // Bẫy lỗi chuỗi con hoặc trạng thái phục vụ
        cout << "=> Ban nay dang co khach!\n"; return; 
    }

    dsDonHang[nDon].maDonHang = "DH" + to_string(nDon + 1);
    dsDonHang[nDon].soBan = soBan;

    string maTra, maAm, maNV;
    cout << "Nhap Ma Tra: "; cin >> maTra;
    cout << "Nhap Ma Am Tra: "; cin >> maAm;
    cout << "Nhap Ma Nhan Vien phục vu: "; cin >> maNV;

    double giaTra = 0, giaAm = 0;
    for (int i = 0; i < nTra; i++) {
        if (dsTra[i].maTra == maTra) { giaTra = dsTra[i].giaTien; dsTra[i].soLuongCon--; }
    }
    for (int i = 0; i < nAm; i++) {
        if (dsAm[i].maAm == maAm) { giaAm = dsAm[i].giaThue; dsAm[i].soLuongCon--; }
    }

    dsDonHang[nDon].maTra = maTra;
    dsDonHang[nDon].maAm = maAm;
    dsDonHang[nDon].tongTien = giaTra + giaAm;
    dsDonHang[nDon].daThanhToan = false;

    // Đổi trạng thái bàn và đồng bộ ghi lại toàn bộ File Kho để lưu số lượng trừ đi
    doiTrangThaiBan(dsBan, nBan, soBan, "Dang_phuc_vu", maNV);
    ghiFileTra(dsTra, nTra);
    ghiFileAm(dsAm, nAm);

    cout << "=> Tao don thanh cong! Tam tinh: " << fixed << setprecision(0) << dsDonHang[nDon].tongTien << " VND\n";
    nDon++;
}

void thanhToanDonHang(DonHang dsDonHang[], int nDon, BanTra dsBan[], int nBan, int soBanCanThanhToan) {
    for (int i = 0; i < nDon; i++) {
        if (dsDonHang[i].soBan == soBanCanThanhToan && !dsDonHang[i].daThanhToan) {
            dsDonHang[i].daThanhToan = true;
            cout << "\n================ HOA DON THANH TOAN BAl " << soBanCanThanhToan << " ================\n";
            cout << "Tong so tien can thanh toan: " << fixed << setprecision(0) << dsDonHang[i].tongTien << " VND\n";
            cout << "=> Thanh toan thanh cong!\n";
            
            doiTrangThaiBan(dsBan, nBan, soBanCanThanhToan, "Trong", "Chua_co");
            return;
        }
    }
    cout << "=> Khong tim thay hoa don chua thanh toan tai ban nay!\n";
}