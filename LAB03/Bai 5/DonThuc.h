#include <iostream>

using namespace std;

class DonThuc {
    private:
        int heso;
        int luythua;
    public:
        friend istream& operator>> (istream& in,DonThuc& a);
        friend DonThuc TongDonThuc(DonThuc a,DonThuc b);
        friend DonThuc HieuDonThuc(DonThuc a,DonThuc b);

        int HeSo() const {return heso;}

        void UpdateHeSo(int n) {luythua = n;}
        int GiaTriDonThuc(int x);
        void SoAm() {heso = -heso;}
        friend ostream& operator<< (ostream& out,const DonThuc& a);
};