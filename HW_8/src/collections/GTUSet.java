package collections;

/**
 * Generic GTUSet Class
 * @see CommonCollection
 * */
public class GTUSet<T> extends CommonCollection<T> implements Cloneable{

    /**
     * No parameter constructor.
     * Construct an Set.
     * */
    public GTUSet() {
        super();
    }

    /**
     * Add an specific element to the collection.
     * @param newElement Element that will be inserted.
     * @throws OutOfMemoryError Check the max_size whether it's exceeded or not.
     * */
    public void insert( T newElement ) throws IllegalArgumentException{
        if( !this.contains(newElement) )
            add( newElement );
    }

    /**
     * Erase the specific element from the collection.
     * @param Element T type element.
     * @return if element is removed return true , otherwise return false.
     * */
    @Override
    public boolean erase(T Element) {
        return super.erase(Element);
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
