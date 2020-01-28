#if !defined(_GTU_CONTAINER_)
#define _GTU_CONTAINER_ 

#include <iostream>
#include <memory>
#include "GTUIterator.h"
#include "GTUIteratorConst.h"
#include "Exceptions.h"

namespace GTU_171044024
{
    using std::bad_pafram;

    template <typename T>
    class GTUContainer
    {
        public :

            virtual bool            empty       ( void )  const = 0;
            virtual unsigned int    size        ( void )  const = 0;
            virtual unsigned int    max_size    ( void )  const = 0;
            virtual void            clear       ( void )        = 0;
            
            virtual GTUIterator<T> insert ( const T& value )                        throw( bad_pafram ) = 0 ;
            virtual GTUIterator<T> erase  ( const GTUIterator<T> iterPos ) = 0;

            virtual GTUIterator<T> begin( void ) = 0;
            virtual GTUIterator<T> end( void ) = 0;
            virtual ~GTUContainer(){}

    };
}

#endif