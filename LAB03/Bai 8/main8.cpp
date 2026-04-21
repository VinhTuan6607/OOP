#include <iostream>
#include <vector>
#include "cDSNhanVien.cpp"

using namespace std;

int main () {
    cDSNhanVien DS;
    cout << "----------NHAP DANH SACH NHAN VIEN----------\n";
    cin >> DS;

    cout << "----------XUAT DANH SACH NHAN VIEN----------\n";
    DS.SapXepLuongTangDan();
    cout << "Danh sach nhan vien sau khi sap xep:\n" << DS;

    cout << "--------------------------------------------";
    cout << "\nTong luong nhan vien: " << DS.TongLuongNV();
    cout << "\n\nNhan vien co luong thap nhat: " << DS.NVLuongThapNhat();
    cout << "\n\nNhan vien lon tuoi nhat: " << DS.NVLonTuoiNhat();
    return 0;
}