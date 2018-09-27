#ifndef INC_3331PROJECT_COMMANDDISPLAYSCORESOFEXAM_H
#define INC_3331PROJECT_COMMANDDISPLAYSCORESOFEXAM_H


#include "types/AuthenticatedCommand.h"

class CommandDisplayScoresOfExam : public AuthenticatedCommand {

public:
    CommandDisplayScoresOfExam(FinalProject *finalProject) : AuthenticatedCommand(4, finalProject) {};

    void execute() {
        AuthenticatedCommand::execute();

        unsigned int examID = this->promptForExamID();

        vector<Student> students = this->finalProject->studentDatabase.getStudents();

        if (students.empty())
            __throw_invalid_argument("No students are currently on file.");

        if (examID < 0 || examID >= students.at(0).getExamsCount())
            __throw_invalid_argument("The requested exam is currently not on file.");

        cout << "--- Scores for Exam " << (examID + 1) << " ---" << endl;

        for (unsigned int i = 0; i < students.size(); i++) {

            Student student = students.at(i);

            if (examID < student.getExamsCount())
                cout << student.getID() << ": " << student.getExamScore(examID) << endl;

        }

        cout << "---" << endl;

    }

};


#endif //INC_3331PROJECT_COMMANDDISPLAYSCORESOFEXAM_H
