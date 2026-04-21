#include <iostream>
#include "cDaGiac.cpp"

using namespace std;

int main () {
    cDaGiac ABCD;
    cout << "----------NHAP DA GIAC----------\n";
    cin >> ABCD;

    cout << "\n----------THONG TIN DA GIAC----------\n";
    if (ABCD.TinhDienTich() == 0) {
        cout << "Khong phai la Da giac";
        return 0;
    }
    
    cout << "Chu vi: ";cout << ABCD.TinhChuVi();
    cout << "\nDien tich: ";cout << ABCD.TinhDienTich();

    if (ABCD.TinhDienTich() <= 0) return 0;
    
    cout << "\n\n----------DICH CHUYEN DA GIAC----------\n";
    Diem vectortinhtien;
    cout << "TINH TIEN:\n";
    cout << "Nhap vector tinh tien:\n";cin >> vectortinhtien;
    cDaGiac Tinhtien = ABCD;Tinhtien.TinhTien(vectortinhtien);
    cout << "\nToa do cua cac dinh da giac sau khi tinh tien la:";cout << Tinhtien;

    Diem diemquay;double gocquay;
    cout << "\n\nQUAY:\n";
    cout << "Nhap diem quay:\n";cin >> diemquay;
    cout << "Nhap goc quay (don vi: do): ";cin >> gocquay;
    cDaGiac quay = ABCD;quay.Quay(diemquay,gocquay);
    cout << "\nToa do cua cac dinh da giac sau khi quay la:";cout << quay;

    cout << "\n\n----------THAY DOI KICH THUOC DA GIAC----------\n";
    double k;
    cout << "HE SO k: (k phai khac 0)\n";
    cout << "(Phong to neu k > 1)\n";
    cout << "(Thu nho neu 0 < k < 1)\n";
    cout << "(Giu nguyen neu k = 1)\n";

    cout << "\nNhap he so thay doi k: ";cin >> k;
    while (k == 0) {
        cout << "k phai khac 0\n";
        cout << "Nhap lai he so k: ";cin >> k;
    }

    cout << "\n";
    ABCD.ThayDoiKichThuoc(k);

    if (k == 1) cout << "Da giac khong co su thay doi";

    else if (k > 1) {
        cout << "Da giac sau khi PHONG TO: ";cout << ABCD;
    }
    
    else if (k > 0 && k < 1) {
        cout << "Da giac sau khi THU NHO: ";cout << ABCD;
    }

    return 0;
}