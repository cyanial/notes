#include <iostream>

#include "TutorialConfig.h"

using std::cout;
using std::endl;

int main()
{
    cout << "Project Version: " << Tutorial_VERSION_MAJOR << "."
         << Tutorial_VERSION_MINOR << endl;

    cout << "myVar1: " << My_Var_1 << endl;
    cout << "myVar2: " << My_Var_2 << endl;

    return 0;
}