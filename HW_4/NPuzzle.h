#ifndef _NPUZZLE_H
#define _NPUZZLE_H

#include <iostream> /* Standart C++ Library */ 
#include <cstdlib>  /* For the purpose of taking pseudo number from the user and using some dynamic allocation*/
#include <fstream>  /* File Handling Library */
#include <ctime>    /* Creating Pseudo Number */
#include <string>   /* Using string type variable */
#include <vector>

using namespace std;

/* Function Paramter Detail are located in NPuzzle.cpp file */
/* This is only class definition */
class NPuzzle
{
    public:
        NPuzzle(void){};    /* No parameter constructor */
        void print(void) const;
        void printReport(void) const;
        void readFromFile(const string& filename);
        void writeToFile(const string& filename);
        void shuffle(const int& n);
        void reset(void);
        void setsize(const int& size);
        char moveRandom(void);
        bool move(const char& letter);
        void solvePuzzle(void);
        friend ostream& operator >>(ostream& outputStream,const NPuzzle& p1);
        friend istream& operator <<(istream& inputStream,NPuzzle& p1);

        /* My own function */
        bool quit;
        bool isSolved(void) const;
        int get_puzzle_size(const int& minSize , const int& maxSize) const;
        inline int get_xSize(void) const {return gameBoard.get_xSize();}
        inline int get_ySize(void) const {return gameBoard.get_ySize();}
        string get_file_name(void) const;

    private:
        enum Direction{ right, left, up, down };
        class Board
        {
            public:
                Board(void){}
                void print(void) const;
                void readFromFile(const string& filename);
                void writeToFile(const string& filename);
                void reset(void);
                void setsize(const int& size);
                bool move(const char& letter);
                bool isSolved(void) const;
                int operator ()(const int& x_pos,const int& y_pos) const;
                bool operator ==(const NPuzzle::Board& b1) const;
                int NumberOfBoards(void) const { return number_of_boards;}

                /* My own private Function */
                inline char lastMove(void) const { return last_move;}
                inline void set_last_move(const char& letter) { last_move=letter;}
                inline int NumberOfMoves(void) const { return moveNumber;}
                inline void reset_moveNumber(void){ moveNumber=0;}
                inline void inc_moveNumber(const int& n) { moveNumber+=n;}
                inline void dec_moveNumber(const int& n) { moveNumber-=n;}
                inline int get_xSize(void) const { return xSize;}
                inline int get_ySize(void) const { return ySize;}
                void inc_number_of_boards(void) {++number_of_boards;}
                bool set_player_pos(void);
            private:
                vector<vector<int>> puzzle_map;
                vector<vector<int>> goal_map;
                int xSize,ySize;
                int playerX,playerY;
                int moveNumber;
                char last_move;
                string filename;
                int number_of_boards;
                void release_puzzle(void);
                void set_puzzle(void);
                void set_goal_puzzle(void);
                int get_digit(int number) const;
                bool is_number(const string& s1) const;
                int charToint(char) const;
                bool moveRight(void);
                bool moveLeft(void);
                bool moveUp(void);
                bool moveDown(void);
        };
        Board gameBoard;
        bool set_scenario_puzzle(NPuzzle::Board posBoard,const char& letter,bool& quit);
        bool is_in_boardsets(const NPuzzle::Board& posBoard) const;
        vector<Board> board_sets;
};
#endif  /*  _NPUZZLE_H  */