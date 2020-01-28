#include "NPuzzle.h"
using namespace std;
int main(int argc, char *argv[])
{
    srand(time(NULL));
    NPuzzle Puzzle;

    Puzzle.quit=false;
    char current_key='\0';

    const int min_size=3;
    const int max_size=9;

    int puzzle_size=min_size;
    string filename;

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
    
    cout<<"Your initial random board is:\n\n";

    while(!Puzzle.quit)
    {
        cout>>Puzzle;
        cout<<"Your Move:";
        cin>>current_key;

        switch(current_key)
        {
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

            /* Shuffle*/
            case 's':
            case 'S':
                Puzzle.shuffle(Puzzle.get_xSize()*Puzzle.get_ySize());
                cout<<"-> Shuffled Successfully !\n";
                break;
            
            /* Solve */
            case 'v':
            case 'V':
                Puzzle.solvePuzzle();
                break;

            /* Print report */
            case 't':
            case 'T':
                Puzzle.printReport();
                break;

            /* Load */
            case 'o':
            case 'O':
                filename=Puzzle.get_file_name();
                Puzzle.readFromFile(filename);
                break;

            /* write */
            case 'e':
            case 'E':
                filename=Puzzle.get_file_name();
                Puzzle.writeToFile(filename);
                break;

            /* quit */
            case 'q':
            case 'Q':
                Puzzle.quit=true;
                break;
            
            default:
                cout<<"Invalid Input!\n";
            break;
        }

        if(Puzzle.isSolved()&&!Puzzle.quit)
        {
            cout>>Puzzle;
            cout<<"Problem Solved!\n";
            Puzzle.printReport();
            Puzzle.quit=true;
        }
    }
    return 0;
}