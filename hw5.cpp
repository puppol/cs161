/*********************************************************************
 ** Program Filename: Farkle
 ** Author: Luke Puppo
 ** Date: 3/4/18
 ** Description: Plays the game of Farkle
 ** Input: string inputs
 ** Output: The game of Farkle
 *********************************************************************/
#include <iostream>
#include <assert.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
#include <sstream>
#include <cstdio> //For printf functionallity

using namespace std;

/*********************************************************************
 ** Function: clearScreen
 ** Description: Clears the screen
 ** Parameters: None
 ** Pre-Conditions: Program is running
 ** Post-Conditions: Screen is clear
 *********************************************************************/
int clearScreen(){
    printf("\033c");
    return 1;
}

/*********************************************************************
 ** Function: rollDice
 ** Description: rolls the vector of dice
 ** Parameters: vector of type int
 ** Pre-Conditions: vector exists
 ** Post-Conditions: dice filled with random numbers
 *********************************************************************/
void rollDice(vector<int>& diceVector){
    srand(time(NULL));
    for(int i = 0; i < diceVector.size(); i++){
        diceVector[i] = rand() % 6 + 1;
    }
}

/*********************************************************************
 ** Function: displayDice
 ** Description: Outputs the dice to the user
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void displayDice(vector<int>& diceToDisplay){
    //Print out index and dice values
    cout<<"Index you put in: "<<endl;
    for(int i = 0; i < diceToDisplay.size(); i++){
        cout<<i+1 << " ";
    }
    cout<<endl;
    cout<<"The current dice pool to choose from: "<<endl;
    for(int i = 0; i < diceToDisplay.size(); i++){
        cout<<diceToDisplay[i] << " ";
    }
    cout<<endl;
}

/*********************************************************************
 ** Function: getDieCounts
 ** Description: gets the count of all of the die in the pool
 ** Parameters: vector of type int
 ** Pre-Conditions: vector has stuff
 ** Post-Conditions: a vector with the counts of stuff
 *********************************************************************/
vector<int> getDieCounts(vector<int> diceToCheck){
    vector<int> dieCounts(6);
    for(int i = 0; i < dieCounts.size(); i++){
        for(int j = 0; j < diceToCheck.size(); j++){
            if(diceToCheck[j] == i+1)
                dieCounts[i] += 1;
        }
    }
    return dieCounts;
}

/*********************************************************************
 ** Function: scoreOne
 ** Description: scores based off of one die
 ** Parameters: vector
 ** Pre-Conditions: vector has size one
 ** Post-Conditions: an int of score
 *********************************************************************/
int scoreOne(vector<int> userDice){
    int score = 0;
    score += userDice[0] == 1 ? 100 : 0;
    score += userDice[0] == 5 ? 50 : 0;
    return score;
}

/*********************************************************************
 ** Function: scorTwo
 ** Description: scores two dice
 ** Parameters: vector and bool
 ** Pre-Conditions: user dice is of size two
 ** Post-Conditions: returns score
 *********************************************************************/
int scoreTwo(vector<int> userDice,bool farkleCheck){
    int score = 0;
    for(int i = 0; i < userDice.size(); i++){
        int tempScore = 0;
        tempScore += userDice[i] == 1 ? 100 : 0;
        tempScore += userDice[i] == 5 ? 50 : 0;
        if(tempScore == 0  && farkleCheck==false)
            return 0;
        score += tempScore;
    }
    return score;
}

/*********************************************************************
 ** Function: scoreThree
 ** Description: scores three dice
 ** Parameters: vector and bool
 ** Pre-Conditions: user dice is of size three
 ** Post-Conditions: returns score
 *********************************************************************/
int scoreThree(vector<int> userDice,bool farkleCheck){
    int score = 0;
    vector<int> diceCounts = getDieCounts(userDice);
    for(int i = 0; i < diceCounts.size(); i++){
        int tempScore = 0;
        if(diceCounts[i] == 3){
            tempScore += (i == 0) ? 300 : 0;
            tempScore += (i != 0) ? (i+1) * 100 : 0;
        }
        else if(diceCounts[i] == 2){
            tempScore += (i == 0) ? 200 : 0;
            tempScore += (i == 4) ? 100 : 0;
        }
        else if(diceCounts[i] == 1){
            tempScore += i == 0 ? 100 : 0;
            tempScore += i == 4 ? 50 : 0;
        }
        if(tempScore == 0 && diceCounts[i] != 0  && farkleCheck==false)
            return 0;
        score += tempScore;
    }
    return score;
}

