#ifndef INC_3331PROJECT_COMMANDINSERTSCORESNEWEXAMALL_H
#define INC_3331PROJECT_COMMANDINSERTSCORESNEWEXAMALL_H


#include "types/AuthenticatedCommand.h"

class CommandInsertScoresNewExamAll : public AuthenticatedCommand {

public:
    CommandInsertScoresNewExamAll(FinalProject *finalProject) : AuthenticatedCommand(7, finalProject) {}

    void execute() {
        AuthenticatedCommand::execute();

        vector<unsigned int> scores = this->promptForAllExamScores();
        vector<Student> students = this->finalProject->studentDatabase.getStudents();

        if (scores.size() != students.size()) {

            std::ostringstream ss;
            ss << "Expected " << students.size() << " exam scores to be entered (for each student on file), got "
               << scores.size() << " scores instead.";
            __throw_invalid_argument(ss.str().c_str());

        }

        for (unsigned int i = 0; i < students.size(); i++) {

            Student student = students.at(i);
            student.insertNewExamScore(scores.at(i));

            this->finalProject->studentDatabase.saveStudent(student);

        }

        cout << "Exam scores have been successfully added to all students in file." << endl;

    }

};


#endif //INC_3331PROJECT_COMMANDINSERTSCORESNEWEXAMALL_H
