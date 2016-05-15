#include "container.h"


// Metodi di SmartPointer

template <class T>
Container<T>::SmartPointer::SmartPointer(Nodo* p): pointer(p) {    //costruttore 0~1 parametro + convertitore implicito nodo*->smartp
    if (pointer) pointer->counter++;

}

template <class T>
Container<T>::SmartPointer::~SmartPointer () {   // Distruttore
    if (pointer) {
        (pointer->counter)--;
        if (pointer->counter == 0) delete pointer;
    }
}

template <class T>
Container<T>::SmartPointer::SmartPointer (const SmartPointer& sp): pointer(sp.pointer) {   //costruttore di copia
    if (pointer) pointer->counter++;
}

/*Container::SmartPointer& Container::SmartPointer::operator= (const SmartPointer& var) {    //operatore di assegnazione
    if (&var == this) return *this;
    Nodo* n = pointer;
    pointer = var.pointer;
    if (pointer) (pointer->counter)++;
    if (n) {
        (n->counter)--;
        if ((n->counter) == 0) delete n;
    }
    return *this;
}*/

template <class T>
bool Container<T>::SmartPointer::operator== (const SmartPointer& i)const {     // Operatore di uguaglianza
    return pointer == i.pointer;
}

template <class T>
bool Container<T>::SmartPointer::operator!= (const SmartPointer& i)const {		// Operatore di disuguaglianza
    return pointer != i.pointer;
}

//Container::Nodo* Container::SmartPointer::operator-> () const {return pointer;} // Operatore di accesso a membro

//Container::Nodo& Container::SmartPointer::operator* () const {return *pointer;}


// Metodi di Nodo

template <class T>
Container<T>::Nodo::Nodo (T* t, const SmartPointer& n): info(t), next(n), counter(0) {}

//static Nodo* copia (Nodo*);
//static void distruggi (Nodo*);


// Metodi di Iteratore

template <class T>
bool Container<T>::Iteratore::operator== (const Iteratore& i) const {
    return punt == i.punt;
}

template <class T>
bool Container<T>::Iteratore::operator!= (const Iteratore& i) const {
    return punt != i.punt;
}

/*Container::Iteratore& Container::Iteratore::operator++ () {
    if (punt != 0) punt = punt->next;
    return *this;
}*/

/*Container::Iteratore& Container::Iteratore::operator++ (int) {
    Iteratore aux = *this;
    if (punt != 0) punt = punt->next;
    return aux;
}*/

template <class T>
T* Container<T>::Iteratore::operator* () const {     // Operatore di accesso a membro
    return punt->info;
}


// Metodi di Container

template <class T>
Container<T>::Container(): first(0) {}

template <class T>
Container<T>::Container (const Container& cont): first(cont.first){}

/*Container::Container& Container::operator= (const Container& var) {   // Assegnazione con SmartPointer
    if (&var == this) return *this;
    first = var.first;
    return *this;
}

void Container::push_back (T* nuovo) {
    first = new Nodo (nuovo, first);
}

Container::Iteratore Container::begin () const {
    Iteratore aux;
    aux.punt = first;
    return aux;
}

Container::Iteratore Container::end () const {
    Iteratore aux;
    aux.punt = 0;
    return aux;
}


T* Container::operator[] (const Iteratore& it) const {
    return (it.punt)->info;
}*/
