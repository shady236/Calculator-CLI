# Calculator CLI

### This is a calculator that calculates expressions passed through the command line. Expressions can have numbers, spaces, operators, functions, parentheses and the constant e.


## Compiling & Running:
To compile the source code, just cd to the local directory, and type:

```gcc -g main.c str.c Stack.c Operator.c Function.c Calculator.c -o calc -lm```

To run the tool after compilation, use the following command:

```./calc <expression>```

Where ```<expression>``` is the expression to be evaluated. 

Note: If ```<expression>``` has spaces, it should be enclosed in double quotes "".


## Available operators:
The tool supports the following operators:
* '+' for addition.
* '-' for subtraction.
* '*' for multiplication.
* '/' for division.
* '^' for power.

Example of usage:

```./calc "3^2.0 + 12 * -1.24 - 5(3 - 14) * e^(3/2)"```

Output: 

```3^2.0 + 12 * -1.24 - 5(3 - 14) * e^(3/2) = 240.612899```


## Available Functions:
The tool supports the following operators:
* 'log' for logarithm to the base e.
* 'sqrt' for square root.
* 'fact' for factorial.
* 'abs' for absolute value.
* 'sin' for sin of an angle in degrees.
* 'cos' for cos of an angle in degrees.
* 'tan' for tan of an angle in degrees.

The function parameter should be enclosed in parentheses ().

Example of usage:

```./calc "sin(30) + cos(60) + e^log(sqrt(8 fact(2)))"```

Output: 

```sin(30) + cos(60) + e^log(sqrt(8 fact(2))) = 5.000000```


