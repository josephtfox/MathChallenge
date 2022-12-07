/* File: Program3.cpp
 * Course: CS215-003
 * Project: Project 3
 * Purpose: The main fucntion for the project 3 projgram:
 *          Creates a program for the user to be challenged on different math questions.
 *          The user chooses which kind of math problem they want to be challenged on and are given a randomized
 *          problem based on the certain criteria. The user input is validated and the input is determined to be correct or incorrect,
 *          if the user gets the problem incorrect it is added to the error list where the user is able to practice the problems that 
 *          they got wrong. They are then given a count of how many problems that got wrong and how many problems they got correct. 
 * Author: Tanner Fox
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <istream>
#include "MathOperations.h"
#include "MathReport.h"

using namespace std;

// creates a function for the menu to decide which problem the user wants to use
void menu() {
    cout << "       Math Is Fun! Take a challenge...\n";
    cout << "-------------------------------------\n";
    cout << "1. Addition problem\n";
    cout << "2. Multiplication problem\n";
    cout << "3. Division problem\n";
    cout << "4. Division problem\n";
    cout << "5. Quit this program\n";
    cout << "-------------------------------------\n";
    cout << "Enter your choice(1 - 5): ";
}

int main()
{
    // Intializes all of the constansts for the max and min of the opperands
    const int ADD_SUB_MAX = 500;
    const int ADD_SUB_MIN = 1;
    const int MULT_FIRST_MAX = 99;
    const int MULT_FIRST_MIN = 11;
    const int MULT_SEC_MAX = 9;
    const int MULT_SEC_MIN = 2;
   
    // Intializes the class objects
    MathReport userReport;

    // Intializes the bools to valid input 
    bool valid_input = false;

    // initializes the input of the menu
    int menu_input = 0;

    // do while loop for the challenge, only broken when choosing option 5
    do
    {
        // Initialize the class object for the question
        MathOperations question;

        // Intializes the numbers varibales for the opperands
        int num1 = 0;
        int num2 = 0;

        // do while loop for menu input validation
        do
        {
            menu();
            cin >> menu_input;
            if (cin.fail())
            {
                cin.clear();
                cout << "Invalid choice!" << endl;
                valid_input = false;
            }
            // else if the number is not 1-5 then input is not valid 
            else if (menu_input < 1 || menu_input > 5)
            {
                cin.clear();
                cout << "Invalid choice! The valid choices are 1, 2, 3, 4, and 5." << endl;
                valid_input = false;
            }
            // else input is valid and breaks the loop 
            else
            {
                valid_input = true;
            }
            cin.ignore(256, '\n');
        } while (!valid_input);

        int user_response = 0;
        switch (menu_input)
        {
            // Case for addition 
            case 1:
                num1 = rand() % ADD_SUB_MAX + ADD_SUB_MIN;
                num2 = rand() % ADD_SUB_MAX + ADD_SUB_MIN;
                question.setOperands(num1, num2);
                question.Addition();
                user_response = question.collectUserAnswer();
                question.checkAnswer(user_response);

                // validate if the users answer is correct or not
                if (question.checkAnswer(user_response))
                {

                    cout << "Congratulations! " << user_response << " is the right answer." << endl;
                }
                else
                {
                    cout << "Sorry, the answer is wrong. You may practice again." << endl;
                }

                userReport.insert(question, user_response);

                break;
            
            // Case for Subtraction
            case 2:
                num1 = rand() % ADD_SUB_MAX + ADD_SUB_MIN;
                num2 = rand() % ADD_SUB_MAX + ADD_SUB_MIN;
                if (num1 > num2)
                {
                    question.setOperands(num1, num2);
                }
                else
                {
                    question.setOperands(num2, num1);
                }
                question.Subtraction();
                user_response = question.collectUserAnswer();
                question.checkAnswer(user_response);

                // validate if the users answer is correct or not
                if (question.checkAnswer(user_response))
                {

                    cout << "Congratulations! " << user_response << " is the right answer." << endl;
                }
                else
                {
                    cout << "Sorry, the answer is wrong. You may practice again." << endl;
                }

                userReport.insert(question, user_response);

                break;

            // Case for Multiplication
            case 3:
                num1 = rand() % MULT_FIRST_MAX + MULT_FIRST_MIN;
                num2 = rand() % MULT_SEC_MAX + MULT_SEC_MIN;
                question.setOperands(num1, num2);
                question.Multiplication();
                user_response = question.collectUserAnswer();
                question.checkAnswer(user_response);

                // validate if the users answer is correct or not
                if (question.checkAnswer(user_response))
                {

                    cout << "Congratulations! " << user_response << " is the right answer." << endl;
                }
                else
                {
                    cout << "Sorry, the answer is wrong. You may practice again." << endl;
                }

                userReport.insert(question, user_response);

                break;

            // Case for Division
            case 4:
                int RS = rand() % MULT_FIRST_MAX + MULT_FIRST_MIN;
                num2 = rand() % MULT_SEC_MAX + MULT_SEC_MIN;
                num1 = RS * num2;
                question.setOperands(num1, num2);
                question.Division();
                user_response = question.collectUserAnswer();
                question.checkAnswer(user_response);

                // validate if the users answer is correct or not
                if (question.checkAnswer(user_response))
                {

                    cout << "Congratulations! " << user_response << " is the right answer." << endl;
                }
                else
                {
                    cout << "Sorry, the answer is wrong. You may practice again." << endl;
                }

                userReport.insert(question, user_response);

                break;
        }
    } while (menu_input != 5);

    bool morePractice = true;
    bool withAnswers = false;
    string user_input;

    if (userReport.getNumOfWrongAnswers() != 0)
    {
        morePractice = true;
    }
    else
    {
        morePractice = false;
    }

    switch (morePractice)
    {
        case true:
            userReport.generateReport(withAnswers);
            cout << "Do you want to practice the questions with wrong answers?" << endl << "(enter \"Q\" or \"q\" to quit)";
            getline(cin, user_input);
            if (user_input == "q" || user_input == "Q")
            {
                return 0;
            }
            morePractice = userReport.needMorePactice();
            withAnswers = true;
            break;

        case false:
            withAnswers = true;
            break;
    }
    userReport.generateReport(withAnswers);
    cout << "Thank you for using Math Tutor." << endl;
}