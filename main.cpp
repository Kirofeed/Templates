#include <iostream>
#include <vector>
#include "KSet.h"
#include "iter.h"
using namespace std;

template <typename T>
int count(KSet<T> &kset, T value) {
    Iter<T> *iter = kset.CreateIter();
    T* last = iter->last();
    iter->first();
    while (iter->CurrentItem() != last)
    {
        if (*iter->CurrentItem() == value) {
            return 1;
        }
        iter->next();
    }
    if (*iter->last() != value)
    {
        return 0;
    }
    else {
        return 1;
    }
}


int main(){
    KSet<int> k1;
    KSet<int> k2;
    k1.push(3);
    k1.push(2);
    k1.push(4);
    k1.push(3);
    k1.push(5);
    k1.push(7);
    k1.push(3);
    k2.push(2);
    k2.push(3);
    k2.push(4);
    k2.push(1);
    k2.push(7);
    k2.push(4);
    k2.push(1);
    cout << count<int>(k1, 1) << endl;
    cout << count<int>(k2, 1) << endl;
    KSet<int> k3;
    cout << "k1: " << k1 << endl << "k2: " << k2 << endl;
    k3 = k1 | k2;
    cout << "k1 | k2: " << k3 << endl;
    k3 = k1 / k2;
    cout << "k1 / k2: " << k3 << endl;

    KSet<string> k4;
    k4.push("hello");
    k4.push("world");

    cout << k4 << endl;
    
}
