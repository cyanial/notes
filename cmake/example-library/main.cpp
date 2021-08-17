#include <iostream>

#include "mymath/mymath.h"

using std::cout;
using std::endl;

int main()
{
    MyMath::BasicOp op;
    cout << "1 + 1 = " << op.add(1, 1) << endl;
    cout << "2 - 1 = " << op.sub(2, 1) << endl;
    cout << "2 * 3 = " << op.mul(3, 2) << endl;
    cout << "6 / 3 = " << op.div(6, 3) << endl;

    return 0;
}