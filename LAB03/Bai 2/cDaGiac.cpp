#include <iostream>
#include <cmath>
#include "cDaGiac.h"

using namespace std;

istream& operator>> (istream& in,cDaGiac& a) {          // Dinh nghia toan tu NHAP(>>) cho class cDaGiac
    cout << "Nhap so dinh cua Da giac: ";in >> a.n;
    cout << "Nhap toa do cac dinh cua Da giac:\n";
    for (int i = 0;i < a.n;i++) {
        Diem x;
        cout << "Dinh thu " << i+1 << ":\n";
        in >> x;
        a.arr.push_back(x);
    }
    return in;
}

ostream& operator<< (ostream& out,const cDaGiac& a) {               // Dinh nghia toan tu XUAT(<<) cho class cDaGiac
    for (int i = 0;i < a.arr.size();i++) {
        out << "\nDinh thu " << i+1 << ": " << a.arr[i];
    }
    return out;
}

double cDaGiac::TinhChuVi() {                                      // Input: 1 Da giac, Output: Chu vi cua Da giac do (Kieu du lieu double)
    double sum = DoDaiCanh(arr[0],arr[arr.size()-1]);              // Khoi tao ham sum (sum = canh cua dinh dau va dinh cuoi de thuan tien cho vong lap)
    for (int i = 0;i < arr.size() - 1;i++) {                        // Tao vong lap de cong cac canh duoc tao boi cac dinh ke nhau
        sum += DoDaiCanh(arr[i],arr[i+1]);
    }
    return sum;                                                     // Chu vi Da giac bang TONG cua cac canh trong Da giac do
}

double cDaGiac::TinhDienTich() {                               // Input: 1 Da giac, Output: Dien tich cua Da giac do (Kieu du lieu double)
    double S = 0;                                               // Su dung cong thuc Shoelace de tinh dien tich Da giac
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        S += arr[i].LayX() * arr[j].LayY();
        S -= arr[j].LayX() * arr[i].LayY();
    }
    S = abs(S) / 2;
    return S;
}

void cDaGiac::TinhTien(Diem X) {                       // Input: Diem X (X dong vai tro nhu 1 vector tinh tien), Output: Da giac sau khi da tinh tien (toa do thay doi)
    for (int i = 0;i < arr.size();i++) {               // Cong toa do x , y cua tung dinh voi toa do cua vector tinh tien X
        arr[i] = arr[i] + X;
    }
}

void cDaGiac::Quay(Diem X,double gocquay) {            // Input: 1 Da giac, Diem X la diem co dinh bat ky, goc quay, Output: Da giac sau khi da quay (toa do thay doi)
    for (int i = 0;i < arr.size();i++) {                              // Quay tung diem theo diem co dinh X
        arr[i].QuayDiem(X,gocquay);
    }
}

void cDaGiac::ThayDoiKichThuoc(double k) {             // Input: 1 Da giac, so thuc k, Output: Da giac sao khi thay doi k lan (toa do thay doi)
    Diem I;                                             // I la trong tam cua Da giac 
    for (int i = 0;i < arr.size();i++) {
        I = I + arr[i];
    }
    
    I = I / n;

    for (int i = 0;i < arr.size();i++) {                 // Cong thuc de thay doi kich thuoc
        arr[i] = I + (Diem(k,k) * (arr[i] - I));        
    }                                                    // Phong to neu k > 1, Thu nho neu 0 < k < 1, Giu nguyen neu k = 1
}