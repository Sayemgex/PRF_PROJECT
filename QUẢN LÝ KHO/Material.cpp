#include <iostream>
#include <iomanip>
#include <fstream>
#include "Material.h"

using namespace std;

void docFileTra(Tra danhSachTra[], int &nTra) {
    ifstream file("kho_tra.txt");
    nTra = 0;
    if (!file.is_open()) {
        // Nếu chưa có file, tự tạo dữ liệu mẫu và ghi vào file luôn
        danhSachTra[0] = {"T01", "Hong Tra", 50, 45000};
        danhSachTra[1] = {"T02", "Luc Tra", 30, 40000};
        danhSachTra[2] = {"T03", "Tra Pho Nhi", 20, 60000};
        nTra = 3;
        ghiFileTra(danhSachTra, nTra);
        return;
    }
    while (file >> danhSachTra[nTra].maTra) {
        file.ignore();
        getline(file, danhSachTra[nTra].tenTra);
        file >> danhSachTra[nTra].soLuongCon >> danhSachTra[nTra].giaTien;
        nTra++;
    }
    file.close();
}

void ghiFileTra(Tra danhSachTra[], int nTra) {
    ofstream file("kho_tra.txt");
    for (int i = 0; i < nTra; i++) {
        file << danhSachTra[i].maTra << "\n"
             << danhSachTra[i].tenTra << "\n"
             << danhSachTra[i].soLuongCon << " " << danhSachTra[i].giaTien << "\n";
    }
    file.close();
}

void docFileAm(AmTra danhSachAm[], int &nAm) {
    ifstream file("am_tra.txt");
    nAm = 0;
    if (!file.is_open()) {
        danhSachAm[0] = {"A01", "Tay Thi", "Tu Ne", 200, 5, 50000};
        danhSachAm[1] = {"A02", "Thach Bieu", "Doan Ne", 150, 3, 45000};
        danhSachAm[2] = {"A03", "Chuyet Cau", "Dai Hong Bao", 250, 2, 70000};
        nAm = 3;
        ghiFileAm(danhSachAm, nAm);
        return;
    }
    while (file >> danhSachAm[nAm].maAm) {
        file.ignore();
        getline(file, danhSachAm[nAm].dangAm);
        getline(file, danhSachAm[nAm].chatDat);
        file >> danhSachAm[nAm].dungTich >> danhSachAm[nAm].soLuongCon >> danhSachAm[nAm].giaThue;
        nAm++;
    }
    file.close();
}

void ghiFileAm(AmTra danhSachAm[], int nAm) {
    ofstream file("am_tra.txt");
    for (int i = 0; i < nAm; i++) {
        file << danhSachAm[i].maAm << "\n"
             << danhSachAm[i].dangAm << "\n"
             << danhSachAm[i].chatDat << "\n"
             << danhSachAm[i].dungTich << " " << danhSachAm[i].soLuongCon << " " << danhSachAm[i].giaThue << "\n";
    }
    file.close();
}

void hienThiDanhSachTra(Tra danhSachTra[], int nTra) {
    cout << "\n================= DANH SACH CAC LOAI TRA =================\n";
    cout << left << setw(10) << "Ma Tra" << setw(20) << "Ten Tra" << setw(15) << "So Luong Ton" << setw(15) << "Gia Ban (VND)" << endl;
    cout << "----------------------------------------------------------\n";
    for (int i = 0; i < nTra; i++) {
        cout << left << setw(10) << danhSachTra[i].maTra
             << setw(20) << danhSachTra[i].tenTra
             << setw(15) << danhSachTra[i].soLuongCon
             << setw(15) << fixed << setprecision(0) << danhSachTra[i].giaTien << endl;
    }
    cout << "==========================================================\n";
}

void hienThiDanhSachAm(AmTra danhSachAm[], int nAm) {
    cout << "\n=========================== DANH SACH TRA CU (AM TRA) ===========================\n";
    cout << left << setw(10) << "Ma Am" << setw(15) << "Dang Am" << setw(15) << "Chat Dat" << setw(15) << "Dung Tich" << setw(15) << "So Luong" << setw(15) << "Gia Thue" << endl;
    cout << "---------------------------------------------------------------------------------\n";
    for (int i = 0; i < nAm; i++) {
        cout << left << setw(10) << danhSachAm[i].maAm
             << setw(15) << danhSachAm[i].dangAm
             << setw(15) << danhSachAm[i].chatDat
             << setw(15) << to_string(danhSachAm[i].dungTich) + "ml"
             << setw(15) << danhSachAm[i].soLuongCon
             << setw(15) << fixed << setprecision(0) << danhSachAm[i].giaThue << endl;
    }
    cout << "=================================================================================\n";
}

void themTraMoi(Tra danhSachTra[], int &nTra) {
    cout << "\n--- THEM TRA MOI VAO KHO ---\n";
    cout << "Nhap ma tra: "; cin >> danhSachTra[nTra].maTra;
    cin.ignore();
    cout << "Nhap ten tra: "; getline(cin, danhSachTra[nTra].tenTra);
    cout << "Nhap so luong: "; cin >> danhSachTra[nTra].soLuongCon;
    cout << "Nhap gia ban: "; cin >> danhSachTra[nTra].giaTien;
    nTra++;
    ghiFileTra(danhSachTra, nTra); // Lưu lại vào file văn bản ngay lập tức
    cout << "=> Them tra moi thanh cong va da dong bo vao file!\n";
}

void themAmMoi(AmTra danhSachAm[], int &nAm) {
    cout << "\n--- THEM AM TRA MOI VAO KHO ---\n";
    cout << "Nhap ma am: "; cin >> danhSachAm[nAm].maAm;
    cin.ignore();
    cout << "Nhap dang am: "; getline(cin, danhSachAm[nAm].dangAm);
    cout << "Nhap chat dat: "; getline(cin, danhSachAm[nAm].chatDat);
    cout << "Nhap dung tich (ml): "; cin >> danhSachAm[nAm].dungTich;
    cout << "Nhap so luong: "; cin >> danhSachAm[nAm].soLuongCon;
    cout << "Nhap gia thue: "; cin >> danhSachAm[nAm].giaThue;
    nAm++;
    ghiFileAm(danhSachAm, nAm); // Lưu lại vào file văn bản ngay lập tức
    cout << "=> Them am moi thanh cong va da dong bo vao file!\n";
}