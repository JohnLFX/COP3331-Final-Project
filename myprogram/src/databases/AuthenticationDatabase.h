#ifndef INC_3331PROJECT_AUTHENTICATIONDATABASE_H
#define INC_3331PROJECT_AUTHENTICATIONDATABASE_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdexcept>
#include "../objects/User.h"

using namespace std;

class AuthenticationDatabase {

public:
    AuthenticationDatabase();

    void verifyCredentials(User credentials);

    void changePassword(string username, string newPassword);

    void createUser(User credentials);

private:
    void saveData();

    void reloadData();

    int getUsernameIndex(string username);

    int getUsernameIndex(User credentials) {
        return this->getUsernameIndex(credentials.getUsername());
    }

    vector<User> loadedCredentials;

};


#endif //INC_3331PROJECT_AUTHENTICATIONDATABASE_H
