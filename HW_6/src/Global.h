#include <iostream>

namespace GTU_171044024
{
    template< typename Iterator , typename T >
    Iterator find( Iterator first , Iterator last , const T& data )
    {
        for( ; first != last ; ++first )
            if( *first == data )
                return first;
        
        return last;
    }
    
    template< typename Iterator , typename T >
    Iterator find_if(Iterator first ,Iterator last , T f1 )
    {
        for( ; first != last ; ++first )
            if( f1( *first ) )
                return first;
        
        return last;
    }

    template< typename Iterator , typename T >
    T for_each(Iterator first , Iterator last , T f2)
    {
        for( ; first != last ; ++first )
            f2( *first );
        
        return f2;
    }

}
