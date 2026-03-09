#include <iostream>

using namespace std;

struct HS {             // Tao struct hoc sinh (gom ho ten, diem toan, diem van, diem trung binh)
    string Ten;
    double Toan;
    double Van;
    double DTB;
};

void NhapThongTin (HS& a) {         // Ham nhap thong tin
    cout << "Nhap ten hoc sinh: ";getline(cin,a.Ten);
    cout << "Nhap diem toan: ";cin >> a.Toan;
    cout << "Nhap diem van: ";cin >> a.Van;
    a.DTB = (a.Toan + a.Van) / 2;       // Diem trung binh se bang (Toan + Van) / 2
}

void XuatThongTin (HS a) {          // Ham xuat thong tin
    cout << "Ho ten: " << a.Ten << endl;
    cout << "Diem Toan: " << a.Toan << endl;
    cout << "Diem Van: " << a.Van << endl;
    cout << "Diem trung binh: " << a.DTB;
}

int main () {
    HS hocsinh;
    NhapThongTin(hocsinh);
    XuatThongTin(hocsinh);
    return 0;
}