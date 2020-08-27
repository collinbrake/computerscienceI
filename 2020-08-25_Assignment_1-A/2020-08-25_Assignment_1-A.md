Computer Science I, The University of Akron

Assignment 1-A

Collin Brake

Instructor: Lianghu Tian 

2020-08-27

Error Catalog:

1. Extra space between the `<` and the `iostream` file name:
    - #include errors detected. Please update your includePath. Squiggles are disabled for this translation unit
1. Omit one `<` symbol:
    - expected a file name 
1. Omit the `int` from the `int main()` declaration:
    - ISO C++ forbids declaration of ‘main’ with no type [-Wreturn-type]
1. Omit or mispell the word `main`:
    - the function did not run because it wasn't `
1. Omit one of the `()`, and then both:
    - main`'main' cannot be used as a global variable name or given C language linkage 
1. Mispell `cout` as `out`:
    - ‘out’ has not been declared in ‘std’, namespace "std" has no member "out", identifier "cout" is undefined
1. Omit one or more of the `<<` in a `cout` statement:
    - expression must have integral or unscoped enum type, 
1. Omit one or more of the `std::` in the `using std::cout` expression:
    - expected nested-name-specifier before ‘cout’, identifier "cout" is undefined 1.
1. Omit or comment out the `using std::endl` expression:
    - ‘endl’ was not declared in this scope; did you mean ‘std::endl’?
 1. Leave off the ending curly brace `}`:
    - expected ‘}’ at end of input 