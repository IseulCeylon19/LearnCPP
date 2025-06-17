#include <iostream>
#include <bitset>
// using C++14, right now we cannot use std::format or std::print (run 0.13-PrintStandard for more information)
//May try running by passing -std=c++20 or -std=c++23 to the compiler
// #include <format> // C++20
// #include <print> // C++23

int main()
{
  int x{12};
  std::cout << x << '\n';             // decimal (by default)
  std::cout << std::hex << x << '\n'; // hexadecimal
  std::cout << x << '\n';             // now hexadecimal
  std::cout << std::oct << x << '\n'; // octal
  std::cout << std::dec << x << '\n'; // return to decimal
  std::cout << x << '\n';             // decimal

  // std::bitset<8> means we want to store 8 bits
  std::bitset<8> bin1{0b1100'0101}; // binary literal for binary 1100 0101
  std::bitset<8> bin2{0xC5};        // hexadecimal literal for binary 1100 0101

  std::cout << bin1 << '\n'
            << bin2 << '\n';
  std::cout << std::bitset<4>{0b1010} << '\n'; // create a temporary std::bitset and print it

  /*
  std::cout << std::format("{:b}\n", 0b1010);  // C++20, {:b} formats the argument as binary digits
  std::cout << std::format("{:#b}\n", 0b1010); // C++20, {:#b} formats the argument as 0b-prefixed binary digits

  std::println("{:b} {:#b}", 0b1010, 0b1010); // C++23, format/print two arguments (same as above) and a newline
  */

  return 0;
}