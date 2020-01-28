/*__________________________________________________*/
/*Object-Oriented-Programming with C++ Language HW-1*/
/*Student Name: NEVZAT SEFEROGLU____________________*/
/*Student Number: 171044024_________________________*/
/*Problem : N-Puzzle Game Implementation__in_C++____*/
/*__________________________________________________*/

#include <iostream> /*_Standart input Output Stream Header_*/
#include <cstdlib>  /*For getting pseudo number , i had to use that header*/
#include <ctime>    /*to use rand() function */

/*Direction Enumeration Definition*/
enum Direction{right,left,up,down};

/*Structure which holds my all possible type of puzzle_map*/
struct Puzzle{
    int* puzzle_map;    /*Puzzle Layout*/
    int playerX,playerY,size,totalCost,moveNumber; /*Puzzle Properties*/
    int* goal_map;  /*Target Puzzle*/
    int prevMove;   /*To keep prev enum direction */
};

/*Function that I use during the program */
void playerGuide(void);
struct Puzzle* getInitialPuzzle(void);
int getPuzzleSize(void);
int getRandomNumber(int);
void createInitialPuzzle(int*,int*,int,int*,int*,int*);
void printPuzzle(int*,int);
void game(void);
void gameGetInput(int*,int,int*,int*,int*,bool*,int*,int*,int*);
bool isEndPuzzle(int*,int,int*);
bool shufflePuzzle(int*,int*,int);
bool releasePuzzle(struct Puzzle*);
void getRandomDirectionAndMove(int*,int);
bool getPlayerPos(int*,int,int*,int*);
bool isSolvablePuzzle(int*,int );
int getInversionCount(int*,int);
void swap(int*,int,int);
void IntelligentMove(int*,int*,int,int*,int*,int*,int*,int*);
bool isSave(int,int,int);
struct Puzzle createScenerioPuzzle(int*,int,int,int,int,int*);
int* createGoalPuzzle(int);
int getCost(int*,int*,int);

/* Movement Function */
bool moveRight(int*,int,bool,bool,int*);
bool moveLeft(int*,int,bool,bool,int*);
bool moveUp(int*,int,bool,bool,int*);
bool moveDown(int*,int,bool,bool,int*);
/*______________________End_Function_Decleration_______________*/
int main(void)
{
    srand(time(NULL));  /* From ctime header to get random number */
    game();             /* All Game Design in it */
    return 0;
}

void game(void)
{
    bool quit = false;
    playerGuide();
    struct Puzzle* initialPuzzle=getInitialPuzzle();

    std::cout<<"Your initial random board is:\n\n";
    /* Main Game Loop */
    while(!quit)
    {
        printPuzzle(initialPuzzle->puzzle_map,initialPuzzle->size);
        getPlayerPos(initialPuzzle->puzzle_map,initialPuzzle->size,&initialPuzzle->playerX,&initialPuzzle->playerY);
        gameGetInput(initialPuzzle->puzzle_map,initialPuzzle->size,&initialPuzzle->playerX,&initialPuzzle->playerY,
        &initialPuzzle->totalCost,&quit,&initialPuzzle->moveNumber,initialPuzzle->goal_map,&initialPuzzle->prevMove);
        if(isEndPuzzle(initialPuzzle->puzzle_map,initialPuzzle->size,initialPuzzle->goal_map)){
            std::cout<<"Problem Solved!\n"
                <<"Total number of moves "<<initialPuzzle->moveNumber<<std::endl;
                quit=true;
        } 
    }
    /*__End_Main_Game_Loop____*/
    releasePuzzle(initialPuzzle);
    /*to make free all allocated files during my program */
}

