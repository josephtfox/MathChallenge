/* File: MathReport.cpp
 * Course: CS215-003
 * Project: Project 3
 * Purpose: to declare the class named MathReport
 * Author: Tanner Fox
 */

#include <iostream>
#include <vector>
#include <list>
#include "MathReport.h"
#include "MathOperations.h"

using namespace std;

// default constructor
MathReport::MathReport()
{
    numCorrectAnswers = 0;  // number of correctly answered questions
    numWrongAnswers = 0;  // number of wrong answers
    vector<MathOperations> mathQuestions; // sequence of questions
    list<MathOperations> errorList;  // sequence of questions with wrong answers, need to practice more
}

// add a newQuestion into the vector of mathQuestions
// and the response to check with the correct answer: 
//    if response is correct, increase numCorrectAnswers
//    otherwise, increase numWrongAnswers and also insert newQuestion to errorList
void MathReport::insert(MathOperations newQuestion, int response)
{
    mathQuestions.push_back(newQuestion);
    if (newQuestion.checkAnswer(response))
    {
        numCorrectAnswers += 1;
    }
    else
    {
        numWrongAnswers += 1;
        errorList.push_back(newQuestion);
    }
}

// return the value of numCorrectAnswers
int MathReport::getNumOfCorrectAnswers() const
{
    return numCorrectAnswers;
}

// return the value of numWrongAnswers
int MathReport::getNumOfWrongAnswers() const
{
    return numWrongAnswers;
}

// generate a brief report
// if showAnswer is true, display questions solved with correct answers
//                 otherwise, display questions solved without answers
void MathReport::generateReport(bool showAnswer) const
{
    cout << "You have solved the following " << mathQuestions.size() << " math problems:" << endl << endl;

    if (showAnswer == true)
    {
        for (int i = 0; i < mathQuestions.size(); i++)
        {
            cout << "Question " << i + 1 << " :" << endl;
            mathQuestions[i].print();
            cout << mathQuestions[i].getAnswer() << endl << endl;
        }
    }
    else
    {
        for (int i = 0; i < mathQuestions.size(); i++)
        {
            cout << "Question " << i + 1 << " :" << endl;
            mathQuestions[i].print();
            cout << endl << endl;
        }
    }
    cout << "----------------------------------" << endl << "You answered " << getNumOfCorrectAnswers() << " questions correctly." << endl << "You made " << getNumOfWrongAnswers() << " mistakes." << endl;
    if (getNumOfCorrectAnswers() > getNumOfWrongAnswers())
    {
        cout << "Great job!" << endl;
    }
    else
    {
        cout << "You will do better next time..." << endl;
    }
}

// display the questions in errorList for practice again
// return false if all questions in errorList have been corrected and removed from the errorList
// otherwise return true: errorList is not empty yet, need more practice
bool MathReport::needMorePactice()
{
    int response;

    for (list<MathOperations>::iterator it = errorList.begin(); it != errorList.end();)
    {
        //creates the new question from the error list to fix
        MathOperations question = *it;

        //asks the user for their respsonse
        response = question.collectUserAnswer();

        if (question.checkAnswer(response))
        {
            it = errorList.erase(it);
            cout << "Congratulations! " << response << " is the right answer." << endl;
        }
        else
        {
            cout << "Sorry, the answer is wrong. You may practice again." << endl;
        }
    }
    // Determining if the list is empty or not
    if (errorList.empty())
    {
        return false;
    }
    else
    {
        return true;
    }
}
