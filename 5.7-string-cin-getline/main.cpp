#include <iostream>
#include <string>

int main()
{
    std::cout << "Pick 1 or 2: ";
    int choice{};
    std::cin >> choice;

    std::cout << "Now enter your name: ";
    std::string name{};
    // std::getline(std::cin, name); // note: if no std::ws here, cin will put \n into name
    std::getline(std::cin >> std::ws, name); // note: added std::ws here

    std::cout << "Hello, " << name << ", you picked " << choice << '\n';


    // std::string::length() returns an unsigned integral value (most likely of type size_t).
    // If you want to assign the length to an int variable, you should static_cast it to avoid compiler warnings about signed/unsigned conversions
    int length { static_cast<int>(name.length()) };
    std::cout << "Your name has " << length << " characters.\n";

    // In C++20, you can also use the std::ssize() function to get the length of a std::string as a large signed integral type (usually std::ptrdiff_t)
    // std::cout << "Your name has " << std::ssize(name) << " characters.\n"; // C++20 feature

    // Since a ptrdiff_t may be larger than an int, if you want to store the result of std::ssize() in an int variable, you should static_cast the result to an int
    // int len { static_cast<int>(std::ssize(name)) };

    // Do not pass std::string by value, as it makes an expensive copy
    // Instead, pass it by reference to avoid unnecessary copying
    auto printName = [](const std::string& str) {
        std::cout << "Your name is: " << str << '\n';
    };
    printName(name);

    // In most cases, use a std::string_view parameter instead
    auto printNameView = [](std::string_view str) {
        std::cout << "Your name is: " << str << '\n';
    };
    printNameView(name);
    // If you want to use a std::string_view, you can also pass a string literal directly
    printNameView("John Doe");
    // Note: std::string_view does not own the data it refers to, so be careful with the lifetime of the original string
    // If you want to use a std::string_view with a temporary string, you can do so, but be aware that the temporary will be destroyed after the expression
    printNameView(std::string{"Jane Doe"}); // This is safe, as the temporary string will be destroyed after the function call

    return 0;
}