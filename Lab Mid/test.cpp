#include <bits/stdc++.h>
#define GETTER(type, var) type get_##var() const { return var; }
#define SETTER(type, var) void set_##var(type val) { this->var = val; }
#define nl (cout << endl)
using namespace std;

class Student{
    int x,y;
    public:
    GETTER(int,x)
    GETTER(int,y)
};

int main()
{
    cout << "Hello World";
    return 0;
}
// template <typename T>
// T* reallocate(T* arr, size_t oldSize, size_t newSize) {
//     T* temp = new T[newSize];  // Allocate new memory
//     std::copy(arr, arr + std::min(oldSize, newSize), temp);  // Copy elements
//     delete[] arr;  // Free old memory
//     return temp;  // Return new pointer
// }