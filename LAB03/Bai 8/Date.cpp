#include <iostream>
#include "Date.h"

using namespace std;

Date::Date(int dd,int mm,int yyyy) {            // Phuong thuc thiet lap truyen tham so
    Ngay = dd;
    Thang = mm;
    Nam = yyyy;
}

istream& operator>> (istream& in,Date& day) {           // Dinh nghia toan tu Nhap(>>) cho class Date
    cout << "Nhap Ngay: ";in >> day.Ngay;
    cout << "Nhap Thang: ";in >> day.Thang;
    cout << "Nhap Nam: ";in >> day.Nam;
    return in;
}

ostream& operator<< (ostream& out,const Date& day) {    // Dinh nghia toan tu Xuat(<<) cho class Date
    if (day.Ngay < 10) out << 0;
    out << day.Ngay << "/";
    if (day.Thang < 10) out << 0;
    out << day.Thang << "/" << day.Nam;
    return out;
}