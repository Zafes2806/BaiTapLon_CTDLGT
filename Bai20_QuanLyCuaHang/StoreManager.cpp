#include "Store.cpp"
#include <bits/stdc++.h>

using namespace std;

#ifndef STOREMANAGER_CPP
#define STOREMANAGER_CPP

class StoreManager {
private:
    Store store;
    map<string, int> quantityOfEachItem;

public:
    StoreManager() {
        store = Store();
        quantityOfEachItem = map<string, int>();
    }

    // Phương thức nhập thông tin cửa hàng từ file
    void loadDataFromFile() {
        string fileName;
        cout << "\nNhap vao ten file chua du lieu cua cua hang: ";
        getline(cin, fileName);
        ifstream inputFile(fileName);

        if (!inputFile) {
            cout << "Khong tim thay file!\n";
            return;
        }

        // Làm mới lại cửa hàng
        store = Store();
        quantityOfEachItem = map<string, int>();

        // Lấy ds mặt hàng và hóa đơn từ file
        store.loadDataFromFile(fileName);

        // Thống kê số lượng sản phẩm của mỗi mặt hàng
        Vector<Invoice> invoices = store.getInvoices();
        for (Invoice invoice : invoices) {
            if (invoice.getInvoiceType() == "mua") {
                quantityOfEachItem[invoice.getItemCode()] += invoice.getQuantity();
            } else {
                quantityOfEachItem[invoice.getItemCode()] -= invoice.getQuantity();
            }
        }
        cout << "Lay du lieu cua hang tu file thanh cong!\n";
    }

    // Phương thức lưu thông tin của cửa hàng ra file
    void saveDataToFile() {
        string fileName;
        cout << "\nNhap vao ten file muon luu du lieu cua cua hang: ";
        getline(cin, fileName);
        store.saveDataToFile(fileName);
        cout << "Luu du lieu cua hang vao file thanh cong!\n";
    }

    // Phương thức nhập các mặt hàng
    void importItems() {
        int k;
        cout << "\nNhap vao so loai mat hang muon nhap them: ";
        cin >> k;
        cin.ignore();
        Item item;
        int quantity;
        int purchasePrice;

        for (int i = 1; i <= k; i++) {
            cout << "\nNhap vao thong tin mat hang thu " << i << " muon them:\n";
            cin >> item;
            cout << "So luong san pham nhap vao: ";
            cin >> quantity;
            cout << "Gia mua: ";
            cin >> purchasePrice;
            cin.ignore();

            // Ngày tháng năm nhập sản phẩm
            time_t now = time(NULL);
            tm *ltm = localtime(&now);
            string date = to_string(ltm->tm_mday);
            date += "/" + to_string(ltm->tm_mon + 1);
            date += "/" + to_string(ltm->tm_year + 1900);

            string invoiceCode = "HD" + to_string(store.getInvoices().size() + 1);

            // Thêm hóa đơn mới
            Invoice invoice(invoiceCode, item.getItemCode(), "mua", quantity, date, purchasePrice);
            store.addNewInvoice(invoice);

            if (quantityOfEachItem.find(item.getItemCode()) == quantityOfEachItem.end()) {
                store.addNewItem(item);
            }
            quantityOfEachItem[item.getItemCode()] += quantity;
        }
        cout << "Da nhap xong cac mat hang\n";
    }

    // Phương thức xuất các mặt hàng
    void exportItems() {
        int k;
        cout << "\nNhap vao so loai mat hang muon xuat: ";
        cin >> k;
        cin.ignore();

        for (int i = 1; i <= k; i++) {
            string itemCode;

            cout << "\nNhap vao ma mat hang thu " << i << " muon xuat: ";
            getline(cin, itemCode);
            if (quantityOfEachItem.find(itemCode) == quantityOfEachItem.end()) {
                cout << "Ma san pham " << itemCode << " khong phu hop!\n";
                continue; // Mã sản phẩm không phù hợp
            }

            int quantity;
            int purchasePrice;
            cout << "So luong san pham xuat ra: ";
            cin >> quantity;
            cout << "Gia ban: ";
            cin >> purchasePrice;
            cin.ignore();

            if (quantityOfEachItem[itemCode] < quantity) {
                cout << "So luong san pham mat hang co ma " << itemCode << " con lai khong du!\n";
                continue; // Không đủ sản phẩm
            }

            // Ngày tháng năm nhập sản phẩm
            time_t now = time(NULL);
            tm *ltm = localtime(&now);
            string date = to_string(ltm->tm_mday);
            date += "/" + to_string(ltm->tm_mon + 1);
            date += "/" + to_string(ltm->tm_year + 1900);

            string invoiceCode = "HD" + to_string(store.getInvoices().size() + 1);

            // Thêm hóa đơn mới
            Invoice invoice(invoiceCode, itemCode, "ban", quantity, date, purchasePrice);
            store.addNewInvoice(invoice);
            quantityOfEachItem[itemCode] -= quantity;
        }
        cout << "Da xuat xong cac mat hang!\n";
    }

    // Phương thức hiển thị toàn bộ danh sách mặt hàng hiện có.
    void availableItems() {
        Vector<Item> items = store.getItems();
        cout << "\nToan bo mat hang hien con san pham la: " << endl;
        Title::itemAttributes();
        for (Item item : items) {
            if (quantityOfEachItem[item.getItemCode()] > 0)
                cout << item << endl;
        }
    }

    void inventoryStatistics() {
        cout << "\nThong ke so luong san pham ton cua moi mat hang:" << endl;
        cout << setw(15) << left << "Ma hang";
        cout << "\t";
        cout << setw(10) << left << "So luong" << endl;
        for (auto &x : quantityOfEachItem) {
            if (x.second < 0) continue;
            cout << setw(15) << left << x.first << "\t";
            cout << setw(10) << left << x.second << endl;
        }
    }
};

#endif