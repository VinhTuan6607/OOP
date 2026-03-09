#include <iostream>

using namespace std;

struct PS {             // Tao struct cua phan so (gom tu so va mau so)
    int tuso;
    int mauso;
};

void NhapPS (PS& phanso1 , PS& phanso2) {
    cout << "Nhap tu so cua phan so 1: ";cin >> phanso1.tuso;       // Nhap phan so thu nhat
    cout << "Nhap mau so cua phan so 1: ";cin >> phanso1.mauso;
    
    cout << "Nhap tu so cua phan so 2: ";cin >> phanso2.tuso;       // Nhap  phan so thu hai
    cout << "Nhap mau so cua phan so 2: ";cin >> phanso2.mauso;
    
    if (phanso2.mauso == 0 or phanso1.mauso == 0) {                 // Neu mau so cua 1 trong 2 phan so < 0 thi nhap lai
        cout << "Mau so phai khac 0! Vui long nhap lai" << endl;
        NhapPS (phanso1,phanso2);
    }

    if (phanso1.mauso < 0) {            // Neu mau so < 0 thi chuyen dau tru len tu so
        phanso1.tuso *= -1;             // va neu ca mau va tu deu am thi chuyen lai thanh phan so duong
        phanso1.mauso *= -1;
    }

    if (phanso2.mauso < 0) {
        phanso2.tuso *= -1;
        phanso2.mauso *= -1;
    }
}

void Sosanh (PS phanso1,PS phanso2) {
    // Quy dong phan so 1
    int tuso1 = phanso1.tuso * phanso2.mauso;       // Nhan ca tu va mau cua phan so 1 cho mau so cua phan so 2
    int mauso1 = phanso1.mauso * phanso2.mauso;

    // Quy dong phan so 2
    int tuso2 = phanso2.tuso * phanso1.mauso;       // Nhan ca tu va mau cua phan so 2 cho mau so cua phan so 1
    int mauso2 = phanso2.mauso * phanso1.mauso;

    // So sanh
    if (tuso1 > tuso2) cout << phanso1.tuso << "/" << phanso1.mauso;  // Neu tu so 1 sau khi quy dong lon hon thi xuat phan so 1 truoc khi quy dong
    else if (tuso1 < tuso2) cout << phanso2.tuso << "/" << phanso2.mauso; // Neu tu so 2 sau khi quy dong lon hon thi xuat phan so 2 truoc khi quy dong
}

int main () {
    PS phanso1;
    PS phanso2;

    NhapPS(phanso1,phanso2);

    Sosanh(phanso1,phanso2);

    return 0;
}