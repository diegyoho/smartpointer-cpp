#include "SharedPointer.h"

int main()
{
    SmartPointer::SharedPointer<int> integer = SmartPointer::MakeShared<int>(42);
    SmartPointer::SharedPointer<int> integer2 = SmartPointer::MakeShared<int>(43);
    integer = integer2;

    return 0;
}
