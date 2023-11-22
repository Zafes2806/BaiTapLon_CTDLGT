#include "StoreManager.cpp"
#include <bits/stdc++.h>

using namespace std;

int main() {
    StoreManager storeManager;
    int choice;
    while (1) {
        cout << "\n--------------------MENU----------------------" << endl;
        cout << "1.Doc thong tin quan ly tu file vao chuong trinh" << endl;
        cout << "2.Ghi thong tin quan ly cua cua hang vao file" << endl;
        cout << "3.Nhap them cac mat hang" << endl;
        cout << "4.Xuat ra cac mat hang" << endl;
        cout << "5.Hien thi toan bo danh sach mat hang hien co" << endl;
        cout << "6.Thong ke so luong san pham ton cua moi mat hang" << endl;
        cout << "0.Thoat" << endl;
        cout << "Nhap vao thao tac muon thuc hien: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            storeManager.loadDataFromFile();
            break;

        case 2:
            storeManager.saveDataToFile();
            break;

        case 3:
            storeManager.importItems();
            break;

        case 4:
            storeManager.exportItems();
            break;

        case 5:
            storeManager.availableItems();
            break;

        case 6:
            storeManager.inventoryStatistics();
            break;

        case 0:
            return 0;

        default:
            cout << "\nThao tac khong hop le!" << endl;
        }
    };
}