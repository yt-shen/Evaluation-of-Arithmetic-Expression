# Evaluation-of-Arithmetic-Expression

This is a simple expression evaluator written in C++. It can handle arithmetic operations and variable assignments, allowing users to input mathematical expressions and retrieve results or assign values to variables.

- Supports basic arithmetic operations: addition, subtraction, multiplication, and division.
- Handles parentheses for defining operation precedence.
- Allows the use of variables (a-z, A-Z) to store values.

# Description

The expression evaluator processes user input by reading a series of tokens, including numbers, operators, and variables. It maintains a storage system for these variables, tracking whether they have been defined.
Using a stack-based approach, the evaluator handles operations by comparing the precedence of encountered operators with those already in the stack, ensuring the correct order of operations. It also appropriately manages parentheses for nested expressions. 
After processing the expression, the evaluator outputs either the computed result or the value of the assigned variable, allowing users to perform complex calculations while adhering to mathematical conventions.

# How to use

Compile: `$ make`

Run the program: `$ ./main`

Here are some examples of how to use the expression evaluator:

1. **Basic Arithmetic**:
   - **Input**: `"(1 + 2) * (3 - 4) / 5"`
   - **Output**: `"-0.6"`

2. **Variable Assignment**:
   - **Input**: `"a = 1 + 2 * 3"`
   - **Output**: `"a = 7"`

3. **Using Previously Defined Variables**:
   - **Input**: `"b = (5 - 6) * a"`
   - **Output**: `"b = -7"`

4. ***Using Undefined Variables**:
   - **Input**: `"c = x - 8"`
   - **Output**: `"Error: Containing undefined variable(s)."`