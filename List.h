#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cassert>

template <class T>
class List
{
	public:

		List();
		~List();

		void pushFront(const T& elem);
		void pushBack(const T& elem);
		void popFront();
		void popBack();
		void insert(unsigned int pos, const T& elem);
		void remove(unsigned int pos);

		T front() const;
		T back() const;
		T getValue(unsigned int pos) const;

		bool empty() const;
		unsigned int size() const;
		void clear();

		void print() const;
		void listToArray(T* arr);
		void arrayToList(T* arr, int size);

	private:

		struct node{
			T value;
			node* next;
			node* prev;
		};

		node* first;
		node* last;
		unsigned int numElems;
};

template<class T>
List<T>::List() : first(nullptr), last(nullptr), numElems(0)
{
}

template<class T>
List<T>::~List()
{
	clear();
}

template<class T>
void List<T>::pushFront(const T& elem)
{
	node* aux = new node;
	aux->value = elem;
	aux->next = first;
	aux->prev = nullptr;

	if (first != nullptr)
		first->prev = aux;
	
	first = aux;

	if (numElems == 0)
		last = aux;

	numElems++;
}

template<class T>
void List<T>::pushBack(const T& elem)
{
	node* aux = new node;
	aux->value = elem;
	aux->next = nullptr;

	if (last != nullptr)
	{
		last->next = aux;
	}

	aux->prev = last;
	last = aux;

	if (numElems == 0)
		first = aux;

	numElems++;
}

template<class T>
void List<T>::popFront()
{
	// Abort if the list is empty
	assert(numElems > 0 && "popFront() cannot be called if the list is empty");

	node* aux = first;
	first->next->prev = nullptr;
	first = first->next;
	delete aux;
	numElems--;

	if (numElems == 0)
		last = nullptr;
}

template<class T>
void List<T>::popBack()
{
	// Abort if the list is empty
	assert(numElems > 0 && "popBack() cannot be called if the list is empty");

	if (numElems == 1)
	{
		delete first;
		first = nullptr;
		last = nullptr;
		numElems = 0;
	}
	else
	{
		node* prev = first;
		node* curr = first->next;

		while (curr->next != nullptr)
		{
			prev = prev->next;
			curr = curr->next;
		}

		delete curr;
		last = prev;
		last->next = nullptr;

		numElems--;
	}
}

template<class T>
void List<T>::insert(unsigned int pos, const T& elem)
{
	if (pos == 0)
	{
		pushFront(elem);
	}
	else if (pos >= numElems)
	{
		pushBack(elem);

		assert(pos > numElems && "Required position higher than the current amount of elements. Called pushBack() instead");
	}
	else
	{
		assert(pos < numElems && "insert() needs a position within the bounds of the list");

		node* prev = first;
		node* curr = first->next;
		unsigned int count = 1;
		while (count < pos)
		{
			prev = prev->next;
			curr = curr->next;
			count++;
		}

		node* aux = new node;
		aux->value = elem;
		prev->next = aux;
		aux->prev = prev;
		aux->next = curr;
		curr->prev = aux;

		numElems++;
	}
}

template<class T>
void List<T>::remove(unsigned int pos)
{
	if (pos == 0)
	{
		popFront();
	}
	else if (pos == numElems - 1)
	{
		popBack();
	}
	else
	{
		assert(pos < numElems && "remove() needs a position within the bounds of the list");

		node* prev = first;
		node* curr = first->next;
		unsigned int count = 1;
		while (count < pos)
		{
			prev = prev->next;
			curr = curr->next;
			count++;
		}

		prev->next = curr->next;
		curr->next->prev = prev;
		delete curr;

		numElems--;
	}
}

template<class T>
T List<T>::front() const
{
	assert(numElems > 0 && "The list is empty");

	return first->value;
}

template<class T>
T List<T>::back() const
{
	assert(numElems > 0 && "The list is empty");

	return last->value;
}

template<class T>
T List<T>::getValue(unsigned int pos) const
{
	assert(pos < numElems && "Position out of bounds");

	unsigned int count = 0;
	node* iterator = first;
	while (count < pos && iterator->next != nullptr)
	{
		iterator = iterator->next;
		count++;
	}

	return iterator->value;
}

template<class T>
bool List<T>::empty() const
{
	return numElems == 0;
}

template<class T>
unsigned int List<T>::size() const
{
	return numElems;
}

template<class T>
void List<T>::clear()
{
	while (first != nullptr)
	{
		node* aux = first;
		first = first->next;
		delete aux;
	}
	first = nullptr;
	last = nullptr;
	numElems = 0;
}

template<class T>
void List<T>::print() const
{
	node* iterator = first;

	if (iterator == nullptr)
	{
		std::cout << "The list is empty";
	}
	else
	{
		std::cout << iterator->value;
		iterator = iterator->next;
	}

	while (iterator != nullptr)
	{
		std::cout << " <-> " << iterator->value;
		iterator = iterator->next;
	}

	std::cout << std::endl;
}

template<class T>
void List<T>::listToArray(T* arr)
{
	T auxArr[numElems];
	int counter;

	node* iterator = first;
	while (iterator != nullptr)
	{
		auxArr[counter] = iterator->value;
		iterator = iterator->next;
		counter++;
	}

	arr = auxArr;
}

template<class T>
void List<T>::arrayToList(T* arr, int size)
{
	int counter = size;

	while (counter >= 0)
	{
		pushFront(arr[counter]);
		counter--;
	}
}

#endif