#include <iostream>
#include <iomanip>
#include <fstream>
#include "RoomService.h"

using namespace std;

void khoiTaoNhanVienMao(NhanVien dsNhanVien[], int &nNV) {
    dsNhanVien[0] = {"NV01", "Nguyen Nguyen", "Tea Master"};
    dsNhanVien[1] = {"NV02", "Tran Thi Mai", "Tra nuong"};
    dsNhanVien[2] = {"NV03", "Le Van Nam", "Tra no"};
    nNV = 3;
}

void docFileBan(BanTra dsBan[], int &nBan) {
    ifstream file("ban_tra.txt");
    nBan = 0;
    if (!file.is_open()) {
        for (int i = 0; i < 5; i++) {
            dsBan[i].soBan = i + 1;
            dsBan[i].trangThai = "Trong";
            dsBan[i].maNVPhucVu = "Chua_co";
        }
        nBan = 5;
        ghiFileBan(dsBan, nBan);
        return;
    }
    while (file >> dsBan[nBan].soBan >> dsBan[nBan].trangThai >> dsBan[nBan].maNVPhucVu) {
        nBan++;
    }
    file.close();
}

void ghiFileBan(BanTra dsBan[], int nBan) {
    ofstream file("ban_tra.txt");
    for (int i = 0; i < nBan; i++) {
        file << dsBan[i].soBan << " " << dsBan[i].trangThai << " " << dsBan[i].maNVPhucVu << "\n";
    }
    file.close();
}

void hienThiDanhSachNhanVien(NhanVien dsNhanVien[], int nNV) {
    cout << "\n================ DANH SACH NHAN VIEN PHONG TRA ================\n";
    cout << left << setw(15) << "Ma NV" << setw(25) << "Ho Va Ten" << setw(20) << "Chuc Vu" << endl;
    cout << "---------------------------------------------------------------\n";
    for (int i = 0; i < nNV; i++) {
        cout << left << setw(15) << dsNhanVien[i].maNV
             << setw(25) << dsNhanVien[i].tenNV
             << setw(20) << dsNhanVien[i].chucVu << endl;
    }
    cout << "===============================================================\n";
}

void hienThiDanhSachBan(BanTra dsBan[], int nBan) {
    cout << "\n================ TRANG THAI CAC BAN TRA ================\n";
    cout << left << setw(10) << "So Ban" << setw(20) << "Trang Thai" << setw(20) << "NV PhuC Vu" << endl;
    cout << "--------------------------------------------------------\n";
    for (int i = 0; i < nBan; i++) {
        // Đổi dấu gạch dưới thành khoảng trắng khi hiển thị
        string nvDisplay = dsBan[i].maNVPhucVu;
        if (nvDisplay == "Chua_co") nvDisplay = "Chua co";
        
        cout << left << setw(10) << dsBan[i].soBan
             << setw(20) << dsBan[i].trangThai
             << setw(20) << nvDisplay << endl;
    }
    cout << "========================================================\n";
}

void doiTrangThaiBan(BanTra dsBan[], int nBan, int soBanCanDoi, string trangThaiMoi, string maNV) {
    for (int i = 0; i < nBan; i++) {
        if (dsBan[i].soBan == soBanCanDoi) {
            dsBan[i].trangThai = trangThaiMoi;
            dsBan[i].maNVPhucVu = (trangThaiMoi == "Trong") ? "Chua_co" : maNV;
            ghiFileBan(dsBan, nBan); // Cập nhật file ngay khi đổi trạng thái bàn
            return;
        }
    }
}