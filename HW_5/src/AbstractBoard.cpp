#include <iostream>

/* It has been already saved by itself */

/* I just intend to remark it since I have used a lot of function
from IOSTREAM */

#include "AbstractBoard.h"

namespace
{
    using std::string;

    bool is_number(const string& s1)
    {
        bool flag = true;
        for(unsigned int i = 0 ; i < s1.size() && flag ; ++i)
        {
            if( s1[i] < '0'|| s1[i] > '9' )
                flag = false;
        }

        return flag;
    }

    int get_digit(int number)
    {
        int counter = 1;
        while(number /= 10)
            ++counter;
        return counter;
    }
}
namespace NPuzzle
{
    using std::string;
    using std::cout;
    using std::cin;
    using std::cerr;
    using std::endl;
    using std::ifstream;
    using std::ofstream;
    using std::ios_base;

    int AbstractBoard::Number_Of_Boards = 0;

    AbstractBoard::AbstractBoard(void) : blankRepresentation(-1)
    {
        cout << "hey" << endl;
        ++Number_Of_Boards;
        /* Implementation should be located right there */
    }

    void AbstractBoard::print(void) const
    {
        for(int j = 0 ; j < ySize;++j)
        {
            for(int i = 0 ; i < xSize;++i)
            {
                if( this->operator()(i,j) == blankRepresentation)
                    cout << "\t";
                else if( this->operator()(i,j) == 0)
                    cout << "\tX";
                else
                    cout << "\t" << this->operator()(i,j);
            }
            cout << endl<< endl;
        }
    }

    void AbstractBoard::readFromFile(const string& filename)
    {
        char next = '\0' , prev = '\0';

        bool initialCheck=true;

        int xSize = 0 , ySize = 0;

        
        string strNum;
        strNum.empty();

        /* Board need to be release */

        ifstream inStream;
        
        inStream.open(filename,ios_base::in);

        if(inStream.fail())
        {
            cerr << "\nInput file opening error !\n\n";
            exit(1);
        }

        while(next != '\n')
        {
            next = inStream.get();

            if(next != ' ' && initialCheck)
                ++xSize;
            
            initialCheck = false;
            
            if( next != ' ' && next != '\n' && prev == ' ' )
                ++xSize;
            
            prev = next;
        }
        
        initialCheck = true;
        next = '\0' , prev = '\0';
        inStream.clear();
        inStream.seekg(ios_base::beg);

        while( !inStream.eof() )
        {
            next = inStream.get();

            if( next == '\n' && initialCheck )
                --ySize;
            
            initialCheck=false;
            
            if( next == '\n' && prev != '\n' )
                ++ySize;
            
            if( inStream.eof() && prev != '\n' )
                ++ySize;
            
            prev = next;
        }

        inStream.clear();
        inStream.seekg(ios_base::beg);
        
        setSize( xSize , ySize );

        for( int j = 0 ; j < ySize ; ++j )
        {
            for( int i = 0 ; i < xSize ; ++i )
            {
                inStream >> strNum;

                if( !is_number(strNum) )
                    this -> operator()(i,j) = blankRepresentation;
                
                else
                    this -> operator()(i,j) = stoi(strNum);
            }
        }
        
        inStream.close();
    }

    int AbstractBoard::NumberOfBoards( void )
    {
        return Number_Of_Boards;
    }
    void AbstractBoard::writeToFile(const string& filename)
    {
        int maxNumber = 0 , difNumber = 0 , borderAmount = 0;

        for(int j = 0 ; j < ySize;++j)
            for(int i = 0 ; i < xSize;++i)
                if( this -> operator()( i , j ) == 0 )
                        ++borderAmount;

        maxNumber = get_xSize() * get_ySize() - 1 - borderAmount;

        ofstream outStream;
        outStream.open( filename,ios_base::out );

        if( outStream.fail() )
        {
            cerr << "File could not be opened to load !" << endl;
            exit(-1);
        }

        for( int j = 0 ; j < get_ySize() ; ++j )
        {
            for( int i = 0 ; i < get_xSize() ; ++i )
            {
                if( this -> operator()( i , j ) != blankRepresentation )
                {
                    if( get_digit( this -> operator()( i , j ) ) == get_digit( maxNumber ) )
                    {
                        if( get_digit( this -> operator()( i , j ) ) == 1 )
                            outStream << '0' << this -> operator()( i , j );
                        else
                            outStream << this -> operator()( i , j );
                    }
                    else
                    {
                        difNumber = get_digit( maxNumber ) - get_digit( this -> operator()( i , j ) );

                        for( int k = 0 ; k < difNumber ; ++k )
                            outStream << 0;
                            
                        outStream << this -> operator()( i , j );
                        difNumber = 0;
                    }
                }
                else
                {
                    if( get_digit( maxNumber ) == 1 )
                        outStream << "bb";
                    else
                    {
                        for( int k = 0 ; k < get_digit( maxNumber ) ; ++k )
                            outStream << "b";
                    }
                    
                }
                if( i != get_xSize() - 1 )
                    outStream << " ";
            }
            if( j != get_ySize() - 1 )
                outStream << endl;
        }

        outStream.close();
    }

