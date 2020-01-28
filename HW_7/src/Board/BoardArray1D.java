package Board;
import java.io.*;

/**
 * Extended concrete class which represents whole class.
 * Its implementation is based on two one dimentional array,
 * @see java.lang.Cloneable
 * @see Board.AbstractBoard
 * */
public class BoardArray1D extends AbstractBoard implements Cloneable {

    private int puzzle_map[];

    /**
     * No parameter constructor.
     * Default x size = 3.
     * Default y size = 3.
     * */
    public BoardArray1D( ) {
        this( DEFAULT_X_SIZE , DEFAULT_Y_SIZE );
    }


    /**
     * Copy Constructor.
     * Create a new board which is equivalent the given as a parameter.
     * @param other Using deep copy method , copy the parameter to current board.
     * Defaulted x size = 3.
     * Defaulted y size = 3
     */
    public BoardArray1D( BoardArray1D other ) {
        super();

        setSize( other.get_xSize() , other.get_ySize() );

        for(int j = 0 ; j < this.get_ySize() ; ++j)
            for(int i = 0 ; i < this.get_xSize() ; ++i)
                puzzle_map[ j * this.get_xSize() + i ] = other.puzzle_map[ j * this.get_xSize() + i ];
    }

    /**
     * Create a new board which is equivalent the configuration
     * that is created according to given parameter.
     * @param xSize x size of the board , defaulted x size = 3.
     * @param ySize y size of the board , defaulted y size = 3.
     */
    public BoardArray1D( int xSize , int ySize ) {
        super();

        puzzle_map = null;
        setSize( xSize , ySize );

    }


    /**
     * Create a new board according to given file by the constructor.
     * Defaulted x size = 3.
     * Defaulted y size = 3.
     * @param filename File name which is going to be opened.
     * @throws IOException if file not exist or not opened.
     */
    public BoardArray1D( String filename) throws IOException{
        super();

        puzzle_map = null;
        try
        {
            readFromFile(filename);
        }
        catch ( IOException  ExceptionPocket ) {
            System.out.println( ExceptionPocket.getMessage() );
        }
    }


    /**
     * Set the board with given size.
     * @param xSizeOut x size of the board.
     * @param ySizeOut y size of the board.
     */
    @Override
    public void setSize( int xSizeOut , int ySizeOut ) {

        if( puzzle_map != null) {
            puzzle_map = null;
        }

        /* Base class virtual call */
        super.setSize( xSizeOut , ySizeOut );

        puzzle_map = new int [ xSizeOut * ySizeOut ];

        for(int j = 0 ; j < get_ySize() ; ++j)
            for(int i = 0 ; i < get_xSize() ; ++i)
                puzzle_map[ j * get_xSize() + i ] = -1;

        /* Whatever is goint to be built */

        reset();
    }

    /**
     * Obtaining specific cell content located in board.
     * @param x x coordinate of the number.
     * @param y y coordinate of the number.
     * @return Return the number that is located in x and y.
     */
    @Override
    public int cell( int x , int y ) {

        if( (x < 0 || x > (get_xSize() - 1) ) || (y < 0 || y > (get_ySize() - 1) ) )
        {
            System.err.println("Invalid argument ! Error , operator() ");
            System.exit(-1);
        }

        return puzzle_map[ y * get_xSize() + x ];
    }

    /**
     * Replace the given coordinate number with new.
     * @param x x coordinate of the number.
     * @param y y coordinate of the number.
     * @param content content which is going to be replaced with previous.
     * These method are implemented in extended classes.
     */
    @Override
    protected void cell( int x , int y , int content ) {

        if( (x < 0 || x > ( get_xSize() - 1 ) ) || (y < 0 || y > ( get_ySize() - 1 ) ) )
        {
            System.err.println("Invalid argument ! Error , operator() ");
            System.exit(-1);
        }
        puzzle_map[ y * get_xSize() + x ] = content;

    }

    /**
     * Return a deep copied new BoardArray1D that is equivalent to current.
     * @throws CloneNotSupportedException if Error during the process.
     */
    @Override
    public Object clone() throws CloneNotSupportedException{
        return new BoardArray1D(this);
    }
}
