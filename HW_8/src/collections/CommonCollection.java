package collections;

/**
 * Common generic abstract class for GTUSet and GTUVector function.
 * Implement almost all function superclass GTUContainer.
 * */
public abstract class CommonCollection<T>  extends GTUContainer<T> {

    private T[] dynamicData;
    private int used;
    private int capacity;

    /**
     * Add an specific element to the collection.
     * @param Element Element that will be added.
     * @throws OutOfMemoryError Check the max_size whether it's exceeded or not.
     * */
    @SuppressWarnings("unchecked")
    protected void add( T Element ) throws OutOfMemoryError{

        if( used == Invariable.MAX_SIZE )
            System.err.println("Exceeded MAX_SIZE , cannot be added more !"+ " MAX_SIZE = " + max_size() );

        if( size() == getCapacity() )
        {
            setCapacity( getCapacity()*2 );

            if( capacity >= Invariable.MAX_SIZE )
                capacity = Invariable.MAX_SIZE;

            T[] newBuffer = (T[]) new Object[getCapacity()];

            for( int i = 0 ; i < size() ; ++i )
                newBuffer[i] = dynamicData[i];

            dynamicData = null;
            dynamicData = newBuffer;
        }

        dynamicData[ used ] = Element;
        ++used;
    }

    /**
     * Add an specific element to the  specific given position of collection .
     * @param index index which will be added.
     * @param Element Element that will be added.
     * @throws IndexOutOfBoundsException Check the dynamic array bounds.
     * @throws NullPointerException Check whether Element is null or not.
     * */
    @SuppressWarnings("unchecked")
    protected void add( int index , T Element ) throws IndexOutOfBoundsException , NullPointerException{

        if( index < 0 || index >= this.size() )
            throw new IndexOutOfBoundsException("Invalid index for inserting element !");

        if( Element == null )
            throw new NullPointerException("null element cannot be inserted ! ");

        if( used == Invariable.MAX_SIZE )
            System.err.println("Exceeded MAX_SIZE , cannot be added more !"+ " MAX_SIZE = " + max_size() );

        if( size() == getCapacity() )
        {
            setCapacity( getCapacity()*2 );

            if( capacity >= Invariable.MAX_SIZE )
                capacity = Invariable.MAX_SIZE;

            T[] newBuffer = (T[]) new Object[getCapacity()];

            for( int i = 0 ; i < size() ; ++i )
                newBuffer[i] = dynamicData[i];

            dynamicData = null;
            dynamicData = newBuffer;
        }

        for( int i = (this.size() - 1) ; i >= index ; --i )
            dynamicData[ i+1 ] = dynamicData[ i ];

        dynamicData[index] = Element;
        ++used;
    }

    /**
     * Set the current capacity of the collection.
     * @param capacity Capacity that will be set.
     * */
    protected void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    /**
     * Return current capacity of the collection.
     * @return current capacity.
     * */
    protected int getCapacity() {
        return capacity;
    }


    /**
     * Erase the specific index content from the collection.
     * It might throw an exception.
     * @param index index number.
     * @return Return removed element from the collection.
     * */
    @SuppressWarnings("unchecked")
    protected T erase( int index ) throws  IndexOutOfBoundsException {

        T temp = null;

        if( index < 0 || index >= this.size() )
            throw new IndexOutOfBoundsException("Invalid index to erase! ");

        temp = (T) new Object[1];
        temp = dynamicData[index];

        for( int i = index ; i < this.size() - 1; ++i )
            dynamicData[i] = dynamicData[i + 1];

        dynamicData[ this.size() - 1 ] = null;
        --used;

        return temp;
    }

    /**
     * Erase the specific element from the collection.
     * @param Element T type element.
     * @return if element is removed return true , otherwise return false.
     * */
    protected boolean erase(T Element) {

        int index = -1;

        if( Element == null )
            return false;

        if( !contains(Element) )
            return false;

        for( int i = 0 ; i < size() ; ++i )
            if( dynamicData[i].equals(Element) )
                index = i;

        for( int i = index ; i < this.size() - 1; ++i )
            dynamicData[i] = dynamicData[i + 1];

        dynamicData[ this.size() - 1 ] = null;
        --used;

        return true;
    }


    /**
     * No parameter constructor.
     */
    protected CommonCollection() {
        this(Invariable.InitialCollectionSize);
    }

