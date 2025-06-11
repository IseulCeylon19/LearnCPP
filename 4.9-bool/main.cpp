#include <iostream>
#include <limits>

int main()
{
  std::cout << true << '\n';
  std::cout << false << '\n';

  std::cout << std::boolalpha; // print bools as true or false
  std::cout << true << '\n';
  std::cout << false << '\n';

  std::cout << std::noboolalpha; // not print bools as true or false
  std::cout << true << '\n';
  std::cout << false << '\n';

  // By default, std::cin only accepts numeric input for Boolean variables: 0 is false, and 1 is true. Any other numeric value will be interpreted as true, and will cause std::cin to enter failure mode. Any non-numeric value will be interpreted as false and will cause std::cin to enter failure mode
  bool b{}; // default initialize to false
  std::cout << "Enter a boolean value (try enter true): ";
  std::cin >> b; // try entering true
  std::cout << "You entered: " << b << '\n'
            << std::endl;

  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the input buffer

  bool c{true}; // default initialize to false
  std::cout << "Enter a boolean value: ";
  // Allow the user to input 'true' or 'false' for boolean values
  // This is case-sensitive, so True or TRUE will not work
  std::cin >> std::boolalpha;
  std::cin >> c;

  // Let's also output bool values as `true` or `false`
  std::cout << std::boolalpha;
  std::cout << "You entered: " << c << '\n';

  return 0;
}