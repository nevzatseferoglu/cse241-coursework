#if !defined(_BOARD_ARRAY_2D_)
#define _BOARD_ARRAY_2D_

#include <iostream>
#include <string>
#include "AbstractBoard.h"

namespace NPuzzle
{
    using std::cout;
    using std::cin;
    using std::cerr;
    using std::string;

    class BoardArray2D : public AbstractBoard
    {
        public:

            BoardArray2D( int xSize = 3, int ySize = 3 );
            BoardArray2D( const BoardArray2D& other);
            BoardArray2D( const string& filename);

            virtual void setSize( const int& xSize , const int& ySize );
            virtual int& operator()( int x , int y );
            virtual const int& operator()( int x , int y ) const;

            BoardArray2D& operator=(const BoardArray2D& other);
            
            ~BoardArray2D();
            
        private:

            int** puzzle_map;

    };
}

#endif