/* gameGetInput Purpose */
/* Taking  the input from the input stream via player*/
/* Send this char value into switch-case statement to consider for each of them seperately */
void gameGetInput(int* puzzle_map,int size,int* playerX,int* playerY,int* totalCost,bool* quit,int* moveNumber,int* goal_map,int* prevMove)
{
    /*There is no buttom to press '\0' that I know :) */
    char currentKey='\0';
    std::cout<<"Your Move:";
    //std::cin>>currentKey;
    currentKey='i';
    switch(currentKey)
    {
        /* To Move Right */
        case 'r':
        case 'R':
            moveRight(puzzle_map,size,false,false,moveNumber);
        break;

        /* To Move Left */
        case 'l':
        case 'L':
            moveLeft(puzzle_map,size,false,false,moveNumber);
            break;

        /* To Move Up */
        case 'u':
        case 'U':
            moveUp(puzzle_map,size,false,false,moveNumber);
            break;

        /* To Move Down */
        case 'd':
        case 'D':
            moveDown(puzzle_map,size,false,false,moveNumber);
            break;

        /* To Move Intelligent Move */
        case 'i':
        case 'I': 
            IntelligentMove(puzzle_map,goal_map,size,playerX,playerY,totalCost,moveNumber,prevMove);
            break;

        /* To Shuffle the Current Target Puzzle */
        case 's':
        case 'S':
            shufflePuzzle(puzzle_map,goal_map,size);
            break;

        /* To Quit Game */
        case 'q':
        case 'Q':
            *quit=true;
            break;
        
        default:
            std::cout<<"Invalid Input!\n";
        break;
    }
}
/* createInitialPuzzle Purpose: */
/* To fill my initial puzzle property but it is valid for just initial puzzle */
/* And Also I used my own Algorithm for creating puzzle */
/* My algorithm is so useful to create a puzzle which contains pseudo number , */
/* But Puzzle that I created thanks to algorithm contains no number that is used  more than  times */

