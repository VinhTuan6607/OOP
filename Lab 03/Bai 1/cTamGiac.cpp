#include <iostream>
#include <cmath>
#include "cTamGiac.h"

using namespace std;

cTamGiac::cTamGiac(Diem X,Diem Y,Diem Z) {              // Phuong thuc thiet lap (truyen tham so)
    A = X;
    B = Y;
    C = Z;
}

istream& operator>> (istream& in,cTamGiac& a) {          // Dinh nghia toan tu NHAP(>>) cho class cTamGiac
    cout << "Nhap toa do 3 dinh cua tam giac:\n";
    cout << "Dinh thu 1:\n";
    in >> a.A;

    cout << "\nDinh thu 2:\n";
    in >> a.B;

    cout << "\nDinh thu 3:\n";
    in >> a.C;

    return in;
}

ostream& operator<< (ostream& out,const cTamGiac& a) {  // Dinh nghia toan tu XUAT(<<) cho class cTamGiac
    out << "\nDinh thu 1: " << a.A;
    out << "\nDinh thu 2: " << a.B;
    out << "\nDinh thu 3: " << a.C;
    return out;
}

void cTamGiac::KiemTraLoaiTamGiac() {
    double AB = DoDaiCanh(A,B);                                             // Tao cac bien la do dai cac canh AB, BC, AC
    double BC = DoDaiCanh(B,C);
    double AC = DoDaiCanh(A,C);

    if (AB + BC <= AC || BC + AC <= AB || AB + AC <= BC ) {                // De la tam giac thi: 
        cout << "Khong phai la Tam giac";                                  // Tong do dai 2 canh bat ki phai LON HON do dai canh con lai
        return;
    }

    if (abs(AB - AC) < 1e-2 && abs(AB - BC) < 1e-2 && abs(BC - AC) < 1e-2)  {   // Neu 3 canh bang nhau thi la tam giac deu
        cout << "Tam giac deu";
        return;
    }

    if (abs(AB - AC) < 1e-2 || abs(AB - BC) < 1e-2 || abs(BC - AC) < 1e-2) {    // Xet cac truong hop tam giac can (co 2 canh bang nhau)
        if (abs(AB*AB - (BC*BC + AC*AC)) < 1e-9 ||                                   // Su dung dinh ly Pytago de xem co goc vuong hay khong
            abs(BC*BC - (AC*AC + AB*AB)) < 1e-9 ||                                   // Neu co thi la tam giac vuong can
            abs(AC*AC - (AB*AB + BC*BC)) < 1e-9) {
                cout << "Tam giac vuong can";
                return;
            }

        else {                                                          // Neu khong thi la tam giac can
            cout << "Tam giac can";
            return;
        }
    }

    if (abs(AB*AB - (BC*BC + AC*AC)) < 1e-9 ||                                   // Su dung dinh ly Pytago de xem co goc vuong hay khong
        abs(BC*BC - (AC*AC + AB*AB)) < 1e-9 ||                                   // Neu co thi la tam giac vuong
        abs(AC*AC - (AB*AB + BC*BC)) < 1e-9) {
            cout << "Tam giac vuong";
            return;
        }
    
    else {                                                          // Neu khong nam trong cac truong hop dac biet tren thi la tam giac thuong
        cout << "Tam giac thuong";
        return;
    }
}

double cTamGiac::TinhChuVi() {                                      // Input: 1 Tam giac, Output: Chu vi cua Tam giac do (Kieu du lieu double)
    return DoDaiCanh(A,B) + DoDaiCanh(B,C) + DoDaiCanh(A,C);        // Chu vi Tam giac bang TONG cua 3 canh
}

double cTamGiac::TinhDienTich() {                               // Input: 1 Tam giac, Output: Dien tich cua Tam giac do (Kieu du lieu double)
    double AB = DoDaiCanh(A,B);                                 // Tao cac bien la do dai cac canh AB, BC, AC
    double BC = DoDaiCanh(B,C);
    double AC = DoDaiCanh(A,C);
    double p = TinhChuVi() / 2;                                 // p la nua Chu vi

    double S = sqrt(p*(p-AB)*(p-BC)*(p-AC));                    // Su dung cong thuc Heron de tinh dien tich Tam giac

    return S;
}

void cTamGiac::TinhTien(Diem X) {                       // Input: Diem X (X dong vai tro nhu 1 vector tinh tien), Output: Tam giac sau khi da tinh tien (toa do thay doi)
    A = A + X;                                           // Cong toa do x , y cua tung dinh voi toa do cua vector tinh tien X
    B = B + X;
    C = C + X;
}

void cTamGiac::Quay(Diem X,double gocquay) {            // Input: 1 Tam giac, Diem X la diem co dinh bat ky, goc quay, Output: Tam giac sau khi da quay (toa do thay doi)
    A.QuayDiem(X,gocquay);                              // Quay tung diem theo diem co dinh X
    B.QuayDiem(X,gocquay);
    C.QuayDiem(X,gocquay);
}

void cTamGiac::ThayDoiKichThuoc(double k) {             // Input: 1 Tam giac, so thuc k, Output: Tam giac sao khi thay doi k lan (toa do thay doi)
    Diem I = (A + B + C) / 3.0;                         // I la trong tam cua tam giac ABC 


    A = I + ((A - I) * Diem(k,k));                      // Cong thuc de thay doi kich thuoc
    B = I + ((B - I) * Diem(k,k));
    C = I + ((C - I) * Diem(k,k));                      // Phong to neu k > 1, Thu nho neu 0 < k < 1, Giu nguyen neu k = 1
}