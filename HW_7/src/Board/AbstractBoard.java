package Board;
import java.io.*;
import java.util.Scanner;

/**
 * Abstract Class which holds all the same
 * method and fields that are used in BoardArray1D
 * and BoardArray2D.
 * @see java.lang.Cloneable
 * @see ConstantBoardProperty
 */
public abstract class AbstractBoard implements ConstantBoardProperty, Cloneable {

    private static int Number_Of_Boards = 0;    /* Number of the board */
    private static boolean isNumeric(String str) {
        for (char c : str.toCharArray()) {
            if (!Character.isDigit(c))
                return false;
        }
        return true;
    }
    private static int get_digit(int number) {
        int counter = 1;
        while( (number /= 10) != 0 )
            ++counter;

        return counter;
    }

    private int xSize,ySize;                /* x and y size of the board */
    private int playerX,playerY;            /* blankPos of the board */
    private char last_Move;                 /* Last move */
    private int number_Of_Moves;            /* number of moves */
    private boolean set_player_pos( ) {

        for(int j = 0 ; j < ySize ; ++j)
            for(int i = 0 ; i < xSize ; ++i)
                if(this . cell( i , j ) == ConstantBoardProperty.blankRepresentation )
                {
                    playerX = i;
                    playerY = j;

                    return true;
                }

        return false;
    }
    private boolean moveRight( ) {

        if( ( playerX + 1  )< xSize && this . cell( playerX + 1, playerY ) != 0)
        {
            this . cell( playerX, playerY , this . cell( playerX + 1, playerY ) );
            this . cell( playerX + 1, playerY , ConstantBoardProperty.blankRepresentation);

            return true;
        }

        return false;
    }
    private boolean moveLeft( ) {

        if( ( playerX - 1  ) >= 0 && this . cell( playerX - 1, playerY ) != 0)
        {
            this . cell( playerX, playerY , this . cell( playerX - 1, playerY ) );
            this . cell( playerX - 1, playerY , ConstantBoardProperty.blankRepresentation);

            return true;
        }
        return false;
    }
    private boolean moveUp( ) {

        if( ( playerY - 1  ) >= 0 && this . cell( playerX , playerY - 1 ) != 0)
        {
            this . cell( playerX, playerY , this . cell( playerX , playerY - 1 ) );
            this . cell( playerX , playerY - 1 , ConstantBoardProperty.blankRepresentation );

            return true;
        }

        return false;
    }
    private boolean moveDown( ) {

        if( ( playerY + 1  ) < ySize && this . cell( playerX , playerY + 1 ) != 0)
        {
            this . cell( playerX, playerY , this . cell( playerX , playerY + 1 ) );
            this . cell( playerX , playerY + 1 , ConstantBoardProperty.blankRepresentation  );

            return true;
        }
        return false;
    }

    /**
     * Increase the NumberOfBoards  by 1.
     * */
    protected void inc_Number_Of_Boards( ) { ++Number_Of_Boards; }

    /**
     * Replace the given coordinate number with new.
     * @param x x coordinate of the number.
     * @param y y coordinate of the number.
     * @param content content which is going to be replaced with previous.
     * These method are implemented in extended classes.
     */
    protected abstract void cell( int x , int y , int content );

    /**
     * No parameter constructor.
     * Increase the static board amount.
     */
    public AbstractBoard() {
        ++Number_Of_Boards;
    }

    /**
     * Considering the equality of two boards.
     * @param other It is an java.lang.Object class parameter.
     * Consider the two classes are equivalent or not.
     * @return if puzzles are equivalent , then returns true
     * if not , returns false.
     */
    @Override
    public boolean equals( Object other ) {

        if( other == null)
            return false;

        if( !(other instanceof AbstractBoard) )
            return false;

        if(other == this )
            return true;

        AbstractBoard otherRef = (AbstractBoard) other;

        if( get_xSize() != otherRef.get_xSize() || get_ySize() != otherRef.get_ySize() )
            return false;

        for( int j = 0 ; j < get_ySize() ; ++j )
            for( int i = 0 ; i < get_xSize() ; ++i )
                if( cell( i , j ) != otherRef.cell( i , j ) )
                    return false;

        return true;
    }

