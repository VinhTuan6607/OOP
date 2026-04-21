#include "Diem.cpp"
#include <iostream>
#include <vector>

using namespace std;

class cDaGiac {
    private:
        vector<Diem> arr;
        int n;
    public:
        friend istream& operator>> (istream& in,cDaGiac& a);
        friend ostream& operator<< (ostream& out,const cDaGiac& a);

        double TinhChuVi();
        double TinhDienTich();

        void TinhTien(Diem X);
        void Quay(Diem X,double goc);

        void ThayDoiKichThuoc(double k);
};