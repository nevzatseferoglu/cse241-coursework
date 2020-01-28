#if !defined(_BOARD_ARRAY_1D_)
#define _BOARD_ARRAY_1D_

#include <iostream>
#include <string>
#include "AbstractBoard.h"


namespace NPuzzle
{
    using std::string;
    using std::cout;
    using std::cin;
    using std::cerr;
    using std::endl;

    class BoardArray1D : public AbstractBoard
    {
        public:
        
            BoardArray1D( int xSize = 3, int ySize = 3 );
            BoardArray1D( const BoardArray1D& other);
            BoardArray1D( const string& filename);
            

            virtual void setSize( const int& xSize , const int& ySize );
            virtual int& operator()( int x , int y );
            virtual const int& operator()( int x , int y ) const;

            BoardArray1D& operator=(const BoardArray1D& other);
            
            ~BoardArray1D();

        private:

            int* puzzle_map;
    };
}

#endif