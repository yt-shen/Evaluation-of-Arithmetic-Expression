#include "public.h"

// Define the type of operations.
int type(string opera) {
	if (opera == "(") return 1;	
	if (opera == "+") return 2;
	if (opera == "-") return 3;
	if (opera == "*") return 4;
	if (opera == "/") return 5;
	if (opera == ")") return 6;
	return 0;
}

// The precedence of operations.
int precedence(int type) {
	switch (type) {
	case 1: return 1; // '(' has the lowest precedence.
	case 2:case 3: return 2; // '+' and '-' have medium precedence.
	case 4:case 5: return 3; // '*' and '/' have the highest precedence.
	case 6: return 4; // When ')' appears, compute until the previous '('.
	}
	return 0;
}

// Check if the input is valid.
bool check_variable(string input) {
	return input.length() == 1 && isalpha(input[0]);
}

// Check if all the variables in the expression are defined.
bool check_defined(string input[], int m, int n, variable v[]) {
	bool def = 1;
	char var;
	for (int i = m; i <= n; i++) {
		if (check_variable(input[i])) {
			var = input[i][0];
			// Mark as false if any variable is undefined.
			if (!v[int(var) - 'A'].defined) {
				def = 0;
			}
		}
	}
	return def;
}

// Compute the value according to the operation.
double compute(double x, double y, operation s) {
	switch (s.type) {
	case 2:return x + y;
	case 3:return x - y;
	case 4:return x * y;
	case 5:return x / y;
	}
	return 0;
}

// Evaluate the expression and return the result.
double output(string input[], int m, int n, variable v[]) {
	double number[MAX_INPUT]; // Stack for numbers.
	operation symbol[MAX_INPUT]; // Stack for symbols.
	symbol[0].precedence = 0;
	int s = 0; // Stack pointer for numbers.
	int t = 1; // Stack pointer for symbols.
	char var;
	for (int i = m; i <= n; i++) {
		if (input[i] == ")") {
			while (1) {
				// Compute until the previous '('.
				if (symbol[t - 1].type == 1) {
					t--;
					break;
				}
				else {
					number[s - 2] = compute(number[s - 2], number[s - 1], symbol[t - 1]);
					s--;
					t--;
				}				
			}
		}
		else if (input[i] == "(") {
			symbol[t].type = type(input[i]);
			symbol[t].precedence = precedence(symbol[t].type);
			t++;
		}
		else if (input[i] == "+" || input[i] == "-" || input[i] == "*" || input[i] == "/") {
			// Process operators with higher precedence in the stack.
			while (symbol[t - 1].precedence >= precedence(type(input[i]))) {
				// Compute the first 2 numbers in the stack, then put the result back.
				number[s - 2] = compute(number[s - 2], number[s - 1], symbol[t - 1]);
				s--;
				t--;
			}
			symbol[t].type = type(input[i]);
			symbol[t].precedence = precedence(symbol[t].type);
			t++;
		}
		else if (check_variable(input[i])) {
			var = input[i][0];
			number[s] = v[int(var) - 'A'].value;
			s++;
		}
		else {
			number[s] = atof(input[i].c_str());
			s++;
		}
	}
	// Finish computing remaining operations.
	while (t - 1) {
		s--;
		t--;
		number[s - 1] = compute(number[s - 1], number[s], symbol[t]);
	}
	return number[0];
}