    /**
     * Create an initial collection.
     * @param initialCapacity Capacity that will be set.
     */
    @SuppressWarnings("unchecked")
    protected CommonCollection( int initialCapacity ) throws IllegalArgumentException{
        if( initialCapacity <= 0 )
            throw new IllegalArgumentException("Negative argument is not acceptable !");

        setCapacity(initialCapacity);
        dynamicData = (T[]) new Object[ getCapacity() ];
        used = 0;
    }

    /**
     * Create an initial collection. with given element.
     * @param Element Given element as a parameter.
     */
    protected CommonCollection( T Element ) throws NullPointerException {
        this(Invariable.InitialCollectionSize);

        if( Element == null )
            throw new NullPointerException("Null reference is not valid !");

        add( Element );
    }

    /**
     * Copy Constructor
     * Warning : It does not make deep copy of the collection.
     * @param o Collection reference as an input,
     * @throws NullPointerException Checking the argument whether it is null , or not.
     */
    protected CommonCollection( CommonCollection<T> o ) throws NullPointerException {
        this( o.getCapacity() );

        if( o == null ) {
            this.clear();
            throw new NullPointerException(" Invalid null argument for constructor !");
        }

        for( int i = 0 ; i < o.size() ; ++i )
             dynamicData[i] = o.dynamicData[i];
    }

    /**
     * Return current used size on the collection.
     * @return Return the size as an int primitive type.
     * */
    public int size() {
        return used;
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
    public boolean equals(Object obj) throws NullPointerException , ClassCastException {

        if( obj == null )
            throw new NullPointerException("Null argument cannot be checked !");

        if( !(obj instanceof CommonCollection) )
            throw new ClassCastException( obj.getClass().getTypeName() + "is not an instance of collection ");

        if( ((CommonCollection)obj) == this )
            return true;

        if(this.size() != ((CommonCollection)obj).size() )
            return false;

        for ( int i = 0 ; i < ((CommonCollection)obj).size() ; ++i )
            if( !(dynamicData[i].equals( ((CommonCollection) obj).dynamicData[i]) ) )
                return false;

        return true;
    }

    /**
     * Max allocatable max_size.
     * @return return max-size.
     * */
    public int max_size() {
        return Invariable.MAX_SIZE;
    }

    /**
     * Check whether collection is empty or not.
     * @return if collection is empty return TRUE, otherwise
     * return FALSE.
     * */
    public boolean empty() {
        return this.size() == 0;
    }

    /**
     * Clear all the content in the collection.
     * */
    @SuppressWarnings("unchecked")
    public void clear() {
        dynamicData = null;
        capacity = Invariable.InitialCollectionSize;
        dynamicData = (T[]) new Object[getCapacity()];
        used = 0;
    }

    /**
     * Returns an iterator over the elements in this list in proper sequence.
     * @return GTUIterator<T> return the beginning of the collection as an iterator.
     * */
    public GTUIterator<T> iterator() {
        return new GTUIterator<T>( dynamicData , this.size() );
    }

    /**
     * Takes an Object type , check whether element in the collection
     * or not
     * @param o Object Class Reference
     * @return if element does exist in collection return TRUE
     * , otherwise return FALSE.
     * */
    @SuppressWarnings("unchecked")
    public boolean contains(Object o) throws NullPointerException{

        if( o == null )
            throw new NullPointerException("Collection does not permit to null element !");

        for( int i = 0 ; i < this.size() ; ++i  )
            if( ( ((T)o ).equals(dynamicData[i]) ) )
                return true;


        return false;
    }

    /**
     * Collection representation
     * @return Return string as a collection configuration.
     * */
    @Override
    public String toString() {
        String classInfo = "[";

        for ( int i = 0 ; i < size() ; ++i )
        {
            if( i == 0)
                classInfo += dynamicData[i].toString();
            else
                classInfo += " , " + dynamicData[i].toString();
        }

        classInfo += "]";

        return classInfo;
    }

    /**
     * Collection representation as int for the purpose of hashTable
     * @return Return int as collection configuration.
     * */
    @Override
    public int hashCode() {
        int specialValue = 0;

        for( int i = 0 ; i < size() ; ++i )
            specialValue += ((i+1)*dynamicData[i].hashCode()+1);

        return specialValue;
    }
}
