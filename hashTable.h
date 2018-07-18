#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
using namespace std;

struct element
{
    int key;
    int value;
    struct element* next;
};

class hashTable
{
	private:
		int capacity;
		float factor;
		element* table;
		int size = 0;
		int use = 0;
		int hash(int key);
		void resize();

	public:
		hashTable();
		hashTable(int capacity, float factor);
        ~hashTable();
		void put(int key, int value);
		void remove(int key);
		int get(int key);
		int getSize();
		int getLength();
};


hashTable::hashTable()
{
	capacity = 4;
	factor = 0.75f;
	table = new element[capacity];
	for(int i = 0; i < capacity; i++)
    {
        table[i].next = new element;
        table[i] = {-1, -1, NULL};
    }
}


hashTable::hashTable(int capacity, float factor)
{
	this->capacity = capacity;
	this->factor = factor;
	table = new element[capacity];
	for(int i = 0; i < capacity; i++)
    {
        table[i].next = new element;
        table[i] = {-1, -1, NULL};
    }
}

hashTable::~hashTable()
{
    for(int i = 0; i < capacity; i++)
        delete table[i].next;
    delete[] table;
}

void hashTable::put(int key, int value)
{
	int index = hash(key);
    element* e = table[index].next;
	if(e == NULL)
	{
	    e = new element;
	    table[index].next = e;
	    e->next = new element;
	    *e = {key, value, NULL};
		size++;
		use++;
		if(use >= factor*capacity)
			resize();
	}
	else
	{
		for(e = e->next; e != NULL; e = e->next)
		{
			int k = e->value;
			if(k == key)
			{
				e->value = value;
				return;
			}
		}
		element* temp = table[index].next;
		element* e1 = new element;
		e1->next = new element;
        *e1 = {key, value, temp};
		table[index].next = e1;
		size++;
	}
}

void hashTable::remove(int key)
{
	int index = hash(key);
	element* e = table[index].next;
	element* pre = table[index].next;
    while(e != NULL)
    {
        int k = e->key;
        if(k == key)
        {
            pre->next = e->next;
            size--;
            return;
        }
        pre = e;
        e = e->next;
    }
}

int hashTable::get(int key)
{
	int index = hash(key);
	element* e = table[index].next;
	if(e != NULL)
	{
		for(; e != NULL; e = e->next)
		{
			int k = e->key;
			if(k == key)
				return e->value;
		}
	}
	return -1;
}

int hashTable::getSize()
{
	return size;
}

int hashTable::getLength()
{
	return capacity;
}

int hashTable::hash(int key)
{
	return key%capacity;
}

void hashTable::resize()
{
	int newCapacity = capacity*2;
	element* temp = new element[capacity];
	for(int i = 0; i < capacity; i++)
		temp[i] = table[i];
	table = new element[newCapacity];
	for(int i = 0; i < newCapacity; i++)
    table[i] = {-1, -1, NULL};
	use = 0;
	for(int i = 0; i < capacity; i++)
	{
		if(temp[i].key == -1 && temp[i].next != NULL)
		{
			element* e = temp[i].next;
			while(e != NULL)
			{
				int index = hash(e->key);
				element* e1 = table[index].next;
				table[index].next = e;
				e->next = e1;
				e = e->next;
			}
		}
	}
	capacity = newCapacity;
}


#endif
