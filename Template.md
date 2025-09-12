# Google with 'c++ template requires which std version'
## AI overview is

C++ templates are a fundamental feature of the language and have been available since its early versions. Therefore, templates themselves do not require a specific C++ standard version to be used. They are a core part of C++ from C++98 onwards.
However, various features and enhancements related to templates have been introduced in later C++ standards, making template usage more powerful, flexible, and convenient. For example:

    C++11: introduced features like variadic templates, template aliases, and decltype.
    C++14: brought generic lambdas and variable templates.
    C++17: introduced class template argument deduction (CTAD) and if constexpr.
    C++20: introduced concepts, which allow for more expressive and constrained template parameters, and the requires expression for defining these constraints. 

Therefore, while basic template functionality is available in older standards, to leverage the full power and modern features of C++ templates, using a more recent standard like C++17 or C++20 is highly recommended.

## and rerun; AI overview is


C++ templates are a fundamental feature of the language and have been available since early versions of C++. They do not require a specific modern C++ standard to be used in their basic form.
However, various C++ standards have introduced significant enhancements and new features related to templates, making them more powerful and easier to use:

    C++11:
    Introduced template aliases (using for templates), variadic templates (templates that can take an arbitrary number of arguments), and external templates.
    C++14:
    Introduced variable templates and enhancements to constexpr for use with templates.
    C++17:
    Introduced Class Template Argument Deduction (CTAD), allowing the compiler to deduce template arguments for class templates from constructor arguments, and auto for non-type template parameters.
    C++20:
    Introduced Concepts, a powerful mechanism for constraining template parameters and improving error messages, as well as requires expressions for specifying constraints. 

Therefore, while you can use basic templates with older C++ standards, leveraging the full range of modern template features often benefits from using C++17 or C++20 for new projects. The specific standard you need depends on the particular template features you intend to utilize.

