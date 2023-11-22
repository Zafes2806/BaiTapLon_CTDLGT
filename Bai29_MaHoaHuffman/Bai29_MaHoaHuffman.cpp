#include "HuffmanTree.cpp"
#include <bits/stdc++.h>

using namespace std;

int main() {
    string text;
    cout << "Nhap vao chuoi can nen: ";
    getline(cin, text);
    if (text == "")
        return 0;
    HuffmanTree huffmanTree = HuffmanTree(text);

    string code = huffmanTree.encode(text);
    cout << "Ma Huffman cua chuoi da nhap la: ";
    cout << code << endl;

    cout << "\nBang ma Huffman sau khi ma hoa la:" << endl;
    map<char, string> huffmanCodes = huffmanTree.getHuffmanCodes();
    for (auto x : huffmanCodes) {
        cout << x.first << " : " << x.second << endl;
    }

    cout << "\nChuoi ban dau sau khi duoc ma hoa nguoc la: ";
    cout << huffmanTree.decode(code) << endl;
}