/*Explaining of Creating Pseudo Number Filled Puzzle________________________________________________________*/
/*__________________________________________________________________________________________________________*/
/*Lets  assume that I need to create a new puzzle which should contain numbers between 1-9 _________________*/
/*__________________________________________________________________________________________________________*/
/*Firstly I put my all those number in a simple int array in ordered________________________________________*/
/*__________________________________________________________________________________________________________*/
/*__arr ->  1 2 3 4 5 6 7 8 9_______________________________________________________________________________*/
/*__________________________________________________________________________________________________________*/
/*__arr ->  0 1 2 3 4 5 6 7 8____These are my indexs________________________________________________________*/
/*__________________________________________________________________________________________________________*/
/*Step 1: Take random index number . Ex* 3__________________________________________________________________*/
/*__________________________________________________________________________________________________________*/
/*Swap with this value of index with beginning index value using swap operation_____________________________*/
/*__________________________________________________________________________________________________________*/
/*_new_arr ->  4 2 3 1 5 6 7 8 9____________________________________________________________________________*/
/*__________________________________________________________________________________________________________*/
/*Step 2: Increment beginning swap index , for example , if it is 0 it would be 1 , if it is 1,it would be 2*/
/*__________________________________________________________________________________________________________*/
/*Step 3:Increment the index of loop that You use___________________________________________________________*/
void createInitialPuzzle(int* puzzle_map,int* goal_map,int size,int* playerX,int* playerY,int* totalCost){
    int initial_index=0,pseudoIndex,divisionTool=0;

    for(int i=0;i<size*size;++i)
        puzzle_map[i]=i+1;

    /* Creating Random Numeber */
    while(initial_index!=size*size-1){
        pseudoIndex=((rand()%(size*size-initial_index))+initial_index);
        swap(puzzle_map,pseudoIndex,initial_index);
        ++initial_index;
    }
    /* Check whether it is solvable or not */
    while(!isSolvablePuzzle(puzzle_map,size)||isEndPuzzle(puzzle_map,size,goal_map))
        createInitialPuzzle(puzzle_map,goal_map,size,playerX,playerY,totalCost);

    /* Taking Player Position */
    getPlayerPos(puzzle_map,size,playerX,playerY);
    *totalCost=0;
}
/* Printing Current Puzzle */
void printPuzzle(int* puzzle_map,int size){
    for(int j=0;j<size;++j){
        for(int i=0;i<size;++i){
            if(puzzle_map[size*j+i]== size*size)   std::cout<<"\t";
            else    std::cout<<"\t"<<puzzle_map[size*j+i];
        }
        std::cout<<std::endl<<std::endl;
    }
}
/* Get Pseudo Number randomly */
int getRandomNumber(int size){
    return ((rand()%(size*size-1))+1);
}
/* Get Size of the number from player */
int getPuzzleSize(void){
    int puzzleSize = -1;
    while(puzzleSize<3|puzzleSize>9){
        std::cout<<"Please enter problem size: ";
        std::cin>>puzzleSize;
        std::cout<<std::endl;
    }
    return puzzleSize;
}
/* Move Right If it is not on the border side */
bool moveRight(int* puzzle_map,int size,bool shuffleFlag,bool intelligentFlag,int* moveNumber){
    int playerX=0,playerY=0;
    if(getPlayerPos(puzzle_map,size,&playerX,&playerY)){
        if(playerX+1<size){
            puzzle_map[playerY*size+playerX]=puzzle_map[playerY*size+playerX+1];
            puzzle_map[playerY*size+playerX+1]=size*size;
            if(shuffleFlag==false){
                ++(*moveNumber);
                if(intelligentFlag)
                    std::cout<<"Intelligent move chooses R\n\n";
            }
            return true;
        }
    }
    if(shuffleFlag==false)
    std::cout<<"Invalid move!\n\n";
    return false;
    /* Output Stream is going to change according to bool flags that I use as parameters */
}
/* Move Left If it is not on the border side */
bool moveLeft(int* puzzle_map,int size,bool shuffleFlag,bool intelligentFlag,int* moveNumber){
    int playerX=0,playerY=0;
    if(getPlayerPos(puzzle_map,size,&playerX,&playerY))
    {
        if(playerX-1>=0)
        {
            puzzle_map[playerY*size+playerX]=puzzle_map[playerY*size+playerX-1];
            puzzle_map[playerY*size+playerX-1]=size*size;
            if(shuffleFlag==false)
            {
                ++(*moveNumber);
                if(intelligentFlag)
                    std::cout<<"Intelligent move chooses L\n\n";
            }
            return true;
        }
    }
    if(shuffleFlag==false)
    std::cout<<"Invalid move!\n\n";
    return false;
    /* Output Stream is going to change according to bool flags that I use as parameters */
}
/* Move Up If it is not on the border side */
bool moveUp(int* puzzle_map,int size,bool shuffleFlag,bool intelligentFlag,int* moveNumber){
    int playerX=0,playerY=0;
    if(getPlayerPos(puzzle_map,size,&playerX,&playerY))
    {
        if(playerY-1>=0)
        {
            puzzle_map[playerY*size+playerX]=puzzle_map[(playerY-1)*size+playerX];
            puzzle_map[(playerY-1)*size+playerX]=size*size;
            if(shuffleFlag==false)
            {
                ++(*moveNumber);
                if(intelligentFlag)
                    std::cout<<"Intelligent move chooses U\n\n";
            }
            return true;
        }
    }
    if(shuffleFlag==false)
    std::cout<<"Invalid move!\n\n";
    return false;
    /* Output Stream is going to change according to bool flags that I use as parameters */
}
/* Move Down If it is not on the border side */
bool moveDown(int* puzzle_map,int size,bool shuffleFlag,bool intelligentFlag,int* moveNumber){
    int playerX=0,playerY=0;
    if(getPlayerPos(puzzle_map,size,&playerX,&playerY))
    {
        if(playerY+1<size)
        {
            puzzle_map[playerY*size+playerX]=puzzle_map[(playerY+1)*size+playerX];
            puzzle_map[(playerY+1)*size+playerX]=size*size;
            if(shuffleFlag==false)
            {
                ++(*moveNumber);
                if(intelligentFlag)
                std::cout<<"Intelligent move chooses D\n\n";
            }
            return true;
        }
    }
    if(shuffleFlag==false)
    std::cout<<"Invalid move!\n\n";
    return false;
     /* Output Stream is going to change according to bool flags that I use as parameters */
}
/* Getting User Position by getting over the puzzle_map */
bool getPlayerPos(int* puzzle_map,int size,int* playerX,int* playerY){
    for(int i=0;i<size*size;++i){ 
        if(puzzle_map[i]==size*size){
            *playerX=i%size;
            *playerY=i/size;
            return true;
        }
    }
    return false;
}
/*Check Puzzle Whether It is goal puzzle or not by getting over the puzzle_map */
bool isEndPuzzle(int* puzzle_map,int size,int* goal_map){
    for(int j=0;j<size;++j){
        for(int i=0;i<size;++i){
            if(puzzle_map[j*size+i]!=goal_map[j*size+i])
                return false;
        }
    }
    return true;
}
/* Releasing Puzzle Tools */
bool releasePuzzle(struct Puzzle* currentPuzzle){
    if(currentPuzzle)
    {
        free(currentPuzzle->puzzle_map);
        free(currentPuzzle);
        currentPuzzle=NULL;
        return true;
    }
    return false;
}
/* Shuffling the puzzle */
bool shufflePuzzle(int* puzzle_map,int* goal_map,int size){
    int counter=0,sizeCheck=0; /* to fill the puzzle with int number in order */
    for(int j=0;j<size;++j){
        for(int i=0;i<size;++i){
            puzzle_map[j*size+i]=counter+1;
            ++counter;
        }
    }
    while(++sizeCheck<=size*size)
        getRandomDirectionAndMove(puzzle_map,size);
    if(isEndPuzzle(puzzle_map,size,goal_map)){
        shufflePuzzle(puzzle_map,goal_map,size);
    }
    else
        std::cout<<"Shuffed Successfully !\n";
    return true;
}
/* Getting Random Direction And Moving */
void getRandomDirectionAndMove(int* puzzle_map,int size)
{
    int direction=rand()%4;
    if(direction==right){
        if(moveRight(puzzle_map,size,true,false,NULL));
        else
            getRandomDirectionAndMove(puzzle_map,size);
    }
    else if(direction==left){
        if(moveLeft(puzzle_map,size,true,false,NULL));
        else
            getRandomDirectionAndMove(puzzle_map,size);
    }
    else if(direction==up){
        if(moveUp(puzzle_map,size,true,false,NULL));
        else
            getRandomDirectionAndMove(puzzle_map,size);
    }
    else if(direction==down){
        if(moveDown(puzzle_map,size,true,false,NULL));
        else
            getRandomDirectionAndMove(puzzle_map,size);
    }
}
/* Determining Whether Puzzle is solvable or not */
bool isSolvablePuzzle(int* puzzle_map,int size){
    int playerX=0,playerY=0,inversionNumber=getInversionCount(puzzle_map,size);
    if((size*size)%2&&!(inversionNumber%2))
        return true;
    else if(!((size*size)%2)){
        getPlayerPos(puzzle_map,size,&playerX,&playerY);
        if((!((size*size)-playerY)%2)&&inversionNumber%2)
            return true;
        else if((((size*size)-playerY)%2)&&!(inversionNumber%2))
            return true;
    }
    return false;
}
int getInversionCount(int* puzzle_map,int size){
    int inversionCounter=0;
    for(int i=0;i<size*size-1;++i){
        for(int j=i+1;j<size*size;++j){
            if(puzzle_map[i]!=(size*size)&&puzzle_map[j]!=(size*size)&&(puzzle_map[i]>puzzle_map[j]))
                ++inversionCounter;
        }
    }
    return inversionCounter;
}
/* Getting Initial Puzzle  */
struct Puzzle* getInitialPuzzle(void){
    struct Puzzle* initialPuzzle = (struct Puzzle*)malloc(sizeof(struct Puzzle)*1);
    initialPuzzle->size=getPuzzleSize();
    initialPuzzle->puzzle_map = (int*)malloc(sizeof(int)*initialPuzzle->size*initialPuzzle->size);

