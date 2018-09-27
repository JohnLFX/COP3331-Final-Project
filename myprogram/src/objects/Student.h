#ifndef INC_3331PROJECT_STUDENT_H
#define INC_3331PROJECT_STUDENT_H

#include <string>
#include <vector>

using namespace std;

class Student {

private:
    string id;
    vector<unsigned int> examScores;

public:
    Student(string id, vector<unsigned int> examScores) {
        this->id = id;
        this->examScores = examScores;
    }

    string getID() {
        return this->id;
    }

    unsigned int getExamsCount() {
        return static_cast<unsigned int>(this->examScores.size());
    }

    unsigned int getExamScore(unsigned int examID) {
        if (examID < 0 || examID >= this->getExamsCount()) {
            std::ostringstream ss;
            ss << "Expected an exam ID within [0, " << (this->getExamsCount() - 1) << "], got " << examID
               << " instead.";
            __throw_invalid_argument(ss.str().c_str());
        }

        return this->examScores.at(examID);
    }

    void insertNewExamScore(unsigned int examScore) {
        if (examScore < 0 || examScore > 100)
            __throw_invalid_argument("Invalid exam score. Must be between 0-100, inclusive");

        this->examScores.push_back(examScore);
    }

    void setExamScore(unsigned int examID, unsigned int examScore) {
        if (examID < 0 || examID >= this->examScores.size())
            __throw_invalid_argument("An exam with that ID is currently not on file for this student");

        if (examScore < 0 || examScore > 100)
            __throw_invalid_argument("Invalid exam score. Must be between 0-100, inclusive");

        this->examScores.at(examID) = examScore;

    }

};


#endif //INC_3331PROJECT_STUDENT_H
