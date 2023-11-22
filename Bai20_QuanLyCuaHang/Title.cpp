#include <bits/stdc++.h>

using namespace std;

#ifndef TITLE_CPP
#define TITLE_CPP

class Title {
public:
    static void itemAttributes() {
        cout << setw(15) << left << "Ma hang";
        cout << "\t";
        cout << setw(20) << left << "Ten hang";
        cout << "\t";
        cout << setw(20) << left << "Nha san xuat";
        cout << endl;
    }
    static void invoiceAttributes() {
        cout << setw(15) << left << "Ma hoa don";
        cout << "\t";
        cout << setw(15) << left << "Ma hang";
        cout << "\t";
        cout << setw(15) << left << "Loai hoa don";
        cout << "\t";
        cout << setw(10) << left << "So luong";
        cout << "\t";
        cout << setw(15) << left << "Ngay mua ban";
        cout << "\t ";
        cout << setw(15) << left << "Gia mua ban" << endl;
    }
};

#endif