    initialPuzzle->goal_map=createGoalPuzzle(initialPuzzle->size);
    initialPuzzle->prevMove=-1;

    createInitialPuzzle(initialPuzzle->puzzle_map,initialPuzzle->goal_map,initialPuzzle->size,&initialPuzzle->playerX,&initialPuzzle->playerY
    ,&initialPuzzle->totalCost);

    return initialPuzzle;
}
/* Swap */
void swap(int* puzzle,int initial_index,int goal_index){
    int temp=puzzle[initial_index];
    puzzle[initial_index]=puzzle[goal_index];
    puzzle[goal_index]=temp;
}
/* IntelligentMove Function Purpose______________________________________________________________________*/
/* First of all , I used some tools and parameter from A* Path Finding Algorithm like Manhattan Distance_*/
/* Working Princible ____________________________________________________________________________________*/
/* Calculate Manhattan Distance of all values and sum up all of them , regard this sum , which is totalCost value embedded in struct , to move forward as intelligent */
/* For not to go back previous position , I used prevMove varible________________________________________*/
/* And I also did a bunch of other thing_________________________________________________________________*/
void IntelligentMove(int* puzzle_map,int* goalMap,int size,int* playerX,int* playerY,int* totalCost,int* moveNumber,int* prevMove){
    /*Initialization of some kind of values about getting random move , assigning -1 , to make my decision more advanced */
    int minNum=-1,minIndex=-1,luck=-1,i=0;
    struct Puzzle directionPuzzle[4];

    for(i=0;i<4;++i){
        directionPuzzle[i].totalCost=-1;
        directionPuzzle[i].puzzle_map=NULL;
        directionPuzzle[i].goal_map=NULL;
    }
    printPuzzle(puzzle_map,size);

    if(isSave(*playerX+1,*playerY,size)){
        directionPuzzle[right]=createScenerioPuzzle(puzzle_map,size,*playerX,*playerY,right,moveNumber);
        directionPuzzle[right].totalCost=getCost(directionPuzzle[right].puzzle_map,goalMap,size);
    }
    if(isSave(*playerX-1,*playerY,size)){
        directionPuzzle[left]=createScenerioPuzzle(puzzle_map,size,*playerX,*playerY,left,moveNumber);
        directionPuzzle[left].totalCost=getCost(directionPuzzle[left].puzzle_map,goalMap,size);
    }
    if(isSave(*playerX,*playerY-1,size)){
        directionPuzzle[up]=createScenerioPuzzle(puzzle_map,size,*playerX,*playerY,up,moveNumber);
        directionPuzzle[up].totalCost=getCost(directionPuzzle[up].puzzle_map,goalMap,size);
    }
    if(isSave(*playerX,*playerY+1,size)){
        directionPuzzle[down]=createScenerioPuzzle(puzzle_map,size,*playerX,*playerY,down,moveNumber);
        directionPuzzle[down].totalCost=getCost(directionPuzzle[down].puzzle_map,goalMap,size);
    }

    for(i=0;i<4;++i){
        if(directionPuzzle[i].totalCost!=-1 && i!=*prevMove){
            if(minNum==-1){
                minNum=directionPuzzle[i].totalCost;
                minIndex=i;
            }
            else if(directionPuzzle[i].totalCost<minNum)
                minIndex=i;
            else if(directionPuzzle[i].totalCost==minNum){
                luck=rand()%2;
                if(luck==0) 
                minIndex=i;
            }
        }
    }

    if(minIndex==left) *prevMove=right;
    else if(minIndex==right) *prevMove=left;
    else if(minIndex==up) *prevMove=down;
    else if(minIndex==down) *prevMove=up;
        
    if(minIndex==right)          moveRight(puzzle_map,size,false,true,moveNumber);
    else if (minIndex==left)     moveLeft(puzzle_map,size,false,true,moveNumber);
    else if (minIndex==up)       moveUp(puzzle_map,size,false,true,moveNumber);
    else if (minIndex==down)     moveDown(puzzle_map,size,false,true,moveNumber);

    for(i=0;i<4;++i)
        free(directionPuzzle[i].puzzle_map); 
}
struct Puzzle createScenerioPuzzle(int* puzzle_map,int size,int playerX,int playerY,int index,int* moveNumber)
{
    struct Puzzle direction;
    direction.size=size;
    direction.puzzle_map = (int*)malloc(sizeof(int)*direction.size*direction.size);

