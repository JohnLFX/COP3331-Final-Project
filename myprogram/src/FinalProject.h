#ifndef INC_3331PROJECT_FINALPROJECT_H
#define INC_3331PROJECT_FINALPROJECT_H

#include <iostream>
#include "databases/AuthenticationDatabase.h"
#include "databases/StudentDatabase.h"

using namespace std;

class FinalProject {

public:
    AuthenticationDatabase authenticationDatabase;
    StudentDatabase studentDatabase;
};

#endif //INC_3331PROJECT_FINALPROJECT_H
