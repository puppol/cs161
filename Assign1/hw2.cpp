/******************************************************
 ** Program: hw2.cpp
 ** Author: Luke Puppo
 ** Date: 21 January 2018
 ** Description: Text based adventure game. In this game you are a pirate in search of bounty. The more bounty you collect, the richer you become! Try not to lose all of your men though!
 ** Input: 1, 2, or 5
 ** Output: Various text outputs
 ******************************************************/

#include <iostream>
#include <cstdlib> //For rand() functionallity
#include <unistd.h>//for sleep()
#include <cstdio> //For printf functionallity
#include <fstream>//For highscore file saving
#include <string> //For highscore saving
#include <sstream> //For highscore reading and string manipulation
using namespace std;


//     GLOBAL VARIABLES  //
/////////////////////////////////////////
enum Encounter {
    SMALL, SMALL_ATT, SMALL_LEAVE,
    LARGE, LARGE_ATT, LARGE_LEAVE,
    MERCHANT,
    CITY, CITY_ATT, CITY_LEAVE, CITY_SUCCESS
};

enum Color {
    RED = 31,
    GREEN = 32,
    YELLOW = 33
};

int menCount = 20;
int goldCount = 0;

int temp;




/////////////////////////////////////////

//     START FUNCTIONS     //

/////////////////////////////////////////


/*********************************************************************
 ** Function: clearScreen
 ** Description: clears the terminal screen
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: clears the terminal screen
 *********************************************************************/
int clearScreen(){
    printf("\033c");
    return 1;
}

//Art adapted from AsciiArt
/*********************************************************************
 ** Function: asciiShipSailing
 ** Description: does some ascii art animation
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: art movement
 *********************************************************************/
void asciiShipSailing(){
    int waves = 50;
    int space = 30;
    while (waves > 31){
        clearScreen();
        cout<<"           ";
        cout<<string(waves-space,' ');
        cout<<"    _ ^ _"<<endl;
        cout<<"           ";
        cout<<string(waves-space,' ');
        cout<<"   '_\\V/ `"<<endl;
        cout<<"           ";
        cout<<string(waves-space,' ');
        cout<<"   ' oX`"<<endl;
        cout<<"           ";
        cout<<string(waves-space,' ');
        cout<<"      X"<<endl;
        cout<<"           ";
        cout<<string(waves-space,' ');
        cout<<"      X"<<endl;
        cout<<"     _~    ";
        cout<<string(waves-space,' ');
        cout<<"      X"<<endl;
        cout<<"  _~ )_)_~ ";
        cout<<string(waves-space,' ');
        cout<<"      X"<<endl;
        cout<<"  )_))_))_)";
        cout<<string(waves-space,' ');
        cout<<"      X.a##a."<<endl;
        cout<<"  _!__!__!_";
        cout<<string(waves-space,' ');
        cout<<"   .aa########a."<<endl;
        cout<<" \\______t/";
        cout<<string(waves-space,' ');
        cout<<".a##############aa."<<endl;
        
        cout<<string(waves,'~');
        
        cout<<endl<<"   "<<endl; //Needed to make waves animate
        
        usleep(100000);
        waves--;
        
    }
    
}


/*********************************************************************
 ** Function: setTextColor
 ** Description: Sets up outputting colored text to the screen
 ** Parameters: string text, enum Color color
 ** Pre-Conditions: takes non-colored string
 ** Post-Conditions: colored string
 *********************************************************************/
string setTextColor(string text, Color color){
    ostringstream oss;
    oss << "\033[0;" << color << "m" << text << "\033[0m";
    return oss.str();
}


/*********************************************************************
 ** Function: getUserInput
 ** Description: gets the user input and error handles
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: returns clean input
 *********************************************************************/
