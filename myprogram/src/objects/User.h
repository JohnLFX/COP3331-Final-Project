#ifndef INC_3331PROJECT_CREDENTIALS_H
#define INC_3331PROJECT_CREDENTIALS_H

#include <string>
#include <iostream>

using namespace std;

class User {

private:
    string username, password;

public:
    User(string username, string password) {
        this->username = username;
        this->password = password;
    }

    string getUsername() {
        return this->username;
    }

    string getPassword() {
        return this->password;
    }

    void write(ostream &out) {
        out << this->getUsername() << " " << this->getPassword();
    }

    static User prompt() {

        cout << "Enter username: ";

        string username, password;

        cin >> username;
        cin.ignore();

        cout << "Enter password for " << username << ": ";
        getline(cin, password);
        cout << endl;

        return User(username, password);

    }

};


#endif //INC_3331PROJECT_CREDENTIALS_H
