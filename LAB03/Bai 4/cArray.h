#include <iostream>
#include <vector>

using namespace std;

class cArray {
    private:
        vector<int> a;
    public:
        void Nhap(int n);
        void Xuat();

        void TaoMangNgauNhien(int n);

        int SoLanXuatHienCua(int x);
        void TimSNTLonNhat();
        void KiemTraTangDan();
        void PhanTuLeNhoNhat();
        void SapXepTangDan();
};