int getUserInput(){
    bool goodInput = false;
    int input = 0;
    while(!goodInput){
        cout<<"Please type 1 or 2. If you would like to quit, ";
        cout<<"please type 5: " <<endl;
        cin>>input;
        
        if(cin.good()){
            if(input == 1 || input == 2 || input == 5){
                if(input == 5){
                    exit(0);
                }
                goodInput = true;
            }
            else{
                cout<<"That was not a valid input. Please try again."<<endl;
                return getUserInput();
                
            }
        }
        else {
            cout<<"Please enter a valid input." <<endl;
            cin.clear(); //Clears the error
            cin.ignore(10000,'\n'); //Ignores any other input on the same line, until it hits '\n'
        }
    }
    return input;
}


//Does not have a clearScreen
//Meant for before large events.
/*********************************************************************
 ** Function: displayCounts
 ** Description: Displays important info to the user
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: outputs
 *********************************************************************/
void displayCounts(){
    cout<<"//////////////////////"<<endl;
    cout<<"Your Men: " << menCount <<endl;
    cout<<setTextColor("Your Gold: ", YELLOW) <<goldCount <<endl;
    cout<<"//////////////////////"<<endl<<endl;
}



/*********************************************************************
 ** Function: randomSuccessHandler
 ** Description: handles the success rates for randoms
 ** Parameters: int successCutoff
 ** Pre-Conditions: none
 ** Post-Conditions: random number
 *********************************************************************/
bool randomSuccessHandler(int successCutoff){
    int roll = rand() % 100;
    if(roll < successCutoff){
        return true;
    }
    return false;
}


/*********************************************************************
 ** Function: encounterHandler
 ** Description: Handles all of the story elements
 ** Parameters: enum Encounter currEncounter
 ** Pre-Conditions: none
 ** Post-Conditions: cont the story line
 *********************************************************************/
