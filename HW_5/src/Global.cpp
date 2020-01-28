#include <iostream>
#include "AbstractBoard.h"
#include "Global.h"

namespace
{
    using std::cout;
    using std::endl;

    using namespace NPuzzle;

    bool isValidMove( const AbstractBoard& board1 ,  const AbstractBoard& board2 )
    {
        int unpaired = 0 ;
        bool** test_board = nullptr;

        int x1 = -1 , y1 = -1 ;
        
        test_board = new bool* [ board1.get_xSize() ];
        for( int i = 0 ; i < board1.get_xSize() ; ++i )
            test_board[ i ] = new bool [ board1.get_ySize() ];

        for( int j = 0 ; j < board1.get_ySize() ; ++j )
        {
            for( int i = 0 ; i < board1.get_xSize() ; ++i )
            {
                if(board1( i , j ) == board2( i , j ))
                    test_board[ i ][ j ] = true;
                else
                {
                    test_board[ i ][ j ] = false;
                    
                    if( x1 == -1 || y1 == -1)
                        x1 = i , y1 = j;
                    else if( !( (((i - x1) + (j - y1)) == -1) || (((i - x1) + (j - y1)) == 1 )) )
                    {
                        for( int i = 0 ; i < board1.get_xSize() ; ++i )
                        {
                            delete [] test_board[ i ];
                            test_board[i] = nullptr;
                        }

                        delete [] test_board;
                        test_board = nullptr;

                        return false;
                    }

                    ++unpaired;
                }
            }
        }

        if( unpaired != 2 )
        {
            for( int i = 0 ; i < board1.get_xSize() ; ++i )
            {
                delete [] test_board[ i ];
                test_board[i] = nullptr;
            }

            delete [] test_board;
            test_board = nullptr;

            return false;
        }

        for( int i = 0 ; i < board1.get_xSize() ; ++i )
        {
            delete [] test_board[ i ];
            test_board[i] = nullptr;
        }
        
        delete [] test_board;
        test_board = nullptr;

        return true;    
    }
}

namespace NPuzzle
{
    using std::cout;
    using std::endl;

    bool is_ValidSequence( const AbstractBoard* const sequence[] , int size )
    {
        for( int i = 0 ; i < size ; ++i)
            if( sequence[i] == nullptr )
                return false;

        if( !(( *sequence[ size - 1 ] ).isSolved()) )
            return false;

        for( int i = 0 ; i < size - 1 ; ++i )
        {
            if( (*sequence[i]).get_ySize() != (*sequence[i+1]).get_ySize() ||  (*sequence[i]).get_xSize() != (*sequence[i+1]).get_xSize() )
                return false;

            if( !isValidMove( *sequence[i] , *sequence[i+1] ) )
                return false;
        }

        return true;
    }
}