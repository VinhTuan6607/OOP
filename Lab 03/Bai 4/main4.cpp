#include <iostream>
#include <vector>
#include "cArray.cpp"

using namespace std;

int main () {
    cout << "----------NHAP MANG----------\n";

    int n;cout << "Nhap vao n: ";cin >> n;

    cArray a;
    a.Nhap(n);

    cArray randomArray;
    randomArray.TaoMangNgauNhien(n);

    int x;cout << "Nhap vao x can tim trong Mang hien tai: ";cin >> x;

    cout << "\n----------XUAT MANG----------\n";
    cout << "Mang hien tai la: ";
    a.Xuat();

    cout << "\nMang ngau nhien: ";
    randomArray.Xuat();

    cout << "\n\n----------KIEM TRA MANG----------\n";
    cout << "So lan xuat hien cua " << x << " trong Mang hien tai la: " << a.SoLanXuatHienCua(x);
    a.TimSNTLonNhat();
    cout << "\nMang hien tai la ";a.KiemTraTangDan();

    a.SapXepTangDan();

    cout << "\nPhan tu le nho nhat trong Mang hien tai la: "; a.PhanTuLeNhoNhat();

    cout << "\n\n----------SAP XEP MANG----------\n";
    cout << "Mang hien tai sau khi sap xep Tang dan la: ";a.Xuat();

    return 0;
}