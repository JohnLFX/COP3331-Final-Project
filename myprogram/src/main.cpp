#include <iostream>

#include <stdexcept>
#include "FinalProject.h"
#include "commands/CommandCreateNewUser.h"
#include "commands/CommandDisplayScoresOfStudent.h"
#include "commands/CommandChangePassword.h"
#include "commands/CommandDisplayScoresOfExam.h"
#include "commands/CommandAvgScoreOfStudent.h"
#include "commands/CommandAvgScoreOfExam.h"
#include "commands/CommandInsertScoresNewExamAll.h"
#include "commands/CommandInsertNewStudent.h"
#include "commands/CommandUpdateStudentExamScore.h"
#include "commands/CommandCurveExamScores.h"

using namespace std;

void displayMenu();

int main() {

    cout << "COP3331 Final Project" << endl;

    try {

        FinalProject finalProject = {};

        CommandCreateNewUser commandCreateNewUser(&finalProject);
        CommandChangePassword commandChangePassword(&finalProject);
        CommandDisplayScoresOfStudent commandDisplayScoresOfStudent(&finalProject);
        CommandDisplayScoresOfExam commandDisplayScoresOfExam(&finalProject);
        CommandAvgScoreOfStudent commandAvgScoreOfStudent(&finalProject);
        CommandAvgScoreOfExam commandAvgScoreOfExam(&finalProject);
        CommandInsertScoresNewExamAll commandInsertScoresNewExamAll(&finalProject);
        CommandInsertNewStudent commandInsertNewStudent(&finalProject);
        CommandUpdateStudentExamScore commandUpdateStudentExamScore(&finalProject);
        CommandCurveExamScores commandCurveExamScores(&finalProject);

        int menuOption = -1;

        while (menuOption != 11) {

            cout << endl;
            displayMenu();
            cout << endl << "Choose an option: ";

            cin >> menuOption;

            if (!cin.good()) {

                cout << "Invalid menu option! Enter an integer 1-11, inclusive." << endl;

                cin.clear();
                cin.ignore(INT_MAX, '\n');

                continue;

            }

            try {

                switch (menuOption) {
                    case 1:
                        commandCreateNewUser.execute();
                        break;
                    case 2:
                        commandChangePassword.execute();
                        break;
                    case 3:
                        commandDisplayScoresOfStudent.execute();
                        break;
                    case 4:
                        commandDisplayScoresOfExam.execute();
                        break;
                    case 5:
                        commandAvgScoreOfStudent.execute();
                        break;
                    case 6:
                        commandAvgScoreOfExam.execute();
                        break;
                    case 7:
                        commandInsertScoresNewExamAll.execute();
                        break;
                    case 8:
                        commandInsertNewStudent.execute();
                        break;
                    case 9:
                        commandUpdateStudentExamScore.execute();
                        break;
                    case 10:
                        commandCurveExamScores.execute();
                        break;
                    case 11:
                        // Will end next iteration
                        continue;
                    default:
                        cout << "No command exists with an ID of " << menuOption << endl;
                        continue;
                }

            } catch (invalid_argument &e) {

                cout << "Error: " << e.what() << endl;

            }

        }

    } catch (runtime_error &e) {

        cout << "Runtime Error: " << e.what() << endl;

    } catch (...) {
        cout << "An error has occurred." << endl;
    }

    cout << "Good bye" << endl;

    return 0;
}

void displayMenu() {

    cout << "(1) Create a new user" << endl
         << "(2) Change password" << endl
         << "(3) Display scores of a student" << endl
         << "(4) Display scores of an exam" << endl
         << "(5) Display avg score of a student (in a form like 72.84)" << endl
         << "(6) Display avg score of an exam (in a form like 69.33)" << endl
         << "(7) Insert scores of a new exam to all students" << endl
         << "(8) Insert scores of all exams of a student who is not in file" << endl
         << "(9) Update an exam score of a student" << endl
         << "(10) Update an exam score (with same amount such as 5 points or -3 points) of every student" << endl
         << "(11) Exit" << endl;

}

