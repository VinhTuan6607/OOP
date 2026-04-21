#include <iostream>
#include "cNhanVienSX.h"

using namespace std;

cNhanVienSX::cNhanVienSX() {                                        // Phuong thuc thiet lap mac dinh
    MaNV = "";
    HoTen = "";
    NgayThangNamSinh;
    SoSPGiaCong = 0;
    DonGiaSP = 0;
}

void cNhanVienSX::TinhLuong() {                                     // Ham tinh luong nhan vien
    Luong = double(SoSPGiaCong) * DonGiaSP;
}

istream& operator>> (istream& in,cNhanVienSX& NV) {                 // Dinh nghia toan tu Nhap(>>) cho class cNhanVienSX
    in.ignore();
    cout << "Nhap Ma: ";getline(in,NV.MaNV);
    cout << "Nhap Ho ten: ";getline(in,NV.HoTen);
    cout << "Nhap Ngay sinh:\n";in >> NV.NgayThangNamSinh;
    cout << "Nhap So san pham gia cong: ";in >> NV.SoSPGiaCong;
    cout << "Nhap Don gia: ";in >> NV.DonGiaSP;
    NV.TinhLuong();
    return in;
}

ostream& operator<< (ostream& out,const cNhanVienSX& NV) {          // Dinh nghia toan tu Xuat(<<) cho class cNhanVienSX
    out << "\nMa: " << NV.MaNV;
    out << "\nHo Ten: " << NV.HoTen;
    out << "\nNgay sinh: " << NV.NgayThangNamSinh;
    out << "\nSo san pham da gia cong: " << NV.SoSPGiaCong;
    out << "\nDon gia cua San pham: " << NV.DonGiaSP;
    out << "\nLuong: " << NV.Luong;
    return out;
}

bool cmp (cNhanVienSX a,cNhanVienSX b) {                            // Ham so sanh Luong cua 2 nhan vien
    if (a.Luong < b.Luong) return 1;
    return 0;
}