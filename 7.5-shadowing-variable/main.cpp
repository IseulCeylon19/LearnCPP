// https://www.learncpp.com/cpp-tutorial/variable-shadowing-name-hiding/

#include <iostream>

int value{5}; // global variable

void foo()
{
  std::cout << "global variable value: " << value << '\n'; // value is not shadowed here, so this refers to the global value
}

int main()
{

  // outer block
  int apples{5}; // here's the outer block apples
  {              // nested block
    // apples refers to outer block apples here
    std::cout << apples << '\n'; // print value of outer block apples
    int apples{0};               // define apples in the scope of the nested block
    // apples now refers to the nested block apples
    // the outer block apples is temporarily hidden
    apples = 10;                 // this assigns value 10 to nested block apples, not outer block apples
    std::cout << apples << '\n'; // print value of nested block apples
  } // nested block apples destroyed
  std::cout << apples << '\n'; // prints value of outer block apples

  // -------------------------------------------
  int value{7}; // hides the global variable value (wherever local variable value is in scope)
  ++value;      // increments local value, not global value
  --(::value);  // decrements global value, not local value (parenthesis added for readability)
  std::cout << "local variable value: " << value << '\n';
  foo();
  // local variable value: 8
  // global variable value: 4
  // -------------------------------------------

  // GCC and Clang support the flag -Wshadow that will generate warnings if a variable is shadowed.
  // There are several subvariants of this flag (-Wshadow=global, -Wshadow=local, and -Wshadow=compatible-local.
  // Consult the GCC documentation for an explanation of the differences.

  return 0;
} // outer block apples destroyed