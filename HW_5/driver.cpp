/*______________________________________________________________________ _____________*/
/*Object-Oriented-Programming with C++ Language HW-5____________________ _____________*/
/*Student Name: NEVZAT SEFEROGLU________________________________________ _____________*/
/*Student Number: 171044024___________________________________________________________*/
/*Problem : Difference-Board implementation by using Inhertance-Polimorphism______ ___*/
/*______________________________________________________________________ _____________*/
#include <iostream>

/* Header Files which are already guarded by itself */

#include "./src/AbstractBoard.h"
#include "./src/BoardArray1D.h"
#include "./src/BoardArray2D.h"
#include "./src/BoardVector.h"
#include "./src/Global.h"

/* End of the inclusion */


/*****************************************************************************/

/* Code Snippets Control Macros Definition */
/* You can valid the test that you want to review by making 1 */
/* You can also make invalid that you do not want to review by making 0 */

#define TEST_BOARD_ARRAY_1D 1
#define TEST_BOARD_ARRAY_2D 0
#define TEST_BOARD_VECTOR 0
#define TEST_GLOBAL 0

/*****************************************************************************/

/* You can activate or inactivate sequences for checking the global function */
/* You can valid the test that you want to review by making 1 */
/* You can also make invalid that you do not want to review by making 0 */

#define TEST_SEQUENCE_1 1
#define TEST_SEQUENCE_2 0
#define TEST_SEQUENCE_3 0
#define TEST_SEQUENCE_4 0
#define TEST_SEQUENCE_5 0

/*****************************************************************************/

/* Specific members of std namepsace that I want to use */

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

/* End */


void test_BoardArray1D(void);
void test_BoardArray2D(void);
void test_BoardVector(void);
void test_global(void);

using  namespace NPuzzle;

int main( void )
{
    #if TEST_BOARD_ARRAY_1D
        test_BoardArray1D();
        cout << "NumberOfBoard = " << AbstractBoard::NumberOfBoards() << endl << endl;
    #endif
    

    #if TEST_BOARD_ARRAY_2D
        test_BoardArray2D();
        cout << "NumberOfBoard = " << AbstractBoard::NumberOfBoards() << endl << endl;
    #endif


    #if TEST_BOARD_VECTOR
        test_BoardVector();
        cout << "NumberOfBoard = " << AbstractBoard::NumberOfBoards() << endl << endl;
    #endif


    #if TEST_GLOBAL
        test_global();
        cout << "NumberOfBoard = " << AbstractBoard::NumberOfBoards() << endl << endl;
    #endif


    return 0;
}