/*********************************************************************
 ** Function: eraseDie
 ** Description: erases a vector with elements = -1
 ** Parameters: vector
 ** Pre-Conditions: dice has stuff
 ** Post-Conditions: returns a cleaned dice vector
 *********************************************************************/
vector<int> eraseDie(vector<int> die){
    vector<int> dieFinal;
    for(int i = 0; i < die.size(); i++)
        if(die[i] != -1){
            dieFinal.push_back(die[i]);
        }
    return dieFinal;
}

/*********************************************************************
 ** Function: cleanDiePool
 ** Description: cleans a pool based off of another vector
 ** Parameters: vector, vector
 ** Pre-Conditions: both vectors have elements
 ** Post-Conditions: a cleaned pool
 *********************************************************************/
vector<int> cleanDiePool(vector<int> dicePool, vector<int>dieToRemove){
    vector<int> dieFinal(0);
    for(int i = 0; i < dieToRemove.size(); i++){
        for(int j = 0; j < dicePool.size(); j++){
            if(dicePool[j] == dieToRemove[i] && i < dieToRemove.size()){
                dicePool[j] = -1;
                i+=1;
            }
        }
    }
    dieFinal = eraseDie(dicePool);
    return dieFinal;
}

/*********************************************************************
 ** Function: popDie
 ** Description: pops bad die
 ** Parameters: reference, int
 ** Pre-Conditions: things exist
 ** Post-Conditions: stuff happens
 *********************************************************************/
vector<int> popDie(vector<int> &die, int valueToPop){
    vector<int> poppedDie(0);
    vector<int> dieCopy = die;
    for(int i = 0; i < dieCopy.size(); i++){
        if(dieCopy[i] == valueToPop){
            poppedDie.push_back(dieCopy[i]);
            dieCopy[i] = -1;
        }
    }
    dieCopy = eraseDie(dieCopy);
    die = dieCopy;
    return poppedDie;
}

/*********************************************************************
 ** Function: scoreFour
 ** Description: scores based off of four functions
 ** Parameters: vector, bool
 ** Pre-Conditions: vector is filled
 ** Post-Conditions: returns score
 *********************************************************************/
int scoreFour(vector<int> userDice,bool farkleCheck){
    int score = 0;
    vector<int> diceCounts = getDieCounts(userDice);
    for(int i = 0; i < diceCounts.size(); i++){
        int tempScore = 0;
        if(diceCounts[i] == 4)
            return 1000;
        else if(diceCounts[i] == 3)
            score += scoreThree(popDie(userDice, i+1),farkleCheck);
        else if(diceCounts[i] == 2)
            tempScore += scoreTwo(popDie(userDice, i+1),farkleCheck);
        else if(diceCounts[i] == 1)
            tempScore += scoreOne(popDie(userDice, i+1));
        if(tempScore == 0 && diceCounts[i] != 0  && farkleCheck==false)
            return 0;
        score += tempScore;
    }
    return score;
}

