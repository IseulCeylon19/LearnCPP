#include <iostream>
#include <limits>

int main()
{
  std::cout << "Input a keyboard character: "; // assume the user enters "a b" (without quotes)

  char ch{};
  std::cin >> ch; // extracts a, leaves " b\n" in stream
  std::cout << "You entered: " << ch << '\n';

  std::cin >> ch; // skips leading whitespace (the space), extracts b, leaves "\n" in stream
  std::cout << "You entered: " << ch << '\n';

  
  // If you want to read characters including whitespace, you can use std::cin.get()
  std::cin.clear(); // clear the state of the input stream
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the rest of the line
  std::cout << "Input a keyboard character: "; // assume the user enters "a b" (without quotes)


  std::cin.get(ch); // extracts a, leaves " b\n" in stream
  std::cout << "You entered: " << ch << '\n';

  std::cin.get(ch); // extracts space, leaves "b\n" in stream
  std::cout << "You entered: " << ch << '\n';

  return 0;
}
