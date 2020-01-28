#include "NPuzzle.h"
/*Class Library that I included for the purpose of using class */

using namespace std;
/*std namespace to make more clear code */

/*Pre Condition =  take no parameter , cannot change anything in the class */
/*Post Condition = print the current configuretion of the puzzle */
/*Board Class Public Declared  Function */
void NPuzzle::Board::print(void) const
{
    for(int j=0;j<ySize;++j)
    {
        for(int i=0;i<xSize;++i)
        {
            if(puzzle_map[xSize*j+i]==-1) cout<<"\t";
            else if(puzzle_map[xSize*j+i]==0) cout<<"\tX";
            else    cout<<"\t"<<puzzle_map[xSize*j+i];
        }
        cout << endl<< endl;
    }
}

/*Pre Condition =  take no parameter , cannot change anything in the class*/
/*Post Condition = print the current configuretion of the puzzle */
/*NPuzzle Class Public Declared  Function */
void NPuzzle::print(void) const
{
    gameBoard.print();
}

/*Pre Condition =  take const reference int value */
/*Post Condition = create a N puzzle board */
/*Board Class Public Declared  Function */
void NPuzzle::Board::setsize(const int& size)
{
    ySize=xSize=size;
    puzzle_map=(int*)malloc(sizeof(int)*xSize*ySize);

    for(int i=0;i<xSize*ySize;++i)
        puzzle_map[i]=-1;
    goal_map=createGoalPuzzle();
    
    init_prev_move();
    reset();

    return;
}
/*Pre Condition =  take const reference int value */
/*Post Condition = create a N puzzle board */
/*NPuzzle Class Public Declared  Function */
void NPuzzle::setsize(const int& size)
{
    gameBoard.setsize(size);
    shuffle(size*size*100);
}
/*Pre Condition =  take no parameter  */
/*Post Condition = create a N puzzle final configuration*/
/*Board Class Private Declared  Function */
int* NPuzzle::Board::createGoalPuzzle(void){
    int counter=1,adress=0;
    int* goalPuzzle=(int*)malloc(sizeof(int)*(xSize*ySize));

    for(int j=0;j<ySize;++j){
        for(int i=0;i<xSize;++i)
            if(puzzle_map[j*xSize+i]!=0){
                goalPuzzle[j*xSize+i]=counter;
                adress=j*xSize+i;
                ++counter;
            }
            else
                goalPuzzle[j*xSize+i]=0;
    }
    goalPuzzle[adress]=-1;
    return goalPuzzle;
}
/*Pre Condition =  take no parameter  */
/*Post Condition = detect and change the value of private data which is playerX,playery */
/*Board Class Private Declared  Function */
bool NPuzzle::Board::setPlayerPos(void){
    for(int i=0;i<xSize*ySize;++i){ 
        if(puzzle_map[i]==-1){
            playerX=i%xSize;
            playerY=i/xSize;
            return true;
        }
    }
    return false;
}
/*Pre Condition =  take no parameter and connot change any value in the board class*/
/*Post Condition =  consider whether current puzzle has been solved or has not*/
/*Board Class Private Declared  Function */
bool NPuzzle::Board::isSolved(void) const{
    for(int j=0;j<ySize;++j){
        for(int i=0;i<xSize;++i){
            if(puzzle_map[j*xSize+i]!=goal_map[j*xSize+i])
                return false;
        }
    }
    return true;
}
/*Pre Condition =  take no parameter and connot change any value in the board class*/
/*Post Condition =  consider whether current puzzle is empty or not*/
/*Board Class Private Declared  Function */
bool NPuzzle::Board::is_empty_puzzle(void) const
{
    if(puzzle_map!=NULL&&goal_map!=NULL)
        return false;
    else
        return true;
}
/*Pre Condition =  take string type parameter and read the current configuration from the file */
/*Post Condition =  create a puzzle from file */
/*Board Class Public Declared  Function */
void NPuzzle::Board::readFromFile(const string& input_filename){
    char next='\0',prev='\0';
    bool initialCheck=true;
    string strNum;
    strNum.empty();

    set_empty_or_release_puzzle();

    ifstream inStream;
    inStream.open(input_filename,ios_base::in);

    if(inStream.fail()){
        cerr<<"\nInput file opening error !\n\n";
        exit(1);
    }

    while(next!='\n'){
        next=inStream.get();
        if(next!=' '&&initialCheck)
            ++xSize;
        initialCheck=false;
        if((next!=' '&&next!='\n'&&prev==' '))
            ++xSize;
        prev=next;
    }
    
    initialCheck=true;
    next='\0',prev='\0';
    inStream.clear();
    inStream.seekg(ios_base::beg);

    while(!inStream.eof()){
        next=inStream.get();
        if(next=='\n'&&initialCheck)
            --ySize;
        initialCheck=false;
        if(next=='\n'&&prev!='\n')
            ++ySize;
        if(inStream.eof()&&prev!='\n')
            ++ySize;
        prev=next;
    }

    inStream.clear();
    inStream.seekg(ios_base::beg);

    puzzle_map=(int*)malloc(sizeof(int)*xSize*ySize);

    for(int j=0;j<ySize;++j){
        for(int i=0;i<xSize;++i){
            inStream>>strNum;
            if(!is_number(strNum))
                puzzle_map[j*xSize+i]=-1;
            else
                puzzle_map[j*xSize+i]=stoi(strNum);
        }
    }
    inStream.close();
    goal_map=createGoalPuzzle();
    filename=input_filename;
    init_prev_move();

    return;
}
/*Pre Condition =  take string type parameter and read the current configuration from the file */
/*Post Condition =  create a puzzle from file */
/*NPuzzle Class Public Declared  Function */
void NPuzzle::readFromFile(const string& filename)
{
    gameBoard.readFromFile(filename);
}
/*Pre Condition =  take valid char number ascii code */
/*Post Condition =  return a value which is interger version of typed character */
/*Board Class Private Declared  Function */
int NPuzzle::Board::charToint(char number) const{
    int i=0;
    while(number!='0')
        --number,++i;
    return i;
}
/*Pre Condition =  take valid const char reference letter  */
/*Post Condition =  make a valid move through given dirention */
/*Board Class Public Declared  Function */
bool NPuzzle::Board::move(const char& letter)
{
    bool flag=true;
    setPlayerPos();
    switch(letter)
    {
        case 'r':
        case 'R':
            if(!moveRight())
                flag=false;
        break;

        case 'l':
        case 'L':
            if(!moveLeft())
                flag=false;
            break;

        case 'u':
        case 'U':
            if(!moveUp())
                flag=false;
            break;

        case 'd':
        case 'D':
            if(!moveDown())
                flag=false;
            break;

        default:
            flag=false;
            break;
    }

    if(flag)
        inc_moveNumber(1);
    setPlayerPos();
    return flag;
}
/*Pre Condition =  take valid const char reference letter  */
/*Post Condition =  make a valid move through given dirention */
/*NPuzzle Class Public Declared  Function */
bool NPuzzle::move(const char& letter)
{
    return gameBoard.move(letter);
}
/*Pre Condition =  take no parameter , can change value of Board class*/
/*Post Condition =  make a valid move if it is possible  */
/*Board Class Private Declared  Function */
bool NPuzzle::Board::moveRight(void){
    if((playerX+1)<xSize&&puzzle_map[playerY*xSize+playerX+1]!=0)
    {
        puzzle_map[playerY*xSize+playerX]=puzzle_map[playerY*xSize+playerX+1];
        puzzle_map[playerY*xSize+playerX+1]=-1;
        return true;
    }
    return false;
}
/*Pre Condition =  take no parameter , can change value of Board class*/
/*Post Condition =  make a valid move if it is possible  */
/*Board Class Private Declared  Function */
bool NPuzzle::Board::moveLeft(void){
    if((playerX-1)>=0&&puzzle_map[playerY*xSize+playerX-1]!=0)
    {
        puzzle_map[playerY*xSize+playerX]=puzzle_map[playerY*xSize+playerX-1];
        puzzle_map[playerY*xSize+playerX-1]=-1;
        return true;
    }
    return false;
}
/*Pre Condition =  take no parameter , can change value of Board class*/
/*Post Condition =  make a valid move if it is possible  */
/*Board Class Private Declared  Function */
bool NPuzzle::Board::moveUp(void){
    if((playerY-1)>=0&&puzzle_map[(playerY-1)*xSize+playerX]!=0)
    {
        puzzle_map[playerY*xSize+playerX]=puzzle_map[(playerY-1)*xSize+playerX];
        puzzle_map[(playerY-1)*xSize+playerX]=-1;
        return true;
    }
    return false;
}
/*Pre Condition =  take no parameter , can change value of Board class*/
/*Post Condition =  make a valid move if it is possible  */
/*Board Class Private Declared  Function */
bool NPuzzle::Board::moveDown(void){
    if((playerY+1)<ySize&&puzzle_map[(playerY+1)*xSize+playerX]!=0)
    {
        puzzle_map[playerY*xSize+playerX]=puzzle_map[(playerY+1)*xSize+playerX];
        puzzle_map[(playerY+1)*xSize+playerX]=-1;
        return true;
    }
    return false;
}
/*Pre Condition =  take no parameter , cannot change any value of the NPuzzle class*/
/*Post Condition =  print the current amount of move */
/*NPuzzle Class Public Declared  Function */
void NPuzzle::printReport(void) const
{
    cout<<"========================\n";
    cout<<"Total number of moves "<<gameBoard.get_moveNumber()<<" !"<<endl;
    cout<<"========================\n";
}
/*Pre Condition =  take no parameter */
/*Post Condition =  reset the current puzzle configuration with final configuration*/
/*NPuzzle Class Public Declared  Function */
void NPuzzle::reset(void)
{
    gameBoard.reset();
}
/*Pre Condition =  take no parameter */
/*Post Condition =  reset the current puzzle configuration with final configuration*/
/*Board Class Public Declared  Function */
void NPuzzle::Board::reset(void)
{
    for(int j=0;j<ySize;++j)
        for(int i=0;i<xSize;++i)
            puzzle_map[j*xSize+i]=goal_map[j*xSize+i];
}
/*Pre Condition =  take const valid int type variable */
/*Post Condition =  shuffle the current configuration of the puzzle */
/*NPuzzle Class Public Declared  Function */
void NPuzzle::shuffle(const int& n)
{
    int sizeCheck=0;

    while(++sizeCheck<=n)
        moveRandom();

    if(gameBoard.isSolved())
        shuffle(n);

    gameBoard.reset_moveNumber();
    gameBoard.setPlayerPos();
    gameBoard.init_prev_move();

    return;
}
/*Pre Condition =  take no parameter */
/*Post Condition =  make a valid random move*/
/*NPuzzle Class Public Declared  Function */
char NPuzzle::moveRandom(void)
{
    char dirChar='\0';
    int dirInt=rand()%4;

    if(dirInt==right)       dirChar='R';
    else if(dirInt==left)   dirChar='L';
    else if(dirInt==up)     dirChar='U';
    else if(dirInt==down)   dirChar='D';

    if(!move(dirChar))
        moveRandom();

    return dirChar;
}
/*Pre Condition =  take valid strign type variable */
/*Post Condition =  write current configuration to given file*/
/*Board Board Public Declared  Function */
void NPuzzle::Board::writeToFile(const string& filename)
{
    bool loopFlag=true;
    int maxNumber=0,difNumber=0;

    for(int j=ySize-1;j>=0 && loopFlag;--j){
        for(int i=xSize-1;i>=0 && loopFlag;--i){
            if((goal_map[j*xSize+i]!=0)&&(goal_map[j*xSize+i]!=-1)){
                maxNumber=goal_map[j*xSize+i];
                loopFlag=false;
            }
        }
    }

    ofstream outStream;
    outStream.open(filename,ios_base::out);

    if(outStream.fail()){
        cerr<<"File could not be opened to load !\n";
        exit(-1);
    }

    for(int j=0;j<ySize;++j)
    {
        for(int i=0;i<xSize;++i)
        {
            if(puzzle_map[j*xSize+i]!=-1)
            {
                if(get_digit(puzzle_map[j*xSize+i])==get_digit(maxNumber))
                {
                    if(get_digit(puzzle_map[j*xSize+i])==1)
                        outStream<<'0'<<puzzle_map[j*xSize+i];
                    else
                        outStream<<puzzle_map[j*xSize+i];
                }
                else
                {
                    difNumber=get_digit(maxNumber)-get_digit(puzzle_map[j*xSize+i]);

                    for(int k=0;k<difNumber;++k)
                        outStream<<0;
                        
                    outStream<<puzzle_map[j*xSize+i];
                    difNumber=0;
                }
            }
            else
            {
                if(get_digit(maxNumber)==1)
                    outStream<<"bb";
                else
                {
                    for(int k=0;k<get_digit(maxNumber);++k)
                        outStream<<"b";
                }
                
            }
            if(i!=xSize-1)
                outStream<<" ";
        }
        if(j!=ySize-1)
            outStream<<"\n";
    }
    outStream.close();
}
/*Pre Condition =  take valid strign type variable */
/*Post Condition =  write current configuration to given file*/
/*NPuzzle Board Public Declared  Function */
void NPuzzle::writeToFile(const string& filename)
{
    gameBoard.writeToFile(filename);
}
/*Pre Condition =  take valid int type value*/
/*Post Condition =  return the digits number of given value */
/*NPuzzle Board Public Declared  Function */
int NPuzzle::Board::get_digit(int number) const
{
    int counter=1;
    while(number/=10)
        ++counter;
    return counter;
}
/* Pre Condition =  take valid const string type value , cannot change any value in the class */
/*Post Condition =  return true or false according to  given value is number or not*/
/*NPuzzle Board Private Declared  Function */
bool NPuzzle::Board::is_number(const string& s1) const
{
    bool flag=true;
    for(unsigned int i=0;i<s1.size()&&flag;++i)
    {
        if((s1[i]<'0'||s1[i]>'9'))
            flag=false;
    }
    return flag;
}
/* Pre Condition =  take no parameter  */
/* Post Condition =  make puzzle empty or  if end of the game releasePuzzle too*/
/* NPuzzle Board Public Declared Function */
void NPuzzle::Board::set_empty_or_release_puzzle(void)
{
    if(!is_empty_puzzle())
    {
        free(puzzle_map);
        puzzle_map=NULL;
        free(goal_map);
        goal_map=NULL;
    }
    else
    {
        puzzle_map=NULL;
        goal_map=NULL;
    }

    xSize=ySize=0;
    playerX=playerY=0;
    moveNumber=0;

    totalCost[right]=0;
    totalCost[left]=0;
    totalCost[down]=0;
    totalCost[up]=0;

    filename.empty();
}
/* Pre Condition =  take no parameter , cannot change any value in the calss */
/* Post Condition =  determine the is end puzzle or not */
/* NPuzzle Board Public Declared Function */
bool NPuzzle::is_end_puzzle(void) const
{ 
    return gameBoard.isSolved();
}
/* Pre Condition =  get puzzle size from the user which is define before */
/* Post Condition = return the valid puzzle size */
/* NPuzzle Board Public Declared Function */
int NPuzzle::get_puzzle_size(const int& min_size , const int& max_size) const
{
    int puzzle_size=-1;
    while(puzzle_size<min_size||puzzle_size>max_size){
        cout<<"\nPlease enter problem size: ";
        cin>>puzzle_size;
        cout<<endl;
    }
    return puzzle_size;
}
/* Pre Condition =  take no parameter */
/* Post Condition = return filename */
/* NPuzzle Public Declared Function */
string NPuzzle::get_file_name(void) const
{
    string filename;
    cout<<"Target Filename: ";
    cin>>filename;
    return filename;
}
/* Pre Condition =  take no parameter */
/* Post Condition = release the current puzzle that we created before */
/* NPuzzle Public Declared Function */
void NPuzzle::release_puzzle(void)
{
    gameBoard.set_empty_or_release_puzzle();
}
/* Pre Condition =  take no parameter */
/* Post Condition = make valid intelligent move on the puzzle */
/* NPuzzle Public Declared Function */
void NPuzzle::moveIntelligence(void)
{
    int minNum=__INT_MAX__,cost_same_amount=-1,luck=0;
    bool minIndex[4]={false,false,false,false},flag=true;
    int finalDir,sameCounter=0;

    if(move('R')){
        gameBoard.totalCost[right]=gameBoard.getCost();
        move('L');
        gameBoard.dec_moveNumber(2);
    }
    else
        gameBoard.totalCost[right]=-1;
    
    if(move('L')){
        gameBoard.totalCost[left]=gameBoard.getCost();
        move('R');
        gameBoard.dec_moveNumber(2);
    }
    else
        gameBoard.totalCost[left]=-1;

    if(move('U')){
        gameBoard.totalCost[up]=gameBoard.getCost();
        move('D');
        gameBoard.dec_moveNumber(2);
    }
    else
        gameBoard.totalCost[up]=-1;

    if(move('D')){
        gameBoard.totalCost[down]=gameBoard.getCost();
        move('U');
        gameBoard.dec_moveNumber(2);
    }
    else
        gameBoard.totalCost[down]=-1;
    

    for(int i=0;i<4;++i)
    {
        if(gameBoard.totalCost[i]<=minNum && gameBoard.totalCost[i]!=-1)
        {
            minNum=gameBoard.totalCost[i];
            minIndex[i]=true;
            for(int j=i-1 ;j>=0;--j)
                if(gameBoard.totalCost[j]!=gameBoard.totalCost[i])
                    minIndex[j]=false;
        }
    }
    
    for(int i=0;i<4;++i)
    {
        if(minIndex[i]==true){
            ++cost_same_amount;
            finalDir=i;
        }
    }

    if(cost_same_amount==0)
    {
        if(finalDir==up&&gameBoard.prevMove[gameBoard.getPlayerX()][gameBoard.getPlayerY()-1]==false&&move('U')){
            cout<<"Intelligent move chooses U\n";
            gameBoard.prevMove[gameBoard.getPlayerX()][gameBoard.getPlayerY()]=true;
        }
        else if(finalDir==right&&gameBoard.prevMove[gameBoard.getPlayerX()+1][gameBoard.getPlayerY()]==false&&move('R')){
            cout<<"Intelligent move chooses R\n";
            gameBoard.prevMove[gameBoard.getPlayerX()][gameBoard.getPlayerY()]=true;
        }
        else if(finalDir==left&&gameBoard.prevMove[gameBoard.getPlayerX()-1][gameBoard.getPlayerY()]==false&&move('L')){
            cout<<"Intelligent move chooses L\n";
            gameBoard.prevMove[gameBoard.getPlayerX()][gameBoard.getPlayerY()]=true;
        }
        else if(finalDir==down&&gameBoard.prevMove[gameBoard.getPlayerX()][gameBoard.getPlayerY()+1]==false&&move('D')){
            cout<<"Intelligent move chooses D\n";
            gameBoard.prevMove[gameBoard.getPlayerX()][gameBoard.getPlayerY()]=true;
        }
        else
        {
            for(int j=0;j<gameBoard.get_ySize();++j)
            {
                for(int i=0;i<gameBoard.get_xSize();++i)
                        gameBoard.prevMove[i][j]=false;
            }
            gameBoard.prevMove[gameBoard.getPlayerX()][gameBoard.getPlayerY()]=true;
            
            cout<<"Intelligent move chooses "<<moveRandom()<<endl;

            gameBoard.prevMove[gameBoard.getPlayerX()][gameBoard.getPlayerY()]=true;
        }
    }
    else
    {
        if(minIndex[right]&&gameBoard.prevMove[gameBoard.getPlayerX()+1][gameBoard.getPlayerY()]==false)
            ++sameCounter;
        else if(minIndex[left]&&gameBoard.prevMove[gameBoard.getPlayerX()-1][gameBoard.getPlayerY()]==false)
            ++sameCounter;
        else if(minIndex[up]&&gameBoard.prevMove[gameBoard.getPlayerX()][gameBoard.getPlayerY()-1]==false)
            ++sameCounter;
        else if(minIndex[down]&&gameBoard.prevMove[gameBoard.getPlayerX()][gameBoard.getPlayerY()+1]==false)
            ++sameCounter;

        while(flag)
        {
            luck=rand()%4;
            if(luck==right&&minIndex[right]&&gameBoard.prevMove[gameBoard.getPlayerX()+1][gameBoard.getPlayerY()]==false&&move('R'))
            {
                cout<<"Intelligent move chooses R\n";
                gameBoard.prevMove[gameBoard.getPlayerX()][gameBoard.getPlayerY()]=true;
                flag=false;
            }
            else if(luck==left&&minIndex[left]&&gameBoard.prevMove[gameBoard.getPlayerX()-1][gameBoard.getPlayerY()]==false&&move('L'))
            {
                cout<<"Intelligent move chooses L\n";
                gameBoard.prevMove[gameBoard.getPlayerX()][gameBoard.getPlayerY()]=true;
                flag=false;
            }
            else if(luck==up&&minIndex[up]&&gameBoard.prevMove[gameBoard.getPlayerX()][gameBoard.getPlayerY()-1]==false&&move('U'))
            {
                cout<<"Intelligent move chooses U\n";
                gameBoard.prevMove[gameBoard.getPlayerX()][gameBoard.getPlayerY()]=true;
                flag=false;
            }
            else if(luck==down&&minIndex[down]&&gameBoard.prevMove[gameBoard.getPlayerX()][gameBoard.getPlayerY()+1]==false&&move('D'))
            {
                cout<<"Intelligent move chooses D\n";
                gameBoard.prevMove[gameBoard.getPlayerX()][gameBoard.getPlayerY()]=true;
                flag=false;
            }
            else if(sameCounter==0)
            {
                for(int j=0;j<gameBoard.get_ySize();++j)
                {
                    for(int i=0;i<gameBoard.get_xSize();++i)
                            gameBoard.prevMove[i][j]=false;
                }
                gameBoard.prevMove[gameBoard.getPlayerX()][gameBoard.getPlayerY()]=true;
                cout<<"Intelligent move chooses "<<moveRandom()<<endl;
                gameBoard.prevMove[gameBoard.getPlayerX()][gameBoard.getPlayerY()]=true;
                sameCounter=0;
                flag=false;
            }
        }
        flag=true;
    }
}
/* Pre Condition =  take no parameter , cannot change any value in the Board class*/
/* Post Condition = return the cost of given puzzle */
/* Board Private Declared Function */
int NPuzzle::Board::getCost(void) const
{
    int x0,y0,x1,y1,dx,dy,sum = 0;
    for(y0 = 0; y0 < ySize; ++y0){
        for(x0 = 0; x0 < xSize; ++x0){
            for(y1 = 0; y1 < ySize; ++y1){
                for(x1 = 0; x1 < xSize; ++x1){
                    if(puzzle_map[y0*xSize+x0] == goal_map[y1*xSize+x1]){
                        if(puzzle_map[y0*xSize+x0]!=0&&goal_map[y1*xSize+x1]!=0){
                            dx = (x0 - x1 < 0)? x1 - x0 : x0 - x1;
                            dy = (y0 - y1 < 0)? y1 - y0 : y0 - y1;
                            sum += dx + dy;
                        }
                    }
                }
            }
        }
    }
    return sum;
}
/* Pre Condition =  default constructor definition*/
NPuzzle::Board::Board(void)
{
    puzzle_map=NULL;
    goal_map=NULL;
}
/* Pre Condition =  take no parameter */
/* Post Condition = go through directly go to final puzzle */
/* NPuzzle Private Declared Function */
void NPuzzle::goSolution(void)
{
    bool escape=false;
    int prevMoveNumber=gameBoard.get_moveNumber();
    while(!escape)
    {
        print();
        moveIntelligence();
        if((gameBoard.get_moveNumber() - prevMoveNumber)>200000){
            cout<<"================================\n";
            cout<<"Ram is so hot , I had to quit :D\n";
            cout<<"================================\n\n";
            escape=true;
        }

        if(is_end_puzzle()){
            print();
            cout<<"============================================\n";
            cout<<"Problem Solved by the Intelligent !\n"
                <<"Total number of moves of Intelligent =  "<< gameBoard.get_moveNumber() - prevMoveNumber <<"\n\n";
                cout<<"============================================\n\n";
                escape=true;
        }
        quit=true;
    }
}
/* Pre Condition =  take no parameter */
/* Post Condition = ibitialize a valid prev_move array type  */
/* Board Class Public Function */
void NPuzzle::Board::init_prev_move(void)
{
    setPlayerPos();
    for(int j=0;j<9;++j)
    {
        for(int i=0;i<9;++i)
            prevMove[i][j]=2;
    }
    
    for(int j=0;j<ySize;++j)
    {
        for(int i=0;i<xSize;++i)
            if(puzzle_map[j*xSize+i]!=0)
                prevMove[i][j]=0;
            else
                prevMove[i][j]=-1;
    }
    prevMove[playerX][playerY]=1;
}