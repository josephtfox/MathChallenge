#pragma once
/* File: MathOperations.h
 * Course: CS215-003
 * Project: Project 3
 * Purpose: to declare the class named MathOperations
 * Author: Tanner Fox
 */
#ifndef MATHOPERATIONS_H
#define MATHOPERATIONS_H

const int MAXDIGITS = 4;    // the maximum digits of operands or answers
const char DivisionSymbol = char(246);      // ASCII code for "�"

class MathOperations
{
public:
    // default constructor
    MathOperations();

    // set the private data members: operand1 and operand2
    // to op1 and op2 respectively
    void setOperands(int op1, int op2);

    // get the current value of the private data member: theoperator
    char getOperator() const;

    // return the value of the data member: answer
    int getAnswer() const;

    // set theoperator to '+'
    // apply the addition operation to operand1 and operand2
    // set the answer equal to operand1 + operand2
    void Addition();

    // set theoperator to '-'
    // apply the subtraction operation to operand1 and operand2
    // set the answer equal to operand1 - operand2
    void Subtraction();

    // set theoperator to '*'
    // apply the multiplication operation to operand1 and operand2
    // set the answer equal to operand1 * operand2
    void Multiplication();

    // set theoperator to const DivisionSymbol, it is ASCII code for obelus
    // apply the division operation to operand1 and operand2
    // set the answer equal to operand1 � operand2
    void Division();

    // if answer == response, it returns true
    // otherwise it returns false
    bool checkAnswer(int response) const;

    //display the question in the format described in the problem statement
    // for example:
    //    135
    //  +  78
    //  _____
    //
    void print() const;

    // display the question by calling print() first
    // then ask the user for the answer
    // it returns the valid user answer collected from the user input
    int collectUserAnswer() const;

private:
    int operand1;  // the first operand for basic math operation
    int operand2;  // the second operand for basic math operation
    char theoperator; // the current operator;
    int answer;    // the correct answer
};
#endif /*MATHOPERATIONS*/