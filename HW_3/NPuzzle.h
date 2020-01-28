#ifndef _NPUZZLE_H
#define _NPUZZLE_H

#include <iostream> /* Standart C++ Library */ 
#include <cstdlib>  /* For the purpose of taking pseudo number from the user and using some dynamic allocation*/
#include <fstream>  /* File Handling Library */
#include <ctime>    /* Creating Pseudo Number */
#include <string>   /* Using string type variable */

using namespace std;

/* Function Paramter Detail are located in NPuzzle.cpp file */
/* This is only class definition */
class NPuzzle
{
    public:
        NPuzzle(){}; /* No parameter constructor */
        void print(void) const;
        void printReport(void) const;
        void readFromFile(const string& filename);
        void writeToFile(const string& filename);
        void shuffle(const int& n);
        void reset(void);
        void setsize(const int& size);
        char moveRandom(void);
        void moveIntelligence(void);
        bool move(const char& letter);
        void solvePuzzle(void);
        /* My own function */
        bool quit;
        bool is_end_puzzle(void) const;
        int get_puzzle_size(const int& minSize , const int& maxSize) const;
        string get_file_name(void) const;
        void goSolution(void);
        void release_puzzle(void);
    private:
        enum Direction{ right, left, up, down };
        class Board
        {
            public:
                Board(void); /* No parameter constructor */
                void print(void) const;
                void readFromFile(const string& filename);
                void writeToFile(const string& filename);
                void reset(void);
                void setsize(const int& size);
                bool move(const char& letter);
                bool isSolved(void) const;

                /* My own function */
                inline int get_xSize(void) const {return xSize;}
                inline int get_ySize(void) const {return ySize;}
                inline void reset_moveNumber(void){ moveNumber=0;}
                inline int get_moveNumber(void) const { return moveNumber;}
                inline void inc_moveNumber(const int& n) { moveNumber+=n;}
                inline void dec_moveNumber(const int& n) { moveNumber-=n;}
                void set_empty_or_release_puzzle(void);
                int getCost(void) const;
                inline int getPlayerX(void) {return playerX;}
                inline int getPlayerY(void) {return playerY;}
                void init_prev_move(void);
                bool setPlayerPos(void);
                int totalCost[4];
                int prevMove[9][9];
                


            private:
                int* puzzle_map;
                int* goal_map;
                int xSize,ySize;
                int playerX,playerY;
                int moveNumber;
                string filename;
                /* My own private Function */
                int* createGoalPuzzle(void);
                void release_puzzle(void);
                int get_digit(int number) const;
                bool is_empty_puzzle(void) const;
                bool is_number(const string& s1) const;
                int charToint(char) const;
                bool moveRight(void);
                bool moveLeft(void);
                bool moveUp(void);
                bool moveDown(void);
                bool isStuck(void);
        };
        Board gameBoard;
};
#endif  /*  _NPUZZLE_H  */