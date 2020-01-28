package collections;

/**
 * Generic Iterator class implementation.
 * */
public class GTUIterator<E> {

    private E[] actualData;
    private int currentIndex;
    private int used;


    /**
     * GTUIterator constructor.
     * @param receivedData E type array reference .
     * @param receivedSize given current size
     * */
    protected GTUIterator( E[] receivedData , int receivedSize ) throws NullPointerException {
        if(receivedData == null )
            throw new NullPointerException("Null reference is not valid ! ");

        actualData = receivedData;
        used = receivedSize;
        currentIndex = 0;
    }

    /**
     * Consider the element has next.
     * @return if element has next return true , return false.
     * */
    public boolean hasNext() {
       return currentIndex < used && actualData[currentIndex] != null;
    }

    /**
     * getting next element from the collection.
     * @return the next element of the exact iterator.
     * @throws IndexOutOfBoundsException Check the whether it over bounds or not.
     * */
    public E next() throws IndexOutOfBoundsException{
        if( currentIndex >= used )
            throw new IndexOutOfBoundsException("Iterator cannot be gone further , Out of Bounds in Iterator !");
        else
            return actualData[currentIndex++];
    }

    /**
     * iteration representation
     * @return Return iteration representation as a string.
     * */
    @Override
    public String toString() throws NullPointerException{
        if( actualData[currentIndex] != null )
            return actualData[currentIndex].toString();
        return "";
    }

    /**
     * Clone makes shallow copy available for customer.
     * */
    @Override
    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }

}
