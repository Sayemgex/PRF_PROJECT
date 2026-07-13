#ifndef ORDER_H
#define ORDER_H

#include "../QUẢN LÝ KHO/Material.h"
#include "../NHÂN SỰ & BÀN TRÀ/RoomService.h"
#include <string>

using namespace std;

struct DonHang {
    string maDonHang;
    int soBan;
    string maTra;
    string maAm;
    double tongTien;
    bool daThanhToan;
};

void taoDonHang(DonHang dsDonHang[], int &nDon, BanTra dsBan[], int nBan, Tra dsTra[], int nTra, AmTra dsAm[], int nAm);
void thanhToanDonHang(DonHang dsDonHang[], int nDon, BanTra dsBan[], int nBan, int soBanCanThanhToan);
void tuVanChonAmVaTra();

#endif