void test_BoardArray1D(void)
{
    cout << endl;

    /* Decleration of BoardArray1D  with argument */
    BoardArray1D b1(4,3); /* Constructor with parameter */
    BoardArray1D b2(b1);  /* Copy Constructor */
    BoardArray1D b3;      /* No parameter Constructor  */
    BoardArray1D b4(3,5);      /* Created  for testing assignment operator */
    BoardArray1D b5("shape-puzzle"); /* Constructor with file */
    

    cout << b1.NumberOfBoards << endl;

    /* Print Function Test */
    cout << "print() func b1: " << endl;
    b1.print();
    cout << endl << endl;

    cout << "readFromFile('shapePuzzle') func b1: " << endl;
    b1.readFromFile("shapePuzzle");
    b1.print();
    cout << "Read from file !" << endl;
    cout << endl << endl;

    
    b1.reset();
    cout << "reset() func b1: " << endl;
    b1.print();
    cout << "Puzzle has been reset !" << endl;
    cout << endl << endl;

    b1.setSize(4,3);
    cout << "setSize("<< b1.get_xSize() << "," << b1.get_ySize() <<") func : " << endl;
    b1.print();
    cout << endl << endl;

    cout << "numberOfMoves() func b1: ";
    cout << b1.numberOfMoves() << endl << endl;

    cout << "move('L') func : b1" << endl;
    b1.move('L');
    b1.print();
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl;

    cout << "move('R') func : b1" << endl;
    b1.move('R');
    b1.print();
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl;

    cout << "move('U') func : b1" << endl;
    b1.move('U');
    b1.print();
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl;

    cout << "move('D') func : b1" << endl;
    b1.move('D');
    b1.print();
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl;

    b1.move('R');

    cout << "Attempt to move Right b1" << endl;
    b1.print();
    cout << "Invalid Move !" << endl;
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl << endl;

    cout << "numberOfMoves() func b1: ";
    cout << b1.numberOfMoves() << endl << endl;

    cout << "move('L') func : b1" << endl;
    b1.move('L');
    b1.print();
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl << endl; 

    cout << "isSolved() func : b1" << endl;
    if( b1.isSolved() )
        cout << "Puzzle has been solved ";
    else
        cout << "Puzzle has not been solved yet ! ";
    cout << endl << endl;
    
    cout << "move('R') func : b1" << endl;
    b1.move('R');
    b1.print();
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl << endl;

    cout << "isSolved() func : b1" << endl;
    if( b1.isSolved() )
        cout << "Puzzle has been solved !";
    else
        cout << "Puzzle has not been solved yet ! ";
    cout << endl << endl;

    b1.print();
    cout << "        (x,y) b1"<< endl;
    cout << "operator(2,1) = " << b1(2,1) << endl;
    cout << "operator(0,1) = " << b1(0,1);
    cout << endl << endl;

    
    cout << "move('L') func : b1" << endl;
    b1.move('L');
    b1.print();
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl;

    cout << "Moved Left twice times b2" << endl;
    b2.move('L');
    b2.move('L');
    b2.print();
    cout << "b2 lastMove () " << b2.lastMove() << endl;
    cout << endl;

    cout << "Board b1 object representation " << endl;
    b1.print();

    cout << "Board b2 object representation " << endl;
    b2.print();
    cout << endl << endl;  

    cout << "operator==() func : " << endl;
    if( b1 == b2 )
        cout << "b1 and b2  are equivalent !";
    else
        cout << "b1 and b2  are not equivalent !";
    cout << endl << endl;

    cout << "move('L') func : b1" << endl;
    b1.move('L');
    b1.print();
    cout << endl;

    cout << "lastMove of b1 ";
    cout << b1.lastMove()  << endl;
    cout << endl;

    cout << "Current b2 representation" << endl;
    b2.print();
    cout << endl;

    cout << "operator==() func : " << endl;
    if( b1 == b2 )
        cout << "b1 and b2  are equivalent !";
    else
        cout << "b1 and b2  are not equivalent !";
    cout << endl << endl;

    cout << " Declared like this -> ' BoardArray1D b4(3,5) ' representation which is declared before : " << endl;
    b4.print();
    cout << endl<< endl;

    cout << " Declared like this ->  ' BoardArray1D b5( 'shapePuzzle' ) ' representation which is declared before : " << endl;
    b5.print();
    cout << endl<< endl;

    cout << " operator=() func : " << endl;
    cout << " b4 = b5 " << endl;
    
    b4 = b5;

    cout << endl;

    cout << " b4 representation : " << endl;
    b4.print();

    cout << " b5 representation : " << endl;
    b5.print();

    cout << "***********************************************************************************\n";
    b3.setSize(4,3);
    cout << "setSize("<< b3.get_xSize() << "," << b3.get_ySize() <<") func : b3" << endl;
    b3.print();
    cout << "L , L , U , R , U move to show up the validity of assignment operator b3" << endl;
    b3.move('L');
    b3.move('L');
    b3.move('U');
    b3.move('R');
    b3.move('U');
    b3.print();
    cout << "b3 numberOfMoves() func : ";
    cout << b3.numberOfMoves() << endl;
    cout << "b3 lastMove() func : ";
    cout << b3.lastMove() << endl;
    cout << "***********************************************************************************\n\n";

    b4.setSize(4,3);
    cout << "setSize("<< b4.get_xSize() << "," << b4.get_ySize() <<") func : b4" << endl;
    b4.print();
    cout << "U , L , L , D move to show up the validity of assignment operator b4" << endl;
    b4.move('U');
    b4.move('L');
    b4.move('L');
    b4.move('D');
    b4.print();
    cout << "b4 numberOfMoves() func : ";
    cout << b4.numberOfMoves() << endl;
    cout << "b4 lastMove() func : ";
    cout << b4.lastMove() << endl;
    cout << "***********************************************************************************\n\n";

    cout << "Assinging the b3 to b4" << endl;
    cout << "b3 = b4" << endl;
    b4 = b3;

    cout << "Current statues of b4 : " << endl;
    b4.print();
    cout << "b4 numberOfMoves() func : ";
    cout << b4.numberOfMoves() << endl;
    cout << "b4 lastMove() func : ";
    cout << b4.lastMove() << endl;
    cout << "***********************************************************************************\n";
    cout << endl;
}

