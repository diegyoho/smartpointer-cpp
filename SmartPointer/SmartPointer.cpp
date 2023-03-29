#include <iostream>

#include "SharedPointer.h"

int main()
{
    SmartPointer::SharedPointer<int> integer = SmartPointer::MakeShared<int>(42);
    SmartPointer::SharedPointer<int> integer2{ integer };
    SmartPointer::SharedPointer<int> integer3 = SmartPointer::MakeShared<int>(43);
    integer2 = integer3;

    std::cout << *integer << std::endl;
    
    return 0;
}
