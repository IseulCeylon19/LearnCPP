// https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/

#include <iostream>
#include <typeinfo> // for typeid()

[[maybe_unused]] void printTest()
{
    double d = 10 / 4;
    std::cout << typeid(d).name() << ' ' << d << '\n';

    double dd = 10.0 / 4;
    std::cout << typeid(dd).name() << ' ' << dd << '\n';

    int x{10};
    int y{4};
    std::cout << (double)x / y << '\n';              // C-style cast of x to double
    std::cout << double(x) / y << '\n';              //  // function-style cast of x to double
    std::cout << static_cast<double>(x) / y << '\n'; // prints 2.5

    char c{'a'};
    std::cout << static_cast<int>(c) << '\n'; // prints 97 rather than a

    int i{48};
    // explicit conversion from int to char, so that a char is assigned to variable ch
    char ch{static_cast<char>(i)};
    std::cout << ch << '\n';

    // +++++ Casting vs initializing a temporary object +++++
    // We want to do floating point division, so one of the operands needs to be a floating point type
    // std::cout << double{x} / y << '\n'; // okay if int is 32-bit, narrowing if x is 64-bit and error if -Wnarraowing

    // while int { x } is a valid conversion syntax, unsigned int { x } is not
    // unsigned char c { 'a' };
    // std::cout << unsigned int { c } << '\n'; // THIS IS ERROR
    // Avoid with
    unsigned char cc{'a'};
    using uint = unsigned int;
    std::cout << uint{cc} << '\n';
}

int main()
{
    printTest();

    return 0;
}
