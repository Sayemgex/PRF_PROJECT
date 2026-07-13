#ifndef ROOMSERVICE_H
#define ROOMSERVICE_H

#include <string>
using namespace std;

struct NhanVien {
    string maNV;
    string tenNV;
    string chucVu; 
};

struct BanTra {
    int soBan;
    string trangThai;     
    string maNVPhucVu;    
};

// Khai báo các hàm Đọc/Ghi trạng thái bàn
void docFileBan(BanTra dsBan[], int &nBan);
void ghiFileBan(BanTra dsBan[], int nBan);
void khoiTaoNhanVienMao(NhanVien dsNhanVien[], int &nNV);

void hienThiDanhSachNhanVien(NhanVien dsNhanVien[], int nNV);
void hienThiDanhSachBan(BanTra dsBan[], int nBan);
void doiTrangThaiBan(BanTra dsBan[], int nBan, int soBanCanDoi, string trangThaiMoi, string maNV);

#endif