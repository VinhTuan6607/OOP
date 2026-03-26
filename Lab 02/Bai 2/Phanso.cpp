#include <iostream>
#include "Phanso.h"

using namespace std;

void PhanSo::Nhap() {
    cout << "Tu so: ";cin >> iTu;
    cout << "Mau so: ";cin >> iMau;
    if (iMau == 0) {                 // Neu mau so cua 1 trong 2 phan so < 0 thi nhap lai
        cout << "Mau so phai khac 0! Vui long nhap lai:\n";
        Nhap();
    }

    if (iMau < 0) {            // Neu mau so < 0 thi chuyen dau tru len tu so
        iTu *= -1;             // va neu ca mau va tu deu am thi chuyen lai thanh phan so duong
        iMau *= -1;
    }
}

void PhanSo::Xuat() {
    if (iTu == 0) {cout << 0;return;}         // Neu tu so bang 0 thi phan so bang 0
    if (iMau == 1) {cout << iTu;return;}      // Neu mau so bang 1 thi phan so bang tu so
    cout << iTu << "/" << iMau;
}

void PhanSo::RutGon() {
    if (iTu > 0) {              // Neu phan so duong
        for (int i = min(iTu,iMau);i > 1;i--) {         // Tim uoc chung lon nhat
            if (iTu % i == 0 and iMau % i == 0) {       // Chia ca tu va mau cho uoc chung lon nhat
                iTu /= i;
                iMau /= i;
            }
        }
    }

    if (iTu < 0) {              // Neu phan so am
        for (int i = max(iTu,iMau);i > 1;i--) {         // Tim uoc chung lon nhat
            if (iTu % i == 0 and iMau % i == 0) {       // Chia ca tu va mau cho uoc chung lon nhat
                iTu /= i;
                iMau /= i;
            }
        }
    }
}

PhanSo PhanSo::Tong(PhanSo a,PhanSo b) {
    PhanSo tong;                                        // Tao phan so la tong cua a va b
    tong.iTu = a.iTu * b.iMau + b.iTu * a.iMau;         // Tu so cua tong la tu a + tu b sau khi quy dong bang cach nhan cheo mau so
    tong.iMau = a.iMau * b.iMau;                        // Mau so cua tong la a * b (quy dong phan so)
    tong.RutGon();                                      // Rut gon lai tong
    return tong;
}

PhanSo PhanSo::Hieu(PhanSo a,PhanSo b) {
    PhanSo hieu;                                        // Tao phan so la hieu cua a va b
    hieu.iTu = a.iTu * b.iMau - b.iTu * a.iMau;         // Tu so cua hieu la tu a - tu b sau khi quy dong bang cach nhan cheo mau so
    hieu.iMau = a.iMau * b.iMau;                        // Mau so cua hieu la a * b (quy dong phan so)
    hieu.RutGon();                                      // Rut gon lai hieu
    return hieu;
}

PhanSo PhanSo::Tich(PhanSo a,PhanSo b) {
    PhanSo tich;                                        // Tao phan so la tich cua a va b
    tich.iTu = a.iTu * b.iTu;                           // Tu so cua tich la tu a nhan tu b
    tich.iMau = a.iMau * b.iMau;                        // Mau so cua tich la mau a nhan mau b
    tich.RutGon();                                      // Rut gon lai tich
    return tich;
}

PhanSo PhanSo::Thuong(PhanSo a,PhanSo b) {              // (Chia la nhan nghich dao)
    PhanSo thuong;                                      // Tao phan so la thuong cua a va b
    thuong.iTu = a.iTu * b.iMau;                         // Tu so cua thuong la tu a nhan mau b  
    thuong.iMau = a.iMau * b.iTu;                      // Mau so cua thuong la mau a nhan tu b
    thuong.RutGon();                                    // Rut gon lai thuong
    return thuong;
}

void PhanSo::SoSanh(PhanSo a,PhanSo b) {                // Input: 2 phan so 
    PhanSo quydonga;                                    // Output: so sanh do lon cua 2 phan so
    PhanSo quydongb;

    // Quy dong phan so a
    quydonga.iTu = a.iTu * b.iMau;  
    quydonga.iMau = a.iMau * b.iMau;

    // Quy dong phan so b
    quydongb.iTu = b.iTu * a.iMau;
    quydongb.iMau = a.iMau * b.iMau;

    // So sanh tu so cua 2 phan so sau khi quy dong 
    if (quydonga.iTu == quydongb.iTu) {                  
        a.Xuat();cout << " = ";b.Xuat();
        return;
    }

    else if (quydonga.iTu < quydongb.iTu){
        a.Xuat();cout << " < ";b.Xuat();
        return;
    }

    else if (quydonga.iTu > quydongb.iTu){
        a.Xuat();cout << " > ";b.Xuat();
        return;
    }
}
