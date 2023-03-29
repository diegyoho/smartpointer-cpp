#pragma once
#include <utility>

namespace SmartPointer
{
    template <class T>
    class SharedPointer
    {
    public:

        SharedPointer() = default;

        explicit SharedPointer(T* pointer) :
            pointer{ pointer }
        {
            IncreaseReference();
        }

        SharedPointer(const SharedPointer<T>& other) :
            pointer{ other.pointer },
            refCounter { other.refCounter }
        {
            IncreaseReference();
        }
    
        ~SharedPointer()
        {
            DecreaseReference();
        }

        SharedPointer<T>& operator=(const SharedPointer<T>& rhs)
        {
            if(this != &rhs && this->pointer != rhs.pointer)
            {
                pointer = rhs.pointer;
                refCounter = rhs.refCounter;

                IncreaseReference();
            }
        
            return *this;
        }
    
    private:
    
        T* pointer{ nullptr };
        unsigned int* refCounter{ nullptr };

        void IncreaseReference()
        {
            if(pointer)
            {
                refCounter = refCounter ? refCounter : new unsigned int{};
                ++(*refCounter);
            }
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
        return SharedPointer<TPointer> { new TPointer { std::forward<Params>(args)... } };
    }
}
