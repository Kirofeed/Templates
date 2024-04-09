#ifndef ITER_H
#define ITER_H


#include "KSet.h"


template <typename T>
class Iter {
    int index;
    T* value = 0;
    const KSet<T>* kset;
public:
    Iter(const KSet<T>* kset) {
        this->kset = kset;
    };
    T* first() {
        this->value = &kset->arr[0];
        index = 0;
        return this->value;
    }

    T* last() {
        if (this->kset->sz == -1) {
            return first();
        }
        this->value = &this->kset->arr[this->kset->sz];
        return this->value;
    }
    T* next() {
        this->index++;
        this->value = &this->kset->arr[this->index];
        return this->value;
    }
    T* CurrentItem() {
        return this->value;
    }
};

#endif