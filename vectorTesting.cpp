/*********************************************************************
 * ** Program Filename: checkers.cpp
 * ** Author:jeremy duke
 * ** Date:3/20/2018
 * ** Description:play checkers on a board that can change size
 * ** Input:user chooses the size at launch, and then each player inputs where to move their chips each turn.
 * ** Output:the board, and when the game ends it outputs who won. there are also outputs when you input an invalid move or invalid syntax
 * *********************************************************************/
#include <iostream>
#include <stdlib.h>

using namespace std;
/*********************************************************************
 * ** Function:check_range
 * ** Description:it checks if an int in included in a range. inclusively
 * ** Parameters:int lower_bound,int test_value,int upper_bound
 * ** Pre-Conditions:no
 * ** Post-Conditions:no
 * *********************************************************************/
bool check_range(int lower_bound,int test_value,int upper_bound){
    if ((test_value >= lower_bound)&&(test_value <= upper_bound)){
        return 1;
    }
    return 0;
}
/*********************************************************************
 * ** Function:is_int
 * ** Description:it checks if a string is an int.
 * ** Parameters:string num
 * ** Pre-Conditions:no
 * ** Post-Conditions:no
 * *********************************************************************/
bool is_int(string num){
    if(num == "")
        return 0;
    for(int i=0;i<num.length();i++){
        if (num.empty() || !( check_range( '0' , num[i] , '9') || ((num[i] == '-')&&(i==0)))){
            return 0;
        }
    }
    return 1;
}
/*********************************************************************
 * ** Function:number_to_checker
 * ** Description:changes the int found in the board funciton into the type of checker to be printed to the board
 * ** Parameters:int checker
 * ** Pre-Conditions:no
 * ** Post-Conditions:no
 * *********************************************************************/
string number_to_checker(int checker){
    if(checker == 0)
        return " ";
    if(checker == 1)
        return "x"; //"\033[31mx";
    if(checker == 2)
        return "X"; //"\033[31mX";
    if(checker == 3)
        return "o";
    if(checker == 4)
        return "O";
    return " ";
}
/*********************************************************************
 * ** Function:drawBoard
 * ** Description:it prints out the board with all the current piece placment
 * ** Parameters:int **board, int size
 * ** Pre-Conditions: the board array needs to be declared and initiated
 * ** Post-Conditions: nope, we don't change anything.
 * *********************************************************************/
void drawBoard(int **board, int size, int player){
    int rows = size, cols = size;
    //system("clear");
    cout << "CHECKERS: player " << (string)(player ? "one's turn" : "two's turn") << "\nYou can only move " << (string)(player ? "x or X checkers" : "o or O checkers") << "\n  ";
    for(int i = 0; i < size; i++)
        cout << i+1 << (i<9 ? " " : "");
    cout << endl;
    for(int i=0; i<rows; i++){
        cout << (char)(i+'a') << " ";
        for(int j=0; j<cols; j++) {
            if (i%2 ==j%2)
                cout << /*"\033[0m" <<*/ number_to_checker(board[i][j]) << " ";
            else
                cout << /*"\033[30;47m" <<*/ number_to_checker(board[i][j]) << " ";
            //cout << "\033[0m";
        }
        cout <<endl;
    }

}
/*********************************************************************
 * ** Function:initBoard
 * ** Description:it fills the whole board with the starting pieces
 * ** Parameters:int **board,int size
 * ** Pre-Conditions:the board needs to be declared in heap
 * ** Post-Conditions: we fill it with a number 0-4
 * *********************************************************************/
void initBoard(int **board,int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << i << "  " << j << endl;
            board[i][j] = ( i%2 != j%2 ) ? 0 : ( (i != (size/2)&&i != (size/2)-1) ? ( i > size/2 ? 1 : 3) : 0 );

        }
    }
}
/*********************************************************************
 * ** Function:check_king
 * ** Description:it checks there are any non kings that needs to be kinged and then kings them.
 * ** Parameters:int **board,int size
 * ** Pre-Conditions:the board array needs to be declared and initiated
 * ** Post-Conditions:no
 * *********************************************************************/
void check_king(int **board,int size){
    for(int j =0; j< size; j++){
        if(board[0][j] == 1)
            board[0][j] = 2;
        if(board[size-1][j] == 3)
            board[size-1][j] = 4;
    }
}
/*********************************************************************
 * ** Function:check_ending
 * ** Description:it checks the game should end
 * ** Parameters:int **board,int
 * ** Pre-Conditions:the board array needs to be declared and initiated
 * ** Post-Conditions:no
 * *********************************************************************/
