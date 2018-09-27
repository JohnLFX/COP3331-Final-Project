#ifndef INC_3331PROJECT_COMMANDAVGSCOREOFSTUDENT_H
#define INC_3331PROJECT_COMMANDAVGSCOREOFSTUDENT_H


#include <iomanip>
#include "types/AuthenticatedCommand.h"

class CommandAvgScoreOfStudent : public AuthenticatedCommand {

public:
    CommandAvgScoreOfStudent(FinalProject *finalProject) : AuthenticatedCommand(5, finalProject) {}

    void execute() {
        AuthenticatedCommand::execute();

        string studentID = this->promptForStudentID();

        Student student = this->finalProject->studentDatabase.getStudent(studentID);

        int sum = 0;

        for (unsigned int i = 0; i < student.getExamsCount(); i++)
            sum += student.getExamScore(i);

        float average = (float) sum / student.getExamsCount();

        cout << "Average Exam Score for " << studentID << ": " << fixed << setprecision(2) << average << endl;

    }

};


#endif //INC_3331PROJECT_COMMANDAVGSCOREOFSTUDENT_H
