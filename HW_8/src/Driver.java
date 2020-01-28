/* GTU-HW8 */
/* Nevzat Seferoglu - 171044024 */

import collections.*;

public class Driver {

    /* On , Off switching to make debugging easier */

    public final static boolean test_GTUVector = true;
    public final static boolean test_GTUSet = true;

    /*End*/

    public static void main( String... argv ) {

        try {

            if( test_GTUVector )
                test_GTUVector();

            System.out.println("\n\n");

            if( test_GTUSet )
                test_GTUSet();

        }
        catch (Exception ExceptionPackage) {
            System.out.println(ExceptionPackage.getMessage());
        }

    }

    public static void test_GTUVector() {

        System.out.println("");
        System.out.println("************GTUVector_Test**************");
        System.out.println("There are 4 kind of constructor in Vector ");

        System.out.println("1 - public GTUVector()");
        System.out.println("2 - public GTUVector( int initialCapacity )");
        System.out.println("3 - public GTUVector( T Element )");
        System.out.println("4 - public GTUVector( GTUVector<T> o )");
        System.out.println("");

        System.out.println("Warning : 4th constructor does not make deep copy of collection !");
        System.out.println("");

        GTUVector<Integer> v1 = new GTUVector<>(3);
        System.out.println("GTUVector<Integer> v1 = new GTUVector<>(3);");
        GTUVector<Integer> v2 = new GTUVector<>();
        System.out.println("GTUVector<Integer> v2 = new GTUVector<>();");
        GTUVector<String> v3 = new GTUVector<>("GTU");
        System.out.println("GTUVector<String> v3 = new GTUVector<>(\"GTU\");");
        System.out.println("");

        System.out.println("********* Inserting_Test **********");
        System.out.println("");

        System.out.println("> Insertion on the vectors. ");
        System.out.println("There are 2 different method for insertion ");
        System.out.println("1 - public void insert( T newElement ) ,             add the element to the end of the vector.");
        System.out.println("2 - public void insert( int index , T newElement ) , add the element on specific position. ");
        System.out.println("");

        v1.insert(1);
        System.out.println("> insert(1)     on v1");
        v1.insert(2);
        System.out.println("> insert(2)     on v1");
        v1.insert(3);
        System.out.println("> insert(3)     on v1");

        System.out.println("");
        System.out.println("> toString      on v1");
        System.out.println(v1);

        System.out.println("");
        System.out.println("> size()        on v1");
        System.out.println("Size = " + v1.size());

        v1.insert(-1);
        System.out.println("> insert(-1)    on v1");
        v1.insert(-2);
        System.out.println("> insert(-2)    on v1");
        v1.insert(-3);
        System.out.println("> insert(-3)    on v1");

        System.out.println("");
        System.out.println("> toString      on v1");
        System.out.println(v1);

        System.out.println("");
        System.out.println("> size()        on v1");
        System.out.println("Size = " + v1.size());

        System.out.println("");
        System.out.println("> insert(1,-4)  on v2");
        v1.insert(1,-4);

        System.out.println("");
        System.out.println("> toString      on v1");
        System.out.println(v1);

        System.out.println("");
        v2.insert(1);
        System.out.println("> insert(1)     on v2");
        v2.insert(-4);
        System.out.println("> insert(-4)    on v2");
        v2.insert(2);
        System.out.println("> insert(2)     on v2");
        v2.insert(3);
        System.out.println("> insert(3)     on v2");
        v2.insert(-1);
        System.out.println("> insert(-1)    on v2");
        v2.insert(-2);
        System.out.println("> insert(-2)    on v2");
        v2.insert(-3);
        System.out.println("> insert(-3)    on v2");

        System.out.println("");
        System.out.println("> size()        on v1");
        System.out.println("Size = " + v1.size());

        System.out.println("");
        System.out.println("************ End_Inserting_Test *********");
        System.out.println("");

        System.out.println("********* contains_Test **********");

        System.out.println("");
        System.out.println("> toString      on v3");
        System.out.println(v3);

        System.out.println("");
        v3.insert("ITU");
        System.out.println("> insert(\"ITU\")     on v3");

        System.out.println("");
        System.out.println("> toString      on v3");
        System.out.println(v3);

        System.out.println("");
        System.out.println("> contains(\"GTU\")       on v3 = " + v3.contains("GTU") );
        System.out.println("> contains(\"ODTU\")       on v3 = " + v3.contains("ODTU") );
        System.out.println("> contains(\"ITU\")       on v3 = " + v3.contains("ITU") );

        System.out.println("");
        System.out.println("************ End_contains_Test *********");
        System.out.println("");


        System.out.println("********* Equality_Test **********");
        System.out.println("");

        System.out.println("");
        System.out.println("> toString      on v1");
        System.out.println(v1);

        System.out.println("");
        System.out.println("> toString      on v2");
        System.out.println(v2);

        System.out.println("");
        System.out.println("v1.equals(v2) = " + v1.equals(v2));

        System.out.println("");
        v2.insert(11);
        System.out.println("> insert(11)    on v2");

        System.out.println("");
        System.out.println("v1.equals(v2) = " + v1.equals(v2));

        System.out.println("");
        System.out.println("************ End_Equality_Test *********");
        System.out.println("");


        System.out.println("********* Erasing_Test **********");
        System.out.println("");

        System.out.println("There is an erase in vector.");
        System.out.println("> public T erase(int index)  , erase the element from specific position. ");

        System.out.println("");
        System.out.println("> toString      on v1");
        System.out.println(v1);

        System.out.println("");
        v1.erase(0);
        System.out.println("> erase(0)      on v1");

        System.out.println("");
        System.out.println("> toString      on v1");
        System.out.println(v1);

        System.out.println("");
        v1.erase(3);
        System.out.println("> erase(3)      on v1");

        System.out.println("");
        System.out.println("> toString      on v1");
        System.out.println(v1);


        System.out.println("");
        System.out.println("> size()        on v1");
        System.out.println("Size = " + v1.size());

        System.out.println("");
        System.out.println("************ End_Erasing_Test *********");
        System.out.println("");


        System.out.println("********* Empty_Test **********");
        System.out.println("");

        System.out.println("");
        System.out.println("> toString      on v1");
        System.out.println(v1);

        System.out.println("");
        System.out.println("> empty()       on v1 = " + v1.empty() );


        System.out.println("");
        System.out.println("************ End_Empty_Test *********");
        System.out.println("");

        System.out.println("********* Clear_Test **********");
        System.out.println("");


        System.out.println("");
        System.out.println("> toString      on v1");
        System.out.println(v1);

        System.out.println("");
        v1.clear();
        System.out.println("> clear()       on v1");

        System.out.println("");
        System.out.println("> toString      on v1");
        System.out.println(v1);

        System.out.println("");
        System.out.println("> size()        on v1");
        System.out.println("Size = " + v1.size());

        System.out.println("");
        System.out.println("************ End_Clear_Test *********");
        System.out.println("");

        System.out.println("********* max_Size_Test **********");
        System.out.println("");

        System.out.println("");
        System.out.println("> max_size()       on v1 = " + v1.max_size() );

        System.out.println("");
        System.out.println("************ End_max_Size_Test *********");
        System.out.println("");

        System.out.println("********* hash_code_Test **********");
        System.out.println("");

        System.out.println("");
        v1.clear();
        System.out.println("> clear()       on v1");

        System.out.println("");
        v2.clear();
        System.out.println("> clear()       on v2");

        System.out.println("");
        v1.insert(1);
        System.out.println("> insert(1)     on v1");

        System.out.println("");
        v2.insert(1);
        System.out.println("> insert(1)     on v2");

        System.out.println("");
        System.out.println("> toString      on v1");
        System.out.println(v1);

        System.out.println("");
        System.out.println("> toString      on v2");
        System.out.println(v2);

        System.out.println("v1.hashCode() =" + v1.hashCode());
        System.out.println("v2.hashCode() =" + v2.hashCode());
        System.out.println("Same Configuration");

        System.out.println("");
        v1.insert(2);
        System.out.println("> insert(2)     on v1");

        System.out.println("");
        System.out.println("> toString      on v1");
        System.out.println(v1);

        System.out.println("");
        System.out.println("> toString      on v1");
        System.out.println(v2);

        System.out.println("");
        System.out.println("v1.hashCode() =" + v1.hashCode());
        System.out.println("v2.hashCode() =" + v2.hashCode());
        System.out.println("Different Configuration");


        System.out.println("");
        System.out.println("************ End_hash_code_Test *********");
        System.out.println("");

        System.out.println("********* Iterator_Test **********");
        System.out.println("");

        System.out.println("> toString      on v3");
        System.out.println(v3);

        System.out.println("");
        v3.insert("KTU");
        System.out.println("> insert(\"KTU\")     on v3");

        System.out.println("");
        System.out.println("> toString      on v3");
        System.out.println(v3);

        System.out.println("");
        GTUIterator<String> iter = v3.iterator();
        System.out.println("> GTUIterator<String> iter = v3.iterator() ");


        System.out.println("");
        System.out.println("Printing via iterator , all the element to the screen on the vector thanks to for loop. ");

        for( ; iter.hasNext() ; )
            System.out.println( iter.next());

        System.out.println("");
        System.out.println("> iter.hasNext() = " + iter.hasNext() );

        System.out.println("");
        iter = v3.iterator();
        System.out.println("> iter = v3.iterator() ");

        System.out.println("iter.next() = " + iter.next());
        System.out.println("iter.next() = " + iter.next());
        System.out.println("iter.next() = " + iter.next());

        System.out.println("");
        System.out.println("> iter.hasNext() = " + iter.hasNext() );

        System.out.println("");
        System.out.println("************ End_Iterator_Test *********");
        System.out.println("");
    }
    public static void test_GTUSet() {

        System.out.println("");
        System.out.println("************GTUSet_Test**************");
        System.out.println("There is only one constructor for GTUSet . ");
        System.out.println("It is  adequate for purpose of Set .");

        System.out.println("1 - public GTUSet()");
        System.out.println("");

        GTUSet<Integer> s1 = new GTUSet<Integer>();
        System.out.println("GTUSet<Integer> s1 = new GTUSet<>();");
        System.out.println("");

        GTUSet<Integer> s2 = new GTUSet<Integer>();
        System.out.println("GTUSet<Integer> s2 = new GTUSet<>();");
        System.out.println("");

        GTUSet<String> s3 = new GTUSet<String>();
        System.out.println("GTUSet<String> s3 = new GTUSet<String>();");
        System.out.println("");

        System.out.println("********* Inserting_Test **********");
        System.out.println("");

        System.out.println("> Insertion on the set. ");
        System.out.println("There is one insert method for insertion on Set");
        System.out.println("1 - public void insert( T newElement ) ,     add the element to the end of the set.");
        System.out.println("it is adequate because there would not be any repeated element on set");
        System.out.println("");

        s1.insert(1);
        System.out.println("> insert(1)     on s1");
        s1.insert(-4);
        System.out.println("> insert(-4)    on s1");
        s1.insert(2);
        System.out.println("> insert(2)     on s1");
        s1.insert(3);
        System.out.println("> insert(3)     on s1");

        System.out.println("");
        System.out.println("Trying to add existing element that is '3' , There would not be any changing on the set.");
        s1.insert(3);
        System.out.println("> insert(3)     on s1");

        System.out.println("");
        System.out.println("> toString      on s1");
        System.out.println(s1);

        System.out.println("");
        System.out.println("> size()        on s1");
        System.out.println("Size = " + s1.size());

        s1.insert(-1);
        System.out.println("> insert(-1)    on s1");
        s1.insert(-2);
        System.out.println("> insert(-2)    on s1");
        s1.insert(-3);
        System.out.println("> insert(-3)    on s1");

        System.out.println("");
        System.out.println("> toString      on s1");
        System.out.println(s1);

        System.out.println("");
        System.out.println("> size()        on s1");
        System.out.println("Size = " + s1.size());

        System.out.println("");
        System.out.println("> toString      on s1");
        System.out.println(s1);

        System.out.println("");
        s2.insert(1);
        System.out.println("> insert(1)     on s2");
        s2.insert(-4);
        System.out.println("> insert(-4)    on s2");
        s2.insert(2);
        System.out.println("> insert(2)     on s2");
        s2.insert(3);
        System.out.println("> insert(3)     on s2");
        s2.insert(-1);
        System.out.println("> insert(-1)    on s2");
        s2.insert(-2);
        System.out.println("> insert(-2)    on s2");
        s2.insert(-3);
        System.out.println("> insert(-3)    on s2");

        System.out.println("");
        System.out.println("> toString      on s2");
        System.out.println(s2);

        System.out.println("");
        System.out.println("> size()        on s2");
        System.out.println("Size = " + s2.size());

        System.out.println("");
        System.out.println("************ End_Inserting_Test *********");
        System.out.println("");

        System.out.println("********* contains_Test **********");

        s3.insert("GTU");
        System.out.println("> insert(\"GTU\")    on s3");

        System.out.println("");
        System.out.println("> toString      on s3");
        System.out.println(s3);

        System.out.println("");
        s3.insert("ITU");
        System.out.println("> insert(\"ITU\")     on s3");

        System.out.println("");
        System.out.println("> toString      on s3");
        System.out.println(s3);

        System.out.println("");
        System.out.println("> contains(\"GTU\")       on s3 = " + s3.contains("GTU") );
        System.out.println("> contains(\"ODTU\")       on s3 = " + s3.contains("ODTU") );
        System.out.println("> contains(\"ITU\")       on s3 = " + s3.contains("ITU") );

        System.out.println("");
        System.out.println("************ End_contains_Test *********");
        System.out.println("");


        System.out.println("********* Equality_Test **********");
        System.out.println("");

        System.out.println("");
        System.out.println("> toString      on s1");
        System.out.println(s1);

        System.out.println("");
        System.out.println("> toString      on s2");
        System.out.println(s2);

        System.out.println("");
        System.out.println("s1.equals(s2) = " + s1.equals(s2));

        System.out.println("");
        s2.insert(11);
        System.out.println("> insert(11)    on s2");

        System.out.println("");
        System.out.println("s1.equals(s2) = " + s1.equals(s2));

        System.out.println("");
        System.out.println("************ End_Equality_Test *********");
        System.out.println("");


        System.out.println("********* Erasing_Test **********");
        System.out.println("");

        System.out.println("There is an erase in vector.");
        System.out.println("> public T erase(T Element)  , erase the given element from the set ");

        System.out.println("");
        System.out.println("> toString      on s1");
        System.out.println(s1);

        System.out.println("");
        s1.erase((Integer)2);
        System.out.println("> erase(2)      on s1");

        System.out.println("");
        System.out.println("> toString      on s1");
        System.out.println(s1);

        System.out.println("");
        s1.erase((Integer)3);
        System.out.println("> erase(3)      on s1");

        System.out.println("");
        System.out.println("> toString      on s1");
        System.out.println(s1);


        System.out.println("");
        System.out.println("> size()        on s1");
        System.out.println("Size = " + s1.size());

        System.out.println("");
        System.out.println("************ End_Erasing_Test *********");
        System.out.println("");


        System.out.println("********* Empty_Test **********");
        System.out.println("");

        System.out.println("");
        System.out.println("> toString      on s1");
        System.out.println(s1);

        System.out.println("");
        System.out.println("> empty()       on s1 = " + s1.empty() );


        System.out.println("");
        System.out.println("************ End_Empty_Test *********");
        System.out.println("");

        System.out.println("********* Clear_Test **********");
        System.out.println("");


        System.out.println("");
        System.out.println("> toString      on s1");
        System.out.println(s1);

        System.out.println("");
        s1.clear();
        System.out.println("> clear()       on s1");

        System.out.println("");
        System.out.println("> toString      on s1");
        System.out.println(s1);

        System.out.println("");
        System.out.println("> size()        on s1");
        System.out.println("Size = " + s1.size());

        System.out.println("");
        System.out.println("************ End_Clear_Test *********");
        System.out.println("");

        System.out.println("********* max_Size_Test **********");
        System.out.println("");

        System.out.println("");
        System.out.println("> max_size()       on s1 = " + s1.max_size() );

        System.out.println("");
        System.out.println("************ End_max_Size_Test *********");
        System.out.println("");

        System.out.println("********* hash_code_Test **********");
        System.out.println("");

        System.out.println("");
        s1.clear();
        System.out.println("> clear()       on s1");

        System.out.println("");
        s2.clear();
        System.out.println("> clear()       on s2");

        System.out.println("");
        s1.insert(1);
        System.out.println("> insert(1)     on s1");

        System.out.println("");
        s2.insert(1);
        System.out.println("> insert(1)     on s2");

        System.out.println("");
        System.out.println("> toString      on s1");
        System.out.println(s1);

        System.out.println("");
        System.out.println("> toString      on s2");
        System.out.println(s2);

        System.out.println("v1.hashCode() =" + s1.hashCode());
        System.out.println("v2.hashCode() =" + s2.hashCode());
        System.out.println("Same Configuration");

        System.out.println("");
        s1.insert(2);
        System.out.println("> insert(2)     on s1");

        System.out.println("");
        System.out.println("> toString      on s1");
        System.out.println(s1);

        System.out.println("");
        System.out.println("> toString      on s2");
        System.out.println(s2);

        System.out.println("");
        System.out.println("v1.hashCode() =" + s1.hashCode());
        System.out.println("v2.hashCode() =" + s2.hashCode());
        System.out.println("Different Configuration");


        System.out.println("");
        System.out.println("************ End_hash_code_Test *********");
        System.out.println("");

        System.out.println("********* Iterator_Test **********");
        System.out.println("");

        System.out.println("> toString      on s3");
        System.out.println(s3);

        System.out.println("");
        s3.insert("KTU");
        System.out.println("> insert(\"KTU\")     on s3");

        System.out.println("");
        System.out.println("> toString      on s3");
        System.out.println(s3);

        System.out.println("");
        GTUIterator<String> iter = s3.iterator();
        System.out.println("> GTUIterator<String> iter = s3.iterator() ");


        System.out.println("");
        System.out.println("Printing via iterator , all the element to the screen on the vector thanks to for loop. ");

        for( ; iter.hasNext() ; )
            System.out.println( iter.next());

        System.out.println("");
        System.out.println("> iter.hasNext() = " + iter.hasNext() );

        System.out.println("");
        iter = s3.iterator();
        System.out.println("> iter = v3.iterator() ");

        System.out.println("iter.next() = " + iter.next());
        System.out.println("iter.next() = " + iter.next());
        System.out.println("iter.next() = " + iter.next());

        System.out.println("");
        System.out.println("> iter.hasNext() = " + iter.hasNext() );

        System.out.println("");
        System.out.println("************ End_Iterator_Test *********");
        System.out.println("");
    }
}
