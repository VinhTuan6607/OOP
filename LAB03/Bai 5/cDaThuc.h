#include <iostream>
#include <vector>
#include "DonThuc.cpp"

using namespace std;

class cDaThuc {
    private:
        vector<DonThuc> arr;
        int n;
    public:
        cDaThuc(int N = 0);
        int BacDaThuc() {return n;}

        friend istream& operator>> (istream& in,cDaThuc& a);
        friend ostream& operator<< (ostream& out,const cDaThuc& a);

        int GiaTriDaThuc(int x);

        friend cDaThuc operator+(cDaThuc a, cDaThuc b);
        friend cDaThuc operator-(cDaThuc a, cDaThuc b);
};