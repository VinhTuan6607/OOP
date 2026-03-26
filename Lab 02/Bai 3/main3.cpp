#include <iostream>
#include "Sophuc.cpp"

using namespace std;

int main () {
    SoPhuc a , b;
    cout << "Nhap so phuc a:\n";a.Nhap();
    cout << "Nhap so phuc b:\n";b.Nhap();
    
    SoPhuc tong = tong.Tong(a,b);
    SoPhuc hieu = hieu.Hieu(a,b);
    SoPhuc tich = tich.Tich(a,b);
    SoPhuc thuong = thuong.Thuong(a,b);

    cout << "Tong la: ";tong.Xuat();
    cout << "Hieu la: ";hieu.Xuat();
    cout << "Tich la: ";tich.Xuat();
    cout << "Thuong la: ";thuong.Xuat(); 

    return 0;
}