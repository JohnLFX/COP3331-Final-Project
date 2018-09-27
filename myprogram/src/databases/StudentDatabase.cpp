#include <climits>
#include "StudentDatabase.h"

StudentDatabase::StudentDatabase() {
    this->students = vector<Student>();
    this->reloadData();
}

Student StudentDatabase::getStudent(string id) {

    for (unsigned int i = 0; i < this->students.size(); i++) {

        //cout << "Debug: " << this->students.at(i).getID() << " | " << id << endl;

        if (this->students.at(i).getID() == id) {

            return this->students.at(i);

        }

    }

    __throw_invalid_argument("No student found with that ID");

}

void StudentDatabase::saveStudent(Student student) {

    for (unsigned int i = 0; i < this->students.size(); i++) {

        if (this->students.at(i).getID() == student.getID()) {

            this->students.at(i) = student;
            this->saveData();
            return;

        }

    }

    this->students.push_back(student);
    this->saveData();

}

void StudentDatabase::saveData() {

    ofstream outDBFile("Data/scores.txt", ofstream::out);

    if (!outDBFile.is_open())
        throw runtime_error("Failed to open connection to student database for save operation");

    for (unsigned int i = 0; i < this->students.size(); i++) {

        Student student = this->students.at(i);

        outDBFile << student.getID() << " ";

        for (unsigned int j = 0; j < student.getExamsCount(); j++)
            outDBFile << student.getExamScore(j) << " ";

        outDBFile << endl;

    }

    outDBFile.close();

}

void StudentDatabase::reloadData() {

    //Clear the loaded data
    this->students.clear();

    ifstream inDBFile;

    inDBFile.open("Data/scores.txt", ios::in);

    if (!inDBFile.is_open())
        throw runtime_error("Failed to open connection to student database for load operation");

    string line;

    while (getline(inDBFile, line)) {

        istringstream inSS;

        inSS.str(line);

        string id;
        vector<unsigned int> scores;

        inSS >> id;

        if (id.empty())
            break;

        unsigned int score;

        while (!inSS.eof()) {
            inSS >> score;

            if (inSS.fail()) {

                inSS.clear();
                inSS.ignore(INT_MAX, ' ');

            } else {

                scores.push_back(score);

            }

        }

        //cout << "Debug: Loaded student " << id << " with " << scores.size() << " scores" << endl;

        this->students.push_back(Student(id, scores));

    }

    inDBFile.close();

}