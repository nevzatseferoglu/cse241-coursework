#if !defined(_ABSTRACT_BOARD_)
#define _ABSTRACT_BOARD_

/* Abstract  Class  Implementation which is going to be inherited 3 different classes */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

namespace NPuzzle
{
    using std::string;
    using std::cout;
    using std::cin;

    class AbstractBoard
    {
        public:

            /* Constructors */

            AbstractBoard(void);

            /* Members that are given by the lecturer */

            void print(void) const;

            void readFromFile(const string& filename);
            void writeToFile(const string& filename);

            void reset(void);
            virtual void setSize( const int& xSize , const int& ySize );
            
            bool move(const char& letter);
            bool isSolved(void) const;
            
            virtual int& operator()(int x , int y) = 0;
            virtual const int& operator()(int x , int y) const = 0;
            
            bool operator==(const AbstractBoard& other) const;

            static int NumberOfBoards( void );

            inline int numberOfMoves( void ) const { return number_Of_Moves; }
            inline char lastMove( void ) const { return last_Move; }

            /* Members that I need */

            inline int get_xSize(void) const { return xSize; }
            inline int get_ySize(void) const { return ySize; }
            inline int get_blankRepresentation(void) const { return blankRepresentation; }

            /* Destructor */

            virtual ~AbstractBoard();

        protected:

            inline void inc_Number_Of_Boards(void) { ++Number_Of_Boards; }

        private:

            int xSize,ySize;        /* x and y size of the board */
            int playerX,playerY;    /* blankPos of the board */
            int blankRepresentation; /* Blank representation */
            
            static int Number_Of_Boards; /* Number of the board */
            char last_Move;              /* Last move */
            int number_Of_Moves;         /* number of moves */   

            /*Private Functions */
            
            bool set_player_pos(void);
            bool moveRight(void);
            bool moveLeft(void);
            bool moveUp(void);
            bool moveDown(void);
            
    };
}

#endif
