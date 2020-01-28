#if !defined(_SET_)
#define _SET_

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
    class GTUSet : public GTUContainerDerived<T>
    {
        public:

            GTUSet( void );
            GTUSet( const GTUSet<T>& other );
            GTUSet<T>& operator=(const GTUSet<T>& other);
            ~GTUSet();

            GTUIterator<T> insert ( const T& value ) throw( bad_pafram ) override ;

            inline void print_GTUSet_info( void ) const
            {
                cout << endl <<"****GTUSet_INFO********" << endl;
                cout << "Constructors : " << endl;
                cout << "GTUSet()       -> Creat a set whose size is zero " << endl;

                cout << "You can freely use Copy constructor exists " << endl;
                cout << "You can freely use Assignment already overloaded '=' " << endl;
                cout << "You can freely use Destrutor exists " << endl;

                cout << "Class Functions : " << endl << endl;
                cout << "bool               empty ( void ) "<< endl;
                cout << "unsigned int       size( void )" << endl;
                cout << "unsigned int       max_size( void )" << endl;
                cout << "GTUIterator<T>     erase( const GTUIterator<T> iterPos )" << endl;
                cout << "void               clear( void )" << endl;
                cout << "GTUIterator<T>     insert ( const T& value ) throw ( bad_pafram ) " << endl;
                cout << "GTUIterator<T>     begin( void ) "<< endl;
                cout << "GTUIterator<T>     end( void ) " << endl;

                cout << "You can freely use iterator feature ." << endl;
                
                cout <<"********END***************" << endl << endl;
            }

            inline void printSetProperty( void ) const
            {
                shared_ptr< Node<T> > tempHead = this -> ptrHead;

                if( tempHead == nullptr )
                    return;

                cout << "**********************************************" << endl;
                cout << "Set Configuration : \n";
                
                for( unsigned int i = 0 ; i < this -> curSize ; ++i  )
                {
                    cout << tempHead -> data <<  std::endl ;
                    tempHead = tempHead -> next;
                }

                cout << endl;
                cout << "**********************************************" << endl;
                
            }

        private:

            bool isDataExist( const T& data) const;
        
    };

    template<typename T>
    GTUSet<T>::GTUSet( )
        : GTUContainerDerived<T>()
    {
        this -> curSize = 0;
        /*Intentionally left blank*/
    }

    template<typename T>
    GTUSet<T>::GTUSet( const GTUSet<T>& other )
        : GTUContainerDerived<T>(other)
    {
        /* Intentionally left blank */
    }

    template<typename T>
    GTUSet<T>& GTUSet<T>::operator=(const GTUSet<T>& other)
    {
        if( this == &other )
            return *this;

        GTUContainerDerived<T>::operator=(other);

        return *this;
    }
    
    template<typename T>
    GTUSet<T>::~GTUSet()
    {
        this -> clear();
    }

    template<typename T>
    GTUIterator<T> GTUSet<T>::insert ( const T& data ) throw( bad_pafram )
    {
        if( this -> max_size() == this -> size() )
            throw bad_pafram( "Maxsize exceeded ! " );
        if( isDataExist( data ) )
            throw bad_pafram( "Data already exist in list " );

        GTUIterator<T> listHead = this -> _shared_nullptr;

        shared_ptr < Node <T> > tempHead = this -> ptrHead;
        shared_ptr < Node <T> > newNode = make_shared< Node <T> >( nullptr , nullptr );
        newNode -> data = data;

        if(tempHead != nullptr )
        {
            while(tempHead -> next -> next != nullptr )
                tempHead = tempHead -> next;

            tempHead -> next = newNode;
            newNode -> previos = tempHead;
        }
        
        newNode -> next = this -> _shared_nullptr;
        this -> _shared_nullptr -> previos = newNode;

        if( this -> curSize == 0 )
            this -> ptrHead = newNode;
        
        ++this -> curSize;
        listHead = this -> begin();

        return listHead;
    }

    template<typename T>
    bool GTUSet<T>::isDataExist( const T& data) const
    {
        shared_ptr< Node<T> > tempHead = this -> ptrHead;
        
        if( tempHead == nullptr )
            return false;

        while( tempHead -> next != nullptr  )
        {
            if ( tempHead -> data == data )
                return true;

            tempHead = tempHead -> next;
        }

        return false;
    }
}

#endif