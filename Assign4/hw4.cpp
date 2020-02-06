/*********************************************************************
 ** Program Filename: hw4.cpp
 ** Author: Luke Puppo
 ** Date: 02/18/18
 ** Description: Homework assignment 4, in which there are 4 different calculators built in.
 ** Input: User input
 ** Output: Each function outputs text to the screen.
 *********************************************************************/


#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

enum Operators{PLUS = '+', MINUS = '-', MULTIPLY = '*', DIVIDE = '/'};

bool calculatorHandler(int option);
bool runStandardCalculator(string str);


/*********************************************************************
 ** Function: getUserInput
 ** Description: Gets input from the user.
 ** Parameters: None
 ** Pre-Conditions: User knows how to input a string.
 ** Post-Conditions: Returns a string.
 *********************************************************************/
string getUserInput(){
    string str = "";
    getline(cin, str);
    cin.clear();
    return str;
}

/*********************************************************************
 ** Function: getUserInput
 ** Description: Gets input from the user with a prompt included
 ** Parameters: String prompt
 ** Pre-Conditions: Needs a prompt
 ** Post-Conditions: Text output plus returns a string.
 *********************************************************************/
string getUserInput(string prompt){
    cout<<prompt<<endl;
    string str = "";
    getline(cin, str);
    cin.clear();
    return str;
}

/*********************************************************************
 ** Function: convertStringToInteger
 ** Description: Converts a string to an integer
 ** Parameters: string value
 ** Pre-Conditions: Needs a string containing integers
 ** Post-Conditions: returns an integer
 *********************************************************************/
int convertStringToInteger(string value){
    if(value == ""){
        return -1;
    }
    int intValue = atoi(value.c_str());
    return intValue;
}

/*********************************************************************
 ** Function: convertStringToFloat
 ** Description: Converts a string to a float
 ** Parameters: string value
 ** Pre-Conditions: Value is not null and contains only numbers or . -
 ** Post-Conditions: Returns a float
 *********************************************************************/
float convertStringToFloat(string value){
    if(value == ""){
        return -1;
    }
    float floatValue = atof(value.c_str());
    //cout<<"float = " << floatValue <<endl;
    return floatValue;
}

/*********************************************************************
 ** Function: chopStrToVector
 ** Description: Segments a string into sections and stores in a vector
 ** Parameters: string
 ** Pre-Conditions: Needs a string
 ** Post-Conditions: A vector with the string cut into sections
 *********************************************************************/
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

//Adapted from previous homework assignment
/*********************************************************************
 ** Function: check_range
 ** Description: Takes bounds and a value and determines if value is in bounds.
 ** Parameters: int lower_bound, int upper_bound, int value
 ** Pre-Conditions: values are all integers
 ** Post-Conditions: Returns a boolean
 *********************************************************************/
bool check_range(int lower_bound, int upper_bound, int value){
    if(value <= upper_bound && value >= lower_bound){
        return true;
    }
    return false;
}
//Adapted from previous homework assignment
/*********************************************************************
 ** Function: is_int
 ** Description: Checks if a string is an integer
 ** Parameters: string num
 ** Pre-Conditions: num is not ""
 ** Post-Conditions: returns a boolean
 *********************************************************************/
bool is_int(string num){
    for(int i = 0; i < num.length(); i++){
        if(check_range('0','9',num[i]) || num[i] == '-'){
            if(num[i] == '-' && i != 0){
                return false;
            }
            continue;
        }
        else
            return false;
    }
    return true;
}

/*********************************************************************
 ** Function: is_non_neg_int
 ** Description: Determines if the value is an unsigned int
 ** Parameters: String num
 ** Pre-Conditions: String is not ""
 ** Post-Conditions: Returns a boolean
 *********************************************************************/
bool is_non_neg_int(string num){
    for(int i = 0; i < num.length(); i++){
        if(check_range('0','9',num[i])){
            continue;
        }
        else
            return false;
    }
    return true;
}
//Adapted from previous homework assignment
/*********************************************************************
 ** Function: is_float
 ** Description: Determines if a string is a float
 ** Parameters: String num
 ** Pre-Conditions: None - Handles all cases
 ** Post-Conditions: Returns a boolean
 *********************************************************************/
