/***************************************
 ** Program Filename: hw6.cpp
 ** Author: Luke Puppo
 ** Date: 3/18/18
 ** Description: Plays the game Checkers
 ** Input: Various text inputs
 ** Output: A game of checkers
 **************************************/
#include <iostream>
#include <string>
#include <cstdlib> //atoi
#include <cmath>
#include <vector>
#include <cstdio> //For printf functionallity

using namespace std;

/***********************************
 ** Function: clearScreen
 ** Description: Clears the screen
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: A clear screen
 ***********************************/
void clearScreen(){
    printf("\033c");
}


/***********************************
 ** Function: getchar
 ** Description: changes an int to a string for board
 ** Parameters: int
 ** Pre-Conditions: int is good
 ** Post-Conditions: returns a string
 ***********************************/
string getchar(int i){
    switch(i){
        case 0:
            return " "; break;
        case 1:
            return "\033[31mx"; break;
        case 2:
            return "\033[37mo"; break;
        case 3:
            return "\033[31mX"; break;
        case 4:
            return "\033[37mO"; break;
        default:
            return " "; break;
    }
}

/***********************************
 ** Function: printTop
 ** Description: prints the top of the user array
 ** Parameters: int
 ** Pre-Conditions: size exists
 ** Post-Conditions: none
 ***********************************/
void printTop(int size){
    string output = size < 10 ? "   " : "    ";

    for(int i = 0; i < size; i++){
        char letter = (i + 65);
        output += letter;
        output += "   ";
    }
    cout<<output<<endl;
}

/***********************************
 ** Function: drawBoard
 ** Description: draws board with a prompt
 ** Parameters: string, int**, int
 ** Pre-Conditions: all exist
 ** Post-Conditions: draws the board
 ***********************************/
void drawBoard(string prompt, int **board, int size){
    clearScreen();
    printTop(size);
    for(int i=0; i<size; i++){
        string temp = size == 8 ? "" : i+1 < 10 ? " " : "";
        cout<< i+1 << temp;
        for(int j=0; j<size; j++) {
            string piece = getchar(board[i][j]);
            if (i%2 == 0 && j%2 == 0)
                cout << "|\033[30;47m " << piece << " ";
            else if (i%2 == 1 && j%2 == 1)
                cout << "|\033[30;47m " << piece << " ";
            else
                cout << "|\033[0m " << piece << " ";
            cout << "\033[0m";
        }
        cout << endl;
    }
    cout<<prompt<<endl;
}

/***********************************
 ** Function: drawBoard
 ** Description: draws board without a prompt
 ** Parameters: int **, int
 ** Pre-Conditions: variables exist
 ** Post-Conditions: draw board
 ***********************************/
//Currently draws a board successfully
void drawBoard(int **board, int size){
    clearScreen();
    printTop(size);
    for(int i=0; i<size; i++){
        string temp = size == 8 ? "" : i+1 < 10 ? " " : "";
        cout<< i+1 << temp;
        for(int j=0; j<size; j++) {
            string piece = getchar(board[i][j]);
            if (i%2 == 0 && j%2 == 0)
                cout << "|\033[30;47m " << piece << " ";
            else if (i%2 == 1 && j%2 == 1)
                cout << "|\033[30;47m " << piece << " ";
            else
                cout << "|\033[0m " << piece << " ";
            cout << "\033[0m";
        }
        cout << endl;
    }
}

/***********************************
 ** Function: initBoard
 ** Description: sets the values in the board
 ** Parameters: int **, int
 ** Pre-Conditions: both exist
 ** Post-Conditions: an init board
 ***********************************/
void initBoard(int **board, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            board[i][j] = (i < (size/2-1)) && (i%2 != j%2) ? 1 : (i > size/2) && (i%2 != j%2) ? 2 : 0;
        }
    }
}

