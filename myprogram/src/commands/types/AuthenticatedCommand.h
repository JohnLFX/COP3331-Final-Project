#ifndef INC_3331PROJECT_AUTHENTICATEDCOMMAND_H
#define INC_3331PROJECT_AUTHENTICATEDCOMMAND_H

#include "Command.h"

class AuthenticatedCommand : public Command {

public:
    AuthenticatedCommand(const int commandID, FinalProject *finalProject) : Command(commandID, finalProject) {}

    void execute() {

        cout << "Authentication is required for this command." << endl;

        this->finalProject->authenticationDatabase.verifyCredentials(User::prompt());

        cout << "Authentication attempt is successful." << endl;

    }

};


#endif //INC_3331PROJECT_AUTHENTICATEDCOMMAND_H
