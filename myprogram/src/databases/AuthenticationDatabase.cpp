#include "AuthenticationDatabase.h"

AuthenticationDatabase::AuthenticationDatabase() {
    this->reloadData();
}

void AuthenticationDatabase::verifyCredentials(User credentials) {

    int index = this->getUsernameIndex(credentials);

    if (index != -1) {

        if (this->loadedCredentials.at((unsigned int) index).getPassword() != credentials.getPassword())
            __throw_invalid_argument("Invalid password");

    } else {
        throw invalid_argument("Could not find user " + credentials.getUsername());
    }

}

void AuthenticationDatabase::changePassword(string username, string newPassword) {

    int index = this->getUsernameIndex(username);

    if (index != -1) {

        this->loadedCredentials.at((unsigned int) index) = User(username, newPassword);

        cout << "Password successfully changed for user " << username << endl;

        this->saveData();

    } else {
        throw invalid_argument("Could not find user " + username);
    }

}

void AuthenticationDatabase::createUser(User credentials) {

    int index = this->getUsernameIndex(credentials);

    if (index == -1) {

        this->loadedCredentials.push_back(credentials);

        cout << "Successfully created user " << credentials.getUsername() << endl;

        this->saveData();

    } else {
        throw invalid_argument("Username " + credentials.getUsername() + " already exists.");
    }

}

void AuthenticationDatabase::saveData() {

    ofstream outDBFile("User/passwords.txt", ofstream::out);

    if (!outDBFile.is_open())
        throw runtime_error("Failed to open connection to authentication database for save operation");

    for (unsigned int i = 0; i < this->loadedCredentials.size(); i++) {
        //cout << "Debug: Writing user " << this->loadedCredentials.at(i).getUsername() << endl;
        this->loadedCredentials.at(i).write(outDBFile);
        outDBFile << endl;
    }

    outDBFile.close();

}

void AuthenticationDatabase::reloadData() {

    //Clear the loaded data
    this->loadedCredentials.clear();

    ifstream inDBFile;

    inDBFile.open("User/passwords.txt", ios::in);

    if (!inDBFile.is_open())
        throw runtime_error("Failed to open connection to authentication database for load operation");

    while (!inDBFile.eof()) {

        string username, password;

        inDBFile >> username >> password;

        if (!username.empty()) {
            //cout << "Debug: Loaded user " << username << endl;
            this->loadedCredentials.push_back(User(username, password));
        }

    }

    inDBFile.close();

}

int AuthenticationDatabase::getUsernameIndex(string username) {

    if (username.empty())
        __throw_invalid_argument("Username is empty");

    for (unsigned int i = 0; i < this->loadedCredentials.size(); i++)
        if (this->loadedCredentials.at(i).getUsername() == username)
            return i;

    return -1;

}
