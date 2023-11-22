#include <bits/stdc++.h>

using namespace std;

#ifndef ITEM_CPP
#define ITEM_CPP

class Item {
private:
    string itemCode;
    string itemName;
    string manufacturer;

public:
    Item(string itemCode_ = "", string itemName_ = "", string manufacturer_ = "") {
        itemCode = itemCode_;
        itemName = itemName_;
        manufacturer = manufacturer_;
    }

    friend istream &operator>>(istream &in, Item &item) {
        cout << "Ma hang: ";
        getline(in, item.itemCode);
        cout << "Ten hang: ";
        getline(in, item.itemName);
        cout << "Nha san xuat: ";
        getline(in, item.manufacturer);
        return in;
    }

    friend ostream &operator<<(ostream &out, Item item) {
        out << setw(15) << left << item.itemCode << "\t";
        out << setw(20) << left << item.itemName << "\t";
        out << setw(20) << left << item.manufacturer;
        return out;
    }

    string getItemCode() { return itemCode; }
    string getItemName() { return itemName; }
    string getManufacturer() { return manufacturer; }

    void setItemCode(string itemCode_) { itemCode = itemCode_; }
    void setItemName(string itemName_) { itemName = itemName_; }
    void setManufacturer(string manufacturer_) { manufacturer = manufacturer_; }
};

#endif