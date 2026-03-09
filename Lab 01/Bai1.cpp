#include <iostream>

using namespace std;

struct PS {
    int tuso;       // Tao struct cua phan so (gom tu so va mau so)
    int mauso;
};

void NhapPS (PS& phanso) {                  // Ham nhap phan so
    cout << "Nhap tu so: ";cin >> phanso.tuso;
    cout << "Nhap mau so: ";cin >> phanso.mauso;

    if (phanso.mauso == 0) {                // Neu mau so bang 0 thi yeu cau nhap lai   
        cout << "Mau so phai khac 0! Vui long nhap lai" << endl;
        NhapPS (phanso);
    }

    if (phanso.mauso < 0) {                 // Neu mau so < 0 thi chuyen dau tru len tu so
        phanso.tuso *= -1;                  // va neu ca mau va tu deu am thi chuyen lai thanh phan so duong
        phanso.mauso *= -1;
    }
}

void RutgonPS (PS& phanso) {                // Ham rut gon phan so
    if (phanso.tuso > 0) {                  // Neu phan so duong
        for (int i = min(phanso.tuso,phanso.mauso);i > 1;i--) {        // Tim uoc chung lon nhat
            if (phanso.tuso % i == 0 and phanso.mauso % i == 0) {      // Chia ca tu va mau cho uoc chung lon nhat
                phanso.tuso /= i;
                phanso.mauso /= i;
            }
        }
    }

    if (phanso.tuso < 0) {                  // Neu phan so am
        for (int i = max(phanso.tuso,phanso.mauso);i > 1;i--) {         // Tim uoc chung lon nhat
            if (phanso.tuso % i == 0 and phanso.mauso % i == 0) {       // Chia ca tu va mau cho uoc chung lon nhat
                phanso.tuso /= i;
                phanso.mauso /= i;
            }
        }
    }
}

int main () {
    PS phanso;
    NhapPS(phanso);
    RutgonPS(phanso);
    cout << phanso.tuso << "/" << phanso.mauso;
    return 0;
}