    /**
     * Obtaining current configuration of the
     * board as a string.
     * @return Current configuration of the board.
     */
    @Override
    public String toString() {

        String newBoardRepresentation = "";

        for( int j = 0 ; j < ySize ; ++j )
        {
            for( int i = 0 ; i < xSize ; ++i )
            {
                if( cell( i , j ) == ConstantBoardProperty.blankRepresentation )
                    newBoardRepresentation += String.format("%s" ,' ');
                else
                {
                    if( cell( i , j ) == 0 )
                        newBoardRepresentation += String.format("%s" ,'X' );
                    else
                        newBoardRepresentation += String.format("%s" ,cell( i , j ) );
                }

                newBoardRepresentation += String.format("%s",'\t');
            }

            newBoardRepresentation += String.format("%s",'\n');
        }

        return newBoardRepresentation;
    }

    /**
     * Obtaining current configuration of the
     * board as a int.
     * @return Returns board specific number.
     */
    @Override
    public int hashCode() {
        int hashCodeUnique = 0;
        for( int j = 0 ; j < get_ySize() ; ++j )
            for( int i = 0 ; i < get_xSize() ; ++i )
                hashCodeUnique += (cell(i,j) * ((i * j) + i + j ));

        return hashCodeUnique;
    }

    /**
     * Print the current configuration of the board.
     */
    public void print() {

        for(int j = 0 ; j < ySize;++j)
        {
            for(int i = 0 ; i < xSize;++i)
            {
                if( this . cell(i,j) == ConstantBoardProperty.blankRepresentation)
                    System.out.printf("%s" ,' ');
                else if( this . cell(i,j) == 0)
                    System.out.printf("%s" ,'X' );
                else
                    System.out.printf("%s" ,cell( i , j ));

                System.out.printf("%s",'\t');
            }
            System.out.printf("%s",'\n');
        }

    }

    /**
     * Read the file that contains puzzle configuration.
     * @param filename Take the filename that contain puzzle
     *                 configuration and create a puzzle in program.
     * @throws IOException There is a lot Exception necessity process in
     * function so that not giving the crash to customer.
     */
    public void readFromFile(String filename) throws IOException {

        int next = 0 , prev = 0;
        boolean initialCheck = true , flag = true;

        this.xSize = 0; this.ySize = 0;

        FileReader inStream = null;
        Scanner inStreamScanner = null;

        try{

            File fileBoard = new File( filename );
            inStream =  new FileReader( fileBoard );

            while( next != -1 )
            {
                next = inStream.read();

                if( next != '\n' && flag )
                {
                    if(next != ' ' && initialCheck)
                        ++xSize;

                    initialCheck = false;

                    if( next != ' ' && next != '\n' && prev == ' ' )
                        ++xSize;

                    prev = next;

                    initialCheck = true;
                    prev = 0;
                }
                else if( next == '\n' && flag)
                    flag = false;

                if( next == '\n' && initialCheck )
                    --ySize;

                initialCheck=false;

                if( next == '\n' && prev != '\n' )
                    ++ySize;

                if( next == -1 && prev != '\n' )
                    ++ySize;

                prev = next;
            }

            inStream.close();
            inStream = null;

            setSize(xSize,ySize);

            String strNum;
            inStreamScanner = new Scanner(new BufferedReader( new FileReader(fileBoard) ));

            for(int j = 0 ; j < get_ySize() ;++j)
                for(int i = 0 ; i < get_xSize() ;++i)
                {
                    strNum = inStreamScanner.next();
                    if( !isNumeric( strNum ) )
                        cell(i,j, ConstantBoardProperty.blankRepresentation);
                    else
                        cell(i,j,Integer.parseInt(strNum));
                }
            inStreamScanner = null;
        }
        finally {

            if(inStream != null)
                inStream.close();

            if(inStreamScanner != null)
                inStreamScanner.close();
        }

    }

