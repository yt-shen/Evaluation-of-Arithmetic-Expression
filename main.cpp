#include <iostream>
#include <string>
#include "public.h"

using namespace std;

int main() {
	string input[MAX_INPUT];
	variable v[VARIABLE_COUNT];
	char var;
	while (1) {
		int k = 0; // Length of input.
		for (int i = 0; i < MAX_INPUT; i++) {
			cin >> input[i];
			if (getchar() == '\n') {
				break;
			}
			k++;
		}
		// Regular expression evaluation.
		if (input[1] != "=") {
			if (!is_all_defined(input, 0, k, v)) {
				cout << "Error: Containing undefined variable(s).\n";
			}
			else {
				cout << calculate_result(input, 0, k, v) << '\n';
			}
		}
		// Variable assignment.
		else {
			if (!is_all_defined(input, 2, k, v)) {
				cout << "Error: Containing undefined variable(s).\n";
			}
			else {
				var = input[0][0];
				v[int(var) - 'A'].value = calculate_result(input, 2, k, v);
				v[int(var) - 'A'].defined = 1;
				cout << var << " = " << calculate_result(input, 2, k, v) << '\n';
			}
		}
	}

	return 0;
}