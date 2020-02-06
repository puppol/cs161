
#include <string> //getline() length() +=
#include <cmath> //pow()  abs()
#include <iostream>

using namespace std;
#include "helper_functions.h"


/*****************************************************
 ** Function: check_range
 ** Description: Checks if a value is in a range
 ** Parameters: int, int, int
 ** Pre-Conditions: none
 ** Post-Conditions: true/false
 ****************************************************/
bool check_range(int lower_bound, int upper_bound, int value){
    if(value <= upper_bound && value >= lower_bound){
        return true;
    }
    return false;
}


/*****************************************************
 ** Function: is_int
 ** Description: Checks if a string is an integer
 ** Parameters: num
 ** Pre-Conditions: none
 ** Post-Conditions: true/false
 ****************************************************/
bool is_int(string num){
    for(int i = 0; i < num.length(); i++){
        if(!(check_range('0','9',num[i]))){
            return false;
        }
    }
    return true;
}


/*****************************************************
 ** Function: is_float
 ** Description: checks if string is a float
 ** Parameters: string
 ** Pre-Conditions: none
 ** Post-Conditions: true/false
 ****************************************************/
bool is_float(string num){
    bool hasDec;
    for(int i = 0; i < num.length(); i++){
        if(!num[i] == '.'){
            string temp = "" + num[i];
            if(!is_int(temp)){
                return false;
            }
        }
        if(num[i] == '.'){
            if(hasDec){
                return false;
            }
            hasDec=true;
        }
    }
    if(hasDec)
        return true;
}


/*****************************************************
 ** Function: is_capital
 ** Description: checks if char is capital
 ** Parameters: char
 ** Pre-Conditions: none
 ** Post-Conditions: ture/false
 ****************************************************/
bool is_capital(char letter){
    if(letter >= 'A' && letter <='Z'){
        return true;
    }
    return false;
}


/*****************************************************
 ** Function: is_even
 ** Description: checks if number is even
 ** Parameters: num
 ** Pre-Conditions: none
 ** Post-Conditions: true/false
 ****************************************************/
bool is_even(int num){
    if(num % 2 == 0){
        return true;
    }
    return false;
}


/*****************************************************
 ** Function: is_odd
 ** Description: checks if integer is odd
 ** Parameters: int
 ** Pre-Conditions: non
 ** Post-Conditions: true/false
 ****************************************************/
bool is_odd(int num){
    if(num % 2 == 1){
        return true;
    }
    return false;
}


/*****************************************************
 ** Function: equality_test
 ** Description: Checks if two ints are equal
 ** Parameters: int, int
 ** Pre-Conditions: none
 ** Post-Conditions: true/false
 ****************************************************/
int equality_test(int num1, int num2){
    if(num1 == num2){
        return 0;
    }
    else if(num1 < num2){
        return -1;
    }
    else if(num1 > num2){
        return 1;
    }
}


/*****************************************************
 ** Function: float_is_equal
 ** Description: checks if two floats are equal
 ** Parameters: float, float, float
 ** Pre-Conditions: none
 ** Post-Conditions: true/false
 ****************************************************/
bool float_is_equal(float num1, float num2, float precision){
    if(abs(num1-num2) <= precision){
        cout<<abs(num1-num2)<<endl;
        return true;
    }
    return false;
}


/*****************************************************
 ** Function: numbers_present
 ** Description: Finds the numbers present in a string
 ** Parameters: string
 ** Pre-Conditions: none
 ** Post-Conditions: number
 ****************************************************/
bool numbers_present(string sentence){
    for(int i = 0; i < sentence.length(); i++){
        if(check_range('0','9',sentence[i])){
            return true;
        }
    }
    return false;
}


/*****************************************************
 ** Function: letters_present
 ** Description: Checks if there are letters present
 ** Parameters: string
 ** Pre-Conditions: none
 ** Post-Conditions: true/false
 ****************************************************/
bool letters_present(string sentence){
    for(int i = 0; i < sentence.length(); i++){
        if((check_range('a','z',sentence[i]) ||
            check_range('A','Z',sentence[i]))){
            return true;
        }
    }
    return false;
}


/*****************************************************
 ** Function: contains_sub_string
 ** Description: Checks if string contains another string
 ** Parameters: string, string
 ** Pre-Conditions: none
 ** Post-Conditions: true/false
 ****************************************************/
bool contains_sub_string(string sentence, string sub_string){
    int j = 0;
    for(int i = 0; i < sentence.length(); i++){
        if(sentence[i] == sub_string[j]){
            while(j < sub_string.length()){
                if(sentence[i] != sub_string[j]){
                    return false;
                }
                i++;
                j++;
            }
        }
        if(j == sub_string.length()){
            return true;
        }
    }
    return false;
}