    void AbstractBoard::reset(void)
    {
        int counter = 1;

        for( int j = 0 ; j < get_ySize() ; ++j )
            for( int i = 0 ; i < get_xSize() ; ++i )
            {
                if( this -> operator()( i , j ) != 0 )
                {
                    this -> operator()( i , j ) = counter;
                    ++counter;
                }
            }

        this -> operator()( get_xSize() - 1 , get_ySize() - 1 ) = blankRepresentation;

        number_Of_Moves = 0;
        last_Move = 'S';

    }

    void AbstractBoard::setSize( const int& xSize , const int& ySize )
    {
        if( xSize <= 1 || ySize <= 1 )
        {
            cerr << endl << "Invalid size for argument ! " << endl << endl;
            exit(1);
        }

        this -> xSize = xSize;
        this -> ySize = ySize;
        
        number_Of_Moves = 0;
        last_Move = 'S';
    }
    
    bool AbstractBoard::move(const char& letter)
    {
        bool flag = true;

        set_player_pos();
        
        switch(letter)
        {
            case 'r':case 'R':
                flag = moveRight();
            break;

            case 'l':case 'L':
                flag = moveLeft();
                break;

            case 'u':case 'U':
                flag = moveUp();
                break;

            case 'd':case 'D':
                flag = moveDown();
                break;

            default:
                flag = false;
                break;
        }
        
        if( flag )
        {
            ++number_Of_Moves;
            last_Move = letter;
        }

        set_player_pos();
        
        return flag;
    }

    bool AbstractBoard::isSolved(void) const
    {
        int counter = 1;

        for( int j = 0 ; j < get_ySize() ; ++j )
        {
            for( int i = 0 ; i < get_xSize() ; ++i )
            {
                if( this -> operator()( i , j ) != 0 && this -> operator()( i , j ) == counter )
                    ++counter;
                else if( !(counter == get_xSize() * get_ySize() && this -> operator()( i , j ) == blankRepresentation) )
                    return false;
            }
        }
        
        return true;
    }

    bool AbstractBoard::operator==(const AbstractBoard& other) const
    {
        if( get_xSize() != other.get_xSize() || get_ySize() != other.get_ySize() )
            return false;
        
        for( int j = 0 ; j < get_ySize() ; ++j )
            for( int i = 0 ; i < get_xSize() ; ++i )
                if( this -> operator()( i , j ) != other.operator()( i , j ) )
                    return false;
                    
        return true;
    }

    /* There are two seperate function decleration for ()  overloading */
    /* Because the issues of rvalue and lvalue */


    AbstractBoard::~AbstractBoard()
    {
    }

    /* After this point , there are my own functions */
    /* My inline function`s definition in the class  */
    
    bool AbstractBoard::set_player_pos(void)
    {
        for(int j = 0 ; j < ySize ; ++j)
            for(int i = 0 ; i < xSize ; ++i)
                if(this -> operator()( i , j ) == blankRepresentation )
                {
                    playerX = i , playerY = j;
                    return true;
                }
        return false;
    }

    bool AbstractBoard::moveRight(void)
    {
        if( ( playerX + 1  )< xSize && this->operator()( playerX + 1, playerY ) != 0)
        {
            this->operator()( playerX, playerY ) = this->operator()( playerX + 1, playerY );
            this->operator()( playerX + 1, playerY ) = blankRepresentation;

            return true;
        }
        return false;
    }

    bool AbstractBoard::moveLeft(void)
    {
        if( ( playerX - 1  ) >= 0 && this->operator()( playerX - 1, playerY ) != 0)
        {
            this->operator()( playerX, playerY ) = this->operator()( playerX - 1, playerY );
            this->operator()( playerX - 1, playerY ) = blankRepresentation;
            
            return true;
        }
        return false;
    }

    bool AbstractBoard::moveUp(void)
    {
        if( ( playerY - 1  ) >= 0 && this->operator()( playerX , playerY - 1 ) != 0)
        {
            this->operator()( playerX, playerY ) = this->operator()( playerX , playerY - 1 );
            this->operator()( playerX , playerY - 1 ) = blankRepresentation;

            return true;
        }

        return false;
    }

    bool AbstractBoard::moveDown(void)
    {
        if( ( playerY + 1  ) < ySize && this->operator()( playerX , playerY + 1 ) != 0)
        {
            this->operator()( playerX, playerY ) = this->operator()( playerX , playerY + 1 );
            this->operator()( playerX , playerY + 1 ) = blankRepresentation;
            
            return true;
        }
        return false;
    }
    
}
