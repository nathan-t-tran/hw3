#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

using namespace std;

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private vector 
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

template <typename T>
Stack<T>::Stack(): vector<T>(){}

template <typename T>
Stack<T>::~Stack()
{
    clear; 
}

template <typename T>
bool Stack<T>::empty() const
{
    return vector<T>::empty();
}

template <typename T>
size_t Stack<T>::size() const
{
    return vector<T>::size();
}

template<typename T>
void Stack<T>::push(const T& item)
{
    vector<T>::push_back(item);
}
template<typename T>
void Stack<T>::pop()  // throws std::underflow_error if empty
{
    if(empty())
    {
        throw underflow_error;
    }
    else 
    {
        vector<T>::pop_back();
    }
}

template<typename T>
const T& Stack<T>::top() const // throws std::underflow_error if empty
{
    if(empty())
    {
        throw underflow_error;
    }
    else 
    {
        vector<T>::front();
    }
}


#endif