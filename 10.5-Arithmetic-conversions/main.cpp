// https://www.learncpp.com/cpp-tutorial/arithmetic-conversions/
// https://en.cppreference.com/w/cpp/language/usual_arithmetic_conversions.html

#include <iostream>
#include <typeinfo> // for typeid()

[[maybe_unused]] void printType()
{
    int i{2};
    std::cout << typeid(i).name() << '\n'; // show us the name of the type for i => Integer

    double d{3.5};
    std::cout << typeid(d).name() << '\n'; // show us the name of the type for d => Double
    std::cout << typeid(i + d).name() << ' ' << i + d << '\n'; // show us the type of i + d => Double

    short a{4};
    short b{5};
    std::cout << typeid(a + b).name() << ' ' << a + b << '\n'; // show us the type of a + b => Integer

    // You might expect the expression 5u - 10 to evaluate to -5 since 5 - 10 = -5. But here’s what actually results
    std::cout << typeid(5u-10).name() << ' ' << 5u - 10 << '\n'; // 5u means treat 5 as an unsigned integer => unsigned integer

    // While it’s clear to us that 5 is greater than -3, when this expression evaluates
    // -3 is converted to a large unsigned int that is larger than 5.
    // Thus, this prints false rather than the expected result of true
    std::cout << std::boolalpha << (-3 < 5u) << '\n';
    // Above error with -Werror flag
}

int main()
{
    printType();

    return 0;
}