/***********************************
 ** Function: movePiece
 ** Description: Moves a piece
 ** Parameters: int **, int, int, int, int, int
 ** Pre-Conditions: things exist
 ** Post-Conditions: a piece is moved
 ***********************************/
//Rows are numbers, cols are letters, needs input as two ints converted
//Assumes  the move to be valid
void movePiece(int **board, int size, int fromCol, int fromRow, int toCol, int toRow){
    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = 0;
    if(board[toRow][toCol] == 2 && toRow == 0)
        board[toRow][toCol] = 4;
    else if(board[toRow][toCol] == 1 && toRow == size-1)
        board[toRow][toCol] = 3;

}

/***********************************
 ** Function: getMiddleCords
 ** Description: gets the coords for the jumped piece
 ** Parameters: int *, int *, int, int
 ** Pre-Conditions: all exist
 ** Post-Conditions: two middle coords
 ***********************************/
void getMiddleCords(int *mcol, int *mrow, int fromCol, int fromRow, int toCol, int toRow){
    if(fromRow > toRow && fromCol < toCol){
        (*mrow) = fromRow-1;
        (*mcol) = fromCol+1;
    }
    else if(fromRow > toRow && fromCol > toCol){
        (*mrow) = fromRow-1;
        (*mcol) = fromCol-1;
    }
    else if(fromRow < toRow && fromCol < toCol){
        (*mrow) = fromRow+1;
        (*mcol) = fromCol+1;
    }
    else if(fromRow < toRow && fromCol > toCol){
        (*mrow) = fromRow+1;
        (*mcol) = fromCol-1;
    }
}

/***********************************
 ** Function: jumpPiece
 ** Description: jumps a piece
 ** Parameters: int**. size, vector<int>
 ** Pre-Conditions: Things exist
 ** Post-Conditions: A piece is jumped
 ***********************************/
void jumpPiece(int **board, int size, vector<int> userMovesVector){
    int mrow = 0;
    int mcol = 0;
    for(int i = 0; i < userMovesVector.size() - 2; i+=2){
        movePiece(board, size, userMovesVector[i], userMovesVector[i+1], userMovesVector[i+2], userMovesVector[i+3]);
        getMiddleCords(&mcol, &mrow, userMovesVector[i], userMovesVector[i+1], userMovesVector[i+2], userMovesVector[i+3]);
        board[mrow][mcol] = 0;
    }
}

/***********************************
 ** Function: isNonKingMoveValid
 ** Description: Checks if move is valid for non king piece
 ** Parameters: int **, int, int, int, int, int
 ** Pre-Conditions: All exist
 ** Post-Conditions: Boolean
 ***********************************/
//player = 0 -- player1     O  BOT
//player = 1 -- player2     X  TOP
//Assumes passed is not a king
//Assumes passed are in bounds of game
bool isNonKingMoveValid(int** board, int player, int fromCol, int fromRow, int toCol, int toRow){
    //cout<<"inside isNonKing"<<endl;
    int piece = board[fromRow][fromCol];
    if(piece && (piece%2 == player)){//Checks if piece exists and is right player
        if(piece == 1){//x{
            if(!(toRow%2 == 0 && toCol%2 == 0) && !(toRow%2 == 1 && toCol%2 == 1) && (toRow > fromRow)){
                if(abs(toCol - fromCol) == 1 && (toRow == fromRow+1) && board[toRow][toCol] == 0){
                    return true;
                }
            }
        }

        else if(piece == 2){ //o
            if(!(toRow%2 == 0 && toCol%2 == 0) && !(toRow%2 == 1 && toCol%2 == 1) && (toRow < fromRow))
                if(abs(toCol - fromCol) == 1 && (toRow == fromRow-1) && board[toRow][toCol] == 0)
                    return true;
        }
    }
    return false;
}

/***********************************
 ** Function: isNonKingJumpValid
 ** Description: Determines if jump is valid for non king piece
 ** Parameters: int **, int, bool, int, int, int, int
 ** Pre-Conditions: All exist
 ** Post-Conditions: Boolean
 ***********************************/
