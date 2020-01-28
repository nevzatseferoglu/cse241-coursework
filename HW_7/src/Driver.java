import Board.*;

/**
 * Board constructing program with a several function
 * that can be used in many
 * puzzle based game.
 * @author Nevzat Seferoglu
 * @version 1.0
 * @since 14-01-2020
 */

public class Driver {

    /* You can activate or inactivate Board Class type or global function , it would be east to debug the code */

    static final boolean TEST_BOARD_ARRAY_1D = true;
    static final boolean TEST_BOARD_ARRAY_2D = true;
    static final boolean TEST_GLOBAL = true;

    /* You can activate or inactivate sequences for checking the global function */
    /* You can valid the test that you want to review by making true */
    /* You can also make invalid that you do not want to review , by making false */

    static final boolean TEST_SEQUENCE_1 = true;
    static final boolean TEST_SEQUENCE_2 = false;
    static final boolean TEST_SEQUENCE_3 = false;
    static final boolean TEST_SEQUENCE_4 = false;
    static final boolean TEST_SEQUENCE_5 = false;


    public static void main(String... args) {

        try
        {
            if (TEST_BOARD_ARRAY_1D) {
                test_BoardArray1D();
                System.out.println("NumberOfBoard = " + AbstractBoard.NumberOfBoards());
            }

            if (TEST_BOARD_ARRAY_2D) {
                test_BoardArray2D();
                System.out.println("NumberOfBoard = " + AbstractBoard.NumberOfBoards());
            }

            if ( TEST_GLOBAL ) {
                test_global();
                System.out.println("NumberOfBoard = " + AbstractBoard.NumberOfBoards());
            }

        }
        catch (Exception ExceptionPackage) {
            System.out.println(ExceptionPackage.getMessage());
        }
    }

