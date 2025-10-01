#include <iostream>
#include <cstddef> // for NULL
#include <cstddef> // for std::nullptr_t

// [[maybe_unused]] gets rid of compiler warnings about ptr2 being set but not used
void nullify1([[maybe_unused]] int *ptr2)
{
    ptr2 = nullptr; // Make the function parameter a null pointer
}
void nullify2(int *&refptr) // refptr is now a reference to a pointer
{
    refptr = nullptr; // Make the function parameter a null pointer
}

// ----------------------------------

void print(int x) // this function accepts an integer
{
    std::cout << "print(int): " << x << '\n';
}

void print(int *ptr) // this function accepts an integer pointer
{
    std::cout << "print(int*): " << (ptr ? "non-null\n" : "null\n");
}

// ----------------------------------

void print(std::nullptr_t)
{
    std::cout << "in print(std::nullptr_t)\n";
}

void print(int *)
{
    std::cout << "in print(int*)\n";
}

int main()
{
    int x{5};
    int *ptr{&x}; // ptr points to x

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

    nullify1(ptr);

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

    nullify2(ptr);

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

    // --------------------------------

    print(ptr); // always calls print(int*) because ptr has type int* (good)
    print(0);   // always calls print(int) because 0 is an integer literal (hopefully this is what we expected)

    print(NULL); // this statement could do any of the following:
    // call print(int) (Visual Studio does this)
    // call print(int*)
    // result in an ambiguous function call compilation error (gcc and Clang do this)

    print(nullptr); // always calls print(int*)

    // --------------------------------

    print(nullptr); // calls print(std::nullptr_t)

    // int x{5};
    // int *ptr{&x};

    print(ptr); // calls print(int*)

    ptr = nullptr;
    print(ptr); // calls print(int*) (since ptr has type int*)

    return 0;
}
