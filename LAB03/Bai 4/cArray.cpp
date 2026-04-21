#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "cArray.h"

using namespace std;

void cArray::Nhap(int n) {                                  // Ham Nhap
    cout << "Nhap cac phan tu cua Mang hien tai: ";
    if (n == 0) cout << "\n";
    for (int i = 0;i < n;i++) {
        int c;cin >> c;
        a.push_back(c);
    }
}

void cArray::Xuat() {                                       // Ham Xuat
    for (int v : a) {
        cout << v << " ";
    }
}

void cArray::TaoMangNgauNhien(int n) {                                  // Ham Tao Mang ngau nhien
    random_device rd; 
    mt19937 generator(rd()); 
    std::uniform_int_distribution<int> distribution(-100, 100);         // Gia tri trong khoang tu -100 den 100

    for (int i = 0;i < n;i++) {
        a.push_back(distribution(generator));
    }
}

int cArray::SoLanXuatHienCua(int x) {                           // Input: 1 Mang va 1 gia tri cua x, Output: So lan x xuat hien trong mang
    int dem = 0;
    for (int i = 0;i < a.size();i++) {                          // Duyet toan mang (neu co x thi so la xuat hien + 1)
        if (a[i] == x) dem++;
    }
    return dem;
}

bool laSNT(int n) {
    if (n < 2) return false;                    // Các số < 2 không phải SNT
    if (n == 2) return true;                    // 2 là SNT chẵn duy nhất
    if (n % 2 == 0) return false;               // Loại các số chẵn khác 2

    // Kiểm tra các số lẻ từ 3 đến căn bậc hai của n
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void cArray::TimSNTLonNhat() {                      // Input: 1 Mang, Output: So nguyen to lon nhat cua mang
    int maxSNT = -1;
    bool check = false;

    for (int i = 0; i < a.size(); i++) {
        if (laSNT(a[i])) {
            if (!check || a[i] > maxSNT) {
                maxSNT = a[i];
                check = true;
            }
        }
    }

    if (check) {
        cout << "\nSo nguyen to lon nhat la: " << maxSNT;
    } else {
        cout << "\nMang khong co so nguyen to.";
    }
}

void cArray::KiemTraTangDan() {                                     // Ham kiem tra tang dan
    if (a.size() <= 0) {cout << "Mang trong";return;}               // Neu Ham trong thi khong can kiem tra
    for (int i = 0;i < a.size() - 1;i++) {
        if (a[i] > a[i+1]) {cout <<"Mang khong Tang dan";return;}
    }
    cout << "Mang Tang dan";
}

void cArray::SapXepTangDan() {                          // Input: 1 Mang, Output: Mang da sap xep
    sort(a.begin(),a.end());
}

void cArray::PhanTuLeNhoNhat() {                        // Input: 1 Mang, Output: Phan tu le nho nhat trong mang
    for (int i = 0;i < a.size();i++) {
        if (a[i] % 2 == 1) {cout << a[i];return;}
    }
    cout << "Khong co phan tu le";
}