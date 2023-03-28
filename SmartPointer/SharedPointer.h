#pragma once
#include <utility>

namespace SmartPointer
{
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

        SharedPointer(const SharedPointer<T>& other)
        {
            pointer = other.pointer;
            refCounter = other.refCounter;

            IncreaseReference();
        }
    
        ~SharedPointer()
        {
            DecreaseReference();
        }

        SharedPointer<T>& operator=(const SharedPointer<T>& other)
        {
            if(this == &other || this->pointer == other.pointer)
            {
                return *this;
            }
        
            pointer = other.pointer;
            refCounter = other.refCounter;

            IncreaseReference();
        
            return *this;
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

    template<class TPointer, class... Params>
    static SharedPointer<TPointer> MakeShared(Params&&... args)
    {
        return SharedPointer<TPointer> { std::forward<Params>(args)... };
    }
}
