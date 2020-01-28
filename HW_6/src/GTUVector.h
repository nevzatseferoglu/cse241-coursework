#if !defined(_GTU_VECTOR_)
#define _GTU_VECTOR_

#include <iostream>
#include "GTUContainerDerived.h"
#include "Exceptions.h"


namespace GTU_171044024
{
    using std::shared_ptr;
    using std::make_shared;
    using std::cout;
    using std::cerr;
    using std::endl;
    using std::bad_pafram;
    
    template<typename T>
    class GTUVector : public GTUContainerDerived<T>
    {
        public:

            GTUVector( unsigned int outSize = 0 );
            GTUVector( const GTUVector<T>& other );
            GTUVector<T>& operator=(const GTUVector<T>& other);
            ~GTUVector();
            
            T& operator[]( int index );
            const T& operator[]( int index ) const;

            GTUIterator<T> insert ( const GTUIterator<T> iterPos , const T& value ) throw ( bad_pafram );
            GTUIterator<T> insert ( const T& value ) throw ( bad_pafram ) override;


            inline void printVectorProperty( void ) const
            {
                shared_ptr< Node<T> > tempHead = this -> ptrHead;

                if( tempHead == nullptr )
                    return;

                cout << "**********************************************" << endl;
                cout << "Vector Configuration : \n";
                
                for( unsigned int i = 0 ; i < this -> curSize ; ++i  )
                {
                    cout << tempHead -> data << " " ;
                    tempHead = tempHead -> next;
                }
                cout << endl;
                cout << "**********************************************" << endl;
                
            }

            inline void print_GTUVector_info( void ) const
            {
                cout << endl <<"****GTUVector_INFO********" << endl;
                cout << "Constructors : " << endl;
                cout << "GTUVector()       -> Creat a vector whose size is zero " << endl;
                cout << "GTUVector( size ) -> Creat a vector whose size is given size " << endl << endl ;

                cout << "You can freely use Copy constructor exists " << endl;
                cout << "You can freely use Assignment already overloaded '=' " << endl;
                cout << "You can freely use Destrutor exists " << endl;
                cout << "You can freely use [] operator freely " << endl << endl;

                cout << "Class Functions : " << endl << endl;
                cout << "bool               empty ( void ) "<< endl;
                cout << "unsigned int       size( void )" << endl;
                cout << "unsigned int       max_size( void )" << endl;
                cout << "GTUIterator<T>     erase( const GTUIterator<T> iterPos )" << endl;
                cout << "void               clear( void )" << endl;
                cout << "GTUIterator<T>     insert ( const GTUIterator<T> iterPos , const T& value ) throw ( bad_pafram )" << endl;
                cout << "GTUIterator<T>     insert ( const T& value ) throw ( bad_pafram ) " << endl;
                cout << "GTUIterator<T>     begin( void ) "<< endl;
                cout << "GTUIterator<T>     end( void ) " << endl << endl;

                cout << "You can freely use iterator feature ." << endl;

                cout <<"********END***************" << endl << endl;
            }

        private:

            void createInitialList( const unsigned int size );

    };
    
    template<typename T>
    GTUVector<T>::GTUVector( unsigned int outSize )
        : GTUContainerDerived<T>()
    {
        createInitialList( outSize );
    }

    template<typename T>
    GTUVector<T>::GTUVector( const GTUVector<T>& other )
        : GTUContainerDerived<T>(other)
    {
        /* Intentionally left blank */
    }

    template<typename T>
    GTUVector<T>& GTUVector<T>::operator=(const GTUVector<T>& other)
    {
        if( this == &other )
            return *this;

        GTUContainerDerived<T>::operator=(other);

        return *this;
    }
    
    template<typename T>
    GTUVector<T>::~GTUVector()
    {
        this -> clear();
    }

    template<typename T>
    T& GTUVector<T>::operator[]( int index )
    {
        shared_ptr < Node<T> > tempHead = nullptr;

        if( index < 0 || index > this -> curSize - 1 )
            throw Exceptions( "Invalid index input , Error Code : operator[] !" );

        tempHead = this -> ptrHead;
        for( int i = 0 ; i < index ; ++i )
            tempHead = tempHead -> next;
        
        return tempHead -> data;
    }

    template<typename T>
    const T& GTUVector<T>::operator[]( int index ) const
    {
        shared_ptr < Node<T> > tempHead = nullptr;

        if( index < 0 || index > this -> curSize - 1 )
        {
            throw Exceptions( "Invalid index input , Error Code : const operator[] !" );
        }

        tempHead = this -> ptrHead;
        for( int i = 0 ; i < index ; ++i )
            tempHead = tempHead -> next;
        
        return tempHead -> data;
    }

    template<typename T>
    GTUIterator<T> GTUVector<T>::insert ( const GTUIterator<T> iterPos , const T& data ) throw ( bad_pafram )
    {
        bool flag = true;
        GTUIterator<T> listPtr = this -> begin();
        shared_ptr< Node<T> > tempNode = this -> ptrHead;
        shared_ptr< Node<T> > newNode = nullptr;
        shared_ptr< Node<T> > tempNodePrev = nullptr;

        if( this -> max_size() == this -> size() )
            throw( "Maxsize has been exceeded !");

        while( flag )
        {
            if( listPtr == iterPos )
                flag = false;
            else
            {
                tempNode = tempNode -> next;
                ++listPtr;
            }
        }

        tempNodePrev = tempNode -> previos;

        newNode = make_shared< Node<T> >( tempNode , tempNodePrev );
        newNode -> data = data;
        
        tempNode -> previos = newNode;
        
        if(tempNodePrev != nullptr)
            tempNodePrev -> next = newNode;
        else
            this -> ptrHead = newNode;
        
        ++this -> curSize;
        listPtr = this -> begin();

        return listPtr;
    }

    template<typename T>
    GTUIterator<T> GTUVector<T>::insert ( const T& data ) throw (bad_pafram)
    {
        GTUIterator<T> listHead = this -> _shared_nullptr;


        if( this -> max_size() == this -> size() )
            throw bad_pafram( "Maxsize exceeded ! " );

        shared_ptr < Node <T> > tempHead = this -> ptrHead;
        shared_ptr < Node <T> > newNode = make_shared< Node <T> >( nullptr , nullptr );
        newNode -> data = data;

        if(tempHead != nullptr )
        {
            while(tempHead -> next -> next != nullptr )
                tempHead = tempHead -> next;

            tempHead -> next = newNode;
            newNode -> previos = tempHead;
            newNode -> next = this -> _shared_nullptr;
            this -> _shared_nullptr -> previos = newNode;

        }
        else
        {
            newNode -> next = this -> _shared_nullptr;
            this -> _shared_nullptr -> previos = newNode;
            this -> ptrHead = newNode;

        }

        ++(this -> curSize);
        listHead = this -> begin();

        return listHead;
    }

    template<typename T>
    void GTUVector<T>::createInitialList( const unsigned int size )
    {
        this -> curSize = size;

        shared_ptr < Node<T> > tempHead = nullptr;
        
        if( this -> curSize != 0)
        {
            this -> ptrHead = make_shared< Node<T> >( nullptr , nullptr );
            tempHead = this -> ptrHead;

            for( int  i = 0 ; i < this -> curSize - 1 ; ++i )
            {
                this -> ptrHead -> next = make_shared< Node<T> >( nullptr , this -> ptrHead );
                this -> ptrHead = this -> ptrHead -> next;
            }

            this -> ptrHead -> next = this -> _shared_nullptr;
            this -> _shared_nullptr -> previos = this -> ptrHead;

            this -> ptrHead = tempHead;
        }
    }
}

#endif