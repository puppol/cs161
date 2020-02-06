#include <iostream>
#include <assert.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;




void rollDice(vector<int>& diceVector){
    for(int i = 0; i < diceVector.size(); i++){
        diceVector[i] = rand() % 6 + 1;
    }
}

void displayDice(vector<int>& diceToDisplay){
    //Print out index and dice values
}


//POSSIBLE INPUT ERROR HERE CHECK RECURSIVE CALL IF ISSUE
string getUserDiceSelection(){
    cout<<"Input the indexes you want to score in one string without spaces. "<<endl;
    string userSelection = "";
    getline(cin, userSelection);
    for(int i = 0; i < userSelection.length(); i++){
        if(userSelection[i] == ' '  || (userSelection[i] < '0' && userSelection[i] > [9])){
            userSelection = "";
            getUserDiceSelection();
        }
    }
    return userSelection;
}

vector<int> getDieCounts(vector<int> diceToCheck){
    vector<int> dieCounts(6);
    int count = 0;
    for(int i = 0; i < diceCounts.size(); i++){
        for(int j = 0; j < diceToCheck.size(); i++){
            if(diceToCheck[j] == i+1)
                count += 1;
        }
        diceCounts[i] = count;
        count = 0;
    }
    return dieCounts;
}

bool checkIfFarkle(vector<int> diceToCheck){
    int counter = 0;
    for(int i = 0; i < diceToCheck.size(); i++){
        if(diceToCheck[i] == 1 || diceToCheck[i] == 5)
            return false;
    }


    

}



//CHECK HERE IF MEMORY LEAK
int indexOfThreeOfKind(vector<int> diceCounts){
    int counter = 0;
    for(int i = 0; i < diceCounts.size(); i++){
        if(dieCounts[i] == 3)
            arrOfIndexes[0] = i;
    }
    return arrOfIndexes;
}


//CHECK HERE IF MEMORY LEAK
int *indexesOfTripple(vector<int> diceCounts){
    int counter = 0;
    int *arrOfIndexes = new int[2];
    for(int i = 0; i < diceCounts.size(); i++){
        if(dieCounts[i] == 3){
            counter += 1;
            arrOfIndexes[counter - 1] = i;
        }
    }
    return arrOfIndexes;

}
//CHECK HERE IF MEMORY LEAK
int *indexesOfDoubles(vector<int> diceCounts){
    int counter = 0;
    int *arrOfIndexes = new int[3];
    for(int i = 0; i < diceCounts.size(); i++){
        if(dieCounts[i] == 2){
            counter += 1;
            arrOfIndexes[counter - 1] = i;
        }
    }
    return arrOfIndexes;
}
//CHECK HERE IF MEMORY LEAK
int *indexesOfStraight(vector<int> diceCounts){
    int *arrOfIndexes = new int[6];
    if(dieCounts[0] == 1 && dieCounts[1] == 1 && dieCounts[2] == 1 && dieCounts[3] == 1 && dieCounts[4] == 1 && dieCounts[5] == 1)
        for(int i = 0; i < 6; i++)
            arrOfIndexes[i] = i+1;
    return arrOfIndexes;
}
//CHECK HERE IF MEMORY LEAK
int *indexesOfQuadDouble(vector<int> diceCounts){
    bool foundQuad = false;
    bool foundDouble = false;
    int *arrOfIndexes = new int[2];
    int counter = 0;
    for(int i = 0; i < diceCounts.size(); i++){
        if(diceCounts[i] == 4){
            foundQuad = true;
            arrOfIndexes[counter] = i;
            counter++;
        }
        else if(diceCounts[i] == 2){
            foundDouble = true;
            arrOfIndexes[counter] = i;
            counter++;
        }
    }
    if(foundDouble && foundQuad){
        return arrOfIndexes;
    }
}

int scoreDice(vector<int> diceToScore){
    int score = 0;
    for(int i = 0; i < diceToScore.size(); i++){
        score += diceToScore[i] == 1 ? 100 : 0;
        score += diceToScore[i] == 5 ? 50 : 0;
    }
    vector<int> dieCounts = getDieCounts(diceToScore);
    score += dieCounts[0] == 3 ? 300 : 0;
    int counter = 0;
    for(int i = 1; i < dieCounts.size(); i++){
        score += dieCounts[i] == 3 ? (i+1) * 100 : 0;
        score += dieCounts[i] == 4 ? 1500 : 0;
        score += (dieCounts[0] == 1 && dieCounts[1] == 1 && dieCounts[2] == 1 && dieCounts[3] == 1 && dieCounts[4] == 1 && dieCounts[5] == 1) ? 1500 : 0;
    }



    return score;
}




int playerTurn(){
    int score = 0;
    vector<int> dice(6); //Creates a vector of size 6
    vector<int> playerDice();
    while(dice.size() > 0){
        rollDice(dice);
        displayDice(dice);
        if(scoreDice(dice) != 0){
            playerDice = getUserDiceSelection();
            while(scoreDice(playerDice) == 0)
                playerDice = getUserDiceSelection();
            score = scoreDice(playerDice)
            if(score < 500)
                return 0;
            popDice(dice, playerDice);
        }
    }


}





int main(){
    srand(time(NULL));
    string numPlayers = "";
    getline(cin,numPlayers);
    vector<int> playerScores(atoi(numPlayers.c_str()),0); //Creates vector size of numPlayers and sets score to 0




}

