#ifndef INC_3331PROJECT_STUDENTDATABASE_H
#define INC_3331PROJECT_STUDENTDATABASE_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "../objects/Student.h"

using namespace std;

class StudentDatabase {

public:
    StudentDatabase();

    Student getStudent(string id);

    void saveStudent(Student student);

    vector<Student> getStudents() {
        return this->students;
    }

private:
    vector<Student> students;

    void saveData();

    void reloadData();

};


#endif //INC_3331PROJECT_STUDENTDATABASE_H
