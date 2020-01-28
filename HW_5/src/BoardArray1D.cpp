#include <iostream>
#include "BoardArray1D.h"
#include "AbstractBoard.h"

namespace NPuzzle
{
    using std::string;
    using std::cout;
    using std::cin;
    using std::cerr;
    using std::endl;


    BoardArray1D::BoardArray1D(int xSize, int ySize) : AbstractBoard()
        , puzzle_map(nullptr)
    {
        setSize( xSize , ySize );

        /* Intentionally left blank */
    }

    BoardArray1D::BoardArray1D( const BoardArray1D& other) : AbstractBoard( other )
        , puzzle_map(nullptr)
    {
        inc_Number_Of_Boards();
        
        setSize( get_xSize() , get_ySize() );

        for(int j = 0 ; j < get_ySize() ; ++j)
            for(int i = 0 ; i < get_xSize() ; ++i)
                puzzle_map[ j * get_xSize() + i ] = other.puzzle_map[ j * get_xSize() + i ];
    }

    BoardArray1D::BoardArray1D( const string& filename) : AbstractBoard()
        , puzzle_map(nullptr)
    {
        readFromFile( filename );
    }


    void BoardArray1D::setSize( const int& xSize , const int& ySize )
    {
        if( puzzle_map != nullptr)
        {
            delete [] puzzle_map;
            puzzle_map = nullptr;
        }

        /* Base class virtual call */
        AbstractBoard::setSize( xSize , ySize );
        puzzle_map = new int [ xSize * ySize ];

        for(int j = 0 ; j < get_ySize() ; ++j)
            for(int i = 0 ; i < get_xSize() ; ++i)
                puzzle_map[ j * get_xSize() + i ] = -1;

        /* Whatever is goint to be built */
        
        reset();
    }

    int& BoardArray1D::operator()(int x , int y)
    {
        if( (x < 0 || x > (get_xSize() - 1) ) || (y < 0 || y > (get_ySize() - 1) ) )
        {
            cerr << endl << "Invalid argument ! Error , operator() " << endl << endl;
            exit(1);
        }

        return puzzle_map[ y * get_xSize() + x ];
    }

    const int& BoardArray1D::operator()(int x , int y) const
    {
        if( (x < 0 || x > (get_xSize() - 1) ) || (y < 0 || y > (get_ySize() - 1) ) )
        {
            cerr << endl << "Invalid argument ! Error , operator() " << endl << endl;
            exit(1);
        }
        
        return puzzle_map[ y * get_xSize() + x ];
    }

    BoardArray1D& BoardArray1D::operator=(const BoardArray1D& other)
    {
        if( puzzle_map != nullptr )
        {
            delete [] puzzle_map;
            puzzle_map = nullptr;
        }

        AbstractBoard::operator=( other );

        puzzle_map = new int [ get_xSize() * get_ySize() ];
        
        for(int j = 0 ; j < get_ySize() ; ++j)
            for(int i = 0 ; i< get_xSize() ; ++i)
                puzzle_map[ j * get_xSize() + i ] = other.puzzle_map[ j * get_xSize() + i ];

        return *this;
    }

    BoardArray1D::~BoardArray1D()
    {
        delete [] puzzle_map;
        puzzle_map = nullptr;
    }
}