#include <string.h>
#include <iostream>

template<typename T>
struct node
{
    T data;
    node* next;
};

template<typename T>
class link
{
private:
    node<T>* head;
    node<T>* tail;
    int size;

public:
    link();
    link(T data);
    ~link();
    void addFirst(T data);
    void addLast(T data);
    void add(T data, int index);
    void removeFirst();
    void removeLast();
    void remove(int index);
    int getSize();
    node<T>* getIndex(int index);
};

template<typename T>
link<T>::link()
{
    head = NULL;
    tail = head;
    size = 0;
}

template<typename T>
link<T>::link(T data)
{
    head = new node<T>;
    tail = new node<T>;
    head->data = data;
    head->next = NULL;
    tail = head;
    size = 1;
}

template<typename T>
link<T>::~link()
{
    if(size > 0)
        for(int i = 0; i < size; i++)
        {
            node<T>* temp = new node<T>;
            delete temp;
        }
}

template<typename T>
void link<T>::addFirst(T data)
{
    if(size == 0)
    {
        head = new node<T>;
        tail = new node<T>;
        head->data = data;
        head->next = NULL;
        tail = head;
    }
    else
    {
        node<T>* temp = new node<T>;
        temp->data = data;
        temp->next = head;
        head = temp;
    }
    size++;
}

template<typename T>
void link<T>::addLast(T data)
{
    if(size == 0)
    {
        head = new node<T>;
        tail = new node<T>;
        tail->data = data;
        tail->next = NULL;
        head = tail;
    }
    else
    {
        node<T>* temp = new node<T>;
        temp->data = data;
        temp->next  = NULL;
        tail->next = temp;
        tail = temp;
    }
    size++;
}

template<typename T>
void link<T>::add(T data, int k)
{
    if(k == 0)
        addFirst(data);
    if(k > size - 1)
        addLast(data);
    else
    {
        node<T>* temp1 = getIndex(k-1);
        node<T>* temp2 = getIndex(k);
        node<T>* temp = new node<T>;
        temp->data = data;
        temp->next = temp2;
        temp1->next = temp;
        size++;
    }
}

template<typename T>
void link<T>::removeFirst()
{
    if(size == 0)
    {
        std::cout << "None elements!" << std::endl;
        return;
    }
    else
    {
        node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    size--;
}

template<typename T>
void link<T>::removeLast()
{
    if(size == 0)
    {
        std::cout << "None elements!" << std::endl;
        return;
    }
    else
    {
        node<T>* temp1 = getIndex(size - 2);
        node<T>* temp = tail;
        temp1->next = NULL;
        tail = temp1;
        delete temp;
    }
    size--;
}

template<typename T>
void link<T>::remove(int index)
{
    if(index == 0)
        removeFirst();
    else if(index >= size - 1)
        removeLast();
    else
    {
        node<T>* temp1 = getIndex(index - 1);
        node<T>* temp2 = getIndex(index + 1);
        node<T>* temp = getIndex(index);
        temp1->next = temp2;
        delete temp;
        size--;
    }
}

template<typename T>
int link<T>::getSize()
{
    return size;
}

template<typename T>
node<T>* link<T>::getIndex(int index)
{
    node<T>* temp = head;
    int i = 0;
    while(i < index)
    {
        temp = temp->next;
        i++;
    }
    return temp;
}