void test_BoardArray2D(void)
{
    cout << endl;

    /* Decleration of BoardArray1D  with argument */
    BoardArray2D b1(4,3); /* Constructor with parameter */
    BoardArray2D b2(b1);  /* Copy Constructor */
    BoardArray2D b3;      /* No parameter Constructor  */
    BoardArray2D b4(3,5);      /* Created  for testing assignment operator */
    BoardArray2D b5("shapePuzzle"); /* Constructor with file */

    /* Print Function Test */
    cout << "print() func b1: " << endl;
    b1.print();
    cout << endl << endl;

    cout << "readFromFile('shapePuzzle') func b1: " << endl;
    b1.readFromFile("shapePuzzle");
    b1.print();
    cout << "Read from file !" << endl;
    cout << endl << endl;

    
    b1.reset();
    cout << "reset() func b1: " << endl;
    b1.print();
    cout << "Puzzle has been reset !" << endl;
    cout << endl << endl;

    b1.setSize(4,3);
    cout << "setSize("<< b1.get_xSize() << "," << b1.get_ySize() <<") func : " << endl;
    b1.print();
    cout << endl << endl;

    cout << "numberOfMoves() func b1: ";
    cout << b1.numberOfMoves() << endl << endl;

    cout << "move('L') func : b1" << endl;
    b1.move('L');
    b1.print();
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl;

    cout << "move('R') func : b1" << endl;
    b1.move('R');
    b1.print();
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl;

    cout << "move('U') func : b1" << endl;
    b1.move('U');
    b1.print();
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl;

    cout << "move('D') func : b1" << endl;
    b1.move('D');
    b1.print();
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl;

    b1.move('R');

    cout << "Attempt to move Right b1" << endl;
    b1.print();
    cout << "Invalid Move !" << endl;
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl << endl;

    cout << "numberOfMoves() func b1: ";
    cout << b1.numberOfMoves() << endl << endl;

    cout << "move('L') func : b1" << endl;
    b1.move('L');
    b1.print();
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl << endl; 

    cout << "isSolved() func : b1" << endl;
    if( b1.isSolved() )
        cout << "Puzzle has been solved ";
    else
        cout << "Puzzle has not been solved yet ! ";
    cout << endl << endl;
    
    cout << "move('R') func : b1" << endl;
    b1.move('R');
    b1.print();
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl << endl;

    cout << "isSolved() func : b1" << endl;
    if( b1.isSolved() )
        cout << "Puzzle has been solved !";
    else
        cout << "Puzzle has not been solved yet ! ";
    cout << endl << endl;

    b1.print();
    cout << "        (x,y) b1"<< endl;
    cout << "operator(2,1) = " << b1(2,1) << endl;
    cout << "operator(0,1) = " << b1(0,1);
    cout << endl << endl;

    
    cout << "move('L') func : b1" << endl;
    b1.move('L');
    b1.print();
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl;

    cout << "Moved Left twice times b2" << endl;
    b2.move('L');
    b2.move('L');
    b2.print();
    cout << "b2 lastMove () " << b2.lastMove() << endl;
    cout << endl;

    cout << "Board b1 object representation " << endl;
    b1.print();

    cout << "Board b2 object representation " << endl;
    b2.print();
    cout << endl << endl;  

    cout << "operator==() func : " << endl;
    if( b1 == b2 )
        cout << "b1 and b2  are equivalent !";
    else
        cout << "b1 and b2  are not equivalent !";
    cout << endl << endl;

    cout << "move('L') func : b1" << endl;
    b1.move('L');
    b1.print();
    cout << endl;

    cout << "lastMove of b1 ";
    cout << b1.lastMove()  << endl;
    cout << endl;

    cout << "Current b2 representation" << endl;
    b2.print();
    cout << endl;

    cout << "operator==() func : " << endl;
    if( b1 == b2 )
        cout << "b1 and b2  are equivalent !";
    else
        cout << "b1 and b2  are not equivalent !";
    cout << endl << endl;

    cout << " Declared like this -> ' BoardArray2D b4(3,5) ' representation which is declared before : " << endl;
    b4.print();
    cout << endl<< endl;

    cout << " Declared like this ->  ' BoardArray2D b5( 'shapePuzzle' ) ' representation which is declared before : " << endl;
    b5.print();
    cout << endl<< endl;

    cout << "operator=() func : " << endl;
    cout << "b4 = b5 " << endl;

    b4 = b5;

    cout << endl;
    cout << " b4 representation : " << endl;
    b4.print();

    cout << " b5 representation : " << endl;
    b5.print();

    cout << "***********************************************************************************\n";
    b3.setSize(4,3);
    cout << "setSize("<< b3.get_xSize() << "," << b3.get_ySize() <<") func : b3" << endl;
    b3.print();
    cout << "L , L , U , R , U move to show up the validity of assignment operator b3" << endl;
    b3.move('L');
    b3.move('L');
    b3.move('U');
    b3.move('R');
    b3.move('U');
    b3.print();
    cout << "b3 numberOfMoves() func : ";
    cout << b3.numberOfMoves() << endl;
    cout << "b3 lastMove() func : ";
    cout << b3.lastMove() << endl;
    cout << "***********************************************************************************\n\n";

    b4.setSize(4,3);
    cout << "setSize("<< b4.get_xSize() << "," << b4.get_ySize() <<") func : b4" << endl;
    b4.print();
    cout << "U , L , L , D move to show up the validity of assignment operator b4" << endl;
    b4.move('U');
    b4.move('L');
    b4.move('L');
    b4.move('D');
    b4.print();
    cout << "b4 numberOfMoves() func : ";
    cout << b4.numberOfMoves() << endl;
    cout << "b4 lastMove() func : ";
    cout << b4.lastMove() << endl;
    cout << "***********************************************************************************\n\n";

    cout << "Assinging the b3 to b4" << endl;
    cout << "b3 = b4" << endl;
    b4 = b3;

    cout << "Current statues of b4 : " << endl;
    b4.print();
    cout << "b4 numberOfMoves() func : ";
    cout << b4.numberOfMoves() << endl;
    cout << "b4 lastMove() func : ";
    cout << b4.lastMove() << endl;
    cout << "***********************************************************************************\n";
    cout << endl;

}

