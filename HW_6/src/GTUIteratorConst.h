#if !defined(_GTU_ITERATOR_CONST_)
#define _GTU_ITERATOR_CONST_

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

    template <typename T>
    class GTUIteratorConst
    {
        public:

            GTUIteratorConst( shared_ptr <Node<T> >& ptr ) : iterPtr(ptr)
            {
                /* Intentionally left blank */
            }

            inline const T& operator*()
            {
                return iterPtr -> data;
            }

            inline const T* operator->()
            {
                return &(iterPtr -> data) ;
            }

            inline GTUIteratorConst operator++()
            {
                if( iterPtr -> next != nullptr )
                {
                    iterPtr = iterPtr -> next;
                    return iterPtr;
                }
                
                throw Exceptions( "Const Attempt to reach out of vector ! Error : ++() !" );
            }

            inline GTUIteratorConst operator++(int)
            {
                GTUIteratorConst tempIter(iterPtr);

                if( iterPtr -> next != nullptr )
                {
                    iterPtr = iterPtr -> next;
                    return tempIter;
                }

                throw Exceptions( "Const Attempt to reach out of vector ! Error : ++(int) !" );
                
            }

            inline GTUIteratorConst operator--()
            {
                if( iterPtr -> previos != nullptr )
                {
                    iterPtr = iterPtr -> previos;
                    return iterPtr;
                }
                
                throw Exceptions( "Const Attempt to reach out of vector ! Error : --() !" );
            }

            inline GTUIteratorConst operator--(int)
            {
                GTUIteratorConst tempIter(iterPtr);

                if( iterPtr -> previos != nullptr )
                {
                    iterPtr = iterPtr -> previos;
                    return tempIter;
                }

                throw Exceptions( "Const Attempt to reach out of vector ! Error : --(int) !" );
            }

            inline bool operator==( const GTUIteratorConst& other ) const
            {
                return iterPtr == other.iterPtr;
            }

            inline bool operator!=( const GTUIteratorConst& other ) const
            {
                return iterPtr != other.iterPtr;
            }

        private:

            shared_ptr< Node<T> > iterPtr;
    };
}


#endif