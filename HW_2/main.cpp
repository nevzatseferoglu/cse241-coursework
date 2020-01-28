/*______________________________________________________________________ */
/*Object-Oriented-Programming with C++ Language HW-2____________________ */
/*Student Name: NEVZAT SEFEROGLU________________________________________ */
/*Student Number: 171044024______________________________________________*/
/*Problem : N-Puzzle Game Implementation(Extended Version)__in_C++______ */
/*______________________________________________________________________ */
#include <iostream> /*_Standart input Output Stream Header_*/
#include <string>   /*To use string class */
#include <fstream>  /*File Handling */
#include <cstdlib>  /*For getting pseudo number , i had to use that header*/
#include <ctime>    /*to use rand() function */

enum Direction{right,left,up,down};

struct Puzzle{
    int* puzzle_map;    /*Puzzle Layout*/
    int xSize,ySize;    /*Puzzle Properties*/
    int playerX,playerY,totalCost,moveNumber;   
    int* goal_map;  /*Target Puzzle*/
    int prevMove; /*To keep prev enum direction */
};


/* Entire Function in Program */
void game(int,char**);
void gameGetInput(struct Puzzle&,bool*);
void printPuzzle(const struct Puzzle&);
int getRandomNumber(const int);
int getPuzzleSize(void);
bool moveRight(struct Puzzle&,bool,bool,bool);
bool moveLeft(struct Puzzle&,bool,bool,bool);
bool moveUp(struct Puzzle&,bool,bool,bool);
bool moveDown(struct Puzzle&,bool,bool,bool);
bool getPlayerPos(struct Puzzle&);
bool isEndPuzzle(const struct Puzzle&);
bool releasePuzzle(struct Puzzle&);
bool shufflePuzzle(struct Puzzle&);
void getRandomDirectionAndMove(struct Puzzle&);
void swap(int*,int,int);
void IntelligentMove(struct Puzzle&);
struct Puzzle createScenerioPuzzle(const struct Puzzle&,int);
bool isStuck(struct Puzzle&);
int getCost(const struct Puzzle&,struct Puzzle);
int* createGoalPuzzle(struct Puzzle&);
void getInitialPuzzle(struct Puzzle&);
bool isSolvablePuzzle(struct Puzzle&);
int getInversionCount(const struct Puzzle&);
void createInitialPuzzle(struct Puzzle&);
void readFile(std::string,struct Puzzle&);
int getExponential(int,int);
int charToint(char);
void playerGuide(void);
std::string getFilename(void);
bool loadPuzzleFromFile(struct Puzzle&);
bool savePuzzleToFile(struct Puzzle&);
int getDigit(int);
void printReport(const struct Puzzle&);
void goSolution(struct Puzzle&,bool*);


int main(int argc, char *argv[])
{
    srand(time(NULL));  /* From ctime header to get random number */
    game(argc,argv);    /* All Game Design in it */
    return 0;

    /* I send argument count and argument vector for getting input from command line */
}

void game(int argc,char** argv)
{
    bool quit = false;
    struct Puzzle curPuzzle;
    
    /* Player  */
    playerGuide();
    switch(argc)
    {
        case 1:
            getInitialPuzzle(curPuzzle);
        break;

        case 2:
            readFile(argv[argc-1],curPuzzle);
        break;

        default:
            std::cerr<<"Critical Argument Error !\n";
            exit(1);
        break;
    }
    /* Argument Handling */

    std::cout<<"Your initial random board is:\n\n";
    /* Main Game Loop */
    while(!quit)
    {
        printPuzzle(curPuzzle);
        gameGetInput(curPuzzle,&quit);
        if(isEndPuzzle(curPuzzle)&&!quit)
        {
            printPuzzle(curPuzzle);
            std::cout<<"Problem Solved!\n"
                <<"Total number of moves "<<curPuzzle.moveNumber<<std::endl;
                quit=true;
        }
    /*__End_Main_Game_Loop____*/
    }
    releasePuzzle(curPuzzle);
    /*to make free all allocated files during my program */
}

