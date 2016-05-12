#include "container.h"

template <class T>

Container<T>::SmartPointer& Container::SmartPointer::operator=(const SmartPointer& sp) {
    if (this == &sp) return *this;
    Nodo* t = punt;
    punt = sp.punt;
    /*if (t) {
        (t->riferimenti)--;
        if((t->riferimenti)==0) delete t;
    }*/
    return *this;
}

/*container& container::operator=(const container& cont)
{
    if(&cont==this) return *this;
    first=cont.first;
    return *this;
}
*/
