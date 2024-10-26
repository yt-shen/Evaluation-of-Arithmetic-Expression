# Evaluation-of-Arithmetic-Expression

This is a simple expression evaluator written in C++. It can handle arithmetic operations and variable assignments, allowing users to input mathematical expressions and retrieve results or assign values to variables.

- Supports basic arithmetic operations: addition, subtraction, multiplication, and division.
- Handles parentheses for defining operation precedence.
- Allows the use of variables (a-z, A-Z) to store values.

# Usage Examples

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