void test_BoardVector(void)
{
    cout << endl;

    /* Decleration of BoardArray1D  with argument */
    BoardVector b1(4,3); /* Constructor with parameter */
    BoardVector b2(b1);  /* Copy Constructor */
    BoardVector b3;      /* No parameter Constructor  */
    BoardVector b4(3,5);      /* Created  for testing assignment operator */
    BoardVector b5("shapePuzzle"); /* Constructor with file */

    /* Print Function Test */
    cout << "print() func b1: " << endl;
    b1.print();
    cout << endl << endl;

    cout << "readFromFile('shapePuzzle') func b1: " << endl;
    b1.readFromFile("shapePuzzle");
    b1.print();
    cout << "Read from file !" << endl;
    cout << endl << endl;

    
    b1.reset();
    cout << "reset() func b1: " << endl;
    b1.print();
    cout << "Puzzle has been reset !" << endl;
    cout << endl << endl;

    b1.setSize(4,3);
    cout << "setSize("<< b1.get_xSize() << "," << b1.get_ySize() <<") func : " << endl;
    b1.print();
    cout << endl << endl;

    cout << "numberOfMoves() func b1: ";
    cout << b1.numberOfMoves() << endl << endl;

    cout << "move('L') func : b1" << endl;
    b1.move('L');
    b1.print();
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl;

    cout << "move('R') func : b1" << endl;
    b1.move('R');
    b1.print();
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl;

    cout << "move('U') func : b1" << endl;
    b1.move('U');
    b1.print();
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl;

    cout << "move('D') func : b1" << endl;
    b1.move('D');
    b1.print();
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl;

    b1.move('R');

    cout << "Attempt to move Right b1" << endl;
    b1.print();
    cout << "Invalid Move !" << endl;
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl << endl;

    cout << "numberOfMoves() func b1: ";
    cout << b1.numberOfMoves() << endl << endl;

    cout << "move('L') func : b1" << endl;
    b1.move('L');
    b1.print();
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl << endl; 

    cout << "isSolved() func : b1" << endl;
    if( b1.isSolved() )
        cout << "Puzzle has been solved ";
    else
        cout << "Puzzle has not been solved yet ! ";
    cout << endl << endl;
    
    cout << "move('R') func : b1" << endl;
    b1.move('R');
    b1.print();
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl << endl;

    cout << "isSolved() func : b1" << endl;
    if( b1.isSolved() )
        cout << "Puzzle has been solved !";
    else
        cout << "Puzzle has not been solved yet ! ";
    cout << endl << endl;

    b1.print();
    cout << "        (x,y) b1"<< endl;
    cout << "operator(2,1) = " << b1(2,1) << endl;
    cout << "operator(0,1) = " << b1(0,1);
    cout << endl << endl;

    cout << "move('L') func : b1" << endl;
    b1.move('L');
    b1.print();
    cout << "lastMove () " << b1.lastMove() << endl;
    cout << endl;

    cout << "Moved Left twice times b2" << endl;
    b2.move('L');
    b2.move('L');
    b2.print();
    cout << "b2 lastMove () " << b2.lastMove() << endl;
    cout << endl;

    cout << "Board b1 object representation " << endl;
    b1.print();

    cout << "Board b2 object representation " << endl;
    b2.print();
    cout << endl << endl;  

    cout << "operator==() func : " << endl;
    if( b1 == b2 )
        cout << "b1 and b2  are equivalent !";
    else
        cout << "b1 and b2  are not equivalent !";
    cout << endl << endl;

    cout << "move('L') func : b1" << endl;
    b1.move('L');
    b1.print();
    cout << endl;

    cout << "lastMove of b1 ";
    cout << b1.lastMove()  << endl;
    cout << endl;

    cout << "Current b2 representation" << endl;
    b2.print();
    cout << endl;

    cout << "operator==() func : " << endl;
    if( b1 == b2 )
        cout << "b1 and b2  are equivalent !";
    else
        cout << "b1 and b2  are not equivalent !";
    cout << endl << endl;

    cout << " Declared like this -> ' BoardVector b4(3,5) ' representation which is declared before : " << endl;
    b4.print();
    cout << endl << endl;

    cout << " Declared like this ->  ' BoardVector b5( 'shapePuzzle' ) ' representation which is declared before : " << endl;
    b5.print();
    cout << endl << endl;

    cout << " operator=() func : " << endl;
    cout << " b4 = b5 " << endl;
    
    b4 = b5;
    cout << endl;

    cout << " b4 representation : " << endl;
    b4.print();

    cout << " b5 representation : " << endl;
    b5.print();

    cout << "***********************************************************************************\n";
    b3.setSize(4,3);
    cout << "setSize("<< b3.get_xSize() << "," << b3.get_ySize() <<") func : b3" << endl;
    b3.print();
    cout << "L , L , U , R , U move to show up the validity of assignment operator b3" << endl;
    b3.move('L');
    b3.move('L');
    b3.move('U');
    b3.move('R');
    b3.move('U');
    b3.print();
    cout << "b3 numberOfMoves() func : ";
    cout << b3.numberOfMoves() << endl;
    cout << "b3 lastMove() func : ";
    cout << b3.lastMove() << endl;
    cout << "***********************************************************************************\n\n";

    b4.setSize(4,3);
    cout << "setSize("<< b4.get_xSize() << "," << b4.get_ySize() <<") func : b4" << endl;
    b4.print();
    cout << "U , L , L , D move to show up the validity of assignment operator b4" << endl;
    b4.move('U');
    b4.move('L');
    b4.move('L');
    b4.move('D');
    b4.print();
    cout << "b4 numberOfMoves() func : ";
    cout << b4.numberOfMoves() << endl;
    cout << "b4 lastMove() func : ";
    cout << b4.lastMove() << endl;
    cout << "***********************************************************************************\n\n";

    cout << "Assinging the b3 to b4" << endl;
    cout << "b3 = b4" << endl;
    b4 = b3;

    cout << "Current statues of b4 : " << endl;
    b4.print();
    cout << "b4 numberOfMoves() func : ";
    cout << b4.numberOfMoves() << endl;
    cout << "b4 lastMove() func : ";
    cout << b4.lastMove() << endl;
    cout << "***********************************************************************************\n";
    cout << endl;
}

