#include <iostream>
#include "Time.h"

using namespace std;

void Time::Nhap() {                                 // Ham nhap gio phut giay 
    cout << "Gio: ";cin >> iGio;                    // (Co the nhap giay va phut > 60)
    cout << "Phut: ";cin >> iPhut;                      
    cout << "Giay: ";cin >> iGiay;
    if (iGio < 0 || iPhut < 0 || iGiay < 0) {       // Thoi gian khong the am (neu nhap so am thi yeu cau nhap lai)
        cout << "Thoi gian khong hop le! Hay nhap lai thoi gian:\n";
        Nhap();
    }
}

void Time::Xuat() {                                 // Ham xuat thoi gian
    cout << iGio << "h ";
    if (iPhut < 10) cout << 0;                      // Neu phut va giay < 10 thi xuat them so 0 phia truoc cho de nhin
    cout << iPhut << "m ";
    if (iGiay < 10) cout << 0;
    cout << iGiay << "s";
}

void Time::TinhCongThemMotGiay() {                  // Input: thoi gian hien tai
    iGiay++;                                        // Cong them 1 giay

    iPhut += iGiay / 60;                            // Phut se bang phan nguyen cua giay chia 60
    iGiay = iGiay % 60;                             // Giay se bang phan du sau khi da chia 60

    iGio += iPhut / 60;                             // Gio se bang phan nguyen cua phut chia 60
    iPhut = iPhut % 60;                             // Phut se bang phan du sau khi da chia 60
}                                                   //Output: thoi gian cua 1 giay sau do