//player = 0 -- player1     O  BOT
//player = 1 -- player2     X  TOP
bool isNonKingJumpValid(int** board, int player, bool multiJumps, int fromCol, int fromRow, int toCol, int toRow){
    int piece = board[fromRow][fromCol];
    if(multiJumps)
        piece = player % 2 == 0 ? 2 : 1;
    int mrow = 0;
    int mcol = 0;
    if(multiJumps || (piece && (piece%2 == player))){//Checks if piece exists and is right player
        getMiddleCords(&mcol, &mrow, fromCol, fromRow, toCol, toRow);
        if(piece == 1){//x{
            if(!(toRow%2 == 0 && toCol%2 == 0) && !(toRow%2 == 1 && toCol%2 == 1) && (toRow > fromRow)){
                if(abs(toCol - fromCol) == 2 && (toRow == fromRow+2) && board[toRow][toCol] == 0 && board[mrow][mcol] % 2 == 0 && board[mrow][mcol] != 0){
                    return true;
                }
            }
        }
        else if(piece == 2){ //o
            if(!(toRow%2 == 0 && toCol%2 == 0) && !(toRow%2 == 1 && toCol%2 == 1) && (toRow < fromRow))
                if(abs(toCol - fromCol) == 2 && (toRow == fromRow-2) && board[toRow][toCol] == 0 && board[mrow][mcol] % 2 == 1)
                    return true;
        }
    }
    return false;
}

/***********************************
 ** Function: isKingMoveValid
 ** Description: Checks if move is valid for king piece
 ** Parameters: int **, int, int, int, int, int, int
 ** Pre-Conditions: all exist
 ** Post-Conditions: Boolean
 ***********************************/
bool isKingMoveValid(int **board, int player, int fromCol, int fromRow, int toCol, int toRow){
    //3 is X, 4 is 0
    int piece = board[fromRow][fromCol];
    if(piece < 3)
        return isNonKingMoveValid(board,player,fromCol,fromRow,toCol,toRow);

    if(piece && (piece%2 == player)){//Checks if piece exists and is right player
        if(!(toRow%2 == 0 && toCol%2 == 0) && !(toRow%2 == 1 && toCol%2 == 1)){
            if(abs(toCol - fromCol) == 1 && (abs(toRow - fromRow) == 1) && board[toRow][toCol] == 0){
                return true;
            }
        }
    }
    return false;
}

/***********************************
 ** Function: isKingJumpValid
 ** Description: Checks if jump is valid for a king piece
 ** Parameters: int **, int, bool, int, int, int, int
 ** Pre-Conditions: All exist
 ** Post-Conditions: boolean
 ***********************************/
bool isKingJumpValid(int **board, int player, bool multiJumps, int fromCol, int fromRow, int toCol, int toRow){
    int piece = board[fromRow][fromCol];
    if(multiJumps)
        piece = player % 2 == 0 ? 4 : 3;
    int mrow = 0;
    int mcol = 0;
    if(multiJumps || (piece && (piece%2 == player))){//Checks if piece exists and is right player
        getMiddleCords(&mcol, &mrow, fromCol, fromRow, toCol, toRow);
        if(piece == 3){//x{
            if(!(toRow%2 == 0 && toCol%2 == 0) && !(toRow%2 == 1 && toCol%2 == 1)){
                if(abs(toCol - fromCol) == 2 && board[toRow][toCol] == 0 && board[mrow][mcol] % 2 == 0 && board[mrow][mcol] != 0){
                    return true;
                }
            }
        }
        else if(piece == 4){ //o
            if(!(toRow%2 == 0 && toCol%2 == 0) && !(toRow%2 == 1 && toCol%2 == 1))
                if(abs(toCol - fromCol) == 2 && board[toRow][toCol] == 0 && board[mrow][mcol] % 2 == 1)
                    return true;
        }
    }
    return false;

}

