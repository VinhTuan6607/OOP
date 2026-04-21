#include <iostream>

using namespace std;

class Date {
    private:
        int Ngay;
        int Thang;
        int Nam;
    public:
        Date(int dd = 0,int mm = 0,int yyyy = 0);                   // Phuong thuc thiet lap mac dinh

        int getNgay() {return Ngay;}
        int getThang() {return Thang;}
        int getNam() {return Nam;}
        
        friend istream& operator>> (istream& in,Date& day);
        friend ostream& operator<< (ostream& out,const Date& day);
};