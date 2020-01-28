#if !defined(_GTU_ITERATOR_)
#define _GTU_ITERATOR_

#include <iostream>
#include <memory>
#include "Node.h"
#include "Exceptions.h"

namespace GTU_171044024
{
    using std::shared_ptr;
    using std::make_shared;
    using std::cout;
    using std::cerr;
    using std::endl;

    template<typename T>
    class GTUIterator
    {
        public:
        
            GTUIterator( shared_ptr <Node<T> >& ptr ) : iterPtr(ptr){}

            inline T& operator*() const
            {
                return iterPtr -> data;
            }

            inline T* operator->() const
            {
                return &(iterPtr -> data) ;
            }

            inline GTUIterator operator++()
            {
                if( iterPtr -> next != nullptr )
                {
                    iterPtr = iterPtr -> next;
                    return iterPtr;
                }
                
                throw Exceptions( "Attempt to reach out of vector ! Error : ++() !" );
            }

            inline GTUIterator operator++(int)
            {
                GTUIterator tempIter(iterPtr);

                if( iterPtr -> next != nullptr )
                {
                    iterPtr = iterPtr -> next;
                    return tempIter;
                }
                
                throw Exceptions( "Attempt to reach out of vector ! Error : ++(int) !" );
                
            }

            inline const GTUIterator operator--()
            {
                if( iterPtr -> previos != nullptr )
                {
                    iterPtr = iterPtr -> previos;
                    return iterPtr;
                }
                
                throw Exceptions( "Attempt to reach out of vector ! Error : --() !" );
            }

            inline const GTUIterator operator--(int)
            {
                GTUIterator tempIter(iterPtr);

                if( iterPtr -> previos != nullptr )
                {
                    iterPtr = iterPtr -> previos;
                    return tempIter;
                }
                
                throw Exceptions( "Attempt to reach out of vector ! Error : --(int) !" );
            }

            inline bool operator==( const GTUIterator& other ) const
            {
                return iterPtr == other.iterPtr;
            }

            inline bool operator!=( const GTUIterator& other ) const
            {
                return iterPtr != other.iterPtr;
            }

        private:

            shared_ptr< Node<T> > iterPtr;
    };
}


#endif