/***********************************
 ** Function: getUserInput
 ** Description: Gets the user input
 ** Parameters: None
 ** Pre-Conditions: Takes a c-style string
 ** Post-Conditions: Returns String
 ***********************************/
string getUserInput(){
    char cinput[256];
    cin.getline(cinput, 256);
    string input = cinput;
    if(input.length() < 5){
        cout<<"Bad input"<<endl;
        input = getUserInput();
    }
    return input;
}

/***********************************
 ** Function: chopStrToVector
 ** Description: Converts string to vector
 ** Parameters: string
 ** Pre-Conditions: string is populated
 ** Post-Conditions: vector<string>
 ***********************************/
vector<string> chopStrToVector(string str){
    str += " ";
    vector<string> rawVector;
    string tempStr = "";

    for(int i = 0; i < str.length(); i++){
        if(str.substr(i,1) != " "){
            tempStr += str.substr(i,1);
        }
        else{
            if(tempStr != ""){
                rawVector.push_back(tempStr);
                //cout<<"Element " << i << ": " << tempStr<<endl;
                tempStr = "";
            }
        }
    }
    return rawVector;
}

/***********************************
 ** Function: isVectorElementValid
 ** Description: checks to insure each element is correct
 ** Parameters: string, int
 ** Pre-Conditions: string is populated
 ** Post-Conditions: boolean
 ***********************************/
bool isVectorElementValid(string str,int arraySize){
    if(str.length() > 0 && str.length() <= 3){
        if(str[0] >= 'A' && str[0] <= 'L'){
            if(str.length() == 3 && arraySize == 10 && str[0] <= 'J'){
                if((str[1] > '0' && str[1] <= '1') && (str[2] == '0')){
                    return true;
                }
            }
            if(str.length() == 3 && arraySize == 12 && str[0] <= 'L'){
                if((str[1] >= '0' && str[1] <= '1') && (str[2] >= '0' && str[2] <= '2')){
                    return true;
                }
            }
            else if(str.length() == 2 && (str[1] > '0' && str[1] <= '8')){
                if((arraySize == 8 && str[0] <= 'H') || (arraySize == 10 && str[0] <= 'J') || (arraySize == 12 && str[0] <= 'L'))
                    return true;
            }
        }
    }
    return false;
}

/***********************************
 ** Function: verifyVector
 ** Description: verifys the vector is correct format
 ** Parameters: vector<string>, int
 ** Pre-Conditions: all exist and have values
 ** Post-Conditions: boolean
 ***********************************/
bool verifyVector(vector<string> choppedStr, int arraySize){
    if(choppedStr.size() <= 1)
        return false;
    for(int i = 0; i < choppedStr.size(); i++){
        if(isVectorElementValid(choppedStr[i], arraySize))
            continue;
        else{
            return false;
        }
    }
    string temp = "";
    for(int i = 0; i < choppedStr.size()-1; i++){
        temp = choppedStr[i];
        for(int j = i+1; j < choppedStr.size(); j++){
            if(choppedStr[j] == temp)
                return false;
        }
    }
    return true;
}

/***********************************
 ** Function: splitIntoMoves
 ** Description: splits a vector into moves
 ** Parameters: vector<string>
 ** Pre-Conditions: vector<string> is filled and verified
 ** Post-Conditions: vector<int>
 ***********************************/
vector<int> splitIntoMoves(vector<string> choppedVector){
    vector<int> movesVector;
    for(int i = 0; i < choppedVector.size(); i++){
        movesVector.push_back(choppedVector[i][0]-65);
        string temp = choppedVector[i].substr(1,choppedVector[i].length()-1);
        movesVector.push_back(atoi(temp.c_str())-1);
    }
    return movesVector;
}

/***********************************
 ** Function: checkIfValidMovesLeft
 ** Description: checks if there are any valid moves left
 ** Parameters: int **, int, int
 ** Pre-Conditions: all exist
 ** Post-Conditions: boolean
 ***********************************/
