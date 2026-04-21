#include <iostream>
#include <cmath>
#include <iomanip>
#include "Diem.h"

using namespace std;

Diem::Diem (double a,double b) {        // Phuong thuc thiet lap (truyen tham so)
    x = a;
    y = b;
}

istream& operator>> (istream& in,Diem& a) {         // Dinh nghia toan tu NHAP(>>) cho class Diem
    cout << "Nhap toa do (x;y):\n";
    cout << "x = ";in >> a.x;
    cout << "y = ";in >> a.y;
    return in;
}

ostream& operator<< (ostream& out,const Diem& a) {      // Dinh nghia toan tu XUAT(<<) cho class Diem
    double tx = (abs(a.x) < 1e-10) ? 0 : a.x;           // Xuat toi da 2 so thap phan sau dau ,
    double ty = (abs(a.y) < 1e-10) ? 0 : a.y;

    out << "(";

    if (abs(tx - round(tx)) < 1e-9) out << defaultfloat << (long long)round(tx);
    else out << fixed << setprecision(2) << tx;

    out << " ; " ;

    if (abs(ty - round(ty)) < 1e-9) out << defaultfloat << (long long)round(ty);
    else out << fixed << setprecision(2) << ty;

    out << ")";                                         // Xuat duoi dang (x;y)

    out << defaultfloat;
    return out;
}

double DoDaiCanh (Diem a,Diem b) {                                              // Input: Hai diem a va b, Output: Do dai canh ab
    double dodai = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);           // Su dung cong thuc tinh do dai vector trong toan hoc
    return sqrt(dodai);
}

Diem operator+ (Diem a,Diem b) {                        // Dinh nghia toan tu + cho class Diem
    a.x += b.x;
    a.y += b.y;
    return a;
}

Diem operator- (Diem a,Diem b) {                        // Dinh nghia toan tu - cho class Diem
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

Diem operator* (Diem a,Diem b) {                        // Dinh nghia toan tu * cho class Diem
    a.x *= b.x;
    a.y *= b.y;
    return a;
}

Diem operator/ (Diem a,double b) {                      // Dinh nghia toan tu / cho class Diem
    a.x /= b;
    a.y /= b;
    return a;
}

void Diem::QuayDiem(Diem X,double gocquay) {            // Input: 1 Diem, Diem X la diem co dinh bat ky, goc quay, Output: Diem sau khi da quay (toa do thay doi)
    double rad = gocquay * M_PI / 180.0;                // Chuyen goc quay thanh don vi radian

    double tempX,tempY;

    tempX = X.x + (x - X.x)*cos(rad) - (y - X.y)*sin(rad);  // Su dung cong thuc de quay diem theo diem X
    tempY = X.y + (x - X.x)*sin(rad) + (y - X.y)*cos(rad);

    x = tempX;
    y = tempY;
}