#include "KSet.h"
#include "iter.h"
#include <iostream>
#include <sstream>

using namespace std;
template <typename T>
ostream& operator<< (ostream& os, const KSet<T>& kset) {
        for(int i = 0; i != kset.GetSZ() + 1; ++i) {
            os << kset.GetArr()[i] << "\t";
        }
        return os;
    }