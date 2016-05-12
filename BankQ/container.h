#ifndef CONTAINER_H
#define CONTAINER_H

template <class T>
class Container {
    friend class Iteratore;

    private:

        class SmartPointer;

        class Nodo {
            public:
                T* info;
                SmartPointer next;
                Nodo();
                Nodo (T* u, const SmartPointer& p): info(u), next(p) {}
                ~Nodo();
        };

        class SmartPointer{
            public:
                SmartPointer(Nodo* = 0);							//costruttore 0~1 parametro + convertitore implicito nodo*->smartp
                ~SmartPointer();									//distruttore
                SmartPointer(const SmartPointer&);						//costruttore di copia
                SmartPointer& operator=(const SmartPointer&);			//operatore di assegnazione
                bool operator==(const SmartPointer&)const;		//operatore di uguaglianza
                bool operator!=(const SmartPointer&)const;		//operatore di disuguaglianza
                Nodo* operator->()const;					//operatore di accesso a membro
                Nodo& operator*()const;

                Nodo* pointer;

                /*SmartPointer& operator=(const SmartPointer& sp) {
                    if (this == &sp) return *this;
                    Nodo* t = pointer;
                    pointer = sp.pointer;

                    return *this;
                }*/
        };

        SmartPointer first;
        static Nodo* copia (Nodo*);
        static void distruggi (Nodo*);
    public:
        class Iteratore {
            friend class Container;

            private:
                Container::SmartPointer punt;

            public:
                bool operator== (Iteratore i) const {
                    return punt == i.punt;
                }

                bool operator!= (Iteratore i) const {
                    return punt != i.punt;
                }

              /*  Iteratore& operator++ () {
                    if (punt != 0) punt = punt->next;
                    return *this;
                }*/

                Iteratore operator++ (int) {
                    Iteratore aux;
                    aux.punt = 0;
                    return aux;
                }
        };

        Container(): first(0) {}

        Container& operator= (const Container& var) {   // Assegnazione con SmartPointer
            if (&var == this) return *this;
            first = var.first;
            return *this;
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

        T* operator[] (Iteratore it) const {
            return (it.punt)->info;
        }

        void push_back (T nuovo) {
            first = new Nodo (&nuovo, first);
        }
};

#endif // CONTAINER_H