    static void test_BoardArray1D( ) {

        try {
                /* Decleration of BoardArray1D  with argument */
                BoardArray1D b1 = new BoardArray1D(4, 3); /* Constructor with parameter */
                BoardArray1D b2 = new BoardArray1D(b1);                         /* Copy Constructor */
                BoardArray1D b3 = new BoardArray1D();                           /* No parameter Constructor  */
                BoardArray1D b4 = new BoardArray1D(3, 5);            /* Created  for testing assignment operator */
                BoardArray1D b5 = new BoardArray1D("shape-puzzle");    /* Constructor with file */

                System.out.println("===========BoardArray1D-Start==============================");

                /* Print Function Test */
                System.out.println("print() func b1: ");
                b1.print();
                System.out.println(" ");
                System.out.println(" ");

                System.out.println("readFromFile('shape-puzzle') func b1: ");
                b1.readFromFile("shape-puzzle");
                b1.print();
                System.out.println(" ");
                System.out.println(" ");


                b1.reset();
                System.out.println("reset() func b1");
                b1.print();
                System.out.println("Puzzle has been reset !");
                System.out.println(" ");
                System.out.println(" ");

                b1.setSize(4, 3);
                System.out.println("setSize(" + b1.get_xSize() + "," + b1.get_ySize() + ") func : ");
                b1.print();
                System.out.println(" ");
                System.out.println(" ");

                System.out.println("numberOfMoves() func b1: ");
                System.out.println(b1.numberOfMoves());
                System.out.println(" ");

                System.out.println("move('L') func : b1");
                b1.move('L');
                b1.print();
                System.out.println("lastMove () " + b1.lastMove());
                System.out.println(" ");

                System.out.println("move('R') func : b1");
                b1.move('R');
                b1.print();

                System.out.println("move('U') func : b1");
                b1.move('U');
                b1.print();

                System.out.println("move('D') func : b1");
                b1.move('D');
                b1.print();

                b1.move('R');
                System.out.println("Attempt to move Right b1");
                b1.print();
                System.out.println("lastMove () " + b1.lastMove());
                System.out.println(" ");
                System.out.println(" ");

                System.out.println("numberOfMoves() func b1: ");
                System.out.println(b1.numberOfMoves());
                System.out.println(" ");


                System.out.println("move('L') func : b1");
                b1.move('L');
                b1.print();
                System.out.println(" ");
                System.out.println(" ");

                System.out.println("isSolved() func : b1");
                if (b1.isSolved())
                    System.out.println("Puzzle has been solved ");
                else
                    System.out.println("Puzzle has not been solved yet ! ");
                System.out.println(" ");
                System.out.println(" ");

                System.out.println("move('R') func : b1");
                b1.move('R');
                b1.print();
                System.out.println(" ");
                System.out.println(" ");

                System.out.println("isSolved() func : b1");
                if (b1.isSolved())
                    System.out.println("Puzzle has been solved ");
                else
                    System.out.println("Puzzle has not been solved yet ! ");
                System.out.println(" ");
                System.out.println(" ");

                b1.print();
                System.out.println("        (x,y) b1");
                System.out.println("cell(2,1) = " + b1.cell(2, 1));
                System.out.println("cell(0,1) = " + b1.cell(0, 1));
                System.out.println(" ");
                System.out.println(" ");

                System.out.println("move('L') func : b1");
                b1.move('L');
                b1.print();
                System.out.println(" ");
                System.out.println(" ");

                System.out.println("Moved Left twice times b2");
                b2.move('L');
                b2.move('L');
                b2.print();
                System.out.println("b2 lastMove () " + b2.lastMove());
                System.out.println(" ");

                System.out.println("Board b1 object representation ");
                b1.print();

                System.out.println("Board b2 object representation ");
                b2.print();
                System.out.println(" ");
                System.out.println(" ");

                System.out.println("Equals func : ");
                if (b1.equals(b2))
                    System.out.println("b1 and b2  are equivalent !");
                else
                    System.out.println("b1 and b2  are not equivalent !");
                System.out.println(" ");
                System.out.println(" ");

                System.out.println("move('L') func : b1");
                b1.move('L');
                b1.print();
                System.out.println(" ");

                System.out.println("lastMove of b1 ");
                System.out.println(b1.lastMove());
                System.out.println(" ");

                System.out.println("Current b2 representation");
                b2.print();
                System.out.println(" ");

                System.out.println("Equals func : ");
                if (b1.equals(b2))
                    System.out.println("b1 and b2  are equivalent !");
                else
                    System.out.println("b1 and b2  are not equivalent !");
                System.out.println(" ");
                System.out.println(" ");

                System.out.println(" Declared like this -> ' BoardArray1D b3 = new BoardArray1D(3,5) ' representation which is declared before : ");
                b3.print();
                System.out.println(" ");
                System.out.println(" ");

                System.out.println(" Declared like this -> ' BoardArray1D b4 = new BoardArray1D(3,5) ' representation which is declared before : ");
                b4.print();
                System.out.println(" ");
                System.out.println(" ");

                System.out.println(" Declared like this ->  ' BoardArray1D b5 = new BoardArray1D ( 'shape-puzzle' )  representation which is declared before : ");
                b5.print();
                System.out.println(" ");
                System.out.println(" ");

                System.out.println("b2 toString()");
                System.out.println(b2);
                System.out.println(" ");
                b2.writeToFile("b2-output.txt");
                System.out.println("writeToFile(b2) to file b2-output.txt ");

                System.out.println("b1 toString : ");
                System.out.println(b1);

                System.out.println("b1 toString : ");
                System.out.println(b1);

                System.out.println("b2 toString : ");
                System.out.println(b2);

                System.out.println("b3 toString : ");
                System.out.println(b3);

                System.out.println("b4 toString : ");
                System.out.println(b4);

                System.out.println("b5 toString : ");
                System.out.println(b5);

                System.out.println(" ( BoardArray1D b6 = (BoardArray1D)b5.clone() ");
                BoardArray1D b6 = (BoardArray1D)b5.clone();
                System.out.println("b6 toString");
                System.out.println(b6);

                System.out.println();
        }
        catch (Exception ExceptionPackage)
        {
            System.out.println(ExceptionPackage.getMessage());
        }
        finally {
            System.out.println("===========BoardArray1D-End==============================");
        }
    }

