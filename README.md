# Arithmetic calculation Library

This library provides functionality for arithmetic calculations in string calculator for C language.

## Build

To build the library, please follow the steps below:
1. Clone the repository
2. Run `make` in the project directory.

## Usage

After building the library, you can use it by including the `calculation.h` header file and calling the `calculation` function in your C code. The `calculation` function takes a deque of lexemes in Reverse Polish Notation and a double value for the variable `x`, and returns a double value which is the result of the calculation.

## Dependencies

This library depends on the following libraries:
* C Standard Library
* Math Library

## Development

To contribute to this library, please follow the steps below:
1. Clone the repository
2. Run `make` in the project directory to build the library.
3. Make changes to the source code.
4. Run `make` again to rebuild the library.
5. Test your changes.
6. Submit a pull request.

## License

This library is licensed under the MIT License.

## Example Build and Usage

Assuming the library is built as `ArithmeticCalculation.a` and the following code is in a file named `main.c`.

```c
#include <stdio.h>
#include "calculation.h"

int main() {
  lexeme_t *lexemes = NULL;
  Deque *rpn = init_deque();

  // populate lexemes and rpn with appropriate values

  double result = calculation(rpn, 5.0);

  printf("Result: %lf\n", result);
  return 0;
}
```

To compile and link the code with the library:

```bash
$ gcc -c main.c -o main.o
$ gcc main.o -L. -ArithmeticCalculation -o calculator
```

This will create an executable named `calculator`. Running it will print the result of the calculation.

```bash
$ ./calculator
Result: 25.000000
```