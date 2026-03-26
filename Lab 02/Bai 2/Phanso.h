class PhanSo {
    private:
        int iTu,iMau;
    public:
        void Nhap(),Xuat(),RutGon(),SoSanh(PhanSo a,PhanSo b);
        PhanSo Tong(PhanSo a,PhanSo b),
                Hieu(PhanSo a,PhanSo b),
                Tich(PhanSo a,PhanSo b),
                Thuong(PhanSo a,PhanSo b);
};