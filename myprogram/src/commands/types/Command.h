#ifndef INC_3331PROJECT_COMMAND_H
#define INC_3331PROJECT_COMMAND_H

#include <cstring>
#include <sstream>
#include <climits>
#include "../../FinalProject.h"
#include "../../objects/Pwdg.h"

class Command {

public:

    /**
     * Executes the command
     */
    virtual void execute() {};

    Command(int commandID, FinalProject *finalProject) : finalProject(finalProject), commandID(commandID) {};

protected:
    FinalProject *finalProject;

    unsigned int promptForExamID() {

        cout << "Enter Exam ID: ";

        int examID;
        cin >> examID;

        if (!cin.good()) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            __throw_invalid_argument("Input received was not an integer");
        }

        if (examID <= 0)
            __throw_invalid_argument(
                    "Exam IDs are sequential in order and starts at 1. (Expected ID > 0, got ID <= 0)");

        if (examID > 0)
            examID -= 1;

        return (unsigned int) examID;
    }

    vector<unsigned int> promptForAllExamScores() {

        cout << "Enter each exam score in one line, separated by a space: " << endl;

        string input;
        getline(cin, input);

        istringstream inSS;
        inSS.str(input);

        unsigned int score;

        vector<unsigned int> scores;

        while (!inSS.eof()) {
            inSS >> score;

            if (inSS.fail()) {

                inSS.clear();
                inSS.ignore(INT_MAX, ' ');

            } else {

                if (score < 0 || score > 100)
                    __throw_invalid_argument("Exam score must be between 0-100, inclusive");

                scores.push_back(score);

            }
        }

        return scores;

    }

    unsigned int promptForSingleExamScore() {

        cout << "Enter Exam Score: ";

        int examScore;
        cin >> examScore;

        if (!cin.good()) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            __throw_invalid_argument("Input received was not an integer");
        }

        if (examScore < 0 || examScore > 100)
            __throw_invalid_argument("Exam score must be between 0-100, inclusive");

        return (unsigned int) examScore;
    }

    string promptForStudentID() {

        cout << "Enter Student ID: ";

        string id;
        getline(cin, id);

        if (id.length() != 4)
            __throw_invalid_argument("Student ID must be only 4 characters in length. (E.g. U103)");

        char idChars[5];
        strcpy(idChars, id.c_str());

        if (idChars[0] != 'U')
            __throw_invalid_argument("Student ID must start with a 'U' character. (E.g. U103)");

        for (unsigned int i = 1; i < 4; i++)
            if (!isdigit(idChars[i]))
                __throw_invalid_argument("The last three characters of a Student ID must be digits. (E.g. U103)");

        return id;

    }

    string promptForOptionalRandomPassword() {

        cout << "Do you want a randomly generated password? (Y/N): ";

        char choice;
        cin >> choice;

        if (choice == 'Y' || choice == 'y') {

            int length;
            cout << "Enter length of password: ";
            cin >> length;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                __throw_invalid_argument("Invalid input - Not a positive integer.");
            }

            if (length <= 0)
                __throw_invalid_argument("Invalid password length. Length must be greater than 0.");

            string password;

            cout << "Want a strong password? (Y/N): ";
            cin >> choice;

            if (choice == 'Y' || choice == 'y') {

                Strong_pwdg pwdg(length);
                password = pwdg.getStrongPWD();

            } else {

                cout << "Want a password containing digits only? (Y/N): ";
                cin >> choice;

                if (choice == 'Y' || choice == 'y') {

                    Simple_pwdg pwdg(length);
                    password = pwdg.getSimplePWD('D');

                } else {

                    cout << "Want a password containing letters only? (Y/N): ";
                    cin >> choice;

                    if (choice == 'Y' || choice == 'y') {

                        Simple_pwdg pwdg(length);
                        password = pwdg.getSimplePWD('L');

                    } else {

                        Pwdg pwdg(length);
                        password = pwdg.getPWD();

                    }

                }

            }

            cout << "Generated password: " << password << endl;
            return password;

        }

        return "";

    }

private:
    int commandID;

};


#endif //INC_3331PROJECT_COMMAND_H
