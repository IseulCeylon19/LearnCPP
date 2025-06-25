#include <iostream>
#include <string>
#include <string_view>

std::string getName()
{
  std::string s{"Alex"};
  return s;
}

// when getBoolName(true) is called, the function returns a std::string_view that is viewing t. However, t is destroyed at the end of the function.
// This means the returned std::string_view is viewing an object that has been destroyed. So when the returned std::string_view is printed, undefined behavior results
std::string_view getBoolName(bool b)
{
  std::string t{"true"};  // local variable
  std::string f{"false"}; // local variable

  if (b)
    return t; // return a std::string_view viewing t

  return f; // return a std::string_view viewing f
} // t and f are destroyed at the end of the function

int main()
{
  // std::string_view sv{};
  // {                                 // create a nested block
  //   std::string s{"Hello, world!"}; // create a std::string local to this nested block
  //   sv = s;                         // sv is now viewing s
  // } // s is destroyed here, so sv is now viewing an invalid string
  // std::cout << sv << '\n'; // undefined behavior

  // std::string_view name{getName()}; // name initialized with return value of function
  // std::cout << name << '\n';        // undefined behavior

  // using namespace std::string_literals;
  // std::string_view name{"Alex"s}; // "Alex"s creates a temporary std::string
  // std::cout << name << '\n';      // undefined behavior

  // std::string s{"Hello, world!"};
  // std::string_view sv{s}; // sv is now viewing s
  // s = "Hello, a!";         // modifies s, which invalidates sv (s is still valid)
  // std::cout << sv << '\n'; // undefined behavior

  // std::string s{"Hello, world!"};
  // std::string_view sv{s};  // sv is now viewing s
  // s = "Hello, universe!";  // modifies s, which invalidates sv (s is still valid)
  // std::cout << sv << '\n'; // undefined behavior
  // sv = s;                  // revalidate sv: sv is now viewing s again
  // std::cout << sv << '\n'; // prints "Hello, universe!"

  // std::cout << getBoolName(true) << ' ' << getBoolName(false) << '\n'; // undefined behavior

  // std::string_view str{"Peach"};
  // std::cout << str << '\n';
  // // Remove 1 character from the left side of the view
  // str.remove_prefix(1);
  // std::cout << str << '\n';
  // // Remove 2 characters from the right side of the view
  // str.remove_suffix(2);
  // std::cout << str << '\n';
  // str = "Peach"; // reset the view
  // std::cout << str << '\n';



  return 0;
}
