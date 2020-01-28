#include <iostream>
#include "BoardArray2D.h"
#include "AbstractBoard.h"

namespace NPuzzle
{
    using std::string;
    using std::cout;
    using std::cin;
    using std::cerr;
    using std::endl;

    BoardArray2D::BoardArray2D( int xSize , int ySize ) : AbstractBoard()
        , puzzle_map( nullptr )
    {
        setSize( xSize , ySize );
    }
    
    BoardArray2D::BoardArray2D( const BoardArray2D& other) : AbstractBoard( other )
        , puzzle_map(nullptr)
    {
        inc_Number_Of_Boards();
        
        setSize( get_xSize() , get_ySize() );

        for(int j = 0 ; j < get_ySize() ; ++j)
            for(int i = 0 ; i < get_xSize() ; ++i)
                puzzle_map[ i ][ j ] = other.puzzle_map[ i ][ j ];
    }

    BoardArray2D::BoardArray2D( const string& filename) : AbstractBoard()
        , puzzle_map ( nullptr )
    {
        readFromFile( filename );
    }
    

    void BoardArray2D::setSize( const int& xSize , const int& ySize )
    {

        if( puzzle_map != nullptr )
        {
            for(int i = 0 ; i < get_xSize() ; ++i)
            {
                delete [] puzzle_map[ i ];
                puzzle_map[i] = nullptr;
            }

            delete [] puzzle_map;
            puzzle_map = nullptr;
        }
        
        /* Base class virtual call */

        AbstractBoard::setSize( xSize , ySize );

        puzzle_map = new int* [ xSize ];

        for( int i = 0 ; i < xSize ; ++i )
            puzzle_map[ i ] = new int [ ySize ];

        for(int j = 0 ; j < get_ySize() ; ++j)
            for(int i = 0 ; i < get_xSize() ; ++i)
                puzzle_map[ i ][ j ] = -1;
        
        reset();
        
    }

    int& BoardArray2D::operator()( int x , int y )
    {
        if( (x < 0 || x > (get_xSize() - 1) ) || (y < 0 || y > (get_ySize() - 1) ) )
        {
            cerr << endl << "Invalid argument ! Error , operator() " << endl << endl;
            exit(1);
        }

        return puzzle_map[ x ] [ y ];
    }

    const int& BoardArray2D::operator()( int x , int y ) const
    {
        if( (x < 0 || x > (get_xSize() - 1) ) || (y < 0 || y > (get_ySize() - 1) ) )
        {
            cerr << endl << "Invalid argument ! Error , operator() " << endl << endl;
            exit(1);
        }
        
        return puzzle_map[ x ] [ y ];
    }

    BoardArray2D& BoardArray2D::operator=(const BoardArray2D& other)
    {
        if( puzzle_map != nullptr )
        {
            for(int i = 0 ; i < get_xSize() ; ++i)
            {
                delete [] puzzle_map[ i ];
                puzzle_map[ i ] = nullptr;
            }

            delete [] puzzle_map;
            puzzle_map = nullptr;
        }
        
        AbstractBoard::operator=( other );

        puzzle_map = new int* [ get_xSize() ];

        for( int i = 0 ; i < get_xSize() ; ++i )
            puzzle_map[ i ] = new int [ get_ySize() ];

        for(int j = 0 ; j < get_ySize() ; ++j)
            for(int i = 0 ; i< get_xSize() ; ++i)
                puzzle_map[ i ][ j ] = other.puzzle_map[ i ][ j ];

        cout << "5" << endl;

        return *this;
    }
    
    BoardArray2D::~BoardArray2D()
    {
        for(int i = 0 ; i < get_xSize() ; ++i)
        {
            delete  [] puzzle_map[ i ];
            puzzle_map[i] = nullptr;
        }

        delete [] puzzle_map;
        puzzle_map = nullptr;
    }

}