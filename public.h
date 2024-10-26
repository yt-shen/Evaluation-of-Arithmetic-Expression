#include <iostream>
#include <string>

#define MAX_INPUT 100
#define VARIABLE_COUNT 58

using namespace std;

// Type of operations and their precedence.
typedef struct operation{
	int type;
	int precedence;
}operation;

// Value of variables; 'defined' is set to 1 only when the variable is defined.
typedef struct variable {
	double value;
	bool defined = 0;
}variable;

int type(string opera);
int precedence(int type);
bool check_variable(string input);
bool check_defined(string input[], int m, int n, variable v[]);
double compute(double x, double y, operation s);
double output(string input[], int m, int n, variable v[]);