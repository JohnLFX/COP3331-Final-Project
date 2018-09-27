cmake_minimum_required(VERSION 2.8)
project(3331project)

set(CMAKE_CXX_STANDARD 98)

add_executable(3331project src/main.cpp src/databases/AuthenticationDatabase.cpp src/databases/AuthenticationDatabase.h src/objects/Student.h src/databases/StudentDatabase.cpp src/databases/StudentDatabase.h src/objects/User.h src/commands/types/Command.h src/commands/types/AuthenticatedCommand.h src/commands/CommandDisplayScoresOfStudent.h src/FinalProject.h src/commands/CommandCreateNewUser.h src/commands/CommandChangePassword.h src/commands/CommandDisplayScoresOfExam.h src/commands/CommandAvgScoreOfStudent.h src/commands/CommandAvgScoreOfExam.h src/commands/CommandInsertScoresNewExamAll.h src/commands/CommandInsertNewStudent.h src/commands/CommandUpdateStudentExamScore.h src/commands/CommandCurveExamScores.h src/objects/Pwdg.h)