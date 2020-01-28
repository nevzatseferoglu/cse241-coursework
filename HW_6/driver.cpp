/*______________________________________________________________________ _____________*/
/*Object-Oriented-Programming with C++ Language HW-6____________________ _____________*/
/*Student Name: NEVZAT SEFEROGLU________________________________________ _____________*/
/*Student Number: 171044024___________________________________________________________*/
/*Problem : GTUVector and GTUSet Container Implementation____________________________ */
/*______________________________________________________________________ _____________*/

#include <iostream>
#include "./src/GTUVector.h"
#include "./src/GTUSet.h"
#include "./src/Global.h"
#include "./src/Exceptions.h"

using namespace std;
using namespace GTU_171044024;

class testClass
{
    public:
        
        void printScreen( void )
        {
            cout << "-> works fine :) " << endl;
        }
        bool operator==(const testClass& other)
        {
            return data == other.data;
        }

    private:

        int data;

};
/* Global functions's input function argument function */
template < typename T >
bool isNegative( const T& data)
{
    return data < 0 ;
}

template <typename T>
void printMember(const T& data)
{
    cout << data << endl;
}
/************End***************************************/


int main( void )
{

    try
    {
        GTUVector< int > print;
        cout << endl << endl  << "************************BEGIN_GTUVector_Test*****************" << endl << endl;
        print.print_GTUVector_info();
        cout << "GTUVector< int > testVector(5);" << endl;
        GTUVector< int > test_vector1(4);

        cout << "test_vector1[0] = 1 " << endl;
        test_vector1[0] = 1;
        cout << "test_vector1[1] = 2 " << endl;
        test_vector1[1] = 2;
        cout << "test_vector1[2] = 3 " << endl;
        test_vector1[2] = 3;
        cout << "test_vector1[3] = 4 " << endl;
        test_vector1[3] = 4;
        cout << endl;

        cout<<"test_vector1";
        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = test_vector1.begin() ; iter != test_vector1.end() ; ++iter )
            cout << *iter << " ";
        cout << endl << endl;


        cout << "GTUVector< int > test_vector2(4);" << endl;
        GTUVector< int > test_vector2(5);

        cout << "test_vector2[0] = -1 " << endl;
        test_vector2[0] = -1;
        cout << "test_vector2[1] = -2 " << endl;
        test_vector2[1] = -2;
        cout << "test_vector2[2] = -3 " << endl;
        test_vector2[2] = -3;
        cout << "test_vector2[3] = -4 " << endl;
        test_vector2[3] = -4;
        cout << "test_vector2[4] = -5 " << endl;
        test_vector2[4] = -5;

        cout<<"test_vector2";
        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = test_vector2.begin() ; iter != test_vector2.end() ; ++iter )
            cout << *iter << " ";
        cout << endl << endl;

        test_vector1 = test_vector2;
        cout << " Assignment Test" << endl;
        cout << "test_vector1 = test_vector2; " << endl << endl;

        cout<<"test_vector1";
        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = test_vector1.begin() ; iter != test_vector1.end() ; ++iter )
            cout << *iter << " ";
        cout << endl << endl;

        cout<<"test_vector2";
        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = test_vector2.begin() ; iter != test_vector2.end() ; ++iter )
            cout << *iter << " ";
        cout << endl << endl;

        GTUVector< int > test_vector3(3);
        cout << "GTUVector< int > test_vector3(3); " << endl;

        cout << "test_vector2[0] = -4 " << endl;
        test_vector3[0] = -1;
        cout << "test_vector2[1] = -3 " << endl;
        test_vector3[1] = -3;
        cout << "test_vector2[2] = -6 " << endl;
        test_vector3[2] = -6;
        cout << endl;

        cout << " Copy Constructor Test" << endl;
        GTUVector< int > test_vector4(test_vector3);
        cout << "GTUVector< int > test_vector4(test_vector3); " << endl << endl;

        cout<<"test_vector4";
        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = test_vector4.begin() ; iter != test_vector4.end() ; ++iter )
            cout << *iter << " ";
        cout << endl << endl;
        

        GTUVector< int > testVector;
        cout << "GTUVector< int > testVector; " << endl;
        cout << "max_size() = " << testVector.max_size() << endl;

        testVector.insert(1);
        cout <<"insert(1) " << endl;
        testVector.insert(2);
        cout <<"insert(2) " << endl;
        testVector.insert(3);
        cout <<"insert(3) " << endl << endl;

        cout << "printing data using [] operator " << endl;
        cout << "testVector[0] -> " << testVector[0] << endl;
        cout << "testVector[1] -> " << testVector[1] << endl;
        cout << "testVector[2] -> " << testVector[2] << endl;

        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = testVector.begin() ; iter != testVector.end() ; ++iter )
            cout << *iter << " ";
        cout << endl << endl;

        cout << "size() = " << testVector.size() << endl;
        cout << "empty() = ";
        if( testVector.empty() )
            cout << "Vector is empty !" << endl;
        else
            cout << "Vector is not empty !" << endl << endl;

        auto iter = testVector.begin();
        cout << "auto iter = testVector.begin() " << endl;
        cout << "erase(iter)" << endl;
        testVector.erase(iter);
        cout << endl <<"Current configuration thanks to iterator : " << endl;
        for( auto iter = testVector.begin() ; iter != testVector.end() ; ++iter )
            cout << *iter << " ";
        cout << endl << endl;

        iter = testVector.begin();
        cout << "iter = testVector.begin() " << endl;
        testVector.erase(iter);
        cout <<"erase(iter) " << endl ;
        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = testVector.begin() ; iter != testVector.end() ; ++iter )
            cout << *iter << " ";
        cout << endl  << endl;

        cout << "insert( testVector.begin() , 12 ) " << endl;
        testVector.insert( testVector.begin() , 12 );
        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = testVector.begin() ; iter != testVector.end() ; ++iter )
            cout << *iter << " ";
        cout << endl  << endl;
        cout << "insert( testVector.begin() , 13 ) " << endl;
        testVector.insert( testVector.begin() , 13 );
        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = testVector.begin() ; iter != testVector.end() ; ++iter )
            cout << *iter << " ";
        cout << endl  << endl;

        cout << "Inserting specific position with iterator " << endl;
        cout << "auto iter = testVector.begin() " << endl;
        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = testVector.begin() ; iter != testVector.end() ; ++iter )
            cout << *iter << " ";
        cout << endl  << endl;

        cout << "iter = testVector.begin() " << endl;
        iter = testVector.begin();
        cout << "++iter"  << endl;
        ++iter;
        cout << "*iter = " << *iter << endl;
        cout << "insert(iter , -1 ) " << endl;
        testVector.insert(iter , -1 );
        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = testVector.begin() ; iter != testVector.end() ; ++iter )
            cout << *iter << " ";
        cout << endl  << endl;

        cout << "iter = testVector.begin() " << endl;
        iter = testVector.begin();
        cout << "++iter"  << endl;
        ++iter;
        cout << "++iter"  << endl;
        ++iter;
        cout << "*iter = " << *iter << endl;
        cout << "insert(iter , -2 ) " << endl;
        testVector.insert(iter , -2 );
        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = testVector.begin() ; iter != testVector.end() ; ++iter )
            cout << *iter << " ";
        cout << endl  << endl;

        cout << "iter = testVector.end() " << endl;
        iter = testVector.end();
        cout << "testVector.insert(iter , -3)" << endl;
        testVector.insert(iter , -3);
        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = testVector.begin() ; iter != testVector.end() ; ++iter )
            cout << *iter << " ";
        cout << endl  << endl;

        cout << "clear()" << endl;
        testVector.clear();
        cout << "size() = " << testVector.size() <<endl;
        cout << endl << "Current configuration thanks to iterator : " << endl;
        
        cout << "empty() = ";
        if( testVector.empty() )
            cout << "Vector is empty !" << endl << endl;
        else
            cout << "Vector is not empty !" << endl << endl;

        cout << "There is a special case for end() function : " << endl;
        cout << "Special case is normally STL end() return a abstract element which locate"
            << endl << "at the end of the vector , my vector is also work like STL" << endl;
        cout << "So if We made auto iter = testVector.end() " << endl;
        cout << "iter refer a virtual element which could not be dereferenced " << endl;
        cout << "if we made  : " << endl;
        cout << "auto iter = testVector.end() : " << endl;
        cout << "--iter : " << endl;
        cout << "In this case we definitely refer last element in the vector. " << endl;
        cout << "For example : " << endl;
        
        cout << "***********" << endl;
        testVector.insert(1);
        cout << "testVector.insert(1);" << endl;
        testVector.insert(2);
        cout << "testVector.insert(2);" << endl;
        testVector.insert(3);
        cout << "testVector.insert(3);" << endl;
        testVector.insert(4);
        cout << "testVector.insert(4);" << endl;

        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = testVector.begin() ; iter != testVector.end() ; ++iter )
            cout << *iter << " ";
        cout << endl  << endl;
        
        iter = testVector.end();
        cout << "iter = testVector.end(); " << endl;

        cout << "--iter;" << endl;
        --iter;
        cout << "*iter = " << *iter << endl;
        cout << "STL also works like this " << endl;
        cout << "***********" << endl << endl;

        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = testVector.begin() ; iter != testVector.end() ; ++iter )
            cout << *iter << " ";
        cout << endl  << endl;

        cout << "Iterator-Test" << endl;
        cout << "********************************" << endl;
        cout << "GTUIterator<int> iterTest1 = testVector.begin();" << endl;
        GTUIterator<int> iterTest1 = testVector.begin();
        
        cout << "*iterTest1  -> " << *iterTest1 << endl << endl;
        cout << "*iterTest1 = -1;" << endl ;
        *iterTest1 = -1;
        cout << endl << "*iterTest1  -> " << *iterTest1 << endl;
        cout << "Dereferencing operator as a L-value " << endl << endl;

        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = testVector.begin() ; iter != testVector.end() ; ++iter )
            cout << *iter << " ";
        cout << endl  << endl;

        iter = testVector.begin();
        cout << "*operator() : " << endl;
        cout << " *iter -> " << *iter << endl << endl;
        cout << "++operator() : " << endl;
        cout << " *(++iter) -> " << *(++iter) << endl << endl;
        cout << "++operator(int) : " << endl;
        cout << " *(iter++) -> " << *(iter++) << endl;
        cout << " *(iter) -> " << *(iter) << endl << endl;
        cout << "--operator() : " << endl;
        cout << " *(--iter) -> " << *(--iter) << endl << endl;
        cout << "--operator(int) : " << endl;
        cout << " *(iter--) -> " << *(iter--) << endl;
        cout << " *(iter) -> " << *(iter) << endl << endl;

        cout << "iter = testVector.begin();" << endl;
        iter = testVector.begin();
        cout << "GTUIterator<int> iter2 = testVector.begin();" << endl << endl;
        GTUIterator<int> iter2 = testVector.begin();

        cout << "==operator() : " << endl;
        cout << "if( iter == iter2 )" << endl;
        if( iter == iter2 )
            cout << "Equal" << endl << endl;
        else
            cout << "Not Equal" << endl << endl;

        cout <<"*(++iter2) -> " << *(++iter2) << endl;
        cout <<"*(iter) -> " << *(iter) << endl << endl;
        cout << "if( iter == iter2 )" << endl;
        if( iter == iter2 )
            cout << "Equal" << endl << endl;
        else
            cout << "Not Equal" << endl << endl;
        
        cout << "=operator() : " << endl;
        cout << "iter2 = iter; " << endl;
        iter2 = iter;

        cout << "Point that 'iter' refers configuration" << endl;
        while(iter != testVector.end())
        {
            cout << *iter << " ";
            ++iter;
        }
        cout << endl ;


        cout << "Point that 'iter2' refers configuration" << endl;
        while(iter2 != testVector.end())
        {
            cout << *iter2 << " ";
            ++iter2;
        }
        cout << endl ;

        cout << "GTUVector<testClass> v1;" << endl;
        GTUSet<testClass> v1;

        cout << "testClass example;" << endl;
        testClass exampleVector;
        
        cout << "v1.insert(example);" << endl << endl;
        v1.insert(exampleVector);

        cout << "auto iter_specific = v1.begin();" << endl;
        auto iter_specific_v = v1.begin();

        cout << "iter_specific_v ->printScreen();" << endl;
        iter_specific_v ->printScreen();

        cout << endl  << endl;

        cout << "Global-Function-Test" << endl;
        cout << "*********************" << endl;

        GTUSet<double> setGlobalVector;

        setGlobalVector.insert(5.1);
        setGlobalVector.insert(-5.4);
        setGlobalVector.insert(-2.7);

        cout << "auto findIterVector = find( setGlobal.begin() , setGlobal.end() , -5.4 ) " << endl;
        auto findIterVector = find( setGlobalVector.begin() , setGlobalVector.end() , -5.4 );
        cout << "*findIterVector - > " << *findIterVector << endl << endl;


        cout << "auto find_if_Iter_vector = find_if( setGlobal.begin() , setGlobal.end() , isNegative<double> ) " << endl;
        auto find_if_Iter_vector = find_if(setGlobalVector.begin() , setGlobalVector.end() , isNegative<double> );
        cout << "*find_if_Iter_vector - > " << *find_if_Iter_vector << endl << endl;

        cout << "for_each( setGlobal.begin() , setGlobal.end() , printMember<double> ) " << endl;
        auto for_each_Iter_vector = for_each(setGlobalVector.begin() , setGlobalVector.end() , printMember<double> );
        cout <<"Member printed out on the screen " << endl << endl;

        cout << "************************END_GTUVector_Test*****************" << endl<< endl;
        



        GTUSet< int > printSet;
        cout << endl << endl  << "************************BEGIN_GTUSet_Test*****************" << endl << endl;
        printSet.print_GTUSet_info();
        cout << "GTUSet< int > testSet;" << endl;
        GTUSet< int > test_set1;

        cout << "test_set1.insert(-5) " << endl;
        test_set1.insert(-5);
        cout << "test_set1.insert(-7) " << endl;
        test_set1.insert(-7);

        cout << "\nAttempt to insert '-7' again " << endl;
        cout << "test_set1.insert(-7) " << endl;
        cout << "it throws an exception \n" << endl;

        cout << "test_set1.insert(-1) " << endl;
        test_set1.insert(-1);
        cout << endl;

        cout<<"test_set1";
        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = test_set1.begin() ; iter != test_set1.end() ; ++iter )
            cout << *iter << " ";
        cout << endl << endl;


        cout << "GTUSet< int > test_set2;" << endl;
        GTUSet< int > test_set2;

        cout << "test_set2.insert(-1) " << endl;
        test_set2.insert(-1);
        cout << "test_set2.insert(-2) " << endl;
        test_set2.insert(-2);
        cout << "test_set2.insert(-3) " << endl;
        test_set2.insert(-3);
        cout << "test_set2.insert(-4) " << endl;
        test_set2.insert(-4);
        cout << "test_set2.insert(-5) " << endl;
        test_set2.insert(-5);
        cout << endl;

        cout<<"test_set2";
        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = test_set2.begin() ; iter != test_set2.end() ; ++iter )
            cout << *iter << " ";
        cout << endl << endl;

        test_set1 = test_set2;
        cout << " Assignment Test" << endl;
        cout << "test_set1 = test_set2; " << endl << endl;

        cout<<"test_set1";
        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = test_set1.begin() ; iter != test_set1.end() ; ++iter )
            cout << *iter << " ";
        cout << endl << endl;

        cout<<"test_set2";
        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = test_set2.begin() ; iter != test_set2.end() ; ++iter )
            cout << *iter << " ";
        cout << endl << endl;

        cout << "GTUSet< int > test_set3; " << endl;
        GTUSet< int > test_set3;

        cout << "test_set3.insert(1) " << endl;
        test_set3.insert(1);
        cout << "test_set3.insert(2) " << endl;
        test_set3.insert(2);
        cout << "test_set3.insert(3) " << endl;
        test_set3.insert(3);
        cout << endl;

        cout << " Copy Constructor Test" << endl;
        GTUSet< int > test_set4(test_set3);
        cout << "GTUSet< int > test_set4(test_set3); " << endl << endl;

        cout<<"test_set4";
        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = test_set4.begin() ; iter != test_set4.end() ; ++iter )
            cout << *iter << " ";
        cout << endl << endl;
        

        GTUSet< int > testSet;
        cout << "GTUSet< int > testSet; " << endl;
        cout << "max_size() = " << testSet.max_size() << endl;

        testSet.insert(1);
        cout <<"insert(1) " << endl;
        testSet.insert(2);
        cout <<"insert(2) " << endl;
        testSet.insert(3);
        cout <<"insert(3) " << endl << endl;

        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = testSet.begin() ; iter != testSet.end() ; ++iter )
            cout << *iter << " ";
        cout << endl << endl;

        cout << "size() = " << testSet.size() << endl;
        cout << "empty() = ";
        if( testSet.empty() )
            cout << "Set is empty !" << endl;
        else
            cout << "Set is not empty !" << endl << endl;

        auto iterSet = testSet.begin();
        cout << "auto iterSet = testSet.begin() " << endl;
        cout << "erase(iterSet)" << endl;
        testSet.erase(iterSet);
        cout << endl <<"Current configuration thanks to iterator : " << endl;
        for( auto iter = testSet.begin() ; iter != testSet.end() ; ++iter )
            cout << *iter << " ";
        cout << endl << endl;

        iterSet = testSet.begin();
        cout << "iterSet = testSet.begin() " << endl;
        testSet.erase(iterSet);
        cout <<"erase(iterSet) " << endl ;
        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = testSet.begin() ; iter != testSet.end() ; ++iter )
            cout << *iter << " ";
        cout << endl  << endl;


        cout << "clear()" << endl;
        testSet.clear();
        cout << "size() = " << testSet.size() <<endl;
        cout << endl << "Current configuration thanks to iterator : " << endl;
        
        cout << "empty() = ";
        if( testSet.empty() )
            cout << "Set is empty !" << endl << endl;
        else
            cout << "Set is not empty !" << endl << endl;

        cout << "There is a special case for end() function : " << endl;
        cout << "Special case is normally STL end() return a abstract element which locate"
            << endl << "at the end of the set , my Set is also work like STL" << endl;
        cout << "So if We made auto iter = testSet.end() " << endl;
        cout << "iter refer a virtual element which could not be dereferenced " << endl;
        cout << "if we made  : " << endl;
        cout << "auto iter = testSet.end() : " << endl;
        cout << "--iter : " << endl;
        cout << "In this case we definitely refer last element in the Set. " << endl;
        cout << "For example : " << endl;
        
        cout << "***********" << endl;
        testSet.insert(1);
        cout << "testSet.insert(1);" << endl;
        testSet.insert(2);
        cout << "testSet.insert(2);" << endl;
        testSet.insert(3);
        cout << "testSet.insert(3);" << endl;
        testSet.insert(4);
        cout << "testSet.insert(4);" << endl;

        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = testSet.begin() ; iter != testSet.end() ; ++iter )
            cout << *iter << " ";
        cout << endl  << endl;
        
        iter = testSet.end();
        cout << "iter = testSet.end(); " << endl;

        cout << "--iter;" << endl;
        --iter;
        cout << "*iter = " << *iter << endl;
        cout << "STL also works like this " << endl;
        cout << "***********" << endl << endl;

        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iter = testSet.begin() ; iter != testSet.end() ; ++iter )
            cout << *iter << " ";
        cout << endl  << endl;

        cout << "Iterator-Test" << endl;
        cout << "********************************" << endl;
        cout << "GTUIterator<int> iterTest = testSet.begin();" << endl;
        GTUIterator<int> iterTest = testSet.begin();
        
        cout << "*iterTest  -> " << *iterTest << endl << endl;
        cout << "*iterTest = -1;" << endl ;
        *iterTest = -1;
        cout << endl << "*iterTest  -> " << *iterTest << endl;
        cout << "Dereferencing operator as a L-value " << endl << endl;

        cout << endl << "Current configuration thanks to iterator : " << endl;
        for( auto iterTest = testSet.begin() ; iterTest != testSet.end() ; ++iterTest )
            cout << *iterTest << " ";
        cout << endl  << endl;

        iterTest = testSet.begin();
        cout << "*operator() : " << endl;
        cout << " *iterTest -> " << *iterTest << endl << endl;
        cout << "++operator() : " << endl;
        cout << " *(++iterTest) -> " << *(++iterTest) << endl << endl;
        cout << "++operator(int) : " << endl;
        cout << " *(iterTest++) -> " << *(iterTest++) << endl;
        cout << " *(iterTest) -> " << *(iterTest) << endl << endl;
        cout << "--operator() : " << endl;
        cout << " *(--iterTest) -> " << *(--iterTest) << endl << endl;
        cout << "--operator(int) : " << endl;
        cout << " *(iterTest--) -> " << *(iterTest--) << endl;
        cout << " *(iterTest) -> " << *(iterTest) << endl << endl;

        cout << "iterTest = testSet.begin();" << endl;
        iterTest = testSet.begin();
        cout << "GTUIterator<int> iter2set = testSet.begin();" << endl << endl;
        GTUIterator<int> iter2set = testSet.begin();

        cout << "==operator() : " << endl;
        cout << "if( iterTest == iter2set )" << endl;
        if( iterTest == iter2set )
            cout << "Equal" << endl << endl;
        else
            cout << "Not Equal" << endl << endl;

        cout <<"*(++iter2set) -> " << *(++iter2set) << endl;
        cout <<"*(iter) -> " << *(iter) << endl << endl;
        cout << "if( iterTest == iter2set )" << endl;
        if( iterTest == iter2set )
            cout << "Equal" << endl << endl;
        else
            cout << "Not Equal" << endl << endl;
        
        cout << "=operator() : " << endl;
        cout << "iter2set = iterTest; " << endl << endl;
        iter2set = iterTest;

        cout << "Point that 'iter' refers configuration" << endl;
        while(iterTest != testSet.end())
        {
            cout << *iterTest << " ";
            ++iterTest;
        }
        cout << endl ;


        cout << "Point that 'iter2set' refers configuration" << endl;
        while(iter2set != testSet.end())
        {
            cout << *iter2set << " ";
            ++iter2set;
        }
        cout << endl ;

        cout << "GTUSet<testClass> s1;" << endl;
        GTUSet<testClass> s1;

        cout << "testClass example;" << endl;
        testClass example;
        
        cout << "s1.insert(example);" << endl << endl;
        s1.insert(example);

        cout << "auto iter_specific = s1.begin();" << endl;
        auto iter_specific = s1.begin();

        cout << "iter_specific ->printScreen();" << endl;
        iter_specific ->printScreen();

        cout << endl  << endl;
        cout << "Global-Function-Test" << endl;
        cout << "*********************" << endl;

        GTUSet<double> setGlobal;

        setGlobal.insert(5.1);
        setGlobal.insert(-5.4);
        setGlobal.insert(-2.7);

        cout << "auto findIter = find( setGlobal.begin() , setGlobal.end() , -2.7 ) " << endl;
        auto findIter = find( setGlobal.begin() , setGlobal.end() , -2.7 );
        cout << "*findIter - > " << *findIter << endl << endl;


        cout << "auto find_if_Iter = find_if( setGlobal.begin() , setGlobal.end() , isNegative<double> ) " << endl;
        auto find_if_Iter = find_if(setGlobal.begin() , setGlobal.end() , isNegative<double> );
        cout << "*find_if_Iter - > " << *find_if_Iter << endl << endl;

        cout << "for_each( setGlobal.begin() , setGlobal.end() , printMember<double> ) " << endl;
        auto for_each_Iter = for_each(setGlobal.begin() , setGlobal.end() , printMember<double> );
        cout <<"Member printed out on the screen " << endl << endl;

        cout << "************************END_GTUSet_Test*****************" << endl;
    }
    catch(const bad_pafram& error)
    {
        cout << error.getErrorPhrase() << endl;
    }
    catch(const Exceptions& error)
    {
        cout << error.getErrorPhrase() << endl;
    }

    return 0;
}