/*****************************************************
 ** Function: word_count
 ** Description: displays the number of words in a sentence
 ** Parameters: string
 ** Pre-Conditions: none
 ** Post-Conditions: number of words
 ****************************************************/
int word_count(string sentence){
    int spaces = 0;
    for(int i = 0; i < sentence.length(); i++){
        if(sentence[i] == ' '){
            spaces++;
        }
    }
    if(spaces != 0){
        return spaces + 1;
    }
    else if(spaces == 0){
        if(letters_present(sentence)){
            return 1;
        }
    }
    return 0;
}


/*****************************************************
 ** Function: to_upper
 ** Description: converts a string to uppercase
 ** Parameters: string
 ** Pre-Conditions: lowercase
 ** Post-Conditions: uppercase
 ****************************************************/
string to_upper(string sentence){
    string finalString = "";
    for(int i = 0; i < sentence.length(); i++){
        if(sentence[i] >= 'a' && sentence[i] <= 'z'){
            finalString += sentence[i] - 32;
        }
        else{
            finalString += sentence[i];
        }
    }
    return finalString;
}


/*****************************************************
 ** Function: to_lower
 ** Description: converts a string to the lower case
 ** Parameters: string
 ** Pre-Conditions: uppercase letters
 ** Post-Conditions: lowercase letters
 ****************************************************/
string to_lower(string sentence){
    string finalString = "";
    for(int i = 0; i < sentence.length(); i++){
        if(sentence[i] >= 'A' && sentence[i] <= 'Z'){
            finalString += sentence[i] + 32;
        }
        else{
            finalString += sentence[i];
        }
    }
    return finalString;
}


/*****************************************************
 ** Function: string_to_integer
 ** Description: Converts a string to an integer
 ** Parameters: string
 ** Pre-Conditions: none
 ** Post-Conditions: returns an int to the user
 ****************************************************/
int string_to_integer(string str){
    int value = 0;
    for(int i = 0; i < str.length(); i++){
        value = value * 10;
        if(str[i] <= '9' && str[i] >= '0'){
            int temp;
            temp = int(str[i]);
            temp -= 48;
            value += temp;
        }
    }
    return value;
}


/*****************************************************
 ** Function: string_to_float
 ** Description: converts a string to a float
 ** Parameters: string
 ** Pre-Conditions: none
 ** Post-Conditions: a float from the given string
 ****************************************************/
float string_to_float(string str){
    float value = 0;
    bool foundDot = false;
    int currPosition = 0;
    while(!foundDot && currPosition < str.length()){
        if(str[currPosition] <= '9' && str[currPosition] >= '0'){
            value = value * 10;
            float temp;
            temp = float(str[currPosition]);
            temp -= 48;
            value += temp;
        }
        if(str[currPosition] == '.'){
            foundDot = true;
        }
        currPosition++;
    }

    //cout<<"value = " <<value<<endl;


    float afterDotValue = 0;
    for(int i = str.length(); i > currPosition-1; i--){
        if(str[i] <= '9' && str[i] >= '0'){
            afterDotValue = afterDotValue / 10;
            float temp;
            temp = float(str[i]);
            temp -= 48;
            afterDotValue += temp/10;
            //cout<<"afterdotvalue" <<afterDotValue <<endl;
        }
    }

    value += afterDotValue;


    return value;
}


/*****************************************************
 ** Function: get_int
 ** Description: Gets an int from the user. Waits unti receives valid input
 ** Parameters: string
 ** Pre-Conditions: needs a string
 ** Post-Conditions: outputs a float the user
 ****************************************************/
int get_int(string prompt){
    bool goodInput = false;
    if(is_int(prompt)){
        return string_to_integer(prompt);
    }
    if(!goodInput){
        cout<<"You must provide valid input. " <<endl;
        string temp;
        getline(cin, temp);
        get_int(temp);
    }

}


/*****************************************************
 ** Function: get_float
 ** Description: Gets a float from the user. Waits until receives valid input
 ** Parameters: string
 ** Pre-Conditions: needs a string
 ** Post-Conditions: outputs a float to the user
 ****************************************************/
float get_float(string prompt){
    bool goodInput = false;
    if(is_float(prompt)){
        return string_to_float(prompt);
    }
    if(!goodInput){
        cout<<"You must provide valid input. " <<endl;
        string temp;
        getline(cin, temp);
        get_float(temp);
    }
}


/*****************************************************
 ** Function: functionSeparation
 ** Description: Visual separation to the screen.
 ** Parameters: None
 ** Pre-Conditions: N/A
 ** Post-Conditions: Prints spacing to screen
 ****************************************************/
void functionSeparation(){
    cout<<endl;
    cout<<"/////////////////////////////////"<<endl;
    cout<<endl;
}
