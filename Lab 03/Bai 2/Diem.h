#include <iostream>

using namespace std;

class Diem {
    private:
        double x;
        double y;
    public:
        Diem(double a = 0,double b = 0);                    // Phuong thuc thiet lap mac dinh (x = 0 va y = 0)

        double LayX() {return x;};                           // Viet them ham de lay x va y
        double LayY() {return y;};

        friend istream& operator>> (istream& in,Diem& a);
        friend ostream& operator<< (ostream& out,const Diem& b);

        friend double DoDaiCanh (Diem a,Diem b);                // Viet them ham de tinh do dai khi biet toa do 2 dinh

        friend Diem operator+ (Diem a,Diem b);                  // Dinh nghia them toan tu + hai diem
        friend Diem operator- (Diem a,Diem b);                  // Dinh nghia them toan tu - hai diem
        friend Diem operator* (Diem a,Diem b);                  // Dinh nghia them toan tu * hai diem
        friend Diem operator/ (Diem a,double b);                // Dinh nghia them toan tu / 1 diem voi 1 so thuc

        void QuayDiem(Diem X,double gocquay);                   // Viet them ham de quay 1 diem quanh 1 diem co dinh
};