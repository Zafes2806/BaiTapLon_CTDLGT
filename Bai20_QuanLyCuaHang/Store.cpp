#include "Invoice.cpp"
#include "Item.cpp"
#include "MyVector.cpp"
#include "Title.cpp"
#include <bits/stdc++.h>

using namespace std;

#ifndef STORE_CPP
#define STORE_CPP

class Store {
private:
    Vector<Item> items;
    Vector<Invoice> invoices;

private:
    // Nhập danh sách mặt hàng từ file
    void loadItems(ifstream &inputFile) {
        int itemsCount; // Số lượng mặt hàng
        inputFile >> itemsCount;
        inputFile.ignore();

        string line;
        for (int i = 0; i < itemsCount; i++) {
            getline(inputFile, line);

            // Tách dòng vừa lấy vào thành mã hàng, tên hàng, nhà sản xuất
            stringstream ss(line);
            string productAttributes[3];
            int j = 0;
            while (getline(ss, productAttributes[j], ',')) {
                j++;
            }

            // Thêm mặt hàng vào danh sách mặt hàng
            items.push_back(Item(productAttributes[0], productAttributes[1],
                                 productAttributes[2]));
        }
    }

    // Nhập danh sách hóa đơn từ file
    void loadInvoices(ifstream &inputFile) {
        int invoicesCount; // Số lượng hóa đơn
        inputFile >> invoicesCount;
        inputFile.ignore();

        string line;
        for (int i = 0; i < invoicesCount; i++) {
            getline(inputFile, line);

            /* Tách dòng vừa lấy từ file thành mã hóa đơn, mã hàng, loại đơn hàng, số
            lượng, ngày mua bán, giá mua bán */
            stringstream ss(line);
            string invoiceAitributes[6];
            int j = 0;
            while (getline(ss, invoiceAitributes[j], ',')) {
                j++;
            }

            // Chuyển số lượng từ string sang int
            int quantity = 0;
            for (auto x : invoiceAitributes[3]) {
                quantity = quantity * 10 + x - '0';
            }

            // Chuyển giá mua bán từ string sang int
            int purchasePrice = 0;
            for (auto x : invoiceAitributes[5]) {
                purchasePrice = purchasePrice * 10 + x - '0';
            }

            // Thêm hóa đơn vào danh sách hóa đơn
            invoices.push_back(Invoice(invoiceAitributes[0], invoiceAitributes[1],
                                       invoiceAitributes[2], quantity,
                                       invoiceAitributes[4], purchasePrice));
        }
    }

    // Lưu danh sách mặt hàng vào file
    void saveItems(ofstream &outputFile) {
        outputFile << items.size() << endl;
        for (int i = 0; i < items.size(); i++) {
            outputFile << items[i].getItemCode() << ",";
            outputFile << items[i].getItemName() << ",";
            outputFile << items[i].getManufacturer() << endl;
        }
    }

    // Lưu danh sách hóa đơn vào file
    void saveInvoices(ofstream &outputFile) {
        outputFile << invoices.size() << endl;
        for (auto &invoice : invoices) {
            outputFile << invoice.getInvoiceCode() << ",";
            outputFile << invoice.getItemCode() << ",";
            outputFile << invoice.getInvoiceType() << ",";
            outputFile << invoice.getQuantity() << ",";
            outputFile << invoice.getPurchaseDate() << ",";
            outputFile << invoice.getPurchasePrice() << endl;
        }
    }

public:
    Store() {
        items = Vector<Item>();
        invoices = Vector<Invoice>();
    }

    // Phương thức đọc thông tin quản lý của hàng từ file
    void loadDataFromFile(string fileName) {
        ifstream inputFile(fileName);
        loadItems(inputFile);
        loadInvoices(inputFile);
    }

    // Phương thức lưu thông tin quản lý cửa hàng vào file
    void saveDataToFile(string fileName) {
        ofstream outputFile(fileName);
        saveItems(outputFile);
        saveInvoices(outputFile);
    }

    // Phương thức thêm một mặt hàng
    void addNewItem(Item item) {
        items.push_back(item);
    }

    // Phương thức thêm 1 hóa đơn mới
    void addNewInvoice(Invoice invoice) {
        invoices.push_back(invoice);
    }
    // Phương thức trả về danh sách mặt hàng của cửa hàng
    Vector<Item> getItems() { return items; }

    // Phương thức trả về danh sách hóa đơn của cửa hàng
    Vector<Invoice> getInvoices() { return invoices; }
};

#endif