void test_global(void)
{
    AbstractBoard* Test1_Sequence[5];
    AbstractBoard* Test2_Sequence[4];
    AbstractBoard* Test3_Sequence[3];
    AbstractBoard* Test4_Sequence[3];
    AbstractBoard* Test5_Sequence[5];

    Test1_Sequence[ 0 ] = new BoardArray1D("./test-txt/Test1_Sequence/puzzle1.txt");
    Test1_Sequence[ 1 ] = new BoardArray2D("./test-txt/Test1_Sequence/puzzle2.txt");
    Test1_Sequence[ 2 ] = new BoardVector("./test-txt/Test1_Sequence/puzzle3.txt");
    Test1_Sequence[ 3 ] = new BoardArray2D("./test-txt/Test1_Sequence/puzzle4.txt");
    Test1_Sequence[ 4 ] = new BoardArray1D("./test-txt/Test1_Sequence/puzzle5.txt");

    Test2_Sequence[ 0 ] = new BoardArray1D("./test-txt/Test2_Sequence/puzzle1.txt");
    Test2_Sequence[ 1 ] = new BoardArray2D("./test-txt/Test2_Sequence/puzzle2.txt");
    Test2_Sequence[ 2 ] = new BoardVector("./test-txt/Test2_Sequence/puzzle3.txt");
    Test2_Sequence[ 3 ] = new BoardVector("./test-txt/Test2_Sequence/puzzle4.txt");

    Test3_Sequence[ 0 ] = new BoardArray1D("./test-txt/Test3_Sequence/puzzle1.txt");
    Test3_Sequence[ 1 ] = new BoardArray2D("./test-txt/Test3_Sequence/puzzle2.txt");
    Test3_Sequence[ 2 ] = new BoardVector("./test-txt/Test3_Sequence/puzzle3.txt");

    Test4_Sequence[ 0 ] = new BoardArray1D("./test-txt/Test4_Sequence/puzzle1.txt");
    Test4_Sequence[ 1 ] = new BoardArray2D("./test-txt/Test4_Sequence/puzzle2.txt");
    Test4_Sequence[ 2 ] = new BoardVector("./test-txt/Test4_Sequence/puzzle3.txt");

    Test5_Sequence[ 0 ] = new BoardArray1D("./test-txt/Test5_Sequence/puzzle1.txt");
    Test5_Sequence[ 1 ] = new BoardArray2D("./test-txt/Test5_Sequence/puzzle2.txt");
    Test5_Sequence[ 2 ] = new BoardVector("./test-txt/Test5_Sequence/puzzle3.txt");
    Test5_Sequence[ 3 ] = new BoardArray2D("./test-txt/Test5_Sequence/puzzle4.txt");
    Test5_Sequence[ 4 ] = new BoardArray1D("./test-txt/Test5_Sequence/puzzle5.txt");


    cout << endl <<"**********GLOBAL-FUNCTION-TEST*****************" << endl;
    cout << "===============================================" << endl << endl;

    #if TEST_SEQUENCE_1
        cout << "*********SEQUENCE_1_TEST**********" << endl;
        for( int i = 0 ; i < 5 ; ++i )
        {
            Test1_Sequence[i] -> print();
            cout << endl << endl;
        }

        if(is_ValidSequence(Test1_Sequence , 5))
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
        cout << "*********SEQUENCE_1_TEST_END*******" << endl << endl;
    #endif

    #if TEST_SEQUENCE_2
        cout << "*********SEQUENCE_2_TEST**********" << endl;
        for( int i = 0 ; i < 4 ; ++i )
        {
            Test2_Sequence[i] -> print();
            cout << endl << endl;
        }

        if(is_ValidSequence(Test2_Sequence , 4))
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
        cout << "********SEQUENCE_2_TEST_END*******" << endl << endl;
    #endif
    
    #if TEST_SEQUENCE_3
        cout << "*********SEQUENCE_3_TEST**********" << endl;
        for( int i = 0 ; i < 3 ; ++i )
        {
            Test3_Sequence[i] -> print();
            cout << endl << endl;
        }

        if(is_ValidSequence(Test3_Sequence , 3))
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
        cout << "********SEQUENCE_3_TEST_END*******" << endl << endl;
    #endif

    #if TEST_SEQUENCE_4
        cout << "*********SEQUENCE_4_TEST**********" << endl;
        for( int i = 0 ; i < 3 ; ++i )
        {
            Test4_Sequence[i] -> print();
            cout << endl << endl;
        }

        if(is_ValidSequence(Test4_Sequence , 3))
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
        cout << "********SEQUENCE_4_TEST_END*******" << endl << endl;
    #endif

    #if TEST_SEQUENCE_5
        cout << "*********SEQUENCE_5_TEST**********" << endl;
        for( int i = 0 ; i < 5 ; ++i )
        {
            Test5_Sequence[i] -> print();
            cout << endl << endl;
        }

        if(is_ValidSequence(Test5_Sequence , 5))
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
        cout << "********SEQUENCE_5_TEST_END*******" << endl << endl;
    #endif

    cout << "**********GLOBAL-FUNCTION-TEST-END*************" << endl;
    cout << "===============================================" << endl;

    for( int i = 0 ; i < 5 ; ++i )
        delete Test1_Sequence[i];
    for( int i = 0 ; i < 4 ; ++i )
        delete Test2_Sequence[i];
    for( int i = 0 ; i < 3 ; ++i )
        delete Test3_Sequence[i];
    for( int i = 0 ; i < 3 ; ++i )
        delete Test4_Sequence[i];
    for( int i = 0 ; i < 5 ; ++i )
        delete Test5_Sequence[i];
}