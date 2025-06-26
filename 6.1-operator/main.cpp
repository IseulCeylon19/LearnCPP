#include <iostream>

int getValue()
{
  std::cout << "Enter an integer: ";

  int x{};
  std::cin >> x;
  return x;
}

void printCalculation(int x, int y, int z)
{
  std::cout << x + (y * z);
}

int main()
{
  // The Clang compiler evaluates arguments in left-to-right order. The GCC compiler evaluates arguments in right-to-left order
  // The MSVC compiler evaluates arguments in unspecified order.
  // The order of evaluation of function arguments is unspecified in C++14, which means that
  // the compiler can choose any order to evaluate the arguments.

  // enter the inputs 1, 2, and 3, you might assume that this program would calculate 1 + (2 * 3) and print 7
  // BUT depending on the compiler, the output may vary.
  printCalculation(getValue(), getValue(), getValue()); // this line is ambiguous

  // Do this instead to ensure the order of evaluation is clear:
  int a{getValue()}; // will execute first
  int b{getValue()}; // will execute second
  int c{getValue()}; // will execute third

  printCalculation(a, b, c); // this line is now unambiguous

  return 0;
}