/* gameGetInput Purpose */
/* Taking  the input from the input stream via player*/
/* Send this char value into switch-case statement to consider for each of them seperately */
void gameGetInput(struct Puzzle& curPuzzle,bool* quit)
{
    /*There is no buttom to press '\0' that I know :) */
    auto currentKey='\0';
    std::cout<<"Your Move:";
    std::cin>>currentKey;

    switch(currentKey)
    {
        /* To Move Right */
        case 'r':
        case 'R':
            moveRight(curPuzzle,false,false,false);
        break;

        /* To Move Left */
        case 'l':
        case 'L':
            moveLeft(curPuzzle,false,false,false);
            break;

        /* To Move Up */
        case 'u':
        case 'U':
            moveUp(curPuzzle,false,false,false);
            break;

        /* To Move Down */
        case 'd':
        case 'D':
            moveDown(curPuzzle,false,false,false);
            break;

        /* To Move Intelligent Move */
        case 'i':
        case 'I': 
            IntelligentMove(curPuzzle);
            break;

        /* To Shuffle the Current Target Puzzle */
        case 's':
        case 'S':
            shufflePuzzle(curPuzzle);
            break;
        
        /* to go to solution with using intelligent algorithm */
        case 'v':
        case 'V':
            goSolution(curPuzzle,quit);
            break;
        
        /* Print the report about current situation */
        case 't':
        case 'T':
            printReport(curPuzzle);
            break;
        
        /* To save the puzzle configariton to file */
        case 'e':
        case 'E':
            savePuzzleToFile(curPuzzle);
            break;

        /* To load the puzzle configuration from the file */
        case 'y':
        case 'Y':
            loadPuzzleFromFile(curPuzzle);
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
void printPuzzle(const struct Puzzle& curPuzzle){
    for(int j=0;j<curPuzzle.ySize;++j)
    {
        for(int i=0;i<curPuzzle.xSize;++i)
        {
            if(curPuzzle.puzzle_map[curPuzzle.xSize*j+i]==-1) std::cout<<"\t";
            else if(curPuzzle.puzzle_map[curPuzzle.xSize*j+i]==0) std::cout<<"\tX";
            else    std::cout<<"\t"<<curPuzzle.puzzle_map[curPuzzle.xSize*j+i];
        }
        std::cout<<std::endl<<std::endl;
    }
}
int getRandomNumber(const int xSize){
    return ((rand()%(xSize*xSize-1))+1);
}
/* Get Size of the number from player */
int getPuzzleSize(void){
    int puzzleSize = -1;
    while(puzzleSize<3|puzzleSize>9){
        std::cout<<"\nPlease enter problem size: ";
        std::cin>>puzzleSize;
        std::cout<<std::endl;
    }
    return puzzleSize;
}
/* Move Right If it is not on the border side */
bool moveRight(struct Puzzle& curPuzzle,bool shuffleFlag,bool intelligentFlag,bool checkState){
    
    getPlayerPos(curPuzzle);
    if((curPuzzle.playerX+1)<curPuzzle.xSize&&curPuzzle.puzzle_map[curPuzzle.playerY*curPuzzle.xSize+curPuzzle.playerX+1]!=0)
    {
        if(!checkState)
        {
            curPuzzle.puzzle_map[curPuzzle.playerY*curPuzzle.xSize+curPuzzle.playerX]=curPuzzle.puzzle_map[curPuzzle.playerY*curPuzzle.xSize+curPuzzle.playerX+1];
            curPuzzle.puzzle_map[curPuzzle.playerY*curPuzzle.xSize+curPuzzle.playerX+1]=-1;
            if(shuffleFlag==false)
            {
                ++(curPuzzle.moveNumber);
                if(intelligentFlag)
                    std::cout<<"Intelligent move chooses R\n\n";
            }
        }
        return true;
    }

    if(shuffleFlag==false&&!checkState)
        std::cout<<"Invalid move!\n\n";
    return false;
}
/* Move Left If it is not on the border side */
bool moveLeft(struct Puzzle& curPuzzle,bool shuffleFlag,bool intelligentFlag,bool checkState){
    
    getPlayerPos(curPuzzle);
    if((curPuzzle.playerX-1)>=0&&curPuzzle.puzzle_map[curPuzzle.playerY*curPuzzle.xSize+curPuzzle.playerX-1]!=0)
    {
        if(!checkState)
        {
            curPuzzle.puzzle_map[curPuzzle.playerY*curPuzzle.xSize+curPuzzle.playerX]=curPuzzle.puzzle_map[curPuzzle.playerY*curPuzzle.xSize+curPuzzle.playerX-1];
            curPuzzle.puzzle_map[curPuzzle.playerY*curPuzzle.xSize+curPuzzle.playerX-1]=-1;
            if(shuffleFlag==false)
            {
                ++(curPuzzle.moveNumber);
                if(intelligentFlag)
                    std::cout<<"Intelligent move chooses L\n\n";
            }
        }
        return true;
    }

    if(shuffleFlag==false&&!checkState)
        std::cout<<"Invalid move!\n\n";
    return false;
}
/* Move Up If it is not on the border side */
bool moveUp(struct Puzzle& curPuzzle,bool shuffleFlag,bool intelligentFlag,bool checkState){

    getPlayerPos(curPuzzle);
    if((curPuzzle.playerY-1)>=0&&curPuzzle.puzzle_map[(curPuzzle.playerY-1)*curPuzzle.xSize+curPuzzle.playerX]!=0)
    {
        if(!checkState)
        {
            curPuzzle.puzzle_map[curPuzzle.playerY*curPuzzle.xSize+curPuzzle.playerX]=curPuzzle.puzzle_map[(curPuzzle.playerY-1)*curPuzzle.xSize+curPuzzle.playerX];
            curPuzzle.puzzle_map[(curPuzzle.playerY-1)*curPuzzle.xSize+curPuzzle.playerX]=-1;
            if(shuffleFlag==false)
            {
                ++(curPuzzle.moveNumber);
                if(intelligentFlag)
                    std::cout<<"Intelligent move chooses U\n\n";
            }
        }
        return true;
    }

    if(shuffleFlag==false&&!checkState)
    std::cout<<"Invalid move!\n\n";
    return false;
}
/* Move Down If it is not on the border side */
bool moveDown(struct Puzzle& curPuzzle,bool shuffleFlag,bool intelligentFlag,bool checkState){
    
    getPlayerPos(curPuzzle);
    if((curPuzzle.playerY+1)<curPuzzle.ySize&&curPuzzle.puzzle_map[(curPuzzle.playerY+1)*curPuzzle.xSize+curPuzzle.playerX]!=0)
    {
        if(!checkState)
        {
            curPuzzle.puzzle_map[curPuzzle.playerY*curPuzzle.xSize+curPuzzle.playerX]=curPuzzle.puzzle_map[(curPuzzle.playerY+1)*curPuzzle.xSize+curPuzzle.playerX];
            curPuzzle.puzzle_map[(curPuzzle.playerY+1)*curPuzzle.xSize+curPuzzle.playerX]=-1;
            if(shuffleFlag==false)
            {
                ++(curPuzzle.moveNumber);
                if(intelligentFlag)
                std::cout<<"Intelligent move chooses D\n\n";
            }
        }
        return true;
    }

    if(shuffleFlag==false&&!checkState)
        std::cout<<"Invalid move!\n\n";
    return false;
}
/* Getting User Position by getting over the puzzle_map */
bool getPlayerPos(struct Puzzle& curPuzzle){
    for(int i=0;i<curPuzzle.xSize*curPuzzle.ySize;++i){ 
        if(curPuzzle.puzzle_map[i]==-1){
            curPuzzle.playerX=i%curPuzzle.xSize;
            curPuzzle.playerY=i/curPuzzle.xSize;
            return true;
        }
    }
    return false;
}
/*Check Puzzle Whether It is goal puzzle or not by getting over the puzzle_map */
bool isEndPuzzle(const struct Puzzle& curPuzzle){
    for(int j=0;j<curPuzzle.ySize;++j){
        for(int i=0;i<curPuzzle.xSize;++i){
            if(curPuzzle.puzzle_map[j*curPuzzle.xSize+i]!=curPuzzle.goal_map[j*curPuzzle.xSize+i])
                return false;
        }
    }
    return true;
}
/* Releasing Puzzle Tools */
bool releasePuzzle(struct Puzzle& curPuzzle){
    free(curPuzzle.puzzle_map);
        curPuzzle.puzzle_map=NULL;
    free(curPuzzle.goal_map);
        curPuzzle.goal_map=NULL;
    return true;
}
/* Shuffling the puzzle */
bool shufflePuzzle(struct Puzzle& curPuzzle){
    int counter=0,sizeCheck=0;

    curPuzzle.moveNumber=0;

    for(int j=0;j<curPuzzle.ySize;++j){
        for(int i=0;i<curPuzzle.xSize;++i){
            if(curPuzzle.puzzle_map[j*curPuzzle.xSize+i]!=-1&curPuzzle.puzzle_map[j*curPuzzle.xSize+i]!=0){
                curPuzzle.puzzle_map[j*curPuzzle.xSize+i]=counter+1;
                ++counter;
            }
        }
    }

    while(++sizeCheck<=curPuzzle.xSize*curPuzzle.ySize)
        getRandomDirectionAndMove(curPuzzle);

    if(isEndPuzzle(curPuzzle)){
        shufflePuzzle(curPuzzle);
    }
    else
        std::cout<<"Shuffed Successfully !\n";
    return true;
}
/* Getting Random Direction And Moving */
void getRandomDirectionAndMove(struct Puzzle& curPuzzle)
{
    int direction=rand()%4;
    if(direction==right)
    {
        if(moveRight(curPuzzle,true,false,true))
            moveRight(curPuzzle,true,false,false);
        else
            getRandomDirectionAndMove(curPuzzle);
    }
    else if(direction==left)
    {
        if(moveLeft(curPuzzle,true,false,true))
            moveLeft(curPuzzle,true,false,false);
        else
            getRandomDirectionAndMove(curPuzzle);
    }
    else if(direction==up)
    {
        if(moveUp(curPuzzle,true,false,true))
            moveUp(curPuzzle,true,false,false);
        else
            getRandomDirectionAndMove(curPuzzle);
    }
    else if(direction==down)
    {
        if(moveDown(curPuzzle,true,false,true))
            moveDown(curPuzzle,true,false,false);
        else
            getRandomDirectionAndMove(curPuzzle);
    }
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
/* Extention = I also used border check for not stucking player while intelligent move */
void IntelligentMove(struct Puzzle& curPuzzle){
    int minNum=-1,minIndex=-1,luck=-1,i=0;
    struct Puzzle directionPuzzle[4];

    for(i=0;i<4;++i){
        directionPuzzle[i].prevMove=-1;
        directionPuzzle[i].totalCost=-1;
        directionPuzzle[i].puzzle_map=NULL;
        directionPuzzle[i].goal_map=NULL;
    }

    if(moveRight(curPuzzle,false,true,true)){
        directionPuzzle[right]=createScenerioPuzzle(curPuzzle,right);
        directionPuzzle[right].totalCost=getCost(directionPuzzle[right],curPuzzle);
    }
    if(moveLeft(curPuzzle,false,true,true)){
        directionPuzzle[left]=createScenerioPuzzle(curPuzzle,left);
        directionPuzzle[left].totalCost=getCost(directionPuzzle[left],curPuzzle);
    }
    if(moveUp(curPuzzle,false,true,true)){
        directionPuzzle[up]=createScenerioPuzzle(curPuzzle,up);
        directionPuzzle[up].totalCost=getCost(directionPuzzle[up],curPuzzle);
    }
    if(moveDown(curPuzzle,true,true,true)){
        directionPuzzle[down]=createScenerioPuzzle(curPuzzle,down);
        directionPuzzle[down].totalCost=getCost(directionPuzzle[down],curPuzzle);
    }
    
    if(isStuck(curPuzzle))
    {
        if(curPuzzle.prevMove==up) curPuzzle.prevMove=down;
        else if(curPuzzle.prevMove==right) curPuzzle.prevMove=left;
        else if(curPuzzle.prevMove==left) curPuzzle.prevMove=right;
        else if(curPuzzle.prevMove==down) curPuzzle.prevMove=up;
    }
    
    for(i=0;i<4;++i){
        if(directionPuzzle[i].totalCost!=-1 && i!=curPuzzle.prevMove){
            if(minNum==-1){
                minNum=directionPuzzle[i].totalCost;
                minIndex=i;
            }
            else if(directionPuzzle[i].totalCost<minNum)
            {
                minNum=directionPuzzle[i].totalCost;
                minIndex=i;
            }
            else if(directionPuzzle[i].totalCost==minNum){
                luck=rand()%2;
                if(luck==0) 
                minIndex=i;
            }
        }
    }

    if(minIndex==up) curPuzzle.prevMove=down;
    else if(minIndex==right) curPuzzle.prevMove=left;
    else if(minIndex==left) curPuzzle.prevMove=right;
    else if(minIndex==down) curPuzzle.prevMove=up;

    if(minIndex==right)         moveRight(curPuzzle,false,true,false);
    else if (minIndex==left)    moveLeft(curPuzzle,false,true,false);
    else if (minIndex==up)      moveUp(curPuzzle,false,true,false);
    else if (minIndex==down)    moveDown(curPuzzle,false,true,false);

    for(i=0;i<4;++i)
        free(directionPuzzle[i].puzzle_map); 
}
struct Puzzle createScenerioPuzzle(const struct Puzzle& curPuzzle,int index)
{
    struct Puzzle direction;
    direction.xSize=curPuzzle.xSize;
    direction.ySize=curPuzzle.ySize;
    direction.puzzle_map = (int*)malloc(sizeof(int)*direction.xSize*direction.ySize);

    for(int j=0;j<curPuzzle.ySize;++j){
        for(int i=0;i<curPuzzle.xSize;++i)
            direction.puzzle_map[j*curPuzzle.xSize+i]=curPuzzle.puzzle_map[j*curPuzzle.xSize+i];
    }

    if(index==right)
        moveRight(direction,true,true,false);
    else if(index==left)
        moveLeft(direction,true,true,false);
    else if(index==up)
        moveUp(direction,true,true,false);
    else if(index==down)
        moveDown(direction,true,true,false);

    getPlayerPos(direction);

    return direction;
}
/* Stuck checking fucntion */
bool isStuck(struct Puzzle& curPuzzle)
{
    if(!moveLeft(curPuzzle,false,true,true)&&!moveUp(curPuzzle,false,true,true)&&!moveDown(curPuzzle,false,true,true)&&curPuzzle.prevMove==right)
        return true;
    if(!moveRight(curPuzzle,false,true,true)&&!moveUp(curPuzzle,false,true,true)&&!moveDown(curPuzzle,false,true,true)&&curPuzzle.prevMove==left)
        return true;
    if(!moveLeft(curPuzzle,false,true,true)&&!moveRight(curPuzzle,false,true,true)&&!moveDown(curPuzzle,false,true,true)&&curPuzzle.prevMove==up)
        return true;
    if(!moveLeft(curPuzzle,false,true,true)&&!moveUp(curPuzzle,false,true,true)&&!moveRight(curPuzzle,false,true,true)&&curPuzzle.prevMove==down)
        return true;
    return false;
}
/* Calculating Manhattan Distance */
/* Manhattan Distance : It is a kind of Heuristic Fucntion that has been using many path finding and puzzle solving algorthm */
int getCost(const struct Puzzle& curPuzzle,struct Puzzle toGoal) {
    int x0,y0,x1,y1,dx,dy,sum = 0;
    for(y0 = 0; y0 < curPuzzle.ySize; ++y0){
        for(x0 = 0; x0 < curPuzzle.xSize; ++x0){
            for(y1 = 0; y1 < toGoal.ySize; ++y1){
                for(x1 = 0; x1 < toGoal.xSize; ++x1){
                    if(curPuzzle.puzzle_map[y0*curPuzzle.xSize+x0] == toGoal.goal_map[y1*toGoal.xSize+x1]){
                        if(curPuzzle.puzzle_map[y0*curPuzzle.xSize+x0]!=0&&toGoal.goal_map[y1*toGoal.xSize+x1]!=0){
                            dx = (x0 - x1 < 0)? x1 - x0 : x0 - x1;
                            dy = (y0 - y1 < 0)? y1 - y0 : y0 - y1;
                            sum += dx + dy;
                        }
                    }
                }
            }
        }
    }
    std::cout<<"\n\n";
    return sum;
}
/* Creating Target Puzzle */
int* createGoalPuzzle(struct Puzzle& curPuzzle){
    int counter=1,adress=0; /* initial value of counter */
    int* goalPuzzle=(int*)malloc(sizeof(int)*(curPuzzle.xSize*curPuzzle.ySize));

    for(int j=0;j<curPuzzle.ySize;++j){
        for(int i=0;i<curPuzzle.xSize;++i)
            if(curPuzzle.puzzle_map[j*curPuzzle.xSize+i]!=0){
                goalPuzzle[j*curPuzzle.xSize+i]=counter;
                adress=j*curPuzzle.xSize+i;
                ++counter;
            }
            else
                goalPuzzle[j*curPuzzle.xSize+i]=0;
    }
    goalPuzzle[adress]=-1;
    return goalPuzzle;
}
/* Getting Initial Puzzle  */
void getInitialPuzzle(struct Puzzle& curPuzzle){
    curPuzzle.xSize=getPuzzleSize();
    curPuzzle.ySize=curPuzzle.xSize;
    curPuzzle.puzzle_map=(int*)malloc(sizeof(int)*curPuzzle.xSize*curPuzzle.ySize);

    for(int i=0;i<curPuzzle.xSize*curPuzzle.ySize;++i)
        curPuzzle.puzzle_map[i]=-1;

    curPuzzle.totalCost=0;
    curPuzzle.moveNumber=0;    
    curPuzzle.prevMove=-1;
    curPuzzle.goal_map=createGoalPuzzle(curPuzzle);

    createInitialPuzzle(curPuzzle);
    return;
}
/* Determining Whether Puzzle is solvable or not */
bool isSolvablePuzzle(struct Puzzle& curPuzzle){
    int inversionNumber=getInversionCount(curPuzzle);
    
    if((curPuzzle.xSize*curPuzzle.ySize)%2&&!(inversionNumber%2))
        return true;
    else if(!((curPuzzle.xSize*curPuzzle.ySize)%2))
    {
        getPlayerPos(curPuzzle);
        if((!((curPuzzle.xSize*curPuzzle.ySize)-curPuzzle.playerY)%2)&&inversionNumber%2)
            return true;
        else if((((curPuzzle.xSize*curPuzzle.ySize)-curPuzzle.playerY)%2)&&!(inversionNumber%2))
            return true;
    }
    return false;
}
int getInversionCount(const struct Puzzle& curPuzzle){
    int inversionCounter=0;
    for(int i=0;i<curPuzzle.xSize*curPuzzle.ySize-1;++i){
        for(int j=i+1;j<curPuzzle.xSize*curPuzzle.ySize;++j){
            if((curPuzzle.puzzle_map[i]!=-1)&&(curPuzzle.puzzle_map[j]!=-1)&&(curPuzzle.puzzle_map[i]>curPuzzle.puzzle_map[j]))
                ++inversionCounter;
        }
    }
    return inversionCounter;
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
/*__arr .  1 2 3 4 5 6 7 8 9_______________________________________________________________________________*/
/*__________________________________________________________________________________________________________*/
/*__arr .  0 1 2 3 4 5 6 7 8____These are my indexs________________________________________________________*/
/*__________________________________________________________________________________________________________*/
/*Step 1: Take random index number . Ex* 3__________________________________________________________________*/
/*__________________________________________________________________________________________________________*/
/*Swap with this value of index with beginning index value using swap operation_____________________________*/
/*__________________________________________________________________________________________________________*/
/*_new_arr .  4 2 3 1 5 6 7 8 9____________________________________________________________________________*/
/*__________________________________________________________________________________________________________*/
/*Step 2: Increment beginning swap index , for example , if it is 0 it would be 1 , if it is 1,it would be 2*/
/*__________________________________________________________________________________________________________*/
/*Step 3:Increment the index of loop that You use___________________________________________________________*/
void createInitialPuzzle(struct Puzzle& curPuzzle){
    int initial_index=0,pseudoIndex,divisionTool=0;

    for(int i=0;i<curPuzzle.xSize*curPuzzle.ySize;++i)
        curPuzzle.puzzle_map[i]=i+1;

    /* Creating Random Numeber */
    while(initial_index!=curPuzzle.xSize*curPuzzle.ySize-1){
        pseudoIndex=((rand()%(curPuzzle.xSize*curPuzzle.ySize-initial_index))+initial_index);
        swap(curPuzzle.puzzle_map,pseudoIndex,initial_index);
        ++initial_index;
    }

    for(int i=0;i<curPuzzle.xSize*curPuzzle.ySize;++i){ 
        if(curPuzzle.puzzle_map[i]==curPuzzle.xSize*curPuzzle.ySize){
            curPuzzle.puzzle_map[i]=-1;
        }
    }

    /* Check whether it is solvable or not */
    while(!isSolvablePuzzle(curPuzzle)||isEndPuzzle(curPuzzle))
        createInitialPuzzle(curPuzzle);

    /* Taking Player Position */
    getPlayerPos(curPuzzle);
}
/*Step 3:Increment the index of loop that You use___________________________________________________________*/
void readFile(std::string filename,struct Puzzle& curPuzzle){
    int spaceDetermination=0,i=0,j=0,xSize=0,ySize=0,putNumber=0,puzzleIndex=0;
    char next='\0',*tempMap=NULL;

    std::ifstream inStream ;
    inStream.open(filename,std::ios_base::in);
    if(inStream.fail()){
        std::cerr<<"\nInput file opening error !\n\n";
        exit(1);
    }

    while(next!=' '){
        inStream.get(next);
        ++spaceDetermination;
    }
    --spaceDetermination;
    inStream.clear();
    inStream.seekg(std::ios_base::beg);

    while(inStream.get(next)){
        if(next==' ')
            ++xSize;
        if(next=='\n')
            ++ySize;
    }
    ++ySize;
    xSize=xSize/ySize+1;
    inStream.clear();
    inStream.seekg(std::ios_base::beg);
    curPuzzle.xSize=xSize;
    curPuzzle.ySize=ySize;

    tempMap = (char*)malloc(sizeof(char)*(curPuzzle.xSize*curPuzzle.ySize*spaceDetermination+1));
    while(inStream.get(next)){
        if(next!=' '&&next!='\n'){
            tempMap[i]=next;
            ++i;
        }
    }
    tempMap[i]='\0';
    curPuzzle.puzzle_map=(int*)malloc(sizeof(int)*curPuzzle.xSize*curPuzzle.ySize);

    i=0;
    while(i<curPuzzle.xSize*curPuzzle.ySize*spaceDetermination){
        if((i+1)%spaceDetermination==0)
        {
            for(j=0;j<spaceDetermination;++j)
            {
                if(tempMap[i+1-spaceDetermination+j]!='b')  putNumber+=charToint(tempMap[i+1-spaceDetermination+j])*getExponential(10,spaceDetermination-1-j);
                else                                        putNumber=-1;
            }
            curPuzzle.puzzle_map[puzzleIndex]=putNumber;
            ++puzzleIndex;
        }
        ++i,putNumber=0;  
    }

    free(tempMap);
    inStream.close();
    curPuzzle.totalCost=0;
    curPuzzle.moveNumber=0;
    curPuzzle.prevMove=-1;
    curPuzzle.goal_map=createGoalPuzzle(curPuzzle);
    return;
}
/*Step 3:Increment the index of loop that You use___________________________________________________________*/
int getExponential(int base,int power){
    int result=1;
    if(power==0)
        return 1;

    for(int i=0;i<power;++i)
        result*=base;
    return result;
}
/*Step 3:Increment the index of loop that You use___________________________________________________________*/
int charToint(char number){
    int i=0;
    while(number!='0')
        --number,++i;
    return i;
}
/*Step 3:Increment the index of loop that You use___________________________________________________________*/
void playerGuide(void){
    std::cout<<"\t\t.> Welcome to the N-Puzzle Solver Game <<-\n";
    std::cout<<"\t\t___________________________________________\n\n";
    std::cout<<"-. Game Purpose: Solving N-Puzzle by moving over it.\n\n";
    std::cout<<"Input Guide : \n";
    std::cout<<"-------------\n";
    std::cout<<"-. Press (U) to move UP\n";
    std::cout<<"-. Press (R) to move RIGHT\n";
    std::cout<<"-. Press (L) to move LEFT\n";
    std::cout<<"-. Press (D) to move DOWN\n";
    std::cout<<"-. Press (S) to Shuffle the Current Puzzle\n\n";
    std::cout<<"Entended Version Input :\n";
    std::cout<<"------------------------\n";
    std::cout<<"-. Press (V) to solve entire puzzle and show part of each step\n";
    std::cout<<"-. Press (T) to print a report to the screen\n";
    std::cout<<"-. Press (E) to save the current puzzle board into a file\n";
    std::cout<<"-. Press (Y) to load the current puzzle board from the file\n";
    std::cout<<"-. Press (Q) to Quit Puzzle Game\n";
    std::cout<<"_______________________________________________________Good Luck :)\n\n";
}
/*Step 3:Increment the index of loop that You use___________________________________________________________*/
std::string getFilename(void)
{
    std::string filename;
    std::cout<<"Target Filename: ";
    std::cin>>filename;
    return filename;
}
/*  load puzzle from the file */
bool loadPuzzleFromFile(struct Puzzle& curPuzzle)
{
    std::string filename=getFilename();
    curPuzzle.moveNumber=0;
    free(curPuzzle.puzzle_map);
        curPuzzle.puzzle_map=NULL;
    free(curPuzzle.goal_map);
        curPuzzle.goal_map=NULL;
    readFile(filename,curPuzzle);
    getPlayerPos(curPuzzle);
    return true;
}
/* save Puzzle to file */
bool savePuzzleToFile(struct Puzzle& curPuzzle){
    bool loopFlag=true;
    int maxNumber=0,difNumber=0;
    for(int j=curPuzzle.ySize-1;j>=0 && loopFlag;--j){
        for(int i=curPuzzle.xSize-1;i>=0 && loopFlag;--i){
            if((curPuzzle.goal_map[j*curPuzzle.xSize+i]!=0)&&(curPuzzle.goal_map[j*curPuzzle.xSize+i]!=-1)){
                maxNumber=curPuzzle.goal_map[j*curPuzzle.xSize+i];
                loopFlag=false;
            }
        }
    }

    std::string filename=getFilename();
    std::ofstream outStream;
    outStream.open(filename,std::ios_base::out);
    if(outStream.fail()){
        std::cerr<<"File could not be opened to load\n";
        exit(-1);
    }

    for(int j=0;j<curPuzzle.ySize;++j){
        for(int i=0;i<curPuzzle.xSize;++i){
            if(curPuzzle.puzzle_map[j*curPuzzle.xSize+i]!=-1)
            {
                if(getDigit(curPuzzle.puzzle_map[j*curPuzzle.xSize+i])==getDigit(maxNumber))
                    outStream<<curPuzzle.puzzle_map[j*curPuzzle.xSize+i];
                else
                {
                    difNumber=getDigit(maxNumber)-getDigit(curPuzzle.puzzle_map[j*curPuzzle.xSize+i]);
                    for(int k=0;k<difNumber;++k)
                        outStream<<0;
                    outStream<<curPuzzle.puzzle_map[j*curPuzzle.xSize+i];
                    difNumber=0;
                }
            }
            else
                for(int k=0;k<getDigit(maxNumber);++k)
                        outStream<<'b';
            if(i!=curPuzzle.xSize-1)
                outStream<<" ";
        }
        if(j!=curPuzzle.ySize-1)
            outStream<<"\n";
    }
    outStream.close();
    return true;
}
/* get digit of the number */
int getDigit(int number){
    int counter=1;
    while(number/=10)
        ++counter;
    return counter;
}
/* printing Report  */
void printReport(const struct Puzzle& curPuzzle){
    std::cout<<"================================\n";
    std::cout<<curPuzzle.moveNumber<<" moves have been done ! \n";
    std::cout<<"Keep Going !\n";
    std::cout<<"================================\n";
}
/* go to directly the solution */
void goSolution(struct Puzzle& curPuzzle,bool* quit)
{
    bool escape=false;
    int prevMoveNumber=curPuzzle.moveNumber;
    while(!escape)
    {
        printPuzzle(curPuzzle);
        IntelligentMove(curPuzzle);
        if((curPuzzle.moveNumber - prevMoveNumber)>400000){
            std::cout<<"================================\n";
            std::cout<<"Ram is so hot , I had to quit :D\n";
            std::cout<<"================================\n\n";
            escape=true;
        }

        if(isEndPuzzle(curPuzzle)){
            printPuzzle(curPuzzle);
            std::cout<<"============================================\n";
            std::cout<<"Problem Solved by the Intelligent !\n"
                <<"Total number of moves of Intelligent =  "<< curPuzzle.moveNumber - prevMoveNumber <<"\n\n";
                std::cout<<"============================================\n\n";
                escape=true;
        }
    }
    *quit=true;
}