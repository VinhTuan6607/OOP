#include <iostream>
#include "Date.cpp"

using namespace std;

int main () {
    date a;
    cout << "Ngay hom nay la: ";a.Nhap();
    a.NgayThangTiepTheo();
    cout << "Ngay mai la: ";a.Xuat();
    return 0;
}