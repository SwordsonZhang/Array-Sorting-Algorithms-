#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <string.h>

template<typename T>
class queue
{
private:
    int head;
    int tail;
    int capacity;
    T* array;

public:
    queue();
    queue(int capacity);
    ~queue() { delete[] array; }
    void put(T element);
    T peek();
    T poll();
    bool isFull();
    bool isEmpty();
    int getSize();
    int getCapacity();
};

template<typename T>
queue<T>::queue()
{
    head = 0;
    tail = 0;
    capacity = 10;
    array = new T[capacity];
}

template<typename T>
queue<T>::queue(int capacity)
{
    head = 0;
    tail = 0;
    this->capacity = capacity;
    array = new T[this->capacity];
}

template<typename T>
void queue<T>::put(T element)
{
    if(isFull())
    {
        std::cout << "Queue is full. Cannot put again." << std::endl;
        return;
    }
    array[tail%capacity] = element;
    tail++;
}

template<typename T>
T queue<T>::peek()
{
    if(isEmpty())
    {
        std::cout << "None elements!" << std::endl;
        return NULL;
    }
    else
        return array[head];
}

template<typename T>
T queue<T>::poll()
{
    T temp = peek();
    if(temp != NULL)
        head++;
    return temp;
}

template<typename T>
bool queue<T>::isFull()
{
    return tail != 0 && head == tail%capacity;
}

template<typename T>
bool queue<T>::isEmpty()
{
    return head == tail;
}

template<typename T>
int queue<T>::getSize()
{
    if(tail <= capacity)
        return tail - head;
    else
    {
        return capacity - head + tail%capacity;
    }
}

#endif

