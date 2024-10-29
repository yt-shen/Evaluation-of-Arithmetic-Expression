#include <iostream>
#include <string>

#define MAX_INPUT 100
#define VARIABLE_COUNT 58

using namespace std;

// 'precedence' is used to handle the order of operations.
typedef struct operation{
	int type;
	int precedence;
}operation;

// 'defined' is set to 1 only when the variable has been defined.
typedef struct variable {
	double value;
	bool defined = 0;
}variable;

int get_type(string opera);
int get_precedence(int type);
bool is_variable_valid(string input);
bool is_all_defined(string input[], int m, int n, variable v[]);
double compute(double x, double y, operation s);
double calculate_result(string input[], int m, int n, variable v[]);