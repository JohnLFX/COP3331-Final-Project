#ifndef INC_3331PROJECT_COMMANDINSERTNEWSTUDENT_H
#define INC_3331PROJECT_COMMANDINSERTNEWSTUDENT_H


#include "types/AuthenticatedCommand.h"

class CommandInsertNewStudent : public AuthenticatedCommand {

public:
    CommandInsertNewStudent(FinalProject *finalProject) : AuthenticatedCommand(8, finalProject) {}

    void execute() {
        AuthenticatedCommand::execute();

        string studentID = this->promptForStudentID();

        int examCount = 1;

        vector<Student> students = this->finalProject->studentDatabase.getStudents();

        for (unsigned int i = 0; i < students.size(); i++) {

            if (students.at(i).getID() == studentID)
                __throw_invalid_argument("A student with that ID already exists on file.");

            int count = students.at(i).getExamsCount();

            if (examCount == 1)
                examCount = count;
            else if (examCount != count)
                __throw_runtime_error("Could not determine the proper amount of exams each student had.");

        }

        vector<unsigned int> scores = this->promptForAllExamScores();

        if (scores.size() != examCount) {

            std::ostringstream ss;
            ss << "Expected " << examCount << " exam scores to be entered, got " << scores.size() << " scores instead.";
            __throw_invalid_argument(ss.str().c_str());

        }

        this->finalProject->studentDatabase.saveStudent(Student(studentID, scores));

        cout << "Exam scores for the new student have been saved successfully." << endl;

    }


};


#endif //INC_3331PROJECT_COMMANDINSERTNEWSTUDENT_H
