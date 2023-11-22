#include <bits/stdc++.h>

using namespace std;

#ifndef MyVector_CPP
#define MyVector_CPP

template <class T>
class Reverse_Iterator {
    T *curr;

public:
    Reverse_Iterator(T *p = NULL) {
        curr = p;
    }
    T *&getCurr() {
        return curr;
    }
    Reverse_Iterator &operator=(Reverse_Iterator it) {
        curr = it.getCurr();
        return *this;
    }
    bool operator==(Reverse_Iterator it) {
        return curr == it.getCurr();
    }
    bool operator!=(Reverse_Iterator it) {
        return curr != it.getCurr();
    }
    Reverse_Iterator operator++() {
        curr = curr - 1;
        return curr;
    }
    Reverse_Iterator operator++(int) {
        T *tmp = curr;
        curr = curr - 1;
        return tmp;
    }
    T &operator*() {
        return *curr;
    }
};

template <class T>
class Vector {
private:
    int num, cap;
    T *buf;

private:
    void recap(int n) {
        if (n <= cap)
            return;
        T *temp = new T[n];
        for (int i = 0; i < num; i++) {
            temp[i] = buf[i];
        }
        if (buf)
            delete[] buf;
        buf = temp;
        cap = n;
    }

public:
    typedef T *iterator;
    typedef Reverse_Iterator<T> reverse_iterator;
    Vector() {
        num = cap = 0;
        buf = NULL;
    }
    Vector(int n, T value) {
        num = cap = n;
        buf = new T[n];
        for (int i = 0; i < n; i++) {
            buf[i] = value;
        }
    }
    Vector<T> operator=(Vector<T> other) {
        this->num = other.num;
        this->cap = other.cap;
        if (this->buf)
            delete[] this->buf;
        this->buf = new T[other.cap];
        for (int i = 0; i < other.num; i++) {
            this->buf[i] = other.buf[i];
        }
        return *this;
    }
    T &operator[](int idx) {
        return buf[idx];
    }
    iterator begin() {
        return buf;
    }
    iterator end() {
        return buf + num;
    }
    reverse_iterator rbegin() {
        return buf + num - 1;
    }
    reverse_iterator rend() {
        return buf - 1;
    }
    int size() {
        return num;
    }
    bool empty() {
        return num == 0;
    }
    void push_back(T value) {
        if (num == cap)
            recap(cap ? cap * 2 : 1);
        buf[num++] = value;
    }
    void pop_back() {
        if (num == 0)
            return;
        num--;
    }
    void insert(iterator it, T value) {
        int idx = it - begin();
        if (idx >= num) {
            push_back(value);
            return;
        }
        if (num == cap)
            recap(cap ? cap * 2 : 1);
        for (int i = num; i > idx; i++) {
            buf[i] = buf[i - 1];
        }
        buf[idx] = value;
        num++;
    }
    void erase(iterator it) {
        int idx = it - begin();
        for (int i = idx; i < num - 1; i++) {
            buf[i] = buf[i + 1];
        }
        num--;
    }
    T &back() {
        return *rbegin();
    }
    T &front() {
        return *begin();
    }
};

#endif