bool checkIfValidMovesLeft(int **board, int size, int player){
    int piece;
    bool flag = false;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            piece = board[i][j] == 2 || board[i][j] == 4 ?
                    board[i][j] : board[i][j] == 1 || board[i][j] == 3 ?
                    board[i][j] : 0;
            if(player == 0 && (piece == 2 || piece == 4)){
                for(int k = 0; k < size; k++){
                    for(int l = 0; l < size; l++){
                        if((isNonKingMoveValid(board, player, j, i, k, l) && piece < 3) ||
                           (isNonKingJumpValid(board, player, false, j, i, k, l) && piece < 3) ||
                           (isKingMoveValid(board, player, j, i, k, l) && piece > 2) ||
                           (isKingJumpValid(board, player, false, j, i, k, l)  && piece > 2))
                            flag = true;
                    }
                }
            }
            else if(player == 1 && piece %2 == 1){
                for(int k = 0; k < size; k++){
                    for(int l = 0; l < size; l++){
                        if((isNonKingMoveValid(board, player, j, i, k, l) && piece < 3) ||
                           (isNonKingJumpValid(board, player, false, j, i, k, l) && piece < 3) ||
                           (isKingMoveValid(board, player, j, i, k, l) && piece > 2) ||
                           (isKingJumpValid(board, player, false, j, i, k, l)  && piece > 2))
                            flag = true;
                    }
                }
            }
        }
    }
    return flag;
}

/***********************************
 ** Function: isAnyValidMovesLeft
 ** Description: checks valid moves for both players
 ** Parameters: int **, int
 ** Pre-Conditions: things exist
 ** Post-Conditions: int that is used for win/loss function
 ***********************************/
int isAnyValidMovesLeft(int **board, int size){
    bool player1MovesLeft = checkIfValidMovesLeft(board,size,0);
    bool player2MovesLeft = checkIfValidMovesLeft(board,size,1);

    if(!player1MovesLeft){
        return 0;
    }
    else if(!player2MovesLeft){
        return 1;
    }
    else if(player1MovesLeft && player2MovesLeft){
        return 2;
    }
    return 3;
}

/***********************************
 ** Function: getUserInputVectorDone
 ** Description: gets the finalized vector of moves
 ** Parameters: int array
 ** Pre-Conditions: none
 ** Post-Conditions: vector<int>
 ***********************************/
vector<int> getUserInputVectorDone(int arraySize){
    vector<string> userVector = chopStrToVector(getUserInput());
    verifyVector(userVector,arraySize);
    vector<int> userMovesVector = splitIntoMoves(userVector);
    return userMovesVector;
}

/***********************************
 ** Function: jumpCheck
 ** Description: Insures full jump is correct
 ** Parameters: int **, int , int, vector<int>
 ** Pre-Conditions: all exist
 ** Post-Conditions: boolean
 ***********************************/
bool jumpCheck(int **board, int piece, int player, vector<int> userMovesVector){
    if(userMovesVector.size() % 2 != 0)
        return false;
    int startIndexMoveOne = 0;
    int startIndexMoveTwo = 2;
    bool flag = false, multiJumps = false;
    for(int i = 4; i <= userMovesVector.size(); i += 2){
        if(i > 4)
            multiJumps = true;
        if(!(isNonKingJumpValid(board, player, multiJumps, userMovesVector[startIndexMoveOne],userMovesVector[startIndexMoveOne + 1],userMovesVector[startIndexMoveTwo],userMovesVector[startIndexMoveTwo + 1]) && piece < 3) && !(isKingJumpValid(board, player, multiJumps, userMovesVector[startIndexMoveOne],userMovesVector[startIndexMoveOne + 1],userMovesVector[startIndexMoveTwo],userMovesVector[startIndexMoveTwo + 1]) && piece > 2)){
            return false;
        }else{
            startIndexMoveOne += 2;
            startIndexMoveTwo += 2;
            flag = true;
            continue;
        }
    }
    return flag;
}

