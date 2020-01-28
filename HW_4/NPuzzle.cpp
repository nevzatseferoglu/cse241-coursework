#include "NPuzzle.h"

using namespace std;
void NPuzzle::Board::print(void) const
{
    for(int j=0;j<ySize;++j)
    {
        for(int i=0;i<xSize;++i)
        {
            if(puzzle_map[i][j]==-1) cout<<"\t";
            else if(puzzle_map[i][j]==0) cout<<"\tX";
            else    cout<<"\t"<<puzzle_map[i][j];
        }
        cout << endl<< endl;
    }
}
void NPuzzle::print(void) const
{
    gameBoard.print();
}
void NPuzzle::Board::setsize(const int& size)
{
    ySize=xSize=size;
    set_puzzle();
    set_goal_puzzle();
    reset();
    return;
}
void NPuzzle::setsize(const int& size)
{
    gameBoard.setsize(size);
    shuffle(size*size);
}
void NPuzzle::Board::set_goal_puzzle(void){
    int counter=1,xAdress=0,yAdress=0;
    for(int j=0;j<ySize;++j)
    {
        for(int i=0;i<xSize;++i)
        {
            if(puzzle_map[i][j]!=0)
            {
                goal_map[i][j]=counter;
                xAdress=i,yAdress=j;
                ++counter;
            }
            else
                goal_map[i][j]=0;
        }
    }
    goal_map[xAdress][yAdress]=-1;
}
bool NPuzzle::Board::set_player_pos(void){
    for(int j=0;j<ySize;++j)
    {
        for(int i=0;i<xSize;++i)
        {
            if(puzzle_map[i][j]==-1)
            {
                playerX=i,playerY=j;
                return true;
            }
        }
    }
    return false;
}
bool NPuzzle::Board::isSolved(void) const{
    for(int j=0;j<ySize;++j){
        for(int i=0;i<xSize;++i){
            if(puzzle_map[i][j]!=goal_map[i][j])
                return false;
        }
    }
    return true;
}
void NPuzzle::Board::readFromFile(const string& input_filename){
    char next='\0',prev='\0';
    bool initialCheck=true;
    string strNum;
    strNum.empty();

    release_puzzle();
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
    
    set_puzzle();

    for(int j=0;j<ySize;++j)
    {
        for(int i=0;i<xSize;++i)
        {
            inStream>>strNum;
            if(!is_number(strNum))
                puzzle_map[i][j]=-1;
            else
                puzzle_map[i][j]=stoi(strNum);
        }
    }
    inStream.close();
    set_goal_puzzle();
    filename=input_filename;
    return;
}
void NPuzzle::readFromFile(const string& filename)
{
    gameBoard.readFromFile(filename);

    board_sets.clear();
    board_sets.push_back(gameBoard);
    board_sets[0].inc_number_of_boards();
}
int NPuzzle::Board::charToint(char number) const{
    int i=0;
    while(number!='0')
        --number,++i;
    return i;
}
bool NPuzzle::Board::move(const char& letter)
{
    bool flag=true;
    set_player_pos();
    switch(letter)
    {
        case 'r':
        case 'R':
            flag=moveRight();
        break;

        case 'l':
        case 'L':
            flag=moveLeft();
            break;

        case 'u':
        case 'U':
            flag=moveUp();
            break;

        case 'd':
        case 'D':
            flag=moveDown();
            break;

        default:
            flag=false;
            break;
    }
    
    if(flag)
        inc_moveNumber(1);
    set_player_pos();
    return flag;
}
bool NPuzzle::move(const char& letter)
{
    bool flag=true;
    if(!gameBoard.move(letter))
        flag=false;

    board_sets.clear();
    board_sets.push_back(gameBoard);
    
    board_sets[0].reset_moveNumber();

    return flag;
}
bool NPuzzle::Board::moveRight(void){
    if((playerX+1)<xSize&&puzzle_map[playerX+1][playerY]!=0)
    {
        puzzle_map[playerX][playerY]=puzzle_map[playerX+1][playerY];
        puzzle_map[playerX+1][playerY]=-1;
        return true;
    }
    return false;
}
bool NPuzzle::Board::moveLeft(void){
    if((playerX-1)>=0&&puzzle_map[playerX-1][playerY]!=0)
    {
        puzzle_map[playerX][playerY]=puzzle_map[playerX-1][playerY];
        puzzle_map[playerX-1][playerY]=-1;
        return true;
    }
    return false;
}
bool NPuzzle::Board::moveUp(void){
    if((playerY-1)>=0&&puzzle_map[playerX][playerY-1]!=0)
    {
        puzzle_map[playerX][playerY]=puzzle_map[playerX][playerY-1];
        puzzle_map[playerX][playerY-1]=-1;
        return true;
    }
    return false;
}
bool NPuzzle::Board::moveDown(void){
    if((playerY+1)<ySize&&puzzle_map[playerX][playerY+1]!=0)
    {
        puzzle_map[playerX][playerY]=puzzle_map[playerX][playerY+1];
        puzzle_map[playerX][playerY+1]=-1;
        return true;
    }
    return false;
}
void NPuzzle::printReport(void) const
{
    cout<<"Total number of moves "<<gameBoard.NumberOfMoves()<<" !"<<endl;
}
void NPuzzle::reset(void)
{
    gameBoard.reset();
    board_sets.clear();
}
void NPuzzle::Board::reset(void)
{
    for(int j=0;j<ySize;++j)
        for(int i=0;i<xSize;++i)
            puzzle_map[i][j]=goal_map[i][j];
}
void NPuzzle::shuffle(const int& n)
{
    int sizeCheck=0;
    reset();

    while(++sizeCheck<=n)
        moveRandom();

    if(gameBoard.isSolved())
        shuffle(n);

    gameBoard.reset_moveNumber();

    board_sets.push_back(gameBoard);
    board_sets[0].inc_number_of_boards();

    return;
}
char NPuzzle::moveRandom(void)
{
    char dirChar='\0';
    int dirInt=rand()%4;

    if(dirInt==right)       dirChar='R';
    else if(dirInt==left)   dirChar='L';
    else if(dirInt==up)     dirChar='U';
    else if(dirInt==down)   dirChar='D';

    if(!gameBoard.move(dirChar))
        moveRandom();

    return dirChar;
}
void NPuzzle::Board::writeToFile(const string& filename)
{
    bool loopFlag=true;
    int maxNumber=0,difNumber=0;

    for(int j=ySize-1;j>=0 && loopFlag;--j)
    {
        for(int i=xSize-1;i>=0 && loopFlag;--i)
        {
            if((goal_map[i][j]!=0)&&(goal_map[i][j]!=-1)){
                maxNumber=goal_map[i][j];
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
            if(puzzle_map[i][j]!=-1)
            {
                if(get_digit(puzzle_map[i][j])==get_digit(maxNumber))
                {
                    if(get_digit(puzzle_map[i][j])==1)
                        outStream<<'0'<<puzzle_map[i][j];
                    else
                        outStream<<puzzle_map[i][j];
                }
                else
                {
                    difNumber=get_digit(maxNumber)-get_digit(puzzle_map[i][j]);

                    for(int k=0;k<difNumber;++k)
                        outStream<<0;
                        
                    outStream<<puzzle_map[i][j];
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
void NPuzzle::writeToFile(const string& filename)
{
    gameBoard.writeToFile(filename);
}
int NPuzzle::Board::get_digit(int number) const
{
    int counter=1;
    while(number/=10)
        ++counter;
    return counter;
}
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
bool NPuzzle::isSolved(void) const
{ 
    return gameBoard.isSolved();
}
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
string NPuzzle::get_file_name(void) const
{
    string filename;
    cout<<"Target Filename: ";
    cin>>filename;
    return filename;
}
void NPuzzle::Board::release_puzzle(void)
{
    if(!(puzzle_map.empty()&&goal_map.empty()))
    {
        puzzle_map.clear();
        goal_map.clear();
    }
    xSize=0;
    ySize=0;
    moveNumber=0;
    filename.clear();
}
void NPuzzle::Board::set_puzzle(void)
{
    puzzle_map.resize(xSize,vector<int>(ySize,-1));
    goal_map.resize(xSize,vector<int>(ySize,-1));
    last_move='S';
}
ostream& operator>>(ostream& outputStream,const NPuzzle& p1)
{
    for(int j=0;j<p1.gameBoard.get_ySize();++j)
    {
        for(int i=0;i<p1.gameBoard.get_xSize();++i)
        {
            if(p1.gameBoard(i,j)==-1) outputStream<<"\t";
            else if(p1.gameBoard(i,j)==0) outputStream<<"\tX";
            else    outputStream<<"\t"<<p1.gameBoard(i,j);
        }
        outputStream << endl<< endl;
    }
    return outputStream;
}
ostream& operator<<(ostream& inputStream,NPuzzle p1)
{
    p1.readFromFile(p1.get_file_name());
    return inputStream;
}
int NPuzzle::Board::operator()(const int& x_pos,const int& y_pos) const
{
    if(x_pos<xSize&&x_pos>=0&&y_pos<ySize&&y_pos>=0)
        return puzzle_map[x_pos][y_pos];
    else
    {
        cout<<"Invalid function parameter input! Error : operator() "<<endl;
        exit(1);
    }
}
bool NPuzzle::Board::operator==(const NPuzzle::Board& b1) const
{
    if(b1.puzzle_map==puzzle_map)
        return true;
    else
        return false;
}
void NPuzzle::solvePuzzle(void)
{
    bool quit=false;
    int i=0;

    vector<char> totalMove;
    Board prev_move_board;

    cout<<"Puzzle has been solving ... \n";
    while(!quit)
    {
        set_scenario_puzzle(board_sets[i],'R',quit);
        set_scenario_puzzle(board_sets[i],'L',quit);
        set_scenario_puzzle(board_sets[i],'U',quit);
        set_scenario_puzzle(board_sets[i],'D',quit);

        ++i;
        if(i%2000==0)
            cout<<"Puzzle Algorithm puts -> "<<board_sets.size()<<" <- different puzzle configuration in it ! \n\n";
        if(i>board_sets[0].NumberOfBoards())
            quit=true;
    }
    if(i<=board_sets[0].NumberOfBoards())
    {
        i=board_sets.size()-1;
        totalMove.push_back(board_sets[i].lastMove());
        while(board_sets[i].lastMove()!='S')
        {
            prev_move_board=board_sets[i];
            if(board_sets[i].lastMove() == 'D'){
                prev_move_board.move('U');
                while(!(prev_move_board == board_sets[i-1]))
                    --i;
            }
            else if(board_sets[i].lastMove() == 'R'){
                prev_move_board.move('L');
                while(!(prev_move_board == board_sets[i-1]))
                    --i;
            }
            else if(board_sets[i].lastMove() == 'U'){
                prev_move_board.move('D');
                while(!(prev_move_board == board_sets[i-1]))
                    --i;
            }
            else if(board_sets[i].lastMove() == 'L'){
                prev_move_board.move('R');
                while(!(prev_move_board == board_sets[i-1]))
                    --i;
            }
            --i;
            totalMove.push_back(board_sets[i].lastMove());
        }

        for(int i=totalMove.size()-1 ; i>=0; --i){
            cout<<totalMove[i]<<endl;
            board_sets[0].move(totalMove[i]);
            board_sets[0].print();
            cout<<endl;
        }
        cout<<"Puzzle can be solved in "<<totalMove.size()-1<<" moves !\n\n";
    }
    else
        cout<<"Puzzle cannot be solvable !"<<endl;
}
bool NPuzzle::set_scenario_puzzle(NPuzzle::Board posBoard,const char& letter,bool& quit)
{
    bool flag=true;
    if(posBoard.move(letter)&&!(is_in_boardsets(posBoard))&&!quit)
    {
        board_sets[0].inc_number_of_boards();
        posBoard.set_last_move(letter);

        if(posBoard.isSolved())
            quit=true;
        board_sets.push_back(posBoard);
    }
    else
        flag=false;
    return flag;
}
bool NPuzzle::is_in_boardsets(const NPuzzle::Board& posBoard) const
{
    bool flag=false;
    for(int i=0;i<board_sets.size()&& !flag ;++i)
        if(board_sets[i]==posBoard)
            flag=true;
    return flag;
}
