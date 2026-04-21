#include <iostream>
#include "Date.cpp"

using namespace std;

class cNhanVienSX {
    private:
        string MaNV;
        string HoTen;
        Date NgayThangNamSinh;
        int SoSPGiaCong;
        long long DonGiaSP;
        long long Luong;
    public:
        cNhanVienSX();

        friend bool cmp (cNhanVienSX a,cNhanVienSX b);                      // Viet them ham so sanh de su dung ham sort

        string getMaNV() {return MaNV;}
        string getHoTen() {return HoTen;}
        Date getNgayThangNamSinh() {return NgayThangNamSinh;}
        int getSoSPGiaCong() {return SoSPGiaCong;}
        long long getDonGiaSP() {return DonGiaSP;}
        long long getLuong() {return Luong;}

        void setMaNV(string id) {MaNV = id;}
        void setHoTen(string name) {HoTen = name;}
        void setNgayThangNamSinh(Date birthday) {NgayThangNamSinh = birthday;}
        void setSoSPGiaCong(int product) {SoSPGiaCong = product;}
        void setDonGiaSP(long long cost) {DonGiaSP = cost;}

        friend istream& operator>> (istream& in,cNhanVienSX& NV);
        friend ostream& operator<< (ostream& out,const cNhanVienSX& NV);

        void TinhLuong();
};