    static void test_global( ) {

        try
        {
            AbstractBoard[] Test1_Sequence = new AbstractBoard[5];
            AbstractBoard[] Test2_Sequence = new AbstractBoard[4];
            AbstractBoard[] Test3_Sequence = new AbstractBoard[3];
            AbstractBoard[] Test4_Sequence = new AbstractBoard[3];
            AbstractBoard[] Test5_Sequence = new AbstractBoard[5];

            Test1_Sequence[ 0 ] = new BoardArray1D("./test-txt/Test1_Sequence/puzzle1.txt");
            Test1_Sequence[ 1 ] = new BoardArray2D("./test-txt/Test1_Sequence/puzzle2.txt");
            Test1_Sequence[ 2 ] = new BoardArray1D("./test-txt/Test1_Sequence/puzzle3.txt");
            Test1_Sequence[ 3 ] = new BoardArray2D("./test-txt/Test1_Sequence/puzzle4.txt");
            Test1_Sequence[ 4 ] = new BoardArray1D("./test-txt/Test1_Sequence/puzzle5.txt");

            Test2_Sequence[ 0 ] = new BoardArray1D("./test-txt/Test2_Sequence/puzzle1.txt");
            Test2_Sequence[ 1 ] = new BoardArray2D("./test-txt/Test2_Sequence/puzzle2.txt");
            Test2_Sequence[ 2 ] = new BoardArray1D("./test-txt/Test2_Sequence/puzzle3.txt");
            Test2_Sequence[ 3 ] = new BoardArray2D("./test-txt/Test2_Sequence/puzzle4.txt");

            Test3_Sequence[ 0 ] = new BoardArray1D("./test-txt/Test3_Sequence/puzzle1.txt");
            Test3_Sequence[ 1 ] = new BoardArray2D("./test-txt/Test3_Sequence/puzzle2.txt");
            Test3_Sequence[ 2 ] = new BoardArray1D("./test-txt/Test3_Sequence/puzzle3.txt");

            Test4_Sequence[ 0 ] = new BoardArray1D("./test-txt/Test4_Sequence/puzzle1.txt");
            Test4_Sequence[ 1 ] = new BoardArray2D("./test-txt/Test4_Sequence/puzzle2.txt");
            Test4_Sequence[ 2 ] = new BoardArray1D("./test-txt/Test4_Sequence/puzzle3.txt");

            Test5_Sequence[ 0 ] = new BoardArray1D("./test-txt/Test5_Sequence/puzzle1.txt");
            Test5_Sequence[ 1 ] = new BoardArray2D("./test-txt/Test5_Sequence/puzzle2.txt");
            Test5_Sequence[ 2 ] = new BoardArray2D("./test-txt/Test5_Sequence/puzzle3.txt");
            Test5_Sequence[ 3 ] = new BoardArray2D("./test-txt/Test5_Sequence/puzzle4.txt");
            Test5_Sequence[ 4 ] = new BoardArray1D("./test-txt/Test5_Sequence/puzzle5.txt");

            System.out.println("\n**********GLOBAL-FUNCTION-TEST*****************");
            System.out.println("===============================================\n\n");

            System.out.println("*********SEQUENCE_1_TEST**********");
            for( int i = 0 ; i < Test1_Sequence.length ; ++i )
            {
                Test1_Sequence[i].print();
                System.out.println("");
                System.out.println("");
            }

            if( BoardGlobal.isValidMovement( Test1_Sequence ) )
                System.out.println("Valid");
            else
                System.out.println("Invalid");
            System.out.println("*********SEQUENCE_1_TEST_END*******");

            System.out.println("*********SEQUENCE_2_TEST**********");
            for( int i = 0 ; i < Test2_Sequence.length ; ++i )
            {
                Test2_Sequence[i].print();
                System.out.println("");
                System.out.println("");
            }

            if( BoardGlobal.isValidMovement( Test2_Sequence ) )
                System.out.println("Valid");
            else
                System.out.println("Invalid");
            System.out.println("*********SEQUENCE_2_TEST_END*******");

            System.out.println("*********SEQUENCE_3_TEST**********");
            for( int i = 0 ; i < Test3_Sequence.length ; ++i )
            {
                Test3_Sequence[i].print();
                System.out.println("");
                System.out.println("");
            }

            if( BoardGlobal.isValidMovement( Test3_Sequence ) )
                System.out.println("Valid");
            else
                System.out.println("Invalid");
            System.out.println("*********SEQUENCE_3_TEST_END*******");


            System.out.println("*********SEQUENCE_4_TEST**********");
            for( int i = 0 ; i < Test4_Sequence.length ; ++i )
            {
                Test4_Sequence[i].print();
                System.out.println("");
                System.out.println("");
            }

            if( BoardGlobal.isValidMovement( Test4_Sequence ) )
                System.out.println("Valid");
            else
                System.out.println("Invalid");
            System.out.println("*********SEQUENCE_4_TEST_END*******");

            System.out.println("*********SEQUENCE_5_TEST**********");
            for( int i = 0 ; i < Test5_Sequence.length ; ++i )
            {
                Test5_Sequence[i].print();
                System.out.println("");
                System.out.println("");
            }

            if( BoardGlobal.isValidMovement( Test5_Sequence ) )
                System.out.println("Valid");
            else
                System.out.println("Invalid");
            System.out.println("*********SEQUENCE_5_TEST_END*******");

            System.out.println("\n**********GLOBAL-FUNCTION-TEST-END*****************");
            System.out.println("===============================================\n\n");
        }
        catch (Exception ExceptionPackage)
        {
            System.out.println(ExceptionPackage.getMessage());
        }
    }

