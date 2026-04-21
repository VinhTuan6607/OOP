#include "Diem.cpp"
#include <iostream>

using namespace std;

class cTamGiac {
    private:
        Diem A;
        Diem B;
        Diem C;
    public:
        cTamGiac(Diem X = {0,0},Diem Y = {0,0},Diem Z = {0,0});             // Phuong thuc thiet lap mac dinh (Ca 3 diem deu co toa do (0;0))

        friend istream& operator>> (istream& in,cTamGiac& a);
        friend ostream& operator<< (ostream& out,const cTamGiac& a);

        void KiemTraLoaiTamGiac();

        double TinhChuVi();
        double TinhDienTich();

        void TinhTien(Diem X);
        void Quay(Diem X,double goc);

        void ThayDoiKichThuoc(double k);
};