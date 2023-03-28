#include "SharedPointer.h"

int main()
{
    SmartPointer::SharedPointer<int> integer = SmartPointer::MakeShared<int>(42);
    auto integer2{integer};
    SmartPointer::SharedPointer<int> integer3{};
    integer3 = integer2;
    return 0;
}
