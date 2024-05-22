#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <iostream>
#include <stdexcept>
#include "ldl.h"

template<typename T>
class Pila
{
private:
    LDL<T> lista;

public:
    Pila() {}
    bool empty() const;
    size_t size() const;
    const T &top() const;
    void push(const T &element);
    void pop();
};

template<typename T>
bool Pila<T>::empty() const
{
    return lista.empty();
}

template<typename T>
size_t Pila<T>::size() const
{
    return lista.size();
}

template<typename T>
const T &Pila<T>::top() const
{
    if (empty())
    {
        throw runtime_error("Trying top() from an empty stack.");
    }
    return lista.front();
}

template<typename T>
void Pila<T>::push(const T &element)
{
    lista.push_front(element);
}

template<typename T>
void Pila<T>::pop()
{
    if (empty())
    {
        throw runtime_error("Trying pop() from an empty stack.");
    }
    lista.pop_front();
}

#endif
