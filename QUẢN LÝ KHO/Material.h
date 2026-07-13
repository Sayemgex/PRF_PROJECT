#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
using namespace std;

struct Tra {
    string maTra;
    string tenTra;      
    int soLuongCon;     
    double giaTien;     
};

struct AmTra {
    string maAm;
    string dangAm;      
    string chatDat;     
    int dungTich;       
    int soLuongCon;
    double giaThue;     
};

// Khai báo các hàm quản lý kho và Đọc/Ghi File
void docFileTra(Tra danhSachTra[], int &nTra);
void ghiFileTra(Tra danhSachTra[], int nTra);
void docFileAm(AmTra danhSachAm[], int &nAm);
void ghiFileAm(AmTra danhSachAm[], int nAm);

void hienThiDanhSachTra(Tra danhSachTra[], int nTra);
void hienThiDanhSachAm(AmTra danhSachAm[], int nAm);
void themTraMoi(Tra danhSachTra[], int &nTra);
void themAmMoi(AmTra danhSachAm[], int &nAm);

#endif