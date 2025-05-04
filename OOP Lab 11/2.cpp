#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class StackOverflowException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Stack is full!";
    }
};

class StackUnderflowException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Stack is empty!";
    }
};

template <class T>
class myStack
{
public:
    size_t size;
    T *arr = nullptr;
    size_t cur = 0;

    myStack(size_t size) : size(size)
    {
        arr = new T[size];
    }
    void push(T value)
    {
        if (cur == size)
            throw StackOverflowException();
        arr[cur++] = value;
    }
    void pop()
    {
        if (cur == 0)
            throw StackUnderflowException();
        cur--;
    }
    ~myStack()
    {
        delete[] arr;
    }
};

int main()
{
    myStack<int> S(3);
    cout << "\nPoping empty Stack\n";
    try
    {
        S.pop();
    }
    catch (const StackUnderflowException &e)
    {
        cout << "Exception Caught: " << e.what();
    }

    cout << "\n\nPushing some values in Stack\n";
    S.push(13);
    S.push(14);
    S.push(15);

    cout << "\nPushing a value in already Full Stack\n";
    try
    {
        S.push(20);
    }
    catch (StackOverflowException &e)
    {
        cout << "Exception Caught: " << e.what() << endl;
    }
    nl;
    return 0;
}