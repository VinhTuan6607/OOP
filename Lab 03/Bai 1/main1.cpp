#include <iostream>
#include "cTamGiac.cpp"

using namespace std;

int main () {
    cTamGiac ABC;
    cout << "----------NHAP TAM GIAC----------\n";
    cin >> ABC;

    cout << "\n----------THONG TIN TAM GIAC----------\n";
    cout << "Loai Tam giac: ";ABC.KiemTraLoaiTamGiac();

    if (ABC.TinhDienTich() <= 0) return 0;

    cout << "\nChu vi: ";cout << ABC.TinhChuVi();
    cout << "\nDien tich: ";cout << ABC.TinhDienTich();
    
    cout << "\n\n----------DICH CHUYEN TAM GIAC----------\n";
    Diem vectortinhtien;
    cout << "TINH TIEN:\n";
    cout << "Nhap vector tinh tien:\n";cin >> vectortinhtien;
    cTamGiac Tinhtien = ABC;Tinhtien.TinhTien(vectortinhtien);
    cout << "\nToa do cua cac dinh tam giac sau khi tinh tien la:";cout << Tinhtien;

    Diem diemquay;double gocquay;
    cout << "\n\nQUAY:\n";
    cout << "Nhap diem quay:\n";cin >> diemquay;
    cout << "Nhap goc quay (don vi: do): ";cin >> gocquay;
    cTamGiac quay = ABC;quay.Quay(diemquay,gocquay);
    cout << "\nToa do cua cac dinh tam giac sau khi quay la:";cout << quay;

    cout << "\n\n----------THAY DOI KICH THUOC TAM GIAC----------\n";
    double k;
    cout << "HE SO k: (k phai lon hon 0)\n";
    cout << "(Phong to neu k > 1)\n";
    cout << "(Thu nho neu 0 < k < 1)\n";
    cout << "(Giu nguyen neu k = 1)\n";

    cout << "\nNhap he so thay doi k: ";cin >> k;
    while (k <= 0) {
        cout << "\nk phai lon hon 0\n";
        cout << "Nhap lai he so k: ";cin >> k;
    }

    cout << "\n";
    ABC.ThayDoiKichThuoc(k);

    if (k == 1) cout << "Tam giac khong co su thay doi";

    else if (k > 1) {
        cout << "Tam giac sau khi PHONG TO: ";cout << ABC;
    }
    
    else if (k > 0 && k < 1) {
        cout << "Tam giac sau khi THU NHO: ";cout << ABC;
    }

    return 0;
}