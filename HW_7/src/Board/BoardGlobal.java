package Board;

/**
 * Content : Abstract polymorphic static method.
 * It is easy to gather other function
 * that is going to be implemented in after days.
 * */
public class  BoardGlobal {

    /**
     * Check the sequence of the Abstract Board whether it is
     * solution or not.
     * @param Sequence
     * @return If it is true sequnce returns false , else returns false.
     */
    static public boolean isValidMovement(AbstractBoard[] Sequence) {

        for( int i = 0 ; i < Sequence.length ; ++i)
            if( Sequence[i] == null )
                return false;

        if( !(( Sequence[ Sequence.length - 1 ] ).isSolved()) )
            return false;

        for( int i = 0 ; i < Sequence.length - 1 ; ++i )
        {
            if( Sequence[i].get_ySize() != Sequence[i+1].get_ySize() ||  Sequence[i].get_xSize() != Sequence[i+1].get_xSize() )
                return false;

            if( !isValidMove( Sequence[i] , Sequence[i+1] ) )
                return false;
        }

        return true;
    }


    static private boolean isValidMove( AbstractBoard board1 , AbstractBoard board2 )
    {
        int unpaired = 0 ;
        boolean[][] test_board = null;

        int x1 = -1 , y1 = -1 ;

        test_board = new boolean[ board1.get_xSize() ][ board1.get_ySize() ];

        for( int j = 0 ; j < board1.get_ySize() ; ++j )
        {
            for( int i = 0 ; i < board1.get_xSize() ; ++i )
            {
                if( board1.cell(i,j) == board2.cell(i,j) )
                    test_board[ i ][ j ] = true;
                else
                {
                    test_board[ i ][ j ] = false;

                    if( x1 == -1 || y1 == -1) {
                        x1 = i;
                        y1 = j;
                    }
                    else if( !( (((i - x1) + (j - y1)) == -1) || (((i - x1) + (j - y1)) == 1 )) )
                    {
                        test_board = null;
                        return false;
                    }
                    ++unpaired;
                }
            }
        }

        if( unpaired != 2 ) {
            test_board = null;
            return false;
        }

        test_board = null;
        return true;
    }
}