bool check_ending(int **board,int size){
    int x_count=0;
    int o_count=0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(board[i][j] == 3||board[i][j] == 4)
                o_count++;
            if(board[i][j] == 1||board[i][j] == 2)
                x_count++;

        }
    }
    if(x_count == 0 || o_count == 0)
        return 0;
    return 1;
}
/*********************************************************************
 * ** Function:size_finder
 * ** Description:it sees if the command line input is valid and returns it. if it is not, then it shuts down the game.
 * ** Parameters:char size[]
 * ** Pre-Conditions:there needs to something in size[]
 * ** Post-Conditions:no
 * *********************************************************************/
int size_finder(char size[]){
    int tempsize = 0;
    tempsize = atoi(size);
    if (tempsize != 8&&tempsize != 10&&tempsize != 12){
        cout << "wrong size of board inputed";
        exit(0);
    }
    return tempsize;
}
/*********************************************************************
 * ** Function:valid_input
 * ** Description:it checks the string that is inputed by the user is valid format
 * ** Parameters:string user_input,int size
 * ** Pre-Conditions:no
 * ** Post-Conditions:no
 * *********************************************************************/
bool valid_input(string user_input,int size){
    int number_of_things = 0, num_length = 0, number_start = 0, j=0;
    for(int i = 0; i < user_input.length(); i++){
        if(j%2==0){
            if(user_input[i]<'a'||user_input[i]>('a'+size-1))
                return 0;
            j++;
            number_start = i+1;
            num_length = 0;
        }
        else if(j%2==1){
            if(user_input[i]==' '){
                if(is_int(user_input.substr(number_start,num_length))&&check_range(1,atoi(user_input.substr(number_start,num_length).c_str()),size)){
                    j++;
                    number_of_things++;
                }else{
                    return 0;
                }
            }
            num_length++;
        }
    }
    if(j%2==0&&number_of_things>1) return 1;
    return 0;
}
/*********************************************************************
 * ** Function:check_move
 * ** Description:it checks the string that is inputed by the user is a valid move
 * ** Parameters:int number_of_things,int from_i,int from_j,int to_i,int to_j,int **board,int player
 * ** Pre-Conditions:the board array needs to be declared and initiated and the string needs to be formated correctly
 * ** Post-Conditions:no
 * *********************************************************************/
bool check_move( int number_of_things,int from_i,int from_j,int to_i,int to_j,int **board,int player){
    cout << "number of things  is "<< number_of_things << " from(i)(j) " << from_i << "," << from_j<< "to (i)(j)" << to_i<< ","<< to_j<< "   check move :";
    if(number_of_things==1)
        if(board[from_i][from_j] == (player ? 1:3)||board[from_i][from_j] == (player ? 2:4)){
            cout << "first checker works\n";
            return 1;
        }
    if(number_of_things>1){
        if(abs(from_j-to_j)==1&&(from_i-to_i==(1-(player*2)))&&(board[from_i][from_j]==0)){
            cout<< "second check\n";
            return 1;
        }
        if(abs(from_j-to_j)==2&&(from_i-to_i==(2*(1-(player*2))))&&(board[from_i][from_j]==0) && (board[(from_i+to_i)/2][(from_j+to_j)/2] == (player ? 3:1) || board[(from_i+to_i)/2][(from_j+to_j)/2] == (player ? 4:2)))
            return 1;
    }

    return 0;
}
/*********************************************************************
 * ** Function:valid_moves
 * ** Description:it seperates the moves from teh input string to be checked by move_check
 * ** Parameters:string user_input,int size, int **board, int player
 * ** Pre-Conditions:the board array needs to be declared and initiated and the string needs to be formated correctly
 * ** Post-Conditions:no
 * *********************************************************************/
