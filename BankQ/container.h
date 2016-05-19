#ifndef CONTAINER_H
#define CONTAINER_H

template <class T>
class Container {
    friend class Iteratore;
private:
    class Nodo;

    class SmartPointer {
    public:
        Nodo* punt;

        SmartPointer(Nodo* n = 0): punt(n) {
            if (punt) punt->references++;
        }
        SmartPointer(const SmartPointer& ptr): punt(ptr.punt) {
            if (punt) punt->references++;
        }
        ~SmartPointer() {
            if (punt) {
                punt->references--;
                if (punt->references == 0) delete punt;
            }
        }

        SmartPointer& operator=(const SmartPointer& ptr) {
            if (this != &ptr) {
                Nodo* n = punt;
                punt = ptr.punt;
                if (punt) punt->references++;
                if (n) {
                    n->references--;
                    if (n->references == 0) delete n;
                }
            }
            return *this;
        }

        bool operator==(const SmartPointer& ptr) const {
            return ptr.punt == punt;
        }

        bool operator!=(const SmartPointer& ptr) const {
            return ptr.punt != punt;
        }

        Nodo* operator->() const {
            return punt;
        }

        Nodo& operator*() const {
            return *punt;
        }
    };

    class Nodo {
    public:
        T* value;
        SmartPointer next;
        int references;

        Nodo(T* t = T(), const SmartPointer& ptr = SmartPointer()): value(t), next(ptr), references(0) {}
    };

    SmartPointer head;
    SmartPointer tail;

public:
    class Iteratore{
        friend class Container;

    private:
        Container::SmartPointer punt;

    public:
        bool operator==(const Iteratore& it) const {
            return it.punt == punt;
        }

        bool operator!=(const Iteratore& it) const {
            return it.punt != punt;
        }

        Iteratore& operator++() {
            if(punt != 0) punt = punt->next;
            return *this;
        }

        Iteratore& operator++(int) {
            Iteratore aux = *this;
            if (punt != 0) punt = punt->next;
            return aux;
        }

        T* operator*() const {
            if (punt != 0) return punt->value;
        }
    };

    Container(const SmartPointer& ptr = 0): head(ptr), tail(0) {
        if (head != 0) {
            SmartPointer p = head;
            while (p != 0)
                p = p->next;
            tail = p;
        }
    }

    Container(const Container& list): head(list.head), tail(list.tail) {}

    Container& operator=(const Container& list) {
        if (this != &list) {
            head = list.head;
            tail = list.tail;
        }
        return *this;
    }

    int getSize() const {
        int count = 0;
        SmartPointer p = head;
        while (p != 0) {
            p = p->next;
            count++;
        }
        return count;
    }

    bool isEmpty() const {
        return getSize() == 0;
    }

    T* at(int pos) const {
        if (pos > -1 && pos < getSize()) {
            SmartPointer p = head;
            while (pos--) {
                p = p->next;
            }
            return p->value;
        } else return 0;
    }

    /*void add(const T& t) {
        if (head == 0) {
            head = SmartPointer(new Nodo(&(const_cast<T&>(t))));
            tail = head;
        } else {
            tail->next = SmartPointer(new Nodo(&(const_cast<T&>(t))));
            tail = tail->next;
        }
    }*/

    void push_back(T* t) {
        if (head == 0) {
            head = SmartPointer(new Nodo(t));
            tail = head;
        } else {
            tail->next = SmartPointer(new Nodo(t));
            tail = tail->next;
        }
    }

    void remove(int pos) {
        if (pos > -1 && pos < getSize()) {
            SmartPointer newHead = head;
            SmartPointer p = newHead;
            head = 0;
            while (pos--) {
                add(p->value);
                p = p->next;
            }
            p = p->next;
            while (p != 0) {
                add(p->value);
                p = p->next;
            }
        }
    }

    void replace(int pos, T* t) {
        if (pos > -1 && pos < getSize()) {
            SmartPointer p = head;
            while (pos--)
                p = p->next;
            p->value = t;
        }
    }

    void replace(int pos, const T& t) {
        if (pos > -1 && pos < getSize()) {
            SmartPointer p = head;
            while (pos--)
                p = p->next;
            T& t_obj = const_cast<T&>(t);
            p->value = &t_obj;
        }
    }

    Iteratore begin() const {
        Iteratore it;
        it.punt = head;
        return it;
    }

    Iteratore end() const {
        Iteratore it;
        it.punt = 0;
        return it;
    }

    T* operator[](const Iteratore& it) const {
        return it.punt->value;
    }
};

#endif // CONTAINER_H

