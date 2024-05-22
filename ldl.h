#ifndef LDL_H
#define LDL_H

#include <cstddef>
#include <stdexcept>
#include <memory>

using namespace std;

template<typename T>
class LDL
{
private:
    struct NodeLDL
    {
        T data;
        shared_ptr<NodeLDL> prev;
        shared_ptr<NodeLDL> next;

        NodeLDL(const T &element, shared_ptr<NodeLDL> p = nullptr, shared_ptr<NodeLDL> n = nullptr)
            : data(element), prev(p), next(n) {}
    };

    size_t listSize;
    shared_ptr<NodeLDL> listFront;
    shared_ptr<NodeLDL> listBack;

public:
    LDL() : listSize(0), listFront(nullptr), listBack(nullptr) {}

    bool empty() const;
    size_t size() const;
    void push_front(const T &element);
    void push_back(const T &element);
    const T &front() const;
    const T &back() const;
    void pop_front();
    void pop_back();
    void clear();
};

template<typename T>
bool LDL<T>::empty() const
{
    return listSize == 0;
}

template<typename T>
size_t LDL<T>::size() const
{
    return listSize;
}

template<typename T>
void LDL<T>::push_front(const T &element)
{
    auto newNode = make_shared<NodeLDL>(element, nullptr, listFront);
    if (empty())
    {
        listBack = newNode;
    }
    else
    {
        listFront->prev = newNode;
    }
    listFront = newNode;
    ++listSize;
}

template<typename T>
void LDL<T>::push_back(const T &element)
{
    auto newNode = make_shared<NodeLDL>(element, listBack, nullptr);
    if (empty())
    {
        listFront = newNode;
    }
    else
    {
        listBack->next = newNode;
    }
    listBack = newNode;
    ++listSize;
}

template<typename T>
const T &LDL<T>::front() const
{
    if (empty())
    {
        throw runtime_error("Trying front() on an empty list");
    }
    return listFront->data;
}

template<typename T>
const T &LDL<T>::back() const
{
    if (empty())
    {
        throw runtime_error("Trying back() on an empty list");
    }
    return listBack->data;
}

template<typename T>
void LDL<T>::pop_front()
{
    if (empty())
    {
        throw runtime_error("Trying pop_front() on an empty list.");
    }
    listFront = listFront->next;
    if (listFront)
    {
        listFront->prev = nullptr;
    }
    else
    {
        listBack = nullptr;
    }
    --listSize;
}

template<typename T>
void LDL<T>::pop_back()
{
    if (empty())
    {
        throw runtime_error("Trying pop_back() on an empty list.");
    }
    listBack = listBack->prev;
    if (listBack)
    {
        listBack->next = nullptr;
    }
    else
    {
        listFront = nullptr;
    }
    --listSize;
}

template<typename T>
void LDL<T>::clear()
{
    listFront = nullptr;
    listBack = nullptr;
    listSize = 0;
}

#endif