bool is_float(string num){
    bool hasDec;
    for(int i = 0; i < num.length(); i++){
        if(!num[i] == '.'){
            string temp = "" + num[i];
            if(!hasDec){
                if(!is_int(temp)){
                    return false;
                }
            }
        }
        if(num[i] == '.' || num[i] == '-'){
            if(hasDec){
                return false;
            }
            if(num[i] == '.')
                hasDec=true;
        }
    }
    if(hasDec)
        return true;
    return false;
}

/*********************************************************************
 ** Function: isNumber
 ** Description: Determines if a string is either an int or a float
 ** Parameters: String num
 ** Pre-Conditions: None - Handles all cases
 ** Post-Conditions: Returns a boolean
 *********************************************************************/
bool isNumber(string num){
    if(is_int(num) || is_float(num)){
        return true;
    }
    return false;
}

/*********************************************************************
 ** Function: isOperator
 ** Description: Determines if a string is an operator
 ** Parameters: String str
 ** Pre-Conditions: None - Handles all cases
 ** Post-Conditions: Returns a boolean
 *********************************************************************/
bool isOperator(string str){
    if(str.length() != 1)
        return false;
    if(str[0] == PLUS)
        return true;
    else if(str[0] == MINUS)
        return true;
    else if(str[0] == MULTIPLY)
        return true;
    else if(str[0] == DIVIDE)
        return true;
    return false;

}

/*********************************************************************
 ** Function: calcValue
 ** Description: Takes two values and an operator and preforms a calculation
 ** Parameters: float value, string operator, string secondValue
 ** Pre-Conditions: None - All cases should be handled
 ** Post-Conditions: A new calculation
 *********************************************************************/
float calcValue(float value, string op, string val2){
    //cout<<isOperator(op)<<endl;
    //cout<<isNumber(op)<<endl;
    if(op[0] == PLUS)
        return value + convertStringToFloat(val2);
    if(op[0] == MINUS)
        return value - convertStringToFloat(val2);
    if(op[0] == MULTIPLY)
        return value * convertStringToFloat(val2);
    if(op[0] == DIVIDE){
        if(convertStringToFloat(val2) == 0){
            cout<<"Attempted to divide by 0. Please enter new input." << endl;
        }
        return value / convertStringToFloat(val2);
    }
}

/*********************************************************************
 ** Function: verifyVector
 ** Description: Determines if a vector has the correct order of elements
 ** Parameters: Vector of type string
 ** Pre-Conditions: A filled vector
 ** Post-Conditions: Returns a boolean
 *********************************************************************/
bool verifyVector(vector<string> myVector){
    for(int i = 0; i < myVector.size(); i++){
        if(i % 2 == 0){
            if(!isNumber(myVector[i])){
                return false;
            }
        }
        else{
            if(!isOperator(myVector[i]))
                return false;
        }
    }
    return true;
}

/*********************************************************************
 ** Function: runStandardCalculator
 ** Description: Handles the running of the Standard Calculator
 ** Parameters: String str
 ** Pre-Conditions: String str
 ** Post-Conditions: Prints output to the screen
 *********************************************************************/
bool runStandardCalculator(string str){
    vector<string> userVector = chopStrToVector(str);
    if(userVector.size() % 2 == 0 || !isNumber(userVector[0]) ){
        cout<<"Something was inputted incorrectly. Try again."<<endl;
        return runStandardCalculator(getUserInput());
    }
    else {
        if(verifyVector(userVector)){
            float value = convertStringToFloat(userVector[0]);
            //cout<<"Ready to start preforming calculations."<<endl;
            if(userVector.size() == 1){
                cout<<"Calculation Value: " << value << endl;
                return true;
            }
            for(int i = 1; i <= userVector.size() - 2; i += 2){
                value = calcValue(value, userVector[i], userVector[i+1]);
            }
            cout<<"Calculation Value: " << value << endl;
            return true;
        }
        else
            cout<<"Input was bad. Try again."<<endl;
        return false;
    }
}

/*********************************************************************
 ** Function: checkIfBinaryString
 ** Description: Checks if a string contains only binary numbers
 ** Parameters: String input
 ** Pre-Conditions: None
 ** Post-Conditions: A string with only 1 and 0
 *********************************************************************/
string checkIfBinaryString(string input){
    for(int i = 0; i < input.length(); i++){
        if(input[i] != '0' && input[i] != '1'){
            return "";
        }
    }
    return input;
}

/*********************************************************************
 ** Function: runBinaryToDecimalCalculator
 ** Description: Handles the binary to decimal calculator
 ** Parameters: None
 ** Pre-Conditions: Takes an input from the user
 ** Post-Conditions: Prints a string
 *********************************************************************/