    static void test_BoardArray2D( ) {
        try {
            /* Decleration of BoardArray2D  with argument */
            BoardArray2D b1 = new BoardArray2D(4, 3); /* Constructor with parameter */
            BoardArray2D b2 = new BoardArray2D(b1);                         /* Copy Constructor */
            BoardArray2D b3 = new BoardArray2D();                           /* No parameter Constructor  */
            BoardArray2D b4 = new BoardArray2D(3, 5);            /* Created  for testing assignment operator */
            BoardArray2D b5 = new BoardArray2D("shape-puzzle");    /* Constructor with file */

            System.out.println("===========BoardArray2D-Start==============================");
            /* Print Function Test */
            System.out.println("print() func b1: ");
            b1.print();
            System.out.println(" ");
            System.out.println(" ");

            System.out.println("readFromFile('shape-puzzle') func b1: ");
            b1.readFromFile("shape-puzzle");
            b1.print();
            System.out.println(" ");
            System.out.println(" ");


            b1.reset();
            System.out.println("reset() func b1");
            b1.print();
            System.out.println("Puzzle has been reset !");
            System.out.println(" ");
            System.out.println(" ");

            b1.setSize(4, 3);
            System.out.println("setSize(" + b1.get_xSize() + "," + b1.get_ySize() + ") func : ");
            b1.print();
            System.out.println(" ");
            System.out.println(" ");

            System.out.println("numberOfMoves() func b1: ");
            System.out.println(b1.numberOfMoves());
            System.out.println(" ");

            System.out.println("move('L') func : b1");
            b1.move('L');
            b1.print();
            System.out.println("lastMove () " + b1.lastMove());
            System.out.println(" ");

            System.out.println("move('R') func : b1");
            b1.move('R');
            b1.print();

            System.out.println("move('U') func : b1");
            b1.move('U');
            b1.print();

            System.out.println("move('D') func : b1");
            b1.move('D');
            b1.print();

            b1.move('R');
            System.out.println("Attempt to move Right b1");
            b1.print();
            System.out.println("lastMove () " + b1.lastMove());
            System.out.println(" ");
            System.out.println(" ");

            System.out.println("numberOfMoves() func b1: ");
            System.out.println(b1.numberOfMoves());
            System.out.println(" ");


            System.out.println("move('L') func : b1");
            b1.move('L');
            b1.print();
            System.out.println(" ");
            System.out.println(" ");

            System.out.println("isSolved() func : b1");
            if (b1.isSolved())
                System.out.println("Puzzle has been solved ");
            else
                System.out.println("Puzzle has not been solved yet ! ");
            System.out.println(" ");
            System.out.println(" ");

            System.out.println("move('R') func : b1");
            b1.move('R');
            b1.print();
            System.out.println(" ");
            System.out.println(" ");

            System.out.println("isSolved() func : b1");
            if (b1.isSolved())
                System.out.println("Puzzle has been solved ");
            else
                System.out.println("Puzzle has not been solved yet ! ");
            System.out.println(" ");
            System.out.println(" ");

            b1.print();
            System.out.println("        (x,y) b1");
            System.out.println("cell(2,1) = " + b1.cell(2, 1));
            System.out.println("cell(0,1) = " + b1.cell(0, 1));
            System.out.println(" ");
            System.out.println(" ");

            System.out.println("move('L') func : b1");
            b1.move('L');
            b1.print();
            System.out.println(" ");
            System.out.println(" ");

            System.out.println("Moved Left twice times b2");
            b2.move('L');
            b2.move('L');
            b2.print();
            System.out.println("b2 lastMove () " + b2.lastMove());
            System.out.println(" ");

            System.out.println("Board b1 object representation ");
            b1.print();

            System.out.println("Board b2 object representation ");
            b2.print();
            System.out.println(" ");
            System.out.println(" ");

            System.out.println("Equals func : ");
            if (b1.equals(b2))
                System.out.println("b1 and b2  are equivalent !");
            else
                System.out.println("b1 and b2  are not equivalent !");
            System.out.println(" ");
            System.out.println(" ");

            System.out.println("move('L') func : b1");
            b1.move('L');
            b1.print();
            System.out.println(" ");

            System.out.println("lastMove of b1 ");
            System.out.println(b1.lastMove());
            System.out.println(" ");

            System.out.println("Current b2 representation");
            b2.print();
            System.out.println(" ");

            System.out.println("Equals func : ");
            if (b1.equals(b2))
                System.out.println("b1 and b2  are equivalent !");
            else
                System.out.println("b1 and b2  are not equivalent !");
            System.out.println(" ");
            System.out.println(" ");

            System.out.println(" Declared like this -> ' BoardArray2D b3 = new BoardArray2D(3,5) ' representation which is declared before : ");
            b3.print();
            System.out.println(" ");
            System.out.println(" ");

            System.out.println(" Declared like this -> ' BoardArray2D b4 = new BoardArray2D(3,5) ' representation which is declared before : ");
            b4.print();
            System.out.println(" ");
            System.out.println(" ");

            System.out.println(" Declared like this ->  ' BoardArray2D b5 = new BoardArray2D ( 'shape-puzzle' )  representation which is declared before : ");
            b5.print();
            System.out.println(" ");
            System.out.println(" ");

            System.out.println("b2 toString()");
            System.out.println(b2);
            System.out.println(" ");
            b2.writeToFile("b2-output.txt");
            System.out.println("writeToFile(b2) to file b2-output.txt ");

            System.out.println("b1 toString : ");
            System.out.println(b1);

            System.out.println("b1 toString : ");
            System.out.println(b1);

            System.out.println("b2 toString : ");
            System.out.println(b2);

            System.out.println("b3 toString : ");
            System.out.println(b3);

            System.out.println("b4 toString : ");
            System.out.println(b4);

            System.out.println("b5 toString : ");
            System.out.println(b5);

            System.out.println(" ( BoardArray2D b6 = (BoardArray2D)b5.clone() ");
            BoardArray2D b6 = (BoardArray2D)b5.clone();
            System.out.println("b6 toString");
            System.out.println(b6);
        }

        catch (Exception ExceptionPackage)
        {
            System.out.println(ExceptionPackage.getMessage());
        }
        finally {
            System.out.println("===========BoardArray2D-End==============================");
        }

    }
}
