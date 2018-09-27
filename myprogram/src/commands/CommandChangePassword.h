#ifndef INC_3331PROJECT_COMMANDCHANGEPASSWORD_H
#define INC_3331PROJECT_COMMANDCHANGEPASSWORD_H

#include "types/AuthenticatedCommand.h"

class CommandChangePassword : public AuthenticatedCommand {

public:
    CommandChangePassword(FinalProject *finalProject) : AuthenticatedCommand(2, finalProject) {}

    void execute() {
        AuthenticatedCommand::execute();

        cout << "Enter username to change password for: ";

        string username, password;

        cin >> username;
        cin.ignore();

        password = this->promptForOptionalRandomPassword();

        if (password.empty()) {
            cout << "Enter the new password for " << username << ": ";
            cin.ignore(BC_STRING_MAX, '\n');
            getline(cin, password);
            cout << endl;
        }

        this->finalProject->authenticationDatabase.changePassword(username, password);

    }

};


#endif //INC_3331PROJECT_COMMANDCHANGEPASSWORD_H
