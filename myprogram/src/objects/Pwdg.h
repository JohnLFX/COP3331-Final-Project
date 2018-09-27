#ifndef INC_3331PROJECT_PWDG_H
#define INC_3331PROJECT_PWDG_H

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Pwdg {

private:
    int length;

public:
    Pwdg(int length) {
        this->length = length;
    }

    string getPWD() {

        char lookupTable[] = {
                '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                '!', '@', '#', '$', '%', '^', '&', '*', '+', '-', '='
        };

        return this->getPWD(lookupTable, 73);

    }

protected:
    string getPWD(const char lookupTable[], int tableSize) {

        string password;

        //Initialize seed used for rand
        srand(time(NULL));

        for (int i = 0; i < this->length; i++)
            password += (lookupTable[rand() % tableSize]);

        return password;

    }

};

class Simple_pwdg : public Pwdg {

public:
    Simple_pwdg(int length) : Pwdg(length) {}

    string getSimplePWD(char x) {

        switch (x) {
            case 'D': {

                char digitsTable[] = {
                        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
                };

                return this->getPWD(
                        digitsTable, 10
                );

            }

            case 'L': {

                char lettersTable[] = {
                        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
                };

                return this->getPWD(
                        lettersTable, 52
                );

            }

            default:
                return this->getPWD();
        }

    }

};

class Strong_pwdg : public Pwdg {

public:
    Strong_pwdg(int length) : Pwdg((length < 8) ? 8 : length) {}

    string getStrongPWD() {

        char lookupTable[] = {
                '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                '!', '@', '#', '$', '%', '^', '&', '*', '+', '-', '='
        };

        unsigned int requiredCharsSize = 4;

        srand(time(NULL));

        char requiredChars[] = {
                lookupTable[rand() % 10], //Digit
                lookupTable[10 + (rand() % 26)], //Upper Letter
                lookupTable[36 + (rand() % 26)], //Lower Letter
                lookupTable[62 + (rand() % 11)] //Symbol
        };

        cout << "Four mandatory random chars: ";

        for (int i = 0; i < requiredCharsSize; i++)
            cout << requiredChars[i] << " ";

        cout << endl;

        string password = this->getPWD();

        vector<int> replacedIndexes;
        replacedIndexes.reserve(requiredCharsSize);

        for (int i = 0; i < requiredCharsSize; i++) {

            int index;

            do {
                index = rand() % password.length();
            } while (std::find(replacedIndexes.begin(), replacedIndexes.end(), index) != replacedIndexes.end());

            password[index] = requiredChars[i];
            replacedIndexes.push_back(index);

            //cout << "Replaced index " << index << " with " << requiredChars[i] << endl;

        }

        return password;

    }

};


#endif //INC_3331PROJECT_PWDG_H
