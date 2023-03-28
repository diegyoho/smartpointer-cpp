#pragma once

template <class T>
class SharedPointer
{
public:

    SharedPointer() = default;

    explicit SharedPointer(T* pointer) : pointer{ pointer }
    {
    }
    
    explicit SharedPointer(T&& value) : SharedPointer{ new T{ value } }
    {
    }
    
    ~SharedPointer()
    {
        delete pointer;
    }

private:

    T* pointer{ nullptr };
};
