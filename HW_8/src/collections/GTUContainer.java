package collections;

/**
 * Generic Abstract super GTUContainer class that
 * behave like java.util.Collection interface , but this
 * is abstract class.
 * @see Invariable
 * */
public abstract class  GTUContainer<T> implements Invariable {

    /**
     * Check whether collection is empty or not.
     * @return if collection is empty return TRUE, otherwise
     * return FALSE.
     * */
    public abstract boolean empty();

    /**
     * Return current used size on the collection.
     * @return Return the size as an int primitive type.
     * */
    public abstract int size();

    /**
     * Return max allocatable size.
     * @return max allocatable size.
     * */
    public abstract int max_size();

    /**
     * Insert a specific element at the end of the collection.
     * @param newElement Element that will be inserted.
     * */
    public abstract void insert( T newElement );

    /**
     * Erase the specific index content from the collection.
     * It might throw an exception.
     * @param index index number.
     * @return Return removed element from the collection.
     * */
    protected abstract T erase( int index) ;

    /**
     * Erase the specific element from the collection.
     * @param Element T type element.
     * @return if element is removed return true , otherwise return false.
     * */
    protected abstract boolean erase( T Element) ;

    /**
     * Clear all the content in the collection.
     * */
    public abstract void clear();

    /**
     * Returns an iterator over the elements in this list in proper sequence.
     * @return GTUIterator<T> return the beginning of the collection as an iterator.
     * */
    public abstract GTUIterator<T> iterator();

    /**
     * Takes an Object type , check whether element in the collection
     * or not
     * @param o Object Class Reference
     * @return if element does exist in collection return TRUE
     * , otherwise return FALSE.
     * */
    public abstract boolean contains(Object o);

}
