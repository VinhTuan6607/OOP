#include <iostream>
#include "Phanso.cpp"

using namespace std;

int main () {
    PhanSo a, b;
    cout << "Nhap phan so a:\n";a.Nhap();
    cout << "Nhap phan so b:\n";b.Nhap();

    cout << "\nPhan so a sau khi rut gon: ";a.RutGon();a.Xuat();
    cout << "\nPhan so b sau khi rut gon: ";b.RutGon();b.Xuat();

    PhanSo ss;
    cout << "\n\nSo sanh: ";ss.SoSanh(a , b);

    PhanSo tong = tong.Tong(a,b);
    PhanSo hieu = hieu.Hieu(a,b);
    PhanSo tich = tich.Tich(a,b);
    PhanSo thuong = thuong.Thuong(a,b);

    cout << "\n\nTong la: ";tong.Xuat();
    cout << "\nHieu la: ";hieu.Xuat();
    cout << "\nTich la: ";tich.Xuat();
    cout << "\nThuong la: ";thuong.Xuat();

    return 0;
}