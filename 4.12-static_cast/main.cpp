#include <iostream>

int main()
{
  int s{-1};
  std::cout << static_cast<unsigned int>(s) << '\n'; // prints 4294967295

  unsigned int u{4294967295};               // largest 32-bit unsigned int
  std::cout << static_cast<int>(u) << '\n'; // implementation-defined prior to C++20, -1 as of C++20

  std::int8_t myInt{65};                        // initialize myInt with value 65
  std::cout << myInt << '\n';                   // you're probably expecting this to print 65 but it prints 'A'
  std::cout << static_cast<int>(myInt) << '\n'; // prints 65

  std::cout << "Enter a number between 0 and 127: ";
  std::int8_t myInt2{};
  std::cin >> myInt2;
  std::cout << "You entered: " << static_cast<int>(myInt2) << '\n';
  // Enter a number between 0 and 127: 35
  // You entered: 51
  // When std::int8_t is treated as a char, the input routines interpret our input as a sequence of characters, not as an integer.
  // So when we enter 35, we’re actually entering two chars, '3' and '5'

  return 0;
}