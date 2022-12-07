/* File: MathOperations.cpp
 * Course: CS215-003
 * Project: Project 3
 * Purpose: to declare the class named MathOperations
 * Author: Tanner Fox
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "MathOperations.h"

using namespace std;

// default constructor
MathOperations::MathOperations()
{
    operand1 = 0;
    operand2 = 0;
    theoperator = ' ';
    answer = 0;
}

// set the private data members: operand1 and operand2
// to op1 and op2 respectively
void MathOperations::setOperands(int op1, int op2)
{
    operand1 = op1;
    operand2 = op2;
}

// get the current value of the private data member: theoperator
char MathOperations::getOperator() const
{
    return theoperator;
}

// return the value of the data member: answer
int MathOperations::getAnswer() const
{
    return answer;
}

// set theoperator to '+'
// apply the addition operation to operand1 and operand2
// set the answer equal to operand1 + operand2
void MathOperations::Addition()
{
    theoperator = '+';
    answer = operand1 + operand2;
}

// set theoperator to '-'
// apply the subtraction operation to operand1 and operand2
// set the answer equal to operand1 - operand2
void MathOperations::Subtraction()
{
    theoperator = '-';
    answer = operand1 - operand2;
}

// set theoperator to '*'
// apply the multiplication operation to operand1 and operand2
// set the answer equal to operand1 * operand2
void MathOperations::Multiplication()
{
    theoperator = '*';
    answer = operand1 * operand2;
}

// set theoperator to const DivisionSymbol, it is ASCII code for obelus
// apply the division operation to operand1 and operand2
// set the answer equal to operand1 ÷ operand2
void MathOperations::Division()
{
    theoperator = DivisionSymbol;
    answer = operand1 / operand2;
}

// if answer == response, it returns true
// otherwise it returns false
bool MathOperations::checkAnswer(int response) const
{
    if (answer == response)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//display the question in the format described in the problem statement
// for example:
//    135
//  +  78
//  _____
//
void MathOperations::print() const
{
    cout << " " << setw(MAXDIGITS) << operand1 << endl << theoperator << setw(MAXDIGITS) << operand2 << endl << "-----" << endl;
}

// display the question by calling print() first
// then ask the user for the answer
// it returns the valid user answer collected from the user input
int MathOperations::collectUserAnswer() const
{
    print();
    bool valid_input = false;
    int input = 0;
    do
    {
        cout << "Please type your answer: ";
        cin >> input;
        if (cin.fail())
        {
            cin.clear();
            cout << "Invalid input! Please try again..." << endl;
            valid_input = false;
        }
        // else the number is valid then break the loop
        else
        {
            valid_input = true;
        }
        cin.ignore(256, '\n');
    } while (!valid_input);
    return input;
}