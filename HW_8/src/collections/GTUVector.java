package collections;

public class GTUVector<T> extends CommonCollection<T> implements Cloneable{

    /**
     * No parameter constructor.
     */
    public GTUVector() {
        super();
    }

    public GTUVector( int initialCapacity ) {
        super(initialCapacity);
    }

    public GTUVector( T Element ) {
        super(Element);
    }

    public GTUVector( GTUVector<T> o ) {
        super(o);
    }

    /**
     * Add an specific element to the collection.
     * @param newElement Element that will be added.
     * @throws IllegalArgumentException Check the max_size whether it's exceeded or not.
     * */
    public void insert( T newElement ) throws IllegalArgumentException{
        add( newElement );
    }

    /**
     * Add an specific element to the  specific given position of collection .
     * @param index index which will be added.
     * @param newElement Element that will be added.
     * @throws IndexOutOfBoundsException Check the dynamic array bounds.
     * @throws NullPointerException Check whether Element is null or not.
     * */
    public void insert( int index , T newElement ) throws IllegalArgumentException{
        add( index , newElement );
    }


    /**
     * Erase the specific index content from the collection.
     * It might throw an exception.
     * @param index index number.
     * @return Return removed element from the collection.
     * */
    @Override
    public T erase(int index) throws IndexOutOfBoundsException {
        return super.erase(index);
    }


    /**
     * Return current capacity of the collection.
     * @return current capacity.
     * */
    @Override
    public int getCapacity() {
        return super.getCapacity();
    }

    /**
     * Collection representation
     * @return Return string as a collection configuration.
     * */
    @Override
    public String toString() {
        return super.toString();
    }


    /**
     * Check the equality of two collection .
     * Warning : Given T type has its own equality check responsibility.
     * @param obj Given collection as an input.
     * @return if it collections are equivalent return TRUE ,
     * otherwise return FALSE.
     * @throws NullPointerException Checking the argument whether it is null , or not.
     * @throws ClassCastException Check whether obj is and actually a instance of CommonCollection.
     * */
    @Override
    public boolean equals(Object obj) throws NullPointerException, ClassCastException {
        return super.equals(obj);
    }


    /**
     * Collection representation as int for the purpose of hashTable
     * @return Return int as collection configuration.
     * */
    @Override
    public int hashCode() {
        return super.hashCode();
    }


    /**
     * Clone makes shallow copy.
     * @return Return Object
     * */
    @Override
    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
}
