## **SquareSolver**
-------------------

Simple program for square equations solving.

Library with functions and testing system include.

## Compilation
--------------
Use ``make`` to compile in different modes

To compile main program in terminal:
```
$ make
```
To compile in testing mode in terminal:
```
$ make test
```

For documentation ``doxygen`` used

To make documentation in terminal:
```
$ doxygen config
```

## Usage
--------
You can solve **any kind** of square equations by just typing 3 coefficients of equation:
```
$ ./a
Введите коэффициенты квадратного уравнения: 1 -2 1
1 корень: 1.00
```

To test square solving you can write your own tests and run testing (***compile in testing mode***)
```
$ ./a tests.txt
[1] OK
[2] OK
[3] OK
...
[21] OK
21/21 passed
```

## What's included?
-----------------
- ``main.c``  and  ``test.c`` - source files for main program and testing system

- ``SquareSolver.h``  and  ``SquareSolver.c`` - a library for solving square equations

- ``UnitTesting.h``  and  ``UnitTesting.c`` - a library for unit testing

- ``SS_Errors.h`` - an error enumeration

- ``Colors.h`` - header file with constants for coloring output in terminal
