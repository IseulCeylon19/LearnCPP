// https://www.learncpp.com/cpp-tutorial/internal-linkage

#include <iostream>

// The use of the static keyword above is an example of a storage class specifier, which sets both the name’s linkage and its storage duration. 
// The most commonly used storage class specifiers are static, extern, and mutable. The term storage class specifier is mostly used in technical documentations
// and is not commonly used in everyday C++ discussions. The term linkage specification is more commonly used in everyday discussions, as it describes the effect of the storage class specifier on the name’s linkage.
// The static keyword can be used to give a name internal linkage, which means that the name is only visible within the translation unit (source file) in which it is defined.
// Names with internal linkage cannot be accessed from other translation units, even if they are declared in a header file.
// Names with internal linkage are not visible outside the translation unit, and cannot be accessed from other translation units.


// In modern C++, use of the static keyword for giving identifiers internal linkage is falling out of favor.
// Unnamed namespaces can give internal linkage to a wider range of identifiers (e.g. type identifiers), and they are better suited for giving many identifiers internal linkage.
// However, the static keyword is still commonly used for giving functions and variables internal linkage.
// The static keyword can also be used to give a name static storage duration, which means that the name is allocated in memory for the lifetime of the program.
// The static keyword can be used to give a name internal linkage, which means that the name is only visible within the translation unit (source file) in which it is defined.


static int g_x{}; // non-constant globals have external linkage by default, but can be given internal linkage via the static keyword

const int g_y{ 1 }; // const globals have internal linkage by default
constexpr int g_z{ 2 }; // constexpr globals have internal linkage by default

// This function is declared as static, and can now be used only within this file
// Attempts to access it from another file via a function forward declaration will fail
[[maybe_unused]] static int add(int x, int y)
{
    return x + y;
}

// if put this in a different file, it will not compile
// because add() has internal linkage and cannot be accessed outside this file
// Uncommenting the following line will cause a compilation error
// extern int add(int x, int y); // forward declaration for function add
// int add(int x, int y); // forward declaration for function add

int main()
{
    std::cout << g_x << ' ' << g_y << ' ' << g_z << '\n';
    return 0;
}