int encounterHandler(Encounter currEncounter){
    int plundered = 0;
    switch(currEncounter){
        case LARGE:
            //Intro to encounter
            //Ask for att or leave
            //Handle that
            //If 1, encounter LARGE_ATT
            //IF 2, enoucnter LARGE_LEAVE
            displayCounts();
            cout<<"You sail to the large coastal village, and drop your anchor in a small cove out of sight of the village. You send a scout to canvas the area, and he says there are around 40 men, but they are not heavily armored. What do you do?" <<endl;
            
            cout<<"1: Attack!"<<endl;
            cout<<"2: Leave" <<endl;
            if(getUserInput() == 1){
                encounterHandler(LARGE_ATT);
            }
            else{ //Either a 1 or a 2, meaning 2 is other option
                encounterHandler(LARGE_LEAVE);
            }
            break;
            
        case LARGE_ATT:
            //Do attack encounter logic here
            //Needs rand
            //If success do stuff
            //If failure do stuff
            
            if(randomSuccessHandler(80)){
                      //rand() % range + lowest
                plundered = rand() % 20000 + 20000;
                clearScreen();
                cout<< setTextColor("Your attack was successful! ",GREEN) << "You easily defeated the warriors." <<endl;
                cout<< setTextColor("Gold plundered: ",YELLOW) << plundered <<endl;
                cout<<"Men lost: 0" <<endl<<endl;
                goldCount += plundered;
            }
            else{
                clearScreen();
                cout<<setTextColor("The attack was a complete failure. ", RED)<<"However, in the heat of the battle, one of your men managed to steal 200 pieces of gold." <<endl;
                cout<<setTextColor("Gold plundered: 200",YELLOW) <<endl;
                cout<<"Men lost: 7" <<endl;
                goldCount += 200;
                menCount -= 7;
            }
            
            break;
            
        case LARGE_LEAVE:
            clearScreen();
            cout<<"On the way out of the cove, a village archer shoots an arrow and injures one of your men. He is no longer battle ready."<<endl;
            menCount--;
            break;
            
        case SMALL:
            //Intro text
            //Ask for user input
            //if user puts 1, encounter SMALL_ATT
            //if user puts 2, encounter SMALL_LEAVE
            displayCounts();
            cout<<"You sail to the small coastal city. As you get close, your ship is spotted by a city scout. Your element of surprise has been lost, but a shady man in a tavern said this village does not have many warriors. What do you do?" <<endl;
            cout<<"1: Trust the shady man. Attack!"<<endl;
            cout<<"2: Leave" <<endl;
            
            if(getUserInput() == 1){
                encounterHandler(SMALL_ATT);
            }
            else{ //Either a 1 or a 2, meaning 2 is other option
                encounterHandler(SMALL_LEAVE);
            }
            break;
            
        case SMALL_ATT:
            //Do attack encounter logic here
            //Needs rand function
            //If success do something
            //If failure do something
            
            if(randomSuccessHandler(90)){
                //rand() % range + lowest
                plundered = rand() % 4000 + 1000;
                clearScreen();
                cout<<setTextColor("Your attack was successful! ",GREEN) <<"However, it seems as if someone had recently plundered all of the villages gold. You find some gold scattered around the village." <<endl;
                cout<<setTextColor("Gold plundered: ",YELLOW) << plundered <<endl;
                cout<<"Men lost: 0" <<endl;
                goldCount += plundered;
            }
            else{
                clearScreen();
                cout<<setTextColor("Your attack failed. ",RED) << "They had been expecting your attack. However, in the heat of the battle, one of your men managed to steal 50 pieces of gold." <<endl;
                cout<<setTextColor("Gold plundered: 50",YELLOW) <<endl;
                cout<<"Men lost: 3" <<endl;
                goldCount += 50;
                menCount -= 3;
            }
            
            break;
            
        case SMALL_LEAVE:
            clearScreen();
            cout<<"You sail away, disappointed. "<<endl;
            break;

        case MERCHANT:
            //Needs random logic here
            plundered = rand() % 100000 + 50000;
            goldCount += plundered;
            clearScreen();
            displayCounts();
            cout<<"You attack the merchant vessels. You manage to plunder 3 of them as the rest escaped. As this is your bread and butter, you walk away unscathed, with " <<plundered << " gold pieces."<<endl;
            break;
            
        case CITY:
            //Intro to encounter
            //Ask for user input
            //Handle that
            //If 1 CITY_ATT
            //If 2 CITY_LEAVE
            displayCounts();
            cout<<"Once you arrive at the city, you find it teaming with merchants. There are many armed guards, but from what you have heard, they are not well trained." <<endl;
            cout<<"1: Attack!"<<endl;
            cout<<"2: Leave the city." <<endl;
            
            if(getUserInput() == 1){
                encounterHandler(CITY_ATT);
            }
            else{ //Either a 1 or a 2, meaning 2 is other option
                encounterHandler(CITY_LEAVE);
            }
            break;
            
        case CITY_ATT:
            //Do text
            if(randomSuccessHandler(60)){
                //rand() % range + lowest
                plundered = rand() % 100000 + 150000;
                clearScreen();
                cout<<setTextColor("Your attack was successful!",GREEN) <<endl;
                cout<<setTextColor("Gold plundered: ",YELLOW) << plundered <<endl;
                cout<<"Men lost: 1" <<endl;
                goldCount += plundered;
                menCount--;
                encounterHandler(CITY_SUCCESS);
            }
            else{
                clearScreen();
                cout<<setTextColor("Your men were easily outnumbered. The entire crew was either killed or captured.",RED) <<endl;
                menCount = 0;
                displayCounts();
                cout<<"Thanks for playing! - Luke"<<endl;
                return 0;
            }
            
            break;
            
        case CITY_LEAVE:
            clearScreen();
            cout<<setTextColor("On your way out, you were stopped. Your crew was captured.",RED)<<endl;
            displayCounts();
            cout<<"Thanks for playing! - Luke"<<endl;
            return 0; //END FLAG
            break;
            
        case CITY_SUCCESS:
            clearScreen();
            cout<<setTextColor("You managed to raid the richest town in the world. You go down as the best pirate in all of history.", GREEN)<<endl;
            displayCounts();
            cout<<"Thanks for playing! - Luke"<<endl;
            return 0; //END FLAG
            break;
    }
    return 1;
}


//Adapted from C++ Reference Library
/*********************************************************************
 ** Function: getHighScore
 ** Description: gets the high score from a file
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: gets the high score
 *********************************************************************/
