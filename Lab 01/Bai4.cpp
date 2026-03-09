#include <iostream>

using namespace std;

struct Time {                   // Tao struct thoi gian (gom ngay, thang, nam)
    int day;
    int month;
    long long int year;
};

bool Namnhuan (Time ngay) {             // Ham check nam nhuan
    if (ngay.year % 4 == 0) return 1;   // Neu nam chia cho 4 thi la nam nhuan
    else return 0;
}

void NhapTime (Time& ngay) {                    // Ham nhap ngay thang nam
    cout << "Nhap ngay thang nam hom nay: ";
    cin >> ngay.day;
    cin >> ngay.month;
    cin >> ngay.year;
}

void Tomorrow (Time ngay) {
    ngay.day++;                         // +1 ngay

    if ((ngay.month == 1 or             // Neu thang cua hom nay la vao cac thang co 31 ngay va hom nay la ngay 31
        ngay.month == 3 or              // thi ngay mai: ngay se tro ve 1 va thang se +1
        ngay.month == 5 or
        ngay.month == 7 or
        ngay.month == 8 or
        ngay.month == 10 or
        ngay.month == 12) 
        and ngay.day > 31) {
            ngay.day -= 31;
            ngay.month++;
        }

    else if ((ngay.month == 4 or        // Neu thang cua hom nay la vao cac thang co 30 ngay va hom nay la ngay 30
        ngay.month == 6 or              // thi ngay mai: ngay se tro ve 1 va thang se +1
        ngay.month == 9 or
        ngay.month == 11) 
        and ngay.day > 30) {
            ngay.day -= 30;
            ngay.month++;
        }
    
    else if (ngay.month == 2) {         // Neu hom nay la thang 2
        if (Namnhuan(ngay)) {           // Neu nam cua hom nay la nam nhuan
            if (ngay.day > 29) {        // Neu ngay cua hom nay la 29
                ngay.day -= 29;         // thi ngay mai: ngay se tro ve 1 va thang se +1
                ngay.month++;
            }
        }

        else {                          // Neu nam cua hom nay la nam khong nhuan
            if (ngay.day > 28) {        // Neu ngay hom nay la 28
                ngay.day -= 28;         // thi ngay mai: ngay se tro ve 1 va thang se +1
                ngay.month++;
            }
        }
    }

    if (ngay.month == 13) {             // Neu hom nay la 31/12 va sau khi cong ngay
        ngay.month -= 12;               // (ngay mai se la ngay 1 thang 13)
        ngay.year++;                    // thi ngay mai: thang se tro ve 1 va nam se +1
    }
    
    cout << "Ngay mai la: ";
    cout << ngay.day << "/" << ngay.month << "/" << ngay.year;  // Xuat ra ngay mai
}

int main () {
    Time hientai;
    NhapTime(hientai);
    Tomorrow(hientai);
    return 0;
}