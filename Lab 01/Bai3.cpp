#include <iostream>

using namespace std;

struct PS {         // Tao struct cua phan so (gom tu so va mau so)
    int tuso;
    int mauso;
};

void NhapPS (PS& phanso1 , PS& phanso2) {
    cout << "Nhap tu so cua phan so 1: ";cin >> phanso1.tuso;           // Nhap phan so thu nhat
    cout << "Nhap mau so cua phan so 1: ";cin >> phanso1.mauso;
    
    cout << "Nhap tu so cua phan so 2: ";cin >> phanso2.tuso;           // Nhap phan so thu hai
    cout << "Nhap mau so cua phan so 2: ";cin >> phanso2.mauso;
    
    if (phanso2.mauso == 0 or phanso1.mauso == 0) {                     // Neu mau so cua 1 trong 2 phan so < 0 thi nhap lai
        cout << "Mau so phai khac 0! Vui long nhap lai" << endl;
        NhapPS (phanso1,phanso2);
    }
}

void RutgonPS (PS& phanso) {
    if (phanso.tuso > 0) {              // Neu phan so duong
        for (int i = min(phanso.tuso,phanso.mauso);i > 1;i--) {         // Tim uoc chung lon nhat
            if (phanso.tuso % i == 0 and phanso.mauso % i == 0) {       // Chia ca tu va mau cho uoc chung lon nhat
                phanso.tuso /= i;
                phanso.mauso /= i;
            }
        }
    }

    if (phanso.tuso < 0) {              // Neu phan so am
        for (int i = max(phanso.tuso,phanso.mauso);i > 1;i--) {         // Tim uoc chung lon nhat
            if (phanso.tuso % i == 0 and phanso.mauso % i == 0) {       // Chia ca tu va mau cho uoc chung lon nhat
                phanso.tuso /= i;
                phanso.mauso /= i;
            }
        }
    }
}

void Quydong (PS& phanso1,PS& phanso2) {
    // Quy dong phan so 1
    int tuso1 = phanso1.tuso * phanso2.mauso;       // Nhan ca tu va mau cua phan so 1 cho mau so cua phan so 2
    int mauso1 = phanso1.mauso * phanso2.mauso;     

    // Quy dong phan so 2
    int tuso2 = phanso2.tuso * phanso1.mauso;       // Nhan ca tu va mau cua phan so 2 cho mau so cua phan so 2
    int mauso2 = phanso2.mauso * phanso1.mauso;

    phanso1.tuso = tuso1;          // Gan lai cac gia tri cua 2 phan so sau khi quy dong
    phanso1.mauso = mauso1;

    phanso2.tuso = tuso2;
    phanso2.mauso = mauso2;
}

void CongPS (PS phanso1, PS phanso2) {
    PS x;       
    Quydong(phanso1,phanso2);       // Quy dong 2 phan so
    x.tuso = phanso1.tuso + phanso2.tuso;       // Cong hai tu so
    x.mauso = phanso1.mauso;                    // Gan lai gia tri cua mau so la mau so sau khi quy dong
    RutgonPS(x);                                // Rut gon phan so
    cout << "Tong = " << x.tuso << "/" << x.mauso;  // Xuat phan so sau khi cong
}

void TruPS (PS phanso1, PS phanso2) {
    PS x;
    Quydong(phanso1,phanso2);       // Quy dong 2 phan so
    x.tuso = phanso1.tuso - phanso2.tuso;       // Tru hai tu so
    x.mauso = phanso1.mauso;                    // Gan lai gia tri cua mau so la mau so sau khi quy dong
    RutgonPS(x);                                // Rut gon phan so
    cout << "Hieu = " << x.tuso << "/" << x.mauso;  // Xuat phan so sau khi tru
}

void NhanPS (PS phanso1, PS phanso2) {
    PS x;
    x.tuso = phanso1.tuso * phanso2.tuso;       // Nhan hai tu so
    x.mauso = phanso1.mauso * phanso2.mauso;    // Nhan hai mau so
    RutgonPS(x);                                // Rut gon
    cout << "Tich = " << x.tuso << "/" << x.mauso;  // Xuat phan so sau khi nhan
}

void ChiaPS (PS phanso1, PS phanso2) {          // (Chia la nhan nghich dao)
    PS x;                                       
    x.tuso = phanso1.tuso * phanso2.mauso;      // Nhan tu so cua phan so 1 cho mau so cua phan so 2
    x.mauso = phanso1.mauso * phanso2.tuso;     // Nhan mau so cua phan so 1 cho tu so cua phan so 2
    RutgonPS(x);                                // Rut gon phan so
    cout << "Thuong = " << x.tuso << "/" << x.mauso;    // Xuat phan so sau khi chia
}

int main () {
    PS phanso1, phanso2;

    NhapPS(phanso1,phanso2);

    CongPS(phanso1,phanso2);cout << endl;
    TruPS(phanso1,phanso2);cout << endl;
    NhanPS(phanso1,phanso2);cout << endl;
    ChiaPS(phanso1,phanso2);cout << endl;

    return 0;
}