#include <iostream>
#include <vector>
#include "cDaThuc.h"

using namespace std;

cDaThuc::cDaThuc(int N) {               // Phuong thuc thiet lap 
    n = N + 1;                          // Nhap vao N la luy thua lon nhat thi Da thuc se co N + 1 phan tu
    arr.resize(N);
}

istream& operator>> (istream& in,cDaThuc& a) {                              // Dinh nghia toan tu Nhap(>>) cho class cDaThuc
    for (int i = 0;i < a.arr.size();i++) {
        cout << "Nhap he so cua x^" << a.arr.size() - 1 - i << " : ";
        in >> a.arr[i];
        a.arr[i].UpdateHeSo(a.arr.size() - 1 - i);
    }
    return in;
}

ostream& operator<< (ostream& out,const cDaThuc& a) {                       // Dinh nghia toan tu Xuat(<<) cho class cDaThuc
    for (int i = 0;i < a.arr.size();i++) {
        if (i > 0 && a.arr[i].HeSo() >= 0) cout << " + ";
        else if (i > 0 && a.arr[i].HeSo() < 0) cout << " - ";

        if (i == 0 && a.arr[i].HeSo() < 0) cout << "-";
        out << a.arr[i];
    }
    return out;
}

int cDaThuc::GiaTriDaThuc(int x) {                  // Input: 1 Da thuc va gia tri cua x, Output: Gia tri cua Da thuc
    int sum = 0;
    for (int i = 0;i < arr.size();i++) {
        sum += arr[i].GiaTriDonThuc(x);
    }
    return sum;
}

cDaThuc operator+(cDaThuc a,cDaThuc b) {                    // Dinh nghia toan tu + cho class cDaThuc
    if (a.n >= b.n) {                                       // Input: 2 Da thuc a va b, Output: 1 Da thuc moi la tong cua 2 da thuc a va b
        int i = a.arr.size() - 1;                           // Neu da thuc a co nhieu phan tu da thuc b
        int j = b.arr.size() - 1;                           // Cong lan luot cac bien co luy thua nho den lon (Cac phan tu tu cuoi mang len dau mang)
        while (j >= 0) {
            a.arr[i] = TongDonThuc(a.arr[i],b.arr[j]);
            i--;
            j--;
        }
        return a;
    }

    int i = a.arr.size() - 1;                               // Neu da thuc b co nhieu phan tu a
    int j = b.arr.size() - 1;                               // Lam tuong tu nhu tren
    while (i >= 0) {
        b.arr[j] = TongDonThuc(a.arr[i],b.arr[j]);
        i--;
        j--;
    }
    return b;
    
}

cDaThuc operator-(cDaThuc a,cDaThuc b) {                    // Dinh nghia toan tu - cho class cDaThuc
    if (a.n >= b.n) {                                       // Input: 2 Da thuc a va b, Output: Da thuc moi la hieu cua a va b
        int i = a.arr.size() - 1;                           // Neu a co nhieu phan tu hon b
        int j = b.arr.size() - 1;                           // Lay cac phan tu cua a tru cho cac phan tu cua b
        while (j >= 0) {
            a.arr[i] = HieuDonThuc(a.arr[i],b.arr[j]);
            i--;
            j--;
        }
        return a;
    }

    int i = a.arr.size() - 1;                               // Neu b co nhieu phan tu hon a
    int j = b.arr.size() - 1;                               // Lay cac phan tu cua a tru cho cac phan tu cua b
    while (i >= 0) {                                        // Cac phan tu con lai cua b se doi dau
        b.arr[j] = HieuDonThuc(a.arr[i],b.arr[j]);
            i--;
            j--;
    }

    while (j >= 0) {
        b.arr[j].SoAm();
        j--;
    }
    return b;
    
}