void runBinaryToDecimalCalculator(){
    string input = checkIfBinaryString(getUserInput("Enter a binary number: "));
    int decimalValue = 0;
    if(input != ""){
        for(int i = 0; i < input.length(); i++){
            decimalValue *= 2;
            if(input[i] == '1'){
                decimalValue++;
            }
        }
    }
    else{
        cout<<"Bad user input"<<endl;
        return runBinaryToDecimalCalculator();
    }
    cout<<decimalValue<<endl;
}

/*********************************************************************
 ** Function: checkIfValidDecimalInput
 ** Description: Returns string if string is a good integer
 ** Parameters: String input
 ** Pre-Conditions: Needs a string
 ** Post-Conditions: Returns an int-able string
 *********************************************************************/
string checkIfValidDecimalInput(string input){
    for(int i = 0; i < input.length(); i++){
        if(input[i] == '-' || !(input[i] >= '0' && input[i] <= '9')){
            return "";
        }
    }
    return input;
}

/*********************************************************************
 ** Function: runDecimalToBinaryCalculator
 ** Description: Handles the decimal to binary conversion
 ** Parameters: None
 ** Pre-Conditions: Takes in a string from the user
 ** Post-Conditions:
 *********************************************************************/
void runDecimalToBinaryCalculator(){
    int value = convertStringToInteger(checkIfValidDecimalInput(getUserInput("Enter a decimal Number: ")));
    string output = "";
    if(value != -1){
        while(value != 0){
            output = char((value % 2) + 48) + output;
            value /= 2;
        }
        cout<<output<<endl;;
    }
    else{
        cout<<"Bad user input." <<endl;
        return runDecimalToBinaryCalculator();
    }
}

/*********************************************************************
 ** Function: getValidGradeNumber
 ** Description: Handles getting valid input for the Grade Calculator
 ** Parameters: String prompt
 ** Pre-Conditions: Good string
 ** Post-Conditions: Returns a good integer
 *********************************************************************/
int getValidGradeNumber(string prompt){
    cout<< prompt << endl;
    string value = getUserInput();
    while(!is_non_neg_int(value)){

        cout<< "Try again. " << prompt <<endl;
        value = getUserInput();
    }
    return convertStringToInteger(value);
}

/*********************************************************************
 ** Function: runGradeCalculator
 ** Description: Handles the grade calculation
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Prints a calculated grade
 *********************************************************************/
void runGradeCalculator(){
    int numGrades = getValidGradeNumber("How many grades will you be working with?");
    float gradeTotal = 0;
    int weight = 1;

    if(numGrades > 0){
        for(int i = 0; i < numGrades; i++){
            gradeTotal += getValidGradeNumber("Enter a grade: ");
        }
    }

    cout<<"Would you like to weight the grades? Yes / No"<<endl;
    string user = getUserInput();
    if(user == "Yes" || user == "yes" || user == "y" || user == "Y"){
        weight = getValidGradeNumber("What weight would you like to add?");
    }
    cout<<"Your grade is: " << (gradeTotal/numGrades)*weight << endl;
}

/*********************************************************************
 ** Function: calculatorHandler
 ** Description: Handles running the different functions
 ** Parameters: int userOption
 ** Pre-Conditions: None - Handles all input
 ** Post-Conditions: Runs a calculator
 *********************************************************************/
bool calculatorHandler(int userOption){
    switch (userOption) {
        case 1:
            runStandardCalculator(getUserInput("Enter your equation: "));
            break;
        case 2:
            runBinaryToDecimalCalculator();
            break;
        case 3:
            runDecimalToBinaryCalculator();
            break;
        case 4:
            runGradeCalculator();
            break;
    }
    return true;
}

/*********************************************************************
 ** Function: main
 ** Description: Handles the user experience
 ** Parameters: None
 ** Pre-Conditions: User provides input
 ** Post-Conditions: Pushes selection to handler
 *********************************************************************/
int main(){
    while(true){
        cout<<"Enter 1 for Standard Calculator \nEnter 2 for Binary to Decimal \nEnter 3 for Decimal to Binary \nEnter 4 for Grade Calculator\n";
        int userInput = convertStringToInteger(getUserInput());
        if(!(userInput == 1 || userInput == 2 || userInput == 3 || userInput == 4)){
            return false;
        }
        calculatorHandler(userInput);
    }
}