    for(int j=0;j<size;++j){
        for(int i=0;i<size;++i)
            direction.puzzle_map[j*size+i]=puzzle_map[j*size+i];
    }
    if(index==right)
        moveRight(direction.puzzle_map,direction.size,true,true,moveNumber);
    else if(index==left)
        moveLeft(direction.puzzle_map,direction.size,true,true,moveNumber);
    else if(index==up)
        moveUp(direction.puzzle_map,direction.size,true,true,moveNumber);
    else if(index==down)
        moveDown(direction.puzzle_map,direction.size,true,true,moveNumber);
    return direction;
}
/* Calculating Manhattan Distance */
/* Manhattan Distance : It is a kind of Heuristic Fucntion that has been using many path finding and puzzle solving algorthm */
int getCost(int* puzzle_map,int* goal_map,int size) {
    int x0,y0,x1,y1,dx,dy,sum = 0;
    for(y0 = 0; y0 < size; ++y0) {
        for(x0 = 0; x0 < size; ++x0) {
            for(y1 = 0; y1 < size; ++y1) {
                for(x1 = 0; x1 < size; ++x1) {
                    if(puzzle_map[y0*size+x0] == goal_map[y1*size+x1]) {
                        dx = (x0 - x1 < 0)? x1 - x0 : x0 - x1;
                        dy = (y0 - y1 < 0)? y1 - y0 : y0 - y1;
                        sum += dx + dy;
                    }
                }
            }
        }
    }
    return sum;
}
/* Consider Move whether Movement is save or not */
bool isSave(int x,int y,int size){
    if(x>=0&&x<size&&y>=0&&y<size)
        return true;
    else
        return false;
}
/* Creating Target Puzzle */
int* createGoalPuzzle(int size){
    int* goalPuzzle=(int*)malloc(sizeof(int)*size*size);

    for(int i=0;i<size*size;++i)
        goalPuzzle[i]=i+1;
    return goalPuzzle;
}
void playerGuide(void){
    std::cout<<"\t\t->> Welcome to the N-Puzzle Solver Game <<-\n";
    std::cout<<"\t\t___________________________________________\n\n";
    std::cout<<"--> Game Purpose: Solving N-Puzzle by moving over it.\n\n";
    std::cout<<"Input Guide : \n";
    std::cout<<"_____________\n\n";
    std::cout<<"--> Press (U) to move UP\n";
    std::cout<<"--> Press (R) to move RIGHT\n";
    std::cout<<"--> Press (L) to move LEFT\n";
    std::cout<<"--> Press (D) to move DOWN\n";
    std::cout<<"--> Press (S) to Shuffle the Current Puzzle\n";
    std::cout<<"--> Press (Q) to Quit Puzzle Game\n";
    std::cout<<"_______________________________________________________Good Luck :)\n\n";
}