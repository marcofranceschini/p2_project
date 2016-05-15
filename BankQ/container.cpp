//#include "container.h"


/*
#ifndef CONTAINER_H
#define CONTAINER_H

template <class T>

class Container {
    friend class Iteratore;

    private:

        class Nodo;

        class SmartPointer {
            public:
                SmartPointer (Nodo* p): pointer(p) {							//costruttore 0~1 parametro + convertitore implicito nodo*->smartp
                    if (pointer) pointer->counter++;

                }

                ~SmartPointer () {   // Distruttore
                    if (pointer) {
                        (pointer->counter)--;
                        if (pointer->counter == 0) delete pointer;
                    }
                }

                SmartPointer (const SmartPointer& sp): pointer(sp.pointer) {					//costruttore di copia
                    if (pointer) pointer->counter++;
                }

                SmartPointer& operator= (const SmartPointer& var) {			//operatore di assegnazione
                    if (&var == this) return *this;
                    Nodo* n = pointer;
                    pointer = var.pointer;
                    if (pointer) (pointer->counter)++;
                    if (n) {
                        (n->counter)--;
                        if ((n->counter) == 0) delete n;
                    }
                    return *this;
                }

                bool operator== (const SmartPointer& i)const {		//operatore di uguaglianza
                    return pointer == i.pointer;
                }

                bool operator!= (const SmartPointer& i)const {		//operatore di disuguaglianza
                    return pointer != i.pointer;
                }

                Nodo* operator-> () const {return pointer;} // Operatore di accesso a membro

                Nodo& operator* () const {return *pointer;}

                Nodo* pointer;
        };

        class Nodo {
            public:
                T* info;
                SmartPointer next;
                int counter;
                //Nodo();
                Nodo (T* t, const SmartPointer& n): info(t), next(n), counter(0) {}
        };

        SmartPointer first;
        //static Nodo* copia (Nodo*);
        //static void distruggi (Nodo*);
    public:
        class Iteratore {
            friend class Container;

            private:
                Container::SmartPointer punt;

            public:
                bool operator== (const Iteratore& i) const {
                    return punt == i.punt;
                }

                bool operator!= (const Iteratore& i) const {
                    return punt != i.punt;
                }

                Iteratore& operator++ () {
                    if (punt != 0) punt = punt->next;
                    return *this;
                }

                Iteratore& operator++ (int) {
                    Iteratore aux = *this;
                    if (punt != 0) punt = punt->next;
                    return aux;
                }

                T* operator* () const {     // Operatore di accesso a membro
                    return punt->info;
                }
        };

        Container(): first(0) {}

        Container (const Container& cont): first(cont.first){}

        Container& operator= (const Container& var) {   // Assegnazione con SmartPointer
            if (&var == this) return *this;
            first = var.first;
            return *this;
        }

        void push_back (T* nuovo) {
            first = new Nodo (nuovo, first);
        }


        // Metodi che usano Iteratore

        Iteratore begin () const {
            Iteratore aux;
            aux.punt = first;
            return aux;
        }

        Iteratore end () const {
            Iteratore aux;
            aux.punt = 0;
            return aux;
        }

        T* operator[] (const Iteratore& it) const {
            return (it.punt)->info;
        }
};

#endif // CONTAINER_H
*/
