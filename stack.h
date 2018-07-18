#include <iostream>
using namespace std;


template<typename T>
class stack
{
    private:
        int size;
        int capacity;
        T* array;
        void resize();

    public:
        stack();
        stack(int size);
		~stack() { delete[] array; }
        void push(T element);
        T peek();
        T pop();
        bool isFull();
        bool isEmpty();
        int getSize();
        int getCapacity();
};

template<typename T>
stack<T>::stack()
{
    size = 0;
    capacity = 4;
    array = new T[capacity];
}

template<typename T>
stack<T>::stack(int capacity)
{
    size = 0;
    this.capacity = capacity;
    array = new T[this.capacity];
}

template<typename T>
void stack<T>::push(T element)
{
    if(size < capacity)
    {
        array[size] = element;
        size++;
    }
    else
    {
        resize();
        array[size] = element;
        size++;
    }
}

template<typename T>
T stack<T>::peek()
{
    if(size == 0)
    {
        cout << "No elements!" << endl;
        exit(0);
    }
    return array[size-1];
}

template<typename T>
T stack<T>::pop()
{
    T item = peek();
    size--;
    return item;
}

template<typename T>
bool stack<T>::isFull()
{
    return size == (capacity - 1);
}

template<typename T>
bool stack<T>::isEmpty()
{
    return size == 0;
}

template<typename T>
int stack<T>::getSize()
{
    return size;
}

template<typename T>
int stack<T>::getCapacity()
{
    return capacity;
}

template<typename T>
void stack<T>::resize()
{
        T temp[capacity];
        for(int i = 0; i < capacity; i++)
            temp[i] = array[i];
        capacity = 2*capacity;
        delete[] array;
        array = new T[capacity];
        for(int i = 0; i < size; i++)
            array[i] = temp[i];
}



