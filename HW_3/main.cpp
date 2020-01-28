/*______________________________________________________________________ _____________*/
/*Object-Oriented-Programming with C++ Language HW-3____________________ _____________*/
/*Student Name: NEVZAT SEFEROGLU________________________________________ _____________*/
/*Student Number: 171044024___________________________________________________________*/
/*Problem : N-Puzzle Game Implementation(Included Class Implementation)__in_C++______ */
/*______________________________________________________________________ _____________*/
#include "NPuzzle.h"
/*Library that I implemented with class data keeper*/

using namespace std;
/* namespace std , to implement more clear code */
int main(int argc, char *argv[])
{
    srand(time(NULL));
    NPuzzle Puzzle;

    /* Make Main Game Loop check value to false */
    Puzzle.quit=false;
    char current_key='\0';

    const int min_size=3; /* min size puzzle row column*/
    const int max_size=9; /* max size puzzle row column*/

    int puzzle_size=min_size; /*Puzzle size variable*/
    string filename; /* filename for output stream */

    /* Player Guide For User */
    cout<<"\t\t.> Welcome to the N-Puzzle Solver Game <<-\n";
    cout<<"\t\t___________________________________________\n\n";
    cout<<"-. Game Purpose: Solving N-Puzzle by moving over it.\n\n";
    cout<<"Input Guide : \n";
    cout<<"-------------\n";
    cout<<"-. Press (U) to move UP\n";
    cout<<"-. Press (R) to move RIGHT\n";
    cout<<"-. Press (L) to move LEFT\n";
    cout<<"-. Press (D) to move DOWN\n";
    cout<<"-. Press (S) to Shuffle the Current Puzzle\n\n";
    cout<<"Entended Version Input :\n";
    cout<<"------------------------\n";
    cout<<"-. Press (V) to solve entire puzzle and show part of each step\n";
    cout<<"-. Press (T) to print a report to the screen\n";
    cout<<"-. Press (O) to save the current puzzle board into a file\n";
    cout<<"-. Press (E) to load the current puzzle board from the file\n";
    cout<<"-. Press (Q) to Quit Puzzle Game\n";
    cout<<"_______________________________________________________Good Luck :)\n\n";
    /* End___Player__Guide  */

    /* Argument Handling */
    switch(argc)
    {
        case 1:
            puzzle_size=Puzzle.get_puzzle_size(min_size,max_size);
            Puzzle.setsize(puzzle_size);
        break;

        case 2:
            Puzzle.readFromFile(argv[argc-1]);
        break;

        default:
            cerr<<"Critical Argument Error !\n";
            exit(1);
        break;
    }
    /* End__Argument Handling */
    
    /* Main Game Loop */
    cout<<"Your initial random board is:\n\n";

    while(!Puzzle.quit)
    {
        /* Getting input from user */
        Puzzle.print();
        cout<<"Your Move:";
        cin>>current_key;

        switch(current_key)
        {
            /* User typed Left , Right ,Up ,Down key handling */
            case 'r':
            case 'R':
            case 'l':
            case 'L':
            case 'u':
            case 'U':
            case 'd':
            case 'D':
                if(!Puzzle.move(current_key))
                    cout<<"-> Invalid Move"<<'\n';
                break;

            /* Intelligent Move */
            case 'i':
            case 'I': 
                Puzzle.moveIntelligence();
                break;

            /* Shuffle the current board */
            case 's':
            case 'S':
                Puzzle.shuffle(get_x*max_size);
                cout<<"-> Shuffled Successfully !\n";
                break;
            
            /* make intelligent solve the entire puzzle */
            case 'v':
            case 'V':
                Puzzle.goSolution();
                break;

            /* Report Handling with User Input */
            case 't':
            case 'T':
                Puzzle.printReport();
                break;

            /* Loading current puzzle from file */
            case 'o':
            case 'O':
                filename=Puzzle.get_file_name();
                Puzzle.readFromFile(filename);
                break;

            /* Writing current puzzle to file */
            case 'e':
            case 'E':
                filename=Puzzle.get_file_name();
                Puzzle.writeToFile(filename);
                break;

            /* Quit the Game */
            case 'q':
            case 'Q':
                Puzzle.quit=true;
                break;
            
            default:
                cout<<"Invalid Input!\n";
            break;
        }

        /* Is End Puzzle Consideration */

        if(Puzzle.is_end_puzzle()&&!Puzzle.quit)
        {
            Puzzle.print();
            cout<<"Problem Solved!\n";
            Puzzle.printReport();
            Puzzle.quit=true;
        }
    }

    /* Releasing Current Puzzle Class Data used from the memory */
    Puzzle.release_puzzle();
    return 0;
}