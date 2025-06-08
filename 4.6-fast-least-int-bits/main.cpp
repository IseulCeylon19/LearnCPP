#include <cstdint> // for fast and least types // for std::size_t
#include <iostream>

int main()
{
  std::cout << sizeof(int) << '\n';
  std::cout << sizeof(long) << '\n';
  std::cout << sizeof(long long) << '\n';
  std::cout << sizeof(std::int8_t) << '\n';
  std::cout << sizeof(std::int16_t) << '\n';
  std::cout << sizeof(std::int32_t) << '\n';
  std::cout << sizeof(std::int64_t) << '\n';

  int x{5};
  std::size_t s{sizeof(x)}; // sizeof returns a value of type std::size_t, so that should be the type of s
  std::cout << "std::size_t s = " << s << '\n';

  // std::size_t is an unsigned integer type that is used to represent the size of any object in bytes.
  // It is defined in the <cstddef> header, which is included by <cstdint>.
  // The size of std::size_t is implementation-defined, but it is guaranteed to be able to represent the size of any object in bytes.
  // It is typically the same size as the pointer type on the platform, which is usually 4 bytes on a 32-bit platform and 8 bytes on a 64-bit platform.
  // It is used for array indexing and loop counting, and it is the type returned by the sizeof operator.
  // It is also used in the standard library for functions that require a size or count, such as std::vector::size() and std::string::length().

  // std::size_t imposes an upper limit on the size of an object
  std::cout << sizeof(std::size_t) << '\n';

  // There are downside, should avoid using these types in new code.
  // They are not guaranteed to be the same size as the corresponding fixed-width types.

  std::cout << "least 8:  " << sizeof(std::int_least8_t) * 8 << " bits\n";
  std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
  std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
  std::cout << "least 64: " << sizeof(std::int_least64_t) * 8 << " bits\n";
  std::cout << '\n';
  std::cout << "fast 8:  " << sizeof(std::int_fast8_t) * 8 << " bits\n";
  std::cout << "fast 16: " << sizeof(std::int_fast16_t) * 8 << " bits\n";
  std::cout << "fast 32: " << sizeof(std::int_fast32_t) * 8 << " bits\n";
  std::cout << "fast 64: " << sizeof(std::int_fast64_t) * 8 << " bits\n";

  return 0;
}