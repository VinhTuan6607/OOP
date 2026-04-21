#include <iostream>
#include "DonThuc.h"

using namespace std;

istream& operator>> (istream& in,DonThuc& a) {                  // Dinh nghia toan tu Nhap(>>) cho class DonThuc
    in >> a.heso;
    return in;
}

ostream& operator<< (ostream& out,const DonThuc& a) {           // Dinh nghia toan tu Xuat(<<) cho class DonThuc
    if (a.luythua == 0) {
        if (a.heso >= 0) out << a.heso;
        else out << -a.heso;
        return out;
    }

    else if (a.luythua == 1) {
        if (a.heso >= 0) cout << a.heso << "x";
        else cout << -a.heso << "x";
        return out;
    }

    if (a.heso >= 0) cout << a.heso << "x^" << a.luythua;
    else cout << -a.heso << "x^" << a.luythua;
    return out;
}

int DonThuc::GiaTriDonThuc(int x) {                            // Input: 1 Don thuc va gia tri cua x, Output: Gia tri cua don thuc do
    int giatri = heso;                                         // Gia tri cua don thuc = he so * x ^ bac cua don thuc 
    for (int i = 0;i < luythua;i++) {                           // Tao vong lap de tinh x ^ bac cua don thuc
        giatri *= x;
    }
    return giatri;
}

DonThuc TongDonThuc(DonThuc a,DonThuc b) {                      // Input: 2 don thuc a va b (a va b co cung bac), Output: 1 don thuc la tong cua a va b
    DonThuc c;                                                  // Tao don thuc moi
    c.heso = a.heso + b.heso;                                   // He so cua don thuc moi = Tong cua 2 he so a va b
    c.luythua = a.luythua;                                      // Bac cua don thuc = Bac cua a va b (a va b co cung bac)
    return c;
}

DonThuc HieuDonThuc(DonThuc a,DonThuc b) {                      // Input: 2 don thuc a va b (a va b co cung bac), Output: 1 don thuc la hieu cua a va b
    DonThuc c;                                                  // Tao don thuc moi
    c.heso = a.heso - b.heso;                                   // He so cua don thuc moi = Hieu cua 2 he so a va b
    c.luythua = a.luythua;                                      // Bac cua don thuc = Bac cua a va b (a va b co cung bac)
    return c;
}