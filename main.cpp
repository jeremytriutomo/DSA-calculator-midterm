#include <iostream>
#include <string>
#include <cmath>
#include "mathFunction.h"
using namespace std;

int main()
{

    double user_operand1, user_operand2;
    char user_operator;

    // User interface
    cout << "============CALCULATOR==========" << endl;
    cout << "Format: 1st_Operand operator 2nd_Operand2" << endl;
    cout << "Example:   2 + 3" << endl;
    cout << "================================" << endl;

    cout << "\n==========Operator List=========" << endl;
    cout << "Addition: + " << endl;
    cout << "Subtraction: - " << endl;
    cout << "Division: /" << endl;
    cout << "Multiplication: *" << endl;
    cout << "Sine: S" << endl;
    cout << "Cosine: C" << endl;
    cout << "Tangent: T" << endl;
    cout << "Square Root: R" << endl;
    cout << "Logarithm: L" << endl;
    cout << "Natural Logarithm: N" << endl;
    cout << "================================" << endl;

    cout << "\nEnter your calculation:" << endl;

    cin >> user_operand1 >> user_operator >> user_operand2;

    // cout << "\nTesting parsing: " << endl;
    // cout << user_operand1 << endl;
    // cout << user_operator << endl;
    // cout << user_operand2 << endl;

    Terms term1;
    term1.set_value(user_operand1, user_operator, user_operand2);
    term1.set_result();
    term1.get_result();
}
