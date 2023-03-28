#pragma once

template <class T>
class SharedPointer
{
public:

    SharedPointer() = default;

    explicit SharedPointer(T* pointer) : pointer{ pointer }
    {
        if(pointer)
        {
            IncreaseReference();
        }
    }
    
    explicit SharedPointer(T&& value) : SharedPointer{ new T{ value } }
    {
    }
    
    ~SharedPointer()
    {
        DecreaseReference();
    }
    
private:
    
    T* pointer{nullptr};
    unsigned int* refCounter{nullptr};

    void IncreaseReference()
    {
        if(!refCounter)
        {
            refCounter = new unsigned int{};
        }

        ++(*refCounter);
    }
    
    void DecreaseReference() const
    {
        if(refCounter && --(*refCounter) == 0)
        {
            DeletePointer();
        }
    }
    
    void DeletePointer() const
    {
        delete pointer;
        delete refCounter;
    }
};
