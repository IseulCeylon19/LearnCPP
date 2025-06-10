#include <iostream>
#include <limits>
#include <iomanip> // for output manipulator std::setprecision()

int main()
{
  std::cout << std::boolalpha; // print bool as true or false rather than 1 or 0
  std::cout << "float: " << std::numeric_limits<float>::is_iec559 << '\n';
  std::cout << "double: " << std::numeric_limits<double>::is_iec559 << '\n';
  std::cout << "long double: " << std::numeric_limits<long double>::is_iec559 << '\n';

  std::cout << "float:  " << sizeof(float) * 8 << " bits\n";
  std::cout << "double: " << sizeof(double) * 8 << " bits\n";
  std::cout << "long double: " << sizeof(long double) * 8 << " bits\n";

  std::cout << "-----------------\n";
  std::cout << 9.87654321f << '\n';
  std::cout << 987.654321f << '\n';
  std::cout << 987654.321f << '\n';
  std::cout << 9876543.21f << '\n';
  std::cout << 0.0000987654321f << '\n';

  std::cout << "-----------------\n";
  std::cout << std::setprecision(17);                             // show 17 digits of precision
  std::cout << 3.33333333333333333333333333333333333333f << '\n'; // f suffix means float
  std::cout << 3.33333333333333333333333333333333333333 << '\n';  // no suffix means double

  std::cout << "-----------------\n";
  // 123456792 is greater than 123456789. The value 123456789.0 has 10 significant digits, but float values typically have 7 digits of precision (and the result of 123456792 is precise only to 7 significant digits). We lost some precision! When precision is lost because a number can’t be stored precisely, this is called a rounding error.
  float f{123456789.0f};             // f has 10 significant digits
  std::cout << std::setprecision(9); // to show 9 digits in f
  std::cout << f << '\n';

  std::cout << "-----------------\n";
  double d{0.1};
  std::cout << d << '\n'; // use default cout precision of 6
  std::cout << std::setprecision(17);
  std::cout << d << '\n';

  std::cout << "-----------------\n";
  std::cout << std::setprecision(17);
  double d1{1.0};
  std::cout << d1 << '\n';
  double d2{0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1}; // should equal 1.0
  std::cout << d2 << '\n';

  std::cout << "-----------------\n";
  double zero{0.0};
  double posinf{5.0 / zero}; // positive infinity
  std::cout << posinf << '\n';
  double neginf{-5.0 / zero}; // negative infinity
  std::cout << neginf << '\n';
  double z1{0.0 / posinf}; // positive zero
  std::cout << z1 << '\n';
  double z2{-0.0 / posinf}; // negative zero
  std::cout << z2 << '\n';
  double nan{zero / zero}; // not a number (mathematically invalid)
  std::cout << nan << '\n';

  return 0;
}