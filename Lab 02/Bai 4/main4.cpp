#include <iostream>
#include "Time.cpp"

using namespace std;

int main () {
    Time thoigian;
    cout << "Nhap thoi gian:\n";thoigian.Nhap();
    thoigian.TinhCongThemMotGiay();
    cout << "Thoi gian sau 1 giay tiep theo: ";thoigian.Xuat();
    return 0;
}