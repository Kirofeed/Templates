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
    T* Iter<T>::first() {
        this->value = &kset->arr[0];
        index = 0;
        return this->value;
    }

    T* Iter<T>::last() {
        if (this->kset->sz == -1) {
            return first();
        }
        this->value = &this->kset->arr[this->kset->sz];
        return this->value;
    }
    T* Iter<T>::next() {
        this->index++;
        this->value = &this->kset->arr[this->index];
        return this->value;
    }
    T* Iter<T>::CurrentItem() {
        return this->value;
    }
};