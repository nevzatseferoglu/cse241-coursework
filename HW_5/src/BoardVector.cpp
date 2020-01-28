#include <iostream>
#include "BoardVector.h"
#include "AbstractBoard.h"

namespace NPuzzle
{
    using std::string;
    using std::cout;
    using std::cin;
    using std::cerr;
    using std::endl;

    BoardVector::BoardVector( int xSize , int ySize ) : AbstractBoard()
    {
        setSize( xSize , ySize );
    }
    
    BoardVector::BoardVector( const BoardVector& other) : AbstractBoard( other )
    {
        inc_Number_Of_Boards();
        
        setSize( get_xSize() , get_ySize() );

        for(int j = 0 ; j < get_ySize() ; ++j)
            for(int i = 0 ; i< get_xSize() ; ++i)
                puzzle_map[ i ][ j ] = other.puzzle_map[ i ][ j ];
    }

    BoardVector::BoardVector( const string& filename) : AbstractBoard()
    {
        readFromFile( filename );
    }
    

    void BoardVector::setSize( const int& xSize , const int& ySize )
    {
        if( !puzzle_map.empty() )
            puzzle_map.clear();
        
        /* Base class virtual call */

        AbstractBoard::setSize( xSize , ySize );

        puzzle_map.resize( xSize , vector < int > ( ySize , -1 ) );
        
        /* Whatever is going to be built */

        reset();
    }

    int& BoardVector::operator()( int x , int y )
    {
        if( (x < 0 || x > (get_xSize() - 1) ) || (y < 0 || y > (get_ySize() - 1) ) )
        {
            cerr << endl << "Invalid argument ! Error , operator() " << endl << endl;
            exit(1);
        }

        return puzzle_map[ x ][ y ];
    }

    const int& BoardVector::operator()( int x , int y ) const
    {
        if( (x < 0 || x > (get_xSize() - 1) ) || (y < 0 || y > (get_ySize() - 1) ) )
        {
            cerr << endl << "Invalid argument ! Error , operator() " << endl << endl;
            exit(1);
        }
        
        return puzzle_map[ x ][ y ];
    }

    BoardVector& BoardVector::operator=(const BoardVector& other)
    {

        if( !puzzle_map.empty() )
            puzzle_map.clear();

        AbstractBoard::operator=( other );
        
        puzzle_map.resize( other.get_xSize() , vector < int > ( other.get_ySize() , -1 ) );

        for(int j = 0 ; j < get_ySize() ; ++j)
            for(int i = 0 ; i< get_xSize() ; ++i)
                puzzle_map[ i ][ j ] = other.puzzle_map[ i ][ j ];

        return *this;
    }
    
    BoardVector::~BoardVector()
    {
        puzzle_map.clear();
    }

}