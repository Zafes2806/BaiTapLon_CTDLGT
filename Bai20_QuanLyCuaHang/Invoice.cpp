#include <bits/stdc++.h>

using namespace std;

#ifndef INVOICE_CPP
#define INVOICE_CPP

class Invoice {
private:
    string invoiceCode;
    string itemCode;
    string invoiceType;
    int quantity;
    string purchaseDate;
    int purchasePrice;

public:
    Invoice(string invoiceCode_ = "", string itemCode_ = "",
            string invoiceType_ = "", int quantity_ = 0,
            string purchaseDate_ = "01/01/1900", int purchasePrice_ = 0.0) {
        invoiceCode = invoiceCode_;
        itemCode = itemCode_;
        invoiceType = invoiceType_;
        quantity = quantity_;
        purchaseDate = purchaseDate_;
        purchasePrice = purchasePrice_;
    }

    friend ostream &operator<<(ostream &out, Invoice invoice) {
        out << setw(15) << invoice.invoiceCode << "\t";
        out << setw(15) << invoice.itemCode << "\t";
        out << setw(15) << invoice.invoiceType << "\t";
        out << setw(10) << invoice.quantity << "\t";
        out << setw(15) << invoice.purchaseDate << "\t";
        out << setw(15) << fixed << setprecision(2) << invoice.purchasePrice;
        return out;
    }

    string getInvoiceCode() { return invoiceCode; }
    string getItemCode() { return itemCode; }
    string getInvoiceType() { return invoiceType; }
    int getQuantity() { return quantity; }
    string getPurchaseDate() { return purchaseDate; }
    float getPurchasePrice() { return purchasePrice; }

    void setInvoiceCode(string invoiceCode_) { invoiceCode = invoiceCode_; }
    void setItemCode(string itemCode_) { itemCode = itemCode_; }
    void setInvoiceType(string invoiceType_) {
        if (invoiceType_ == "ban" || invoiceType_ == "mua")
            invoiceType = invoiceType_;
    }
    void setQuantity(int quantity_) {
        if (quantity_ >= 0)
            quantity = quantity_;
    }
    void setPurchaseDate(string purchaseDate_) { purchaseDate = purchaseDate_; }
    void setPurchasePrice(int purchasePrice_) { purchasePrice = purchasePrice_; }
};

#endif