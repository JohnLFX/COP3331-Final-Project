#ifndef INC_3331PROJECT_COMMANDCREATENEWUSER_H
#define INC_3331PROJECT_COMMANDCREATENEWUSER_H

#include "types/AuthenticatedCommand.h"

class CommandCreateNewUser : public Command {

public:
    CommandCreateNewUser(FinalProject *finalProject) : Command(1, finalProject) {}

    void execute() {

        cout << "Enter the new username: ";

        string username, password;

        cin >> username;
        cin.ignore();

        password = this->promptForOptionalRandomPassword();

        if (password.empty()) {
            cout << "Enter password for the new user " << username << ": ";
            cin.ignore(BC_STRING_MAX, '\n');
            getline(cin, password);
            cout << endl;
        }

        this->finalProject->authenticationDatabase.createUser(User(username, password));

    }

};


#endif //INC_3331PROJECT_COMMANDCREATENEWUSER_H
