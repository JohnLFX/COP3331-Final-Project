#ifndef INC_3331PROJECT_COMMANDUPDATESTUDENTEXAMSCORE_H
#define INC_3331PROJECT_COMMANDUPDATESTUDENTEXAMSCORE_H


#include "types/AuthenticatedCommand.h"

class CommandUpdateStudentExamScore : public AuthenticatedCommand {

public:
    CommandUpdateStudentExamScore(FinalProject *finalProject) : AuthenticatedCommand(9, finalProject) {}

    void execute() {
        AuthenticatedCommand::execute();

        Student student = this->finalProject->studentDatabase.getStudent(this->promptForStudentID());

        unsigned int examID = this->promptForExamID();
        unsigned int examScore = this->promptForSingleExamScore();

        student.setExamScore(examID, examScore);

        this->finalProject->studentDatabase.saveStudent(student);

        cout << "Exam " << (examID + 1) << " score for " << student.getID() << " has been successfully changed to "
             << examScore << "." << endl;

    }

};


#endif //INC_3331PROJECT_COMMANDUPDATESTUDENTEXAMSCORE_H
