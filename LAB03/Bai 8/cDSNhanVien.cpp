#include <iostream>
#include <vector>
#include <algorithm>
#include "cDSNhanVien.h"

using namespace std;

istream& operator>> (istream& in,cDSNhanVien& DS) {                 // Dinh nghia toan tu Nhap(>>) cho class cDSNhanVien
    cout << "Nhap so luong nhan vien: ";in >> DS.n;
    for (int i = 0;i < DS.n;i++) {
        cout << "Nhan vien thu " << i + 1 << ":\n";
        cNhanVienSX a;
        in >> a;
        DS.arr.push_back(a);
        cout << "\n";
    }
    return in;
}

ostream& operator<< (ostream& out,const cDSNhanVien& DS) {          // Dinh nghia toan tu Xuat(<<) cho class cDSNhanVien
    for (int i = 0;i < DS.arr.size();i++) {
        out << "Nhan vien thu " << i + 1 << ":";
        out << DS.arr[i] << "\n\n";
    }
    return out;
}

void cDSNhanVien::SapXepLuongTangDan() {                            // Ham Sap xep lai danh sach nhan vien theo thu tu luong tang dan
    sort(arr.begin(),arr.end(),cmp);
}

cNhanVienSX cDSNhanVien::NVLuongThapNhat() {                        // Ham tim nhan vien co luong thap nhat
    SapXepLuongTangDan();                                           // Input: DS nhan vien, Output: Nhan vien co luong thap nhat
    return arr[0];                                                  // NV co luong thap nhat la NV o vi tri dau tien cua DS sau khi da sap xep theo luong tang dan
}

cNhanVienSX cDSNhanVien::NVLonTuoiNhat() {                                                                      // Ham tim nhan vien lon tuoi nhat
    int nguoilontuoinhat = 0;                                                                                   // Tao bien nguoilontuoi la vi tri cua NV lon tuoi nhat trong DS
    for (int i = 1;i < arr.size();i++) {                                                                        // Input: DS nhan vien, Output: NV co tuoi lon nhat (so sanh dua tren Ngay sinh)
        if (arr[nguoilontuoinhat].getNgayThangNamSinh().getNam() > arr[i].getNgayThangNamSinh().getNam()) {                // So sanh lan luot nam sinh -> thang sinh -> ngay sinh
            nguoilontuoinhat = i;
        }

        else if (arr[nguoilontuoinhat].getNgayThangNamSinh().getNam() == arr[i].getNgayThangNamSinh().getNam()) {
            if (arr[nguoilontuoinhat].getNgayThangNamSinh().getThang() > arr[i].getNgayThangNamSinh().getThang()) {
                nguoilontuoinhat = i;
            }

            else if (arr[nguoilontuoinhat].getNgayThangNamSinh().getThang() == arr[i].getNgayThangNamSinh().getThang()) {
                if (arr[nguoilontuoinhat].getNgayThangNamSinh().getNgay() > arr[i].getNgayThangNamSinh().getNgay()) {
                    nguoilontuoinhat = i;
                }
            }
        }
    }
    return arr[nguoilontuoinhat];
}

long long cDSNhanVien::TongLuongNV() {                // Ham tinh tong luong nhan vien
    long long sum = 0;                                // Input: DS nhan vien, Output: Tong luong cua tat ca cac nhan vien co trong DS
    for (int i = 0;i < arr.size();i++) {
        sum += arr[i].getLuong();
    }
    return sum;
}