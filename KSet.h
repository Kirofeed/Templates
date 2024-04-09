#ifndef KSET_H
#define KSET_H

#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

template <typename T>
class Iter; // Forward declaration of Iter

template <typename T>
class KSet {
    
    friend class Iter<T>; // Use Iter<T> instead of Iter
private:
    T *arr = new T[10]; // Use T instead of int
    int sz;
public:
    KSet() {
        sz = -1;
    }
    
    int size() const {
        return this->sz + 1;
    
    }
    
    void processKSet() {
        std::sort(arr, arr + size());
        auto end = std::unique(arr, arr + size());
        sz = std::distance(arr, end) - 1;
    }

    
    void push(T a) {
        arr[++sz] = a;
        processKSet();
    }

    
    Iter<T>* CreateIter() const {
        return new Iter<T>(this);
    }

   
    KSet<T> &operator=(const KSet<T> &other) {
        this->sz = other.sz;
        for(int i = 0; i != other.size(); ++i) {
            this->arr[i] = other.arr[i];
        }
        return *this;
    }

    
    KSet<T>& operator|(const KSet<T>& other) {
        KSet* NewKSet = new KSet();
        for(int i = 0; i != this->size(); ++i) {
            NewKSet->push(arr[i]);
        }
        for(int i = 0; i != other.size(); ++i) {
            NewKSet->push(other.arr[i]);
        } 
        NewKSet->processKSet();
        return *NewKSet;
    }

    
    KSet<T> &operator|=(const KSet<T> &other) {
        for(int i = 0; i != other.size(); ++i) {
            this->push(other.arr[i]);
        }
        processKSet();
        return *this;
    }

    
    KSet<T>& operator&(const KSet<T>& other) {
        KSet* NewKSet = new KSet();
        int this_size = this->size(),  other_size = other.size();
        for(int i = 0; i != this_size; ++i) {
            for(int j = 0; j != other_size; ++j) {
                if(this->arr[i] == other.arr[j]) {
                    NewKSet->push(this->arr[i]);
                }
            }
        }
        NewKSet->processKSet();
        return *NewKSet;
    }

    
    KSet<T>& operator&=(const KSet<T>& other) {
        vector<T> temp;
        for(int i = 0; i != this->size(); ++i) {
            for(int j = 0; j != other.size(); ++j) {
                if(this->arr[i] == other.arr[j]) {
                    temp.push_back(this->arr[i]);
                }
            }
        }
        this->sz = temp.size() - 1;
        for (int i = 0; i != this->size(); ++i) {
            this->arr[i] = temp[i];
        }
        
        this->processKSet();
        return *this;
    }

    
    KSet<T>& operator/(const KSet<T>& other) {
        KSet* NewKSet = new KSet();
        for(int i = 0; i != this->size(); ++i) {
            bool flag = false;
            for(int j = 0; j != other.size(); ++j) {
                if(this->arr[i] == other.arr[j]) {
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                NewKSet->push(this->arr[i]);
            }
        }
        NewKSet->processKSet();
        return *NewKSet;
    }

    
    KSet<T>& operator/=(const KSet<T>& other) {
        vector<T> temp;
        for(int i = 0; i != this->size(); ++i) {
            bool flag = false;
            for(int j = 0; j != other.size(); ++j) {
                if(this->arr[i] == other.arr[j]) {
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                temp.push_back(this->arr[i]);
            }
        }
        this->sz = temp.size() - 1;
        for(int i = 0; i != this->size(); ++i) {
            this->arr[i] = temp[i];
        }
        this->processKSet();
        return *this;
    }

    

    
    void clear() {
        delete arr;
        this->sz = 0;
    }

    
    bool IsEmpty() {
        return this->sz == 0;
    }

    
    bool IsFull() {
        return this->sz == 10;
    }
    

    int GetSZ() const {
        return this->sz;
    }
    T* GetArr() const {
        return this->arr;
    }
};

    
    
    

#endif // KSET_H