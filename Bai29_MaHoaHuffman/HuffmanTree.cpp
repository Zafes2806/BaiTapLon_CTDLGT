#include "HuffmanNode.cpp"
#include <bits/stdc++.h>

using namespace std;

#ifndef HUFFMANTREE_CPP
#define HUFFMANTREE_CPP

class HuffmanTree {
private:
    HuffmanNode *root;
    map<char, string> huffmanCodes;

private:
    // Xây dựng cây Huffman sử dụng hàng đợi ưu tiên
    void buildHuffmanTree(string text) {
        unordered_map<char, int> charFrequency;

        // Đếm tần suất xuất hiện của từng ký tự trong chuỗi đầu vào
        for (char c : text) {
            charFrequency[c]++;
        }

        // Tạo hàng đợi ưu tiên để xây dựng cây Huffman
        priority_queue<HuffmanNode, vector<HuffmanNode>, greater<HuffmanNode>> pq;

        // Trường hợp đặc biệt chuỗi chỉ có 1 ký tự xuất hiện 1 hoặc nhiều lần
        if (charFrequency.size() == 1) {
            pq.push(HuffmanNode(text[0], charFrequency[text[0]]));
        }

        // Thêm các ký tự vào hàng đợi ưu tiên dưới dạng các nút lá
        for (auto c : charFrequency) {
            pq.push(HuffmanNode(c.first, c.second));
        }

        // Xây dựng cây Huffman bằng cách kết hợp các nút có tần suất nhỏ nhất
        while (pq.size() > 1) {
            HuffmanNode *left = new HuffmanNode(pq.top());
            pq.pop();
            HuffmanNode *right = new HuffmanNode(pq.top());
            pq.pop();

            int combinedFrequency = left->getFrequency() + right->getFrequency();
            HuffmanNode *parent = new HuffmanNode('\0', combinedFrequency);
            parent->setLeft(left);
            parent->setRight(right);

            pq.push(*parent);
        }

        // Gán nút gốc của cây Huffman
        root = new HuffmanNode(pq.top());
    }

    // Phương thức xây dựng các từ mã cho các ký tự
    void buildHuffmanCodes(HuffmanNode *node, string code) {

        if (node == NULL) {
            return;
        }

        // Nếu nút là nút lá, gán từ mã cho ký tự tương ứng
        if (node->getData() != '\0') {
            huffmanCodes[node->getData()] = code;
        }

        // Gọi đệ quy cho cả hai nhánh của cây
        buildHuffmanCodes(node->getLeft(), code + '0');
        buildHuffmanCodes(node->getRight(), code + '1');
    }

    // Xóa các nút bên dưới bao gồm cả node
    void remove(HuffmanNode *node) {
        if (node == NULL)
            return;
        remove(node->getLeft());
        remove(node->getRight());
        delete node;
    }

public:
    HuffmanTree(string text) {
        buildHuffmanTree(text);
        buildHuffmanCodes(root, "");
    }
    ~HuffmanTree() { remove(root); }

    // Bảng mã Huffman cho các ký tự
    map<char, string> getHuffmanCodes() { return huffmanCodes; }

    // Mã hóa chuỗi ký tự dựa trên cây Huffman
    string encode(string text) {
        string encodedText = "";
        for (char c : text) {
            // Tìm từ mã cho ký tự c trong bảng mã Huffman
            string code = huffmanCodes[c];
            encodedText += code;
        }

        return encodedText;
    }

    // Giải mã ngược dựa trên cây Huffman
    string decode(string encodedText) {
        string decodedText = "";
        HuffmanNode *currentNode = root;

        for (char bit : encodedText) {
            if (bit == '0') {
                currentNode = currentNode->getLeft();
            } else if (bit == '1') {
                currentNode = currentNode->getRight();
            }

            if (currentNode->getLeft() == NULL && currentNode->getRight() == NULL) {
                // Nếu đạt đến nút lá, thì đã tìm thấy ký tự và thêm vào chuỗi giải mã
                decodedText += currentNode->getData();
                currentNode = root; // Đặt lại nút hiện tại về gốc để tiếp tục tìm kiếm
            }
        }

        return decodedText;
    }
};

#endif