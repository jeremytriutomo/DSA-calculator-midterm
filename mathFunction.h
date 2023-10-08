#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//=======================================MATH FUNCTIONS=======================================
class MathFunctions
{
public:
    double value;
    // Calculate the sine of the value stored in 'value'.
    double sine()
    {
        return sin(value);
    }

    // Calculate the cosine of the value stored in 'value'.
    double cosine()
    {
        return cos(value);
    }

    // Calculate the tangent of the value stored in 'value'.
    double tangent()
    {
        // Add special handling if cos(value) == 0.
        if (cos(value) == 0)
        {
            std::cout << "tan(" << value << ") is not defined." << std::endl;
            throw std::invalid_argument("tan()");
        }
        return tan(value);
    }

    // Calculate the square root of the value stored in 'value'.
    double squareRoot()
    {
        // Add special handling for negative values.
        if (value < 0)
        {
            std::cout << "sqrt(" << value << ") is not defined for negative numbers." << std::endl;
            throw std::invalid_argument("sqrt()");
        }
        return sqrt(value);
    }

    // Calculate the exponential (e^x) of the value stored in 'value'.
    double exponential()
    {
        return exp(value);
    }

    // Calculate the base 10 logarithm of the value stored in 'value'.
    double logarithm()
    {
        // Add special handling for non-positive values.
        if (value <= 0)
        {
            std::cout << "log(" << value << ") is not defined for non-positive numbers." << std::endl;
            throw std::invalid_argument("log()");
        }
        return log10(value);
    }

    // Calculate the natural logarithm (ln) of the value stored in 'value'.
    double naturalLogarithm()
    {
        // Add special handling for non-positive values.
        if (value <= 0)
        {
            std::cout << "ln(" << value << ") is not defined for non-positive numbers." << std::endl;
            throw std::invalid_argument("ln()");
        }
        return log(value);
    }

    // Basic arithmetic operations:

    // Add the 'operand' value to 'value' and return the result.
    double addition(double operand)
    {
        return value + operand;
    }

    // Subtract the 'operand' value from 'value' and return the result.
    double subtraction(double operand)
    {
        return value - operand;
    }

    // Multiply 'value' by the 'operand' value and return the result.
    double multiplication(double operand)
    {
        return value * operand;
    }

    // Divide 'value' by the 'operand' value and return the result.
    double division(double operand)
    {
        // Add special handling for division by zero (operand is zero).
        if (operand == 0)
        {
            std::cout << "Error! It's a division by ZERO\n";
            throw std::invalid_argument("Error! It's a division by 10");
        }
        return value / operand;
    }
};
//=======================================MATH FUNCTIONS=======================================

//=======================================TERM CLASS===========================================
class Terms
{
    MathFunctions calculate;

private:
    double operand1;
    string ops;
    double operand2;
    double result;

public:
    void set_value(double operand_1, char operators, double operand_2) // assigning the values
    {
        operand1 = operand_1;
        ops = operators;
        operand2 = operand_2;

        calculate.value = operand1;
    }

    double set_result()
    {

        if (ops == "+")
        {
            result = calculate.addition(operand2);
        }

        else if (ops == "-")
        {
            result = calculate.subtraction(operand2);
        }

        else if (ops == "/")
        {
            result = calculate.division(operand2);
        }

        else if (ops == "*")
        {
            result = calculate.multiplication(operand2);
        }

        else if (ops == "S" || ops == "s")
        {
            result = calculate.sine();
        }

        else if (ops == "C" || ops == "c")
        {
            result = calculate.cosine();
        }

        else if (ops == "T" || ops == "t")
        {
            result = calculate.tangent();
        }

        else if (ops == "L" || ops == "l")
        {
            result = calculate.logarithm();
        }

        else if (ops == "N" || ops == "n")
        {
            result = calculate.naturalLogarithm();
        }

        else if (ops == "R" || ops == "r")
        {
            result = calculate.squareRoot();
        }

        else if (ops == "^")
        {
            result = calculate.exponential();
        }

        return result;
    }

    void get_result() // printing result
    {
        cout << operand1 << " " << ops << " " << operand2 << " = " << result;
    }
};
//=======================================TERM CLASS===========================================

//=======================================LINKED LIST=======================================
struct Node
{
    Terms *data; // Each node stores a pointer to a Terms object
    Node *next;  // Each node stores a pointer to the next node in the list

    Node(double operand1, char ops, double operand2, double result) : next(nullptr)
    {
        data = new Terms();                       // Create a new Terms object and initialize the Node's data member
        data->set_value(operand1, ops, operand2); // Set the values of the Terms object
        data->set_result();                       // Calculate the result of the Terms object
    }
};

class LinkedList
{
private:
    Node *head; // The head points to the first node in the linked list

public:
    LinkedList() : head(nullptr) {} // Constructor to initialize the linked list with a null head pointer

    void insert(double operand1, char ops, double operand2, double result)
    {
        Node *newNode = new Node(operand1, ops, operand2, result); // Create a new Node to add the calculated result to the linked list

        if (!head) // If the list is empty, set the new node as the head
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next) // Iterate through the list to find the last node
            {
                current = current->next;
            }
            current->next = newNode; // Add the new node to the end of the list
        }
    }

    void showHistory()
    {
        Node *current = head;

        while (current) // Iterate through the list and display the history of operations
        {
            current->data->get_result();
            current = current->next;
        }
        cout << endl;
    }

    void deleteHistory()
    {
        Node *current = head;

        while (current != nullptr) // Iterate through the list and delete each node and its data
        {
            Node *next = current->next;
            delete current->data;
            delete current;
            current = next;
        }
        head = nullptr; // Set the head to null to indicate an empty list
    }
};
//=======================================LINKED LIST=======================================