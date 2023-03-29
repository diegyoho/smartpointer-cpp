#include "SharedPointer.h"

int main()
{
    SmartPointer::SharedPointer<int> integer = SmartPointer::MakeShared<int>(42);
    SmartPointer::SharedPointer<int> integer2 = SmartPointer::MakeShared<int>(44);
    integer.Reset(integer2.Get());
    
    return 0;
}
