#include <iostream>

void printAddresses(int val, int& ref)
{
    std::cout << "The address of the value parameter is: " << &val << '\n';
    std::cout << "The address of the reference parameter is: " << &ref << '\n';
}

int main()
{
    int x { 5 };
    std::cout << "The address of x is: " << &x << '\n';
    printAddresses(x, x);

    return 0;
}