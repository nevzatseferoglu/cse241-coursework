#if !defined(_BORAD_VECTOR_)
#define _BORAD_VECTOR_

#include <iostream>
#include <string>
#include <vector>
#include "AbstractBoard.h"

namespace NPuzzle
{
    using std::cout;
    using std::cin;
    using std::cerr;
    using std::string;
    using std::vector;

    class BoardVector : public AbstractBoard
    {
        public:

            BoardVector( int xSize = 3, int ySize = 3 );
            BoardVector( const BoardVector& other);
            BoardVector( const string& filename);

            virtual void setSize( const int& xSize , const int& ySize );
            virtual int& operator()( int x , int y );
            virtual const int& operator()( int x , int y ) const;

            BoardVector& operator=(const BoardVector& other);
            
            ~BoardVector();
            
        private:

        vector < vector < int > > puzzle_map;
        
    };
}

#endif