#ifndef INC_3331PROJECT_COMMANDAVGSCOREOFEXAM_H
#define INC_3331PROJECT_COMMANDAVGSCOREOFEXAM_H


#include "types/AuthenticatedCommand.h"

class CommandAvgScoreOfExam : public AuthenticatedCommand {

public:
    CommandAvgScoreOfExam(FinalProject *finalProject) : AuthenticatedCommand(6, finalProject) {}

    void execute() {
        AuthenticatedCommand::execute();

        unsigned int examID = this->promptForExamID();

        vector<Student> students = this->finalProject->studentDatabase.getStudents();

        if (students.empty())
            __throw_invalid_argument("No students are currently on file.");

        if (examID < 0 || examID >= students.at(0).getExamsCount())
            __throw_invalid_argument("The requested exam is currently not on file.");

        int sum = 0;
        int count = 0;

        for (unsigned int i = 0; i < students.size(); i++) {

            Student student = students.at(i);

            if (examID < student.getExamsCount()) {
                sum += student.getExamScore(examID);
                count++;
            }

        }

        if (count != 0) {

            float average = (float) sum / count;

            cout << "Average score for Exam " << (examID + 1) << ": " << fixed << setprecision(2) << average << endl;

        } else {

            throw invalid_argument("There are no scores available for that exam");

        }

    }

};


#endif //INC_3331PROJECT_COMMANDAVGSCOREOFEXAM_H
