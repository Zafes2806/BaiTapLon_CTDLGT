#include <bits/stdc++.h>

using namespace std;

#ifndef HUFFMANNODE_CPP
#define HUFFMANNODE_CPP

class HuffmanNode {
private:
    char data;
    int frequency;
    HuffmanNode *left;
    HuffmanNode *right;

public:
    HuffmanNode(char data = 0, int frequency = 0) {
        this->data = data;
        this->frequency = frequency;
        left = NULL;
        right = NULL;
    }

    char getData() { return data; }
    int getFrequency() { return frequency; }
    HuffmanNode *getLeft() { return left; }
    HuffmanNode *getRight() { return right; }

    void setData(char data_) { data = data_; }
    void setFrequency(int frequency_) { frequency = frequency_; }
    void setLeft(HuffmanNode *left_) { left = left_; }
    void setRight(HuffmanNode *right_) { right = right_; }

    bool operator>(const HuffmanNode &other) const {
        if (frequency == other.frequency)
            return data > other.data;
        return frequency > other.frequency;
    }
};

#endif