/***********************************
 ** Function: playerTurn
 ** Description: Does a full player turn
 ** Parameters: int **, int, int
 ** Pre-Conditions: all exist
 ** Post-Conditions: boolean for next turn
 ***********************************/
bool playerTurn(int **array, int arraySize, int player){
    string playerPrompt = player == 0 ? "Player 1: " : "Player 2: ";
    drawBoard(playerPrompt, array, arraySize);
    vector<int> userMovesVector = getUserInputVectorDone(arraySize);
    int piece = array[userMovesVector[1]][userMovesVector[0]];

    bool flag = false;

    while(!flag){
        if(isNonKingMoveValid(array, player, userMovesVector[0],userMovesVector[1],userMovesVector[2],userMovesVector[3]) || isKingMoveValid(array, player, userMovesVector[0], userMovesVector[1], userMovesVector[2], userMovesVector[3])){
            cout<<"worked"<<endl;
            movePiece(array, arraySize, userMovesVector[0],userMovesVector[1],userMovesVector[2],userMovesVector[3]);
            flag = true;
        }
        else if(jumpCheck(array, piece, player, userMovesVector)){
            jumpPiece(array, arraySize, userMovesVector);
            flag = true;
        }
        else{
            drawBoard("Bad user input. Format like 'A1 B2'", array, arraySize);
            userMovesVector = getUserInputVectorDone(arraySize);
        }
    }
    return flag;
}

/***********************************
 ** Function: doWinText
 ** Description: Displays win text
 ** Parameters: int
 ** Pre-Conditions: whoLost exists
 ** Post-Conditions: a print statement
 ***********************************/
void doWinText(int whoLost){
    int whoWon = 0;
    whoWon = whoLost == 0 ? 2 : whoLost == 1 ? 1 : 0;
    cout<< "Player " << whoWon << " won! " <<endl;

}

/***********************************
 ** Function: game
 ** Description: plays the game
 ** Parameters: int **, int
 ** Pre-Conditions: both exist
 ** Post-Conditions: plays the game, returns win condition
 ***********************************/
int game(int **array, int arraySize){
    int currentPlayer = 0, whoLost = 2;
    while(whoLost == 2){
        int moveCondition = isAnyValidMovesLeft(array, arraySize);
        if(moveCondition == 2){
            playerTurn(array, arraySize, currentPlayer);
            currentPlayer = currentPlayer == 0 ? 1 : 0;
        }
        else if(moveCondition == 0)//means player 1 ran out of moves
            whoLost = 0;
        else if(moveCondition == 1)//means player 2 ran out of moves
            whoLost = 1;
    }
}

void deleteBoard(int **array, int arraySize){
    for(int i = 0; i < arraySize; i++){
        delete [] array[i];
    }

    delete [] array;
}

/***********************************
 ** Function: main
 ** Description: Sets up and runs checkers
 ** Parameters: int, char **
 ** Pre-Conditions: Handles all starts
 ** Post-Conditions: Game is won
 ***********************************/
int main(int argc, char** argv){
    if(argc != 2){
        cout<<"Incorrect arguments supplied. Check the Readme for more information."<<endl;
        return 0;
    }
    int arraySize = atoi(argv[1]) == 8 || atoi(argv[1]) == 10 || atoi(argv[1]) == 12 ? atoi(argv[1]) : 0;
    if(arraySize == 0)
        return 0;

    int **array = new int*[arraySize];
    for(int i = 0; i < arraySize; i++){
        array[i] = new int[arraySize];
    }
    initBoard(array,arraySize);
    drawBoard("Player 1: ",array,arraySize);

    string move = "";
    cout<<"Past move"<<endl;

    int whoLost = game(array, arraySize);

    drawBoard("", array, arraySize);
    doWinText(whoLost);
    deleteBoard(array,arraySize);
}
