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

    int outer_loop = 1;

    while (outer_loop = 1)
    {

        LinkedList history;
        cout << "Type \"0X0\" and Enter to EXIT" << endl;
        cout << "\nEnter your calculation:";
        cin >> user_operand1 >> user_operator >> user_operand2;

        if (user_operand1 == 0 && (user_operator == 'X' || user_operator == 'x') && user_operand2 == 0)
        {
            break;
        }
        else
        {

            Terms term1;
            term1.set_value(user_operand1, user_operator, user_operand2);
            term1.set_result();
            term1.get_result();

            history.insert(term1.result);
            // cout << "\n History: " << endl;
            // history.print();

            int counter = 1;

            while (counter = 1)
            {
                user_operand1 = history.return_result();

                cout << "\n\nType \"H0\" and Enter to display HISTORY" << endl;
                cout << "Type \"X0\" and Enter to EXIT" << endl;
                cout << "\nEnter your calculation: " << user_operand1 << " ";
                cin >> user_operator >> user_operand2;

                // cout << "\nTesting parsing: " << endl;
                // cout << user_operand1 << endl;
                // cout << user_operator << endl;
                // cout << user_operand2 << endl;
                if (user_operator == 'X' || user_operator == 'x')
                {
                    counter = 0;
                    break;
                }
                else if (user_operator == 'H' || user_operator == 'h')
                {
                    cout << "\n History: " << endl;
                    history.print();
                    cout << "\nPress D to Delete Press C to Continue: ";
                    char user_history_input;
                    cin >> user_history_input;
                    if (user_history_input == 'D' || user_history_input == 'd')
                    {
                        history.clear();
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    Terms term2;
                    term2.set_value(user_operand1, user_operator, user_operand2);
                    term2.set_result();
                    term2.get_result();

                    history.insert(term2.result);
                }
            }
        }
    }
}