/*********************************************************************
 ** Function: scoreFive
 ** Description:
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
int scoreFive(vector<int> userDice,bool farkleCheck){
    int score = 0;
    vector<int> diceCounts = getDieCounts(userDice);
    for(int i = 0; i < diceCounts.size(); i++){
        int tempScore = 0;
        if(diceCounts[i] == 5)
            return 2000;
        else if(diceCounts[i] == 4)
            tempScore += scoreFour(popDie(userDice, i+1),farkleCheck);
        else if(diceCounts[i] == 3)
            tempScore += scoreThree(popDie(userDice, i+1),farkleCheck);
        else if(diceCounts[i] == 2)
            tempScore += scoreTwo(popDie(userDice, i+1),farkleCheck);
        else if(diceCounts[i] == 1)
            tempScore += scoreOne(popDie(userDice, i+1));
        if(tempScore == 0 && diceCounts[i] != 0  && farkleCheck==false)
            return 0;
        score += tempScore;
    }

    return score;
}

/*********************************************************************
 ** Function:
 ** Description:
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
int scoreSix(vector<int> userDice,bool farkleCheck){
    int score = 0;
    vector<int> diceCounts = getDieCounts(userDice);
    if((diceCounts[0] == 1 && diceCounts[1] == 1 && diceCounts[2] == 1 && diceCounts[3] == 1 && diceCounts[4] == 1 && diceCounts[5] == 1)){
        return 1500;
    }
    for(int i = 0; i < diceCounts.size(); i++){
        int tempScore = 0;
        if(diceCounts[i] == 6)
            return 3000;
        else if(diceCounts[i] == 5)
            tempScore += scoreFive(popDie(userDice, i+1),farkleCheck);
        else if(diceCounts[i] == 4)
            tempScore += scoreFour(popDie(userDice, i+1),farkleCheck);
        else if(diceCounts[i] == 3)
            tempScore += scoreThree(popDie(userDice, i+1),farkleCheck);
        else if(diceCounts[i] == 2)
            tempScore += scoreTwo(popDie(userDice, i+1),farkleCheck);
        else if(diceCounts[i] == 1)
            tempScore += scoreOne(popDie(userDice, i+1));
        if(tempScore == 0 && diceCounts[i] != 0 && farkleCheck==false)
            return 0;
        score += tempScore;
    }
    return score;
}

/*********************************************************************
 ** Function: special cases
 ** Description: Solves the special cases
 ** Parameters: vectorr
 ** Pre-Conditions: vector is filled
 ** Post-Conditions: score
 *********************************************************************/
int specialCases(vector<int> userDice){
    vector<int> diceCounts = getDieCounts(userDice);
    int counterDoubles = 0;
    int counterTriple = 0;
    int counterQuad = 0;
    //check for two pairs of three
    for(int i = 0; i < diceCounts.size(); i++){
        if(diceCounts[i] == 3) counterTriple += 1;
        else if(diceCounts[i] == 4) counterQuad += 1;
        else if(diceCounts[i] == 2) counterDoubles += 1;
    }
    if(counterTriple == 2)
        return 1500;
    if(counterDoubles == 3)
        return 2500;
    if(counterQuad == 1 && counterDoubles == 1)
        return 1500;
    return 0;
}

/*********************************************************************
 ** Function: userDiceSelectionConditions
 ** Description: Calls appropirate functions
 ** Parameters: vector, bool
 ** Pre-Conditions: vector has stuff
 ** Post-Conditions: score
 *********************************************************************/
int userDiceSelectionConditions(vector<int> userDice,bool farkleCheck){

    switch(userDice.size()){
        case 0: return -1; break;
        case 1: return scoreOne(userDice);  break;
        case 2: return scoreTwo(userDice,farkleCheck);  break;
        case 3: return scoreThree(userDice,farkleCheck);  break;
        case 4: return scoreFour(userDice,farkleCheck);  break;
        case 5: return scoreFive(userDice,farkleCheck);  break;
        case 6:
            int temp = specialCases(userDice);
            if(temp == 0){
                return scoreSix(userDice,farkleCheck);
            }
            return temp; break;

    }
    return 0;
}

/*********************************************************************
 ** Function: noRepeatingChars
 ** Description: checks to insure a string does not have repeating chars
 ** Parameters: str
 ** Pre-Conditions: takes a string
 ** Post-Conditions: returns a bool
 *********************************************************************/
bool noRepeatingChars(string strToCheck){
    for(int i = 0; i < strToCheck.length()-1; i++){
        if(strToCheck.length() < 1)
            return false;
        char check = strToCheck[i];
        for(int j = i+1; j < strToCheck.length(); j++){
            if(check == strToCheck[j])
                return false;
        }
    }
    return true;
}



/*********************************************************************
 ** Function: getUserDiceSelection
 ** Description: gets the selection from the pool
 ** Parameters: vector
 ** Pre-Conditions: vector is filled
 ** Post-Conditions: a new vector of the user selection
 *********************************************************************/
