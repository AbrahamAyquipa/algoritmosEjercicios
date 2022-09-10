#pragma once

class ArrNumeros {
private:
    int* arreglo;
    int sz;

public:
    ArrNumeros() {
        this->arreglo = nullptr;
        this->sz = 0;
    }

    ~ArrNumeros() {
        delete[] this->arreglo;
    }

    void push_back(int valor) {
        int* temp = new int[this->sz + 1];
        for (int i = 0; i < this->sz; ++i) {
            temp[i] = this->arreglo[i];
        }
        temp[this->sz] = valor;
        delete[] this->arreglo;
        this->arreglo = temp;
        ++this->sz;
    }

    void push_front(int valor) {
        int* temp = new int[this->sz + 1];
        temp[0] = valor;
        for (int i = 0; i < this->sz; ++i) {
            temp[i + 1] = this->arreglo[i];
        }
        delete[] this->arreglo;
        this->arreglo = temp;
        ++this->sz;
    }

    void insert(int pos, int valor) {
        if (pos < 0 || pos >= this->sz) return;
        int* temp = new int[this->sz + 1];
        int j = 0;
        for (int i = 0; i < this->sz + 1; ++i) {
            temp[i] = (i == pos ? valor : this->arreglo[j++]);
        }
        delete[] this->arreglo;
        this->arreglo = temp;
        ++this->sz;
    }

    void pop_back() {
        if (this->sz == 0) return;
        if (this->sz == 1) {
            --this->sz;
            delete[] this->arreglo;
            this->arreglo = nullptr;
            return;
        }
        int* temp = new int[this->sz - 1];
        for (int i = 0; i < this->sz - 1; ++i) {
            temp[i] = this->arreglo[i];
        }
        delete[] this->arreglo;
        this->arreglo = temp;
        --this->sz;
    }

    void pop_front() {
        if (this->sz == 0) return;
        if (this->sz == 1) {
            --this->sz;
            delete[] this->arreglo;
            this->arreglo = nullptr;
            return;
        }
        int* temp = new int[this->sz - 1];
        for (int i = 1; i < this->sz; ++i) {
            temp[i - 1] = this->arreglo[i];
        }
        delete[] this->arreglo;
        this->arreglo = temp;
        --this->sz;
    }

    void erase(int pos) {
        if (pos < 0 || pos >= this->sz) return;
        int* temp = new int[this->sz - 1];
        int j = 0;
        for (int i = 0; i < this->sz; ++i) {
            if (i == pos) continue;
            temp[j++] = this->arreglo[i];
        }
        delete[] this->arreglo;
        this->arreglo = temp;
        --this->sz;
    }

    int& at(int pos) {
        if (pos < 0 || pos >= this->sz) throw "Error: Index out of range";
        return this->arreglo[pos];
    }

    int size() {
        return this->sz;
    }
};
