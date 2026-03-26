#include <iostream>
#include "Date.h"

using namespace std;

void date::Nhap() {                    // Ham nhap ngay thang nam
    cin >> iNgay;
    cin >> iThang;
    cin >> iNam;

    if ((iThang == 1 ||                 // Kiem tra cac ngay co hop le hay khong
        iThang == 3 ||                  // Neu cac ngay khong hop le thi yeu cau nhap lai
        iThang == 5 ||
        iThang == 7 ||
        iThang == 8 ||
        iThang == 10 ||
        iThang == 12) 
        && iNgay > 31) {
            cout << "Ngay khong hop le\n\n";
            cout << "Yeu cau nhap lai: ";Nhap();
        }

    else if ((iThang == 4 ||        
        iThang == 6 ||              
        iThang == 9 ||
        iThang == 11) 
        && iNgay > 30) {
            cout << "Ngay khong hop le\n\n";
            cout << "Yeu cau nhap lai: ";Nhap();
        }

    else if (iThang == 2) {         
        if (iNam % 4 == 0) {         
            if (iNgay > 29) {        
            cout << "Ngay khong hop le\n\n";
            cout << "Yeu cau nhap lai: ";Nhap();
            }
        }

        else {                       
            if (iNgay > 28) {        
            cout << "Ngay khong hop le\n\n";
            cout << "Yeu cau nhap lai: ";Nhap();
            }
        }
    }

    if (iThang > 12) {             
        cout << "Ngay khong hop le\n\n";
        cout << "Yeu cau nhap lai: ";Nhap();
    }
}

void date::Xuat() {                     // Ham xuat ngay thang nam
    cout << iNgay << "/" << iThang << "/" << iNam;  
}

void date::NgayThangTiepTheo() {
    iNgay++;                        // ngay + 1

    if ((iThang == 1 ||             // Neu thang cua hom nay la vao cac thang co 31 ngay va hom nay la ngay 31
        iThang == 3 ||              // thi ngay mai: ngay se tro ve 1 va thang se +1
        iThang == 5 ||
        iThang == 7 ||
        iThang == 8 ||
        iThang == 10 ||
        iThang == 12) 
        && iNgay > 31) {
            iNgay -= 31;
            iThang++;
        }

    else if ((iThang == 4 ||        // Neu thang cua hom nay la vao cac thang co 30 ngay va hom nay la ngay 30
        iThang == 6 ||              // thi ngay mai: ngay se tro ve 1 va thang se +1
        iThang == 9 ||
        iThang == 11) 
        && iNgay > 30) {
            iNgay -= 30;
            iThang++;
        }
    
    else if (iThang == 2) {         // Neu hom nay la thang 2
        if (iNam % 4 == 0) {         // Neu nam cua hom nay la nam nhuan
            if (iNgay > 29) {        // Neu ngay cua hom nay la 29
                iNgay -= 29;         // thi ngay mai: ngay se tro ve 1 va thang se +1
                iThang++;
            }
        }

        else {                       // Neu nam cua hom nay la nam khong nhuan
            if (iNgay > 28) {        // Neu ngay hom nay la 28
                iNgay -= 28;         // thi ngay mai: ngay se tro ve 1 va thang se +1
                iThang++;
            }
        }
    }

    if (iThang > 12) {             // Neu hom nay la 31/12 va sau khi cong ngay
        iThang -= 12;               // (ngay mai se la ngay 1 thang 13)
        iNam++;                    // thi ngay mai: thang se tro ve 1 va nam se +1
    }
}
