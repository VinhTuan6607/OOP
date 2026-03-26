#include <iostream>
#include "Sophuc.h"

using namespace std;

void SoPhuc::Nhap() {                               // Ham nhap so phuc
    cout << "Phan thuc: ";cin >> iThuc;
    cout << "Phan ao: ";cin >> iAo;
    if (iThuc == 0 and iAo == 0) {                  // So phuc se khong hop le neu phan thuc va phan ao deu bang 0
        cout << "So phuc phai khac 0 + 0i \n\n";
        cout << "Yeu cau nhap lai: ";
        Nhap();
    }
}

void SoPhuc::Xuat() {                               // Ham xuat so phuc
    if (iAo == 0) cout << iThuc << '\n';
    else if (iAo > 0) cout << iThuc << " + " << iAo << "i" << '\n';
    else if (iAo < 0) cout << iThuc << " - " << -iAo << "i" << '\n';
}

SoPhuc SoPhuc::Tong(SoPhuc a,SoPhuc b) {            //  Input: 2 so phuc
    SoPhuc c;                                       // Tong 2 so phuc co: phan thuc la tong cua 2 phan thuc va 
    c.iThuc = a.iThuc + b.iThuc;                    // Phan ao la tong cua 2 phan ao
    c.iAo = a.iAo + b.iAo;
    return c;                                       // Output: 1 so phuc la tong cua 2 so phuc
}

SoPhuc SoPhuc::Hieu(SoPhuc a,SoPhuc b) {            // Input: 2 so phuc
    SoPhuc c;                                       // Hieu 2 so phuc co: phan thuc la hieu cua 2 phan thuc va 
    c.iThuc = a.iThuc - b.iThuc;                    // Phan ao la hieu cua 2 phan ao
    c.iAo = a.iAo - b.iAo;
    return c;                                       // Output: 1 so phuc la hieu cua 2 so phuc
}

SoPhuc SoPhuc::Tich(SoPhuc a,SoPhuc b) {            // Input: 2 so phuc
    SoPhuc c;                                       // (a+bi)(c+di)
    c.iThuc = a.iThuc * b.iThuc - a.iAo * b.iAo;    // = ac + adi + bci + bdi^2
    c.iAo = a.iThuc * b.iAo + a.iAo * b.iThuc;      // = (ac - bd) + (ad + bc)i   (vi i^2 = -1)
    return c;                                       // Output: 1 so phuc la tich cua 2 so phuc
}

SoPhuc SoPhuc::Thuong(SoPhuc a,SoPhuc b) {                                                      // Input: 2 so phuc
    SoPhuc c;                                                                                   // (a+bi)/(c+di)
    c.iThuc = (a.iThuc * b.iThuc + a.iAo * b.iAo) / (b.iThuc * b.iThuc + b.iAo * b.iAo);        // nhân cả tử và mẫu với (c-di) để khử i ở mẫu
    c.iAo = (a.iAo * b.iThuc - a.iThuc * b.iAo) / (b.iThuc * b.iThuc + b.iAo * b.iAo);          // Phan thuc: (ac + bd) / (c^2 + d^2)                                                    
    return c;                                                                                   // Phan ao : (bc - ad) / (c^2 + d^2)                                                                                                                                               
}                                                                                               // Output: 1 so phuc la tich cua 2 so phuc