    /**
     * Write the current puzzle configuration to given file.
     * @param filename Take the filename that is going to be
     *                 written according the current board configuration and
     *                 write to given filename.
     * @throws IOException There is a lot Exception necessity process in
     * function so that not giving the crash to used.
     */
    public void writeToFile( String filename ) throws IOException {

        int maxNumber = 0 , difNumber = 0 , borderAmount = 0;

        for(int j = 0 ; j < ySize;++j)
            for(int i = 0 ; i < xSize;++i)
                if( cell( i , j ) == 0 )
                    ++borderAmount;

        maxNumber = get_xSize() * get_ySize() - 1 - borderAmount;
        PrintWriter outputStream = null;

        try {
            outputStream = new PrintWriter(new FileWriter(filename));
            for (int j = 0; j < get_ySize(); ++j){
                for (int i = 0; i < get_xSize(); ++i){
                    if( cell( i , j ) != ConstantBoardProperty.blankRepresentation ){
                        if( get_digit( cell( i , j ) ) == get_digit( maxNumber ) ){
                            if( get_digit( cell( i , j ) ) == 1 ) {
                                outputStream.print('0');
                                outputStream.print(cell(i, j));
                            }
                            else
                                outputStream.print(cell(i, j));
                        }
                        else{
                            difNumber = get_digit( maxNumber ) - get_digit( cell( i , j ) );

                            for( int k = 0 ; k < difNumber ; ++k )
                                outputStream.print('0');

                            outputStream.print(cell(i, j));
                            difNumber = 0;
                        }
                    }
                    else{
                        if( get_digit( maxNumber ) == 1 )
                            outputStream.print("bb");
                        else
                        {
                            for( int k = 0 ; k < get_digit( maxNumber ) ; ++k )
                                outputStream.print('b');
                        }

                    }
                    if( i != get_xSize() - 1 )
                        outputStream.print(" ");
                }
                if( j != get_ySize() - 1 )
                    outputStream.print('\n');
            }
        }
        finally {
            if( outputStream != null )
                outputStream.close();
        }

    }

    /**
     * Reset the the board configuration , take the
     * board to the final position.
     */
    public void reset() {

        int counter = 1;

        for( int j = 0 ; j < get_ySize() ; ++j )
            for( int i = 0 ; i < get_xSize() ; ++i )
            {
                if( this . cell( i , j ) != 0 )
                {
                    this . cell( i , j , counter );
                    ++counter;
                }
            }

        this . cell( get_xSize() - 1 , get_ySize() - 1  , ConstantBoardProperty.blankRepresentation ) ;

        number_Of_Moves = 0;
        last_Move = 'S';

    }

    /**
     * Set the board with given size.
     * @param xSizeOut x size of the board.
     * @param ySizeOut y size of the board.
     */
    public void setSize( int xSizeOut , int ySizeOut ) {

        if( xSizeOut <= 1 || ySizeOut <= 1 )
        {
            System.err.println("Invalid size for argument !");
            System.exit(-1);
        }

        this . xSize = xSizeOut;
        this . ySize = ySizeOut;

        number_Of_Moves = 0;
        last_Move = 'S';
    }

    /**
     * Set the board with given size.
     * @param letter Contains the movement information
     *               by the means of letter.
     *               For example , move('L') or move('l')
     *               Moves the blank or player to the left.
     */
    public boolean move( char letter) {

        boolean flag = true;

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

    /**
     * Check the current board which is
     * final or not.
     * @return If solution found returns true , otherwise returns false.
     */
    public boolean isSolved( ) {

        int counter = 1;

        for( int j = 0 ; j < get_ySize() ; ++j )
        {
            for( int i = 0 ; i < get_xSize() ; ++i )
            {
                if( this . cell( i , j ) != 0 && this . cell( i , j ) == counter )
                    ++counter;
                else if( !(counter == get_xSize() * get_ySize() && this . cell( i , j ) == ConstantBoardProperty.blankRepresentation) )
                    return false;
            }
        }

        return true;
    }


    /**
     * Obtaining specific cell content located in board.
     * @param x x coordinate of the number.
     * @param y y coordinate of the number.
     * @return Return the number that is located in x and y.
     */
    public abstract int  cell( int x , int y );

    /**
     * Obtaining board amount which is created so far.
     * @return Returns the number of Board which created so far.
     */
    public static int NumberOfBoards( ) { return Number_Of_Boards; }

    /**
     * Obtaining total number of moves.
     * @return Returns the number of moves that has made
     * by the current puzzle player.
     */
    public int numberOfMoves( )  { return number_Of_Moves; }

    /**
     * Obtaining last move of current puzzle.
     * @return Returns the last move of the current puzzle
     * player as a character.If there is no last move , then returns 'S'.
     */
    public char lastMove( )  { return last_Move; }

    /**
     * Obtaining x size.
     * @return Returns the y size of the current puzzle.
     */
    public  int get_xSize( ) { return xSize; }

    /**
     * Obtaining y size.
     * @return Returns the y size of the current puzzle.
     */
    public  int get_ySize( ) { return ySize; }
}