#include <iostream>
#include <vector>
#include "cDaThuc.cpp"

using namespace std;

int main () {
    int x;
    cout << "----------NHAP----------\n";
    cout << "Nhap da thuc thu nhat: \n";
    cout << "Nhap bac cua da thuc thu nhat: ";int n;cin >> n;
    while (n < 0) {
        cout << "\nBac cua Da thuc phai >= 0!\n";
        cout << "Nhap lai n cua da thuc thu nhat: ";cin >> n;
    }
    cDaThuc a(n + 1);cin >> a;

    cout << "\nNhap da thuc thu hai: \n";
    cout << "Nhap bac cua da thuc thu hai: ";int m;cin >> m;
    while (m < 0) {
        cout << "\nBac cua Da thuc phai >= 0!\n";
        cout << "Nhap lai n cua da thuc thu hai: ";cin >> m;
    }
    cDaThuc b(m + 1);cin >> b;

    cout << "\nNhap gia tri x can tim: ";cin >> x;

    cout << "\n----------XUAT----------\n";
    cout << "Da thuc thu nhat la: ";cout << a;
    cout << "\nDa thuc thu hai la: ";cout << b;

    cout << "\n\nGia tri cua da thuc thu nhat voi x = " << x << ": " << a.GiaTriDaThuc(x);
    cout << "\nGia tri cua da thuc thu hai voi x = " << x << ": " << b.GiaTriDaThuc(x);

    cout << "\n\nTong hai da thuc: ";cout << a + b;
    cout << "\nGia tri cua Tong voi x = " << x << ": " << (a+b).GiaTriDaThuc(x);

    cout << "\n\nHieu hai da thuc: ";cout << a - b;
    cout << "\nGia tri cua Hieu voi x = " << x << ": " << (a-b).GiaTriDaThuc(x);
    
    return 0;
}