int getHighScore(){
    string score;
    ifstream ifile ("highscore.txt");
    if(ifile.is_open()){
        getline(ifile,score);
        ifile.close();
        int tempInt;
        istringstream buffer(score);
        buffer >> tempInt;
        return tempInt;
    }
    else{
        //cout << "Unable to open file";
        return 0;
    }
    
    return 0;
}

//Adapted from C++ Reference Library
/*********************************************************************
 ** Function: setHighScore
 ** Description: sets the high score in the file
 ** Parameters: int score
 ** Pre-Conditions: needs text file
 ** Post-Conditions: written to text file
 *********************************************************************/
int setHighScore(int scoreNum){
    ofstream ofile ("highscore.txt");
    if(ofile.is_open())
    {
        ofile<<scoreNum;
        ofile.close();
    }
    //else cout << "Unable to open file";
    return 0;
}


/*********************************************************************
 ** Function: main
 ** Description: Handles the flow of the story
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: finished story
 *********************************************************************/
int main(){
    //Start
    //Introduction text
    //Where would you like to go?
    //SMALL or LARGE?
    //1     or 2
    //Encounter handler(1 or 2)
    //
    
    srand(time(NULL));
    clearScreen();
    
    cout<<"You are a pirate on the High seas, but your thirst for gold has grown. You have heard of coastal villages that hide troves of gold, and you desperately want to get your hands on that bountiful booty. Your ship has 20 battle-ready men."<<endl<<endl;
    
    cout<<"Your first mate tells you of a few villages to attack. The first is larger than the other, which carries the risk of losing more men in the skirmish, but carries the opportunity of more booty. The second is small but it is known to be close to a mine. Which village would you like to sail to?"<<endl;
    cout<<"1: Large"<<endl;
    cout<<"2: Small"<<endl;
    
    
    bool option1Selected = false;
    if(getUserInput() == 1){
        asciiShipSailing();
        clearScreen();
        encounterHandler(LARGE);
        option1Selected = true;
    }
    else{ //Either a 1 or a 2, meaning 2 is other option
        asciiShipSailing();
        clearScreen();
        encounterHandler(SMALL);
    }

    if(option1Selected){
        cout<<"You and your crew decide to try the other village."<<endl;
        cout<<"1 or 2: Set sail!"<<endl<<endl;
        temp = getUserInput();
        if(temp == 1 || temp == 2){
            asciiShipSailing();
            clearScreen();
            encounterHandler(SMALL);
        }
        
    }
    else{
        cout<<"You and your crew decide to try the other village."<<endl;
        cout<<"1 or 2: Set sail!"<<endl<<endl;
        temp = getUserInput();
        if(temp == 1 || temp == 2){
            asciiShipSailing();
            clearScreen();
            encounterHandler(LARGE);
        }
        
    }
    
    cout<<endl;
    
    //BOTH SMALL AND LARGE ENCOUNTERS COMPLETE
    
    cout<<"After your two attacks, you still wish to plunder. Your first mate informs you of another city on the far side of the sea. You decide to sail there and hope for the best. Along the way, your scout spots a convoy of merchants. Do you attack the merchants in hope for gold and spices, or sail to the city across the sea?"<<endl;
    cout<<"1: Attack the merchants!"<<endl;
    cout<<"2: Leave the merchants, go for the city!"<<endl;
    
    option1Selected = false;
    
    if(getUserInput() == 1){
        clearScreen();
        encounterHandler(MERCHANT);
        option1Selected = true;
    }
    else{ //Either a 1 or a 2, meaning 2 is other option
        clearScreen();
        encounterHandler(CITY);
    }
    
    if(option1Selected){
        cout<<"After your successful plunder, you set your course for the city. "<<endl;
        cout<<"1 or 2: Set sail!"<<endl<<endl;
        
        temp = getUserInput();
        if(temp == 1 || temp == 2){
            asciiShipSailing();
            clearScreen();
            encounterHandler(CITY);
        }
    }
    
    int savedHighScore = getHighScore();
    //istringstream(savedHighScore) >> highScore;
    if(goldCount > savedHighScore){
        cout<<"New high score!"<<endl;
        setHighScore(goldCount);
    }
    return 0;
}


