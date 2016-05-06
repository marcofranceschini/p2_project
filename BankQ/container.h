#ifndef CONTAINER_H
#define CONTAINER_H

template <class T>
class Container {
    friend class Iteratore;

    private:
        class Nodo {
            public:
                T info;
                Nodo* next;
                Nodo();
                Nodo (const T& u, Nodo* p): info(u), next(p) {}
                ~Nodo();
        };

        Nodo* first;
        static Nodo* copia (Nodo*);
        static void distruggi (Nodo*);
    public:
        class Iteratore {
            friend class Container;

            private:
                Container::Nodo* punt;

            public:
                bool operator== (Iteratore i) const {
                    return punt == i.punt;
                }

                bool operator!= (Iteratore i) const {
                    return punt != i.punt;
                }

                Iteratore& operator++ () {
                    Iteratore aux = *this;
                    if (punt) punt = punt->next;
                    return aux;
                }

                Iteratore operator++ (int) {
                    Iteratore aux;
                    aux.punt = 0;
                    return aux;
                }
        };

        Container(): first(0) {}

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

        T& operator[] (Iteratore it) const {
            return (it.punt)->info;
        }

        void push_back (T nuovo) {
            first = new Nodo (nuovo, first);
        }
};

#endif // CONTAINER_H
