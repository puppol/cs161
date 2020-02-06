//
//  pswdGen.cpp
//  
//
//  Created by Luke Puppo on 1/24/18.
//

#include <iostream>
#include <unistd.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <ctime>
#include <stdlib.h>

using namespace std;


//////////////////////////////////
//      GLOBAL VARIABLES
//////////////////////////////////
int passwordLength = 0;
int numLetters = 0;
int numLowerLetters = 0;
int numUpperLetters = 0;
int numNumbs = 0;


//These two are inclusive
int asciiUpperCase[2] = {65,90};
int asciiLowerCase[2] = {97,122};




//////////////////////////////////
//          FUNCTIONS
//////////////////////////////////


//Resets global variables for next password
bool resetGlobals(){
    passwordLength = 0;
    numLetters = 0;
    numLowerLetters = 0;
    numUpperLetters = 0;
    numNumbs = 0;
    return true;
}

//Pass in the custom text
int getUserInput(string str){
    int userSelection;
    cout<<str<<endl;
    cout<<"0 - No"<<endl;
    cout<<"1 - Yes"<<endl;
    cin>>userSelection;
    return userSelection;
}


int getUserPasswordLength(){
    cout<<"Please enter the number of characters in your desired password: "<<endl;
    int pswdLen;
    cin>>pswdLen;
    if(!(pswdLen > 0)){
        cout<<"Please input a number greater than 0. "<<endl;
        getUserPasswordLength();
    }
    passwordLength =  pswdLen;
}

bool getUserLetters(){
    int letterSelection;
    //Get letters selection
    if(getUserInput("Do you want letters?")){
        //Get number of letters selection
        cout<<"How many letters? "<<endl;
        cin>>numLetters;

        //Get lowercase selection
        if(getUserInput("Do you want lower case letters?")){
            //Get number lowercase nums
            cout<<"How many lower case letters? "<<endl;
            cin>>numLowerLetters;
        }
        //Get uppercase selection
        if(getUserInput("Do you want upper case letters?")){
            cout<<"How many upper case letters? "<<endl;
            cin>>numUpperLetters;
        }
        return true;
    }
    return false;
}



bool getUserNumbers(){
    //Ask for numbers
    //Ask for number of numbers
    //seed random number gen
    //reference ascii table and rand get number

    if(getUserInput("Do you want to use numbers?")){
        cout<<"How many numbers would you like to use?"<<endl;
        cin>>numNumbs;
        return true;
    }
    return false;
}

string generatePassword(){
    srand(time(NULL));

    string password;

    //Working on letters in program
    if(numLetters){
        if(numLowerLetters){
            for(int i = 0; i < numLowerLetters; i++){
                password += rand() % 26 + asciiLowerCase[0];
            }
        }
        if(numUpperLetters){
            for(int i = 0; i < numUpperLetters; i++){
                password += rand() % 26 + asciiUpperCase[0];
            }
        }
    }


    //Working on adding numbers
    if(numNumbs){ // If number in numNums is greater than 0 do stuff
        for(int i = 0; i < numNumbs; i++){
            password += rand() % 10 + 48;
        }
    }
    return password;

}


int main(){
    cout<<"Welcome to password generator."<<endl;

    do {
        getUserPasswordLength();
        
        getUserLetters();
        getUserNumbers();
        cout<<generatePassword()<<endl;

        resetGlobals();
    }
    while(getUserInput("Would you like another password?"));



    return 0;




}

