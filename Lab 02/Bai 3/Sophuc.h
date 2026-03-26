class SoPhuc {
    private:
        int iThuc,iAo;
    public:
        void Nhap(),Xuat();
        SoPhuc Tong(SoPhuc a,SoPhuc b),
                Hieu(SoPhuc a,SoPhuc b),
                Tich(SoPhuc a,SoPhuc b),
                Thuong(SoPhuc a,SoPhuc b);
};