bool valid_moves(string user_input,int size, int **board, int player){
    cout << "checking valid moves\n";
    int number_of_things = 0, num_length = 0, number_start = 0, j=0, from_i = 0, from_j = 0, to_i = 0, to_j = 0;
    bool flag = false;
    for(int i = 0; i < user_input.length(); i++){
        if(j%2==0){
            from_i = (int)(user_input[i]-'a');
            j++;
            number_start = i+1;
            num_length = 0;
        }
        else if(j%2==1){
            if(user_input[i]==' '){
                from_j = atoi(user_input.substr(number_start,num_length).c_str())-1;
                j++;
                number_of_things++;
                flag = check_move(number_of_things,from_i,from_j,to_i,to_j,board,player);
                cout << flag << endl;
                to_i = from_i;
                to_j = from_j;
            }
            num_length++;
        }

    }
    return flag;
}
/*********************************************************************
 * ** Function:move
 * ** Description:it moves the checkers and removes jumped checkers
 * ** Parameters:int from_i,int from_j,int to_i,int to_j, int **board
 * ** Pre-Conditions: and the to and from i and j need to be valid inputs, else there could be a segmentation fault.the board array needs to be declared and initiated and the string needs to be formated correctly
 * ** Post-Conditions:no
 * *********************************************************************/
void move(int from_i,int from_j,int to_i,int to_j, int **board){
    board[to_i][to_j] = board[from_i][from_j];
    board[from_i][from_j]=0;
    if(abs(from_i-to_i)==2 && abs(from_j-to_j)==2){
        cout << "took one piece at: "<< abs((from_i-to_i)/2) << abs((from_j-to_j)/2);
        board[abs((from_i+to_i)/2)][abs((from_j+to_j)/2)]=0;
    }
}
/*********************************************************************
 * ** Function:move_main
 * ** Description:it prepares the to and from i and j to be moves by move()
 * ** Parameters:string user_input, int size, int **board
 * ** Pre-Conditions:the board array needs to be declared and initiated
 * ** Post-Conditions:no
 * *********************************************************************/
void move_main(string user_input, int size, int **board){
    int number_of_things = 0, num_length = 0, number_start = 0, j=0, from_i = 0, from_j = 0, to_i = 0, to_j = 0;
    for(int i = 0; i < user_input.length(); i++){
        if(j%2==0){
            to_i = (int)(user_input[i]-'a');
            j++;
            number_start = i+1;
            num_length = 0;
        }
        else if(j%2==1){
            if(user_input[i]==' '){
                to_j = atoi(user_input.substr(number_start,num_length).c_str())-1;
                j++;
                number_of_things++;
                if(number_of_things>1)
                    move(from_i,from_j,to_i,to_j,board);
                from_i = to_i;
                from_j = to_j;
            }
            num_length++;
        }

    }

}
/*********************************************************************
 * ** Function:turn
 * ** Description:it runs each turn( gets input, checks input, checks move, moves, prints board) i pretty much use this as my main() lol.
 * ** Parameters:int **board,int size,int player
 * ** Pre-Conditions:the board array needs to be declared and initiated
 * ** Post-Conditions:no
 * *********************************************************************/
void turn(int **board,int size,int player){

    char str[256];
    cin.getline(str,255);
    std::string user_input = str;
    user_input += " ";
    if(valid_input(user_input,size)&&valid_moves(user_input,size,board,player)){
        move_main(user_input,size,board);
        check_king(board,size);

    }else{
        cout << "invalid move try again";
        turn(board,size,player);
        //drawBoard(board,size,player);
    }
}
/*********************************************************************
 * ** Function:quit
 * ** Description:it gets around correct type specification by making an int type that quits the game. This is honestly so jank... but it works
 * ** Parameters:nope
 * ** Pre-Conditions:no
 * ** Post-Conditions:quits
 * *********************************************************************/
int quit(){
    cout << "wrong number of inputs";
    exit(0);
    return 0;
}
/*********************************************************************
 * ** Function:main
 * ** Description:main() that creates all the variables and dynamic memory for the game then runs the turns and checks if the game should end.
 * ** Parameters:int argc, char *argv[]
 * ** Pre-Conditions:there need to be valid inputs in the command line arguments. but lets be honest, you guys are going to try everything to break all my valid input filters and in sure that you will find a way.
 * ** Post-Conditions:hopefully all the dynamic variables are deleted.
 * *********************************************************************/
int main(int argc, char *argv[]){
    //int size = (argc==2 ? size_finder(argv[1]) : quit()), player = 0;;
    int size = 10, player = 0;
    int ** array = new int*[size];
    for(int i = 0; i < size; i++){
        array[i] = new int[size];
    }
    initBoard(array,size);
    drawBoard(array,size, player%2);
    while(check_ending(array,size)){
        player++;
        drawBoard(array,size, player%2);
        turn(array,size,player%2);
        cout << "changing player";
    }
    for(int i = 0; i < size; i++){
        delete [] array[i];
    }
    delete [] array;
}

