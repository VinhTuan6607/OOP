#include <iostream>
#include <vector>
#include "cNhanVienSX.cpp"

using namespace std;

class cDSNhanVien {
    private:
        vector<cNhanVienSX> arr;
        int n;
    public:
        friend istream& operator>> (istream& in,cDSNhanVien& DS);
        friend ostream& operator<< (ostream& out,const cDSNhanVien& DS);

        cNhanVienSX NVLuongThapNhat();
        cNhanVienSX NVLonTuoiNhat();

        long long TongLuongNV();
        
        void SapXepLuongTangDan();
};