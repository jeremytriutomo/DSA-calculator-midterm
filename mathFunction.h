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
