#ifndef INC_3331PROJECT_COMMANDDISPLAYSCORESOFSTUDENT_H
#define INC_3331PROJECT_COMMANDDISPLAYSCORESOFSTUDENT_H


#include "types/AuthenticatedCommand.h"

class CommandDisplayScoresOfStudent : public AuthenticatedCommand {

public:
    CommandDisplayScoresOfStudent(FinalProject *finalProject) : AuthenticatedCommand(3, finalProject) {};

    void execute() {
        AuthenticatedCommand::execute();

        string studentID = this->promptForStudentID();

        Student student = this->finalProject->studentDatabase.getStudent(studentID);

        cout << "--- Exam Scores for " << studentID << " ---" << endl;

        for (unsigned int i = 0; i < student.getExamsCount(); i++)
            cout << "Exam " << (i + 1) << ": " << student.getExamScore(i) << endl;

        cout << "---" << endl;

    }

};


#endif //INC_3331PROJECT_COMMANDDISPLAYSCORESOFSTUDENT_H
