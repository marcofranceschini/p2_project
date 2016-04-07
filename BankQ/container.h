#ifndef CONTAINER_H
#define CONTAINER_H

template <class T>
class Container {
    private:
        int size;
        T* users;

    public:
        Container (int s = 0, const T& value = T()):size(s), users(new T[s]) {
            for(int i = 0; i < size; ++i) {
                users[i] = value;
            }
        }

        Container (const Container& v):size(v), users(new T[v.size]) {
            for(int i = 0; i < size; ++i) {
                users[i] = v[i];
            }
        }

        ~Container() {
            delete[] users;
            size = 0;
        }

        Container& operator= (const Container& v) {
            delete[] users;
            size = v.size;
            for(int i = 0; i < size; ++i) {
                users[i]  = v.users[i];
            }
        }

        bool operator== (const Container& v) {
            if(size != v.size)
                return false;
            else{
                for (int i = 0; i < size; ++i) {
                    if(users[i] != v.users[i])
                        return false;
                }
                return true;
            }
        }

        T& operator[] (int index) const {
            if(index < size)
                    return users[index];
        }

        void push_back (const T& value) {
            size++;
            T* app = new T[size];
            for(int i = 0; i < size-1; ++i) {
                app[i] = users[i];
            }
            app[size-1] = value;
            delete[] users;
            users = new T[size];
            users = app;
        }

         void pop_back () {
            if(0 < size) {
                size--;
                T* app = new T[size];
                for(int i = 0; i < size; ++i) {
                    app[i] = users[i];
                }
                delete[] users;
                users = new T[size];
                users = app;
            }
        }

        void remove (int index) {
            if(0 < size && index < size) {
                size--;
                T* app = new T[size];
                for(int i = 0; i < size; ++i) {
                    if(index != i) app[i] = users[i];
                }
                delete[] users;
                users = new T[size];
                users = app;
            }
        }

        void replace (int index, const T& value) {
            if(0 < size && index < size) {
                for(int i = 0; i < size; ++i) {
                    if(index == i)
                        users[i] = value;
                }
            }
        }

        int getSize() const {
            return size;
        }

};

#endif // CONTAINER_H
