#ifndef INC_3331PROJECT_COMMANDCURVEEXAMSCORES_H
#define INC_3331PROJECT_COMMANDCURVEEXAMSCORES_H


#include "types/AuthenticatedCommand.h"

class CommandCurveExamScores : public AuthenticatedCommand {
public:
    CommandCurveExamScores(FinalProject *finalProject) : AuthenticatedCommand(10, finalProject) {}

    void execute() {
        AuthenticatedCommand::execute();

        unsigned int examID = this->promptForExamID();

        cout << "Enter the score difference to update all exams with: ";

        int scoreDifference;
        cin >> scoreDifference;

        if (!cin.good()) {
            cin.clear();
            cin.ignore(INT_MAX, ' ');
            __throw_invalid_argument("Invalid input received. Must be an integer.");
        }

        vector<Student> students = this->finalProject->studentDatabase.getStudents();

        if (students.empty())
            __throw_invalid_argument("No students are currently on file.");

        int expectedExamsCount = students.at(0).getExamsCount();

        if (examID < 0 || examID >= expectedExamsCount)
            __throw_invalid_argument("There is no exam with that exam ID on file.");

        for (unsigned int i = 0; i < students.size(); i++) {
            Student student = students.at(i);

            int n = ((int) student.getExamScore(examID) + scoreDifference);
            const int newScore = max(0, std::min(n, 100));

            student.setExamScore(examID, (const unsigned int) newScore);

            this->finalProject->studentDatabase.saveStudent(student);

        }

        cout << "The Exam " << (examID + 1) << " score for all students have been successfully altered by "
             << scoreDifference << "." << endl;

    }

};


#endif //INC_3331PROJECT_COMMANDCURVEEXAMSCORES_H
