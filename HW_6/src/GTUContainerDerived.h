#if !defined(_GTU_CONTAINER_DERIVED_)
#define _GTU_CONTAINER_DERIVED_

#include <iostream>
#include "GTUContainer.h"
#include "GTUIterator.h"
#include "Node.h"
#include "Exceptions.h"

namespace GTU_171044024
{
    using std::make_shared;
    using std::shared_ptr;
    using std::cout;
    using std::cerr;
    using std::endl;

    template<typename T>
    class GTUContainerDerived : public GTUContainer<T>
    {
        public:

            GTUContainerDerived( );
            GTUContainerDerived( const GTUContainerDerived<T>& other );
            GTUContainerDerived<T>& operator=( const GTUContainerDerived<T>& other );
            ~GTUContainerDerived();

            bool            empty           ( void ) const override;
            unsigned int    size            ( void ) const override;
            unsigned int    max_size        ( void ) const override;

            GTUIterator<T> erase  ( const GTUIterator<T> iterPos ) override;
            
            void            clear           ( void ) override;
            
            GTUIterator<T> begin( void ) override;
            GTUIterator<T> end( void ) override;

        protected:

            unsigned int curSize;
            shared_ptr< Node<T> > ptrHead;
            const unsigned int maxSize = 5000;
            shared_ptr< Node<T> > _shared_nullptr = nullptr;

    };

    template<typename T>
    GTUContainerDerived<T>::GTUContainerDerived( )
        : ptrHead(nullptr) , curSize( 0 )
    {
        _shared_nullptr = make_shared< Node<T> >(nullptr , nullptr);
        /* Intentionally left blank */
    }

    template<typename T>
    GTUContainerDerived<T>::GTUContainerDerived( const GTUContainerDerived<T>& other )
        : curSize( other.size() )
    {
        shared_ptr < Node<T> > tempHead = nullptr;
        shared_ptr < Node<T> > tempOther = nullptr;
        _shared_nullptr = make_shared< Node<T> >(nullptr , nullptr);

        if( !other.empty() )
        {
            tempOther = other.ptrHead;

            ptrHead = make_shared< Node<T> >( nullptr , nullptr );
            tempHead = ptrHead;
            tempHead -> data = tempOther -> data;

            for( int  i = 0 ; i < other.size() - 1 ; ++i )
            {   
                tempHead -> next = make_shared< Node<T> >( nullptr , tempHead );
                tempHead = tempHead -> next;
                tempOther = tempOther -> next;
                tempHead -> data = tempOther -> data;
            }

            tempHead -> next = _shared_nullptr;
            _shared_nullptr -> previos = tempHead;
        }
        
    }
    
    template<typename T>
    GTUContainerDerived<T>& GTUContainerDerived<T>::operator=( const GTUContainerDerived<T>& other )
    {
        shared_ptr < Node<T> > tempHead = nullptr;
        shared_ptr < Node<T> > tempOther = nullptr;

        if( this == &other )
            return *this;

        if( this -> size() != other.size() )
        {
            this -> clear();

            curSize = other.size();
            tempOther = other.ptrHead;

            ptrHead = make_shared< Node<T> >( nullptr , nullptr );
            tempHead = ptrHead;
            tempHead -> data = tempOther -> data;

            for( int  i = 0 ; i < other.size() - 1 ; ++i )
            {
                tempHead -> next = make_shared< Node<T> >( nullptr , tempHead );
                tempHead = tempHead -> next;
                tempOther = tempOther -> next;

                tempHead -> data = tempOther -> data;
            }

            tempHead -> next = _shared_nullptr;
            _shared_nullptr -> previos = tempHead;

            return *this;
        }
        else
        {
            tempHead = ptrHead;
            tempOther = other.ptrHead;

            for( int i = 0 ; i < other.size() ; ++i )
            {
                tempHead -> data = tempOther -> data;

                tempHead = tempHead -> next;
                tempOther = tempOther -> next;
            }

            tempHead -> next = _shared_nullptr;
            _shared_nullptr -> previos = tempHead;

            return *this;
        }
    }
    
    template<typename T>
    GTUContainerDerived<T>::~GTUContainerDerived()
    {
    }

    template<typename T>
    bool GTUContainerDerived<T>::empty( void )  const 
    {
        return ptrHead == nullptr;
    }
    
    template<typename T>
    unsigned int GTUContainerDerived<T>::size( void )  const 
    {
        return curSize;
    }
    
    template<typename T>
    unsigned int GTUContainerDerived<T>::max_size( void )  const 
    {
        return maxSize;
    }

    template<typename T>
    GTUIterator<T> GTUContainerDerived<T>::erase  ( const GTUIterator<T> iterPos )
    {
        bool flag = true;
        unsigned int nodeCounter = 0;
        GTUIterator<T> listPtr = this -> begin();
        shared_ptr< Node<T> > tempNode = ptrHead;
        shared_ptr< Node<T> > beforeNode = nullptr;
        shared_ptr< Node<T> > afterNode = nullptr;

        while( flag )
        {

            ++nodeCounter;
            if( listPtr == iterPos )
                flag = false;
            else
            {
                tempNode = tempNode -> next;
                ++listPtr;
            }
        }
        
        if( nodeCounter > this->size() )
            throw Exceptions( "Member end() could not be erased , Error : erase() " );


        if(nodeCounter == 1)
        {
            ptrHead = ptrHead -> next;
            ptrHead -> previos =nullptr;

            tempNode -> next = nullptr;
            tempNode -> previos = nullptr;
            tempNode = nullptr;
        }
        else
        {
            if( nodeCounter > this -> size() )
                --nodeCounter;
            
            afterNode = ptrHead;
            listPtr = this -> begin();

            for( int i = 0 ; i < nodeCounter  ; ++i )
            {
                if( i == nodeCounter - 2 )
                    beforeNode = afterNode;
                
                afterNode = afterNode -> next;
            }

            beforeNode ->next = afterNode;
            afterNode -> previos = beforeNode;

        }

        --curSize;
        listPtr = this -> begin();

        return listPtr;
    }

    template<typename T>
    void GTUContainerDerived<T>::clear( void )
    {
        shared_ptr< Node<T> > tempNode = nullptr;

        for( int i = 0 ; i < curSize ; ++i )
        {
            tempNode = ptrHead;
            ptrHead = ptrHead -> next;

            tempNode -> next = nullptr;
            tempNode -> previos = nullptr;
        }

        ptrHead = nullptr;
        curSize = 0;
    }

    template<typename T>
    GTUIterator<T> GTUContainerDerived<T>::begin( void )
    {
        GTUIterator<T> iter(ptrHead);
        return iter;
    }

    template<typename T>
    GTUIterator<T> GTUContainerDerived<T>::end( void )
    {
        GTUIterator<T> iter( _shared_nullptr );

        return iter;
    }
}


#endif