vector<int> getUserDiceSelection(vector<int> dicePool){
    vector<int> tempVect(0);

    //get indexes
    string userSelection;
    do{
        cout<<"Enter your dice indexes: " <<endl;
        getline(cin,userSelection);
        istringstream (userSelection) >> numPlayers;
    }
    while(!userSelection.isValid();

    //cant have repeating indexes
    //or out of bounds indexs for dicepool
    if((userSelection.length() <= dicePool.size()) && noRepeatingChars(userSelection)){

        if(userSelection.length() == 1 && userSelection[0] -'0' == 0)
            return tempVect;
        //using dicepool take out the values from that into new vector
        for(int i = 0; i < userSelection.length(); i++){
            if(((userSelection[i] -'0' > dicePool.size()) || (userSelection[0] -'0' == 0))){
                tempVect = vector<int>(0);
                return tempVect;
            }
            int index = (userSelection[i] - '0') - 1;
            tempVect.push_back(dicePool[index]);
        }
        //return that vector
        return tempVect;

    }
    return getUserDiceSelection(dicePool);
}

/*********************************************************************
 ** Function: playerTurn
 ** Description: Does the turn logic for a player
 ** Parameters: pointer, two ints
 ** Pre-Conditions: stuff exists
 ** Post-Conditions: score
 *********************************************************************/
int playerTurn(int *scores, int currentPlayerIndex,int currentScore){
    vector<int> dice(6,1);
    int score = 0;
    while(dice.size() > 0){
        rollDice(dice);
        displayDice(dice);
        if(userDiceSelectionConditions(dice,true) == 0){
            return 0; //Farkled
        }
        cout<<"Choose an index from the first row. If you are done rolling, type 0" << endl;
        vector<int> playerDice = getUserDiceSelection(dice);
        int tempScore = userDiceSelectionConditions(playerDice,false);
        while(tempScore == 0 || tempScore == -1){ //Reprompt for user input
            playerDice = getUserDiceSelection(dice);
            tempScore = userDiceSelectionConditions(playerDice,false);
            if(tempScore == -1)
                return score;
        }
        dice = cleanDiePool(dice, playerDice);
        score += tempScore;
        cout<<"Your current total score is: "<<scores[currentPlayerIndex]<<endl;
        cout<<"Your current score is: "<<score+currentScore<<endl;
    }
    if(dice.size() == 0){
        score += playerTurn(scores,currentPlayerIndex,score+currentScore);
    }
    return score;
}

/*********************************************************************
 ** Function: game
 ** Description: Takes care of the game functionallity
 ** Parameters: pointer, int
 ** Pre-Conditions: things exist
 ** Post-Conditions: the game is played
 *********************************************************************/
int game(int *arr, int numPlayers){
    vector<bool> onBoardFlag(numPlayers,false);
    bool isWin = false;
    while(!isWin){
        clearScreen();
        for(int i = 0; i < numPlayers; i++){
            clearScreen();
            cout<<"Player "<<i+1<<" turn: " << endl;
            cout<<"Score: " << arr[i] << endl;
            int score = playerTurn(arr,i,0);
            if(score != 0){
                if(onBoardFlag[i] && score > 0){
                    arr[i] += score;
                }
                else if(!onBoardFlag[i] && score > 500){
                    onBoardFlag[i] = true;
                    arr[i] += score;
                }
            }
            if(arr[i] > 10000){
                isWin = true;
                return i;
            }
        }
    }
    return 0;
}

/*********************************************************************
 ** Function:main
 ** Description: gets the things to set up game
 ** Parameters: none
 ** Pre-Conditions: user input
 ** Post-Conditions: starts a game
 *********************************************************************/
int main(){
    //Ask for number of players
    string numberPlayers;
    int numPlayers = 1;
    do{
        cout<<"How many players? 2 or more" <<endl;
        getline(cin,numberPlayers);
        istringstream (numberPlayers) >> numPlayers;
    }
    while(numPlayers < 2);


    int *playerScore = new int[numPlayers];


    for(int i = 0; i < numPlayers; i++){
        playerScore[i] = 0;
    }
    //create array for with that number of players
    //send to game function
    int winner = game(playerScore,numPlayers);
    cout<<"Player " << winner+1 << " wins!"<<endl;
    //getWinner(playerScore, numPlayers);
    delete [] playerScore;
}
