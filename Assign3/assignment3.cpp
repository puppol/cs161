/*********************************
 ** Program Filename: hw3.cpp
 ** Author: Luke Puppo
 ** Date: 1/31/18
 ** Description: This is a library designed to provide basic, common functions to its user
 ** Input: int, string, float, char
 ** Output: bool, int, string, float
**********************************/

#include <string> //getline() length() +=
#include <cmath> //pow()  abs()
#include <iostream>

using namespace std;
#include "helper_functions.h"


/////////////////////
//       MAIN      //
/////////////////////


int main(){
    string pass = "BOTH PASS";
    string fail = "ONE OR BOTH FAIL";
    cout<<"Function: check_range()"<<endl;
    cout<<"Test 1:"<<endl;
    cout<<"lower_bound = 0, upper_bound = 100, value = 54"<<endl;
    cout<<"Expected: 1"<<endl;
    cout<<"Actual: "<<check_range(0,100,54)<<endl;

    cout<<"Test 2:"<<endl;
    cout<<"lower_bound = 0, upper_bound = 100, value = 110"<<endl;
    cout<<"Expected: 0"<<endl;
    cout<<"Actual: "<<check_range(0,100,110)<<endl;

    if(check_range(0,100,54) == 1 && check_range(0,100,110) == 0){
        cout<<pass<<endl;
    }
    else{cout<<fail<<endl;}

    functionSeparation();

    cout<<"Function: is_int()"<<endl;
    cout<<"Test 1:"<<endl;
    cout<<"num = 154"<<endl;
    cout<<"Expected: 1"<<endl;
    cout<<"Actual: "<<is_int("154")<<endl;

    cout<<"Test 2:"<<endl;
    cout<<"num = 154.05"<<endl;
    cout<<"Expected: 0"<<endl;
    cout<<"Actual: "<<is_int("154.05")<<endl;

    if(is_int("154") == 1 && is_int("154.05") == 0){
        cout<<pass<<endl;
    }
    else{cout<<fail<<endl;}

    functionSeparation();

    cout<<"Function: is_float()"<<endl;
    cout<<"Test 1:"<<endl;
    cout<<"num = 12.34"<<endl;
    cout<<"Expected: 1"<<endl;
    cout<<"Actual: "<<is_float("12.34")<<endl;

    cout<<"Test 2:"<<endl;
    cout<<"num = 15"<<endl;
    cout<<"Expected: 0"<<endl;
    cout<<"Actual: "<<is_float("15")<<endl;

    if(is_float("12.34") && is_float("15")){
        cout<<pass<<endl;
    }
    else{cout<<fail<<endl;}

    functionSeparation();

    cout<<"Function: is_capital()"<<endl;
    cout<<"Test 1:"<<endl;
    cout<<"letter = 'H'"<<endl;
    cout<<"Expected: 1"<<endl;
    cout<<"Actual: "<<is_capital('H')<<endl;

    cout<<"Test 2:"<<endl;
    cout<<"letter = 'd'"<<endl;
    cout<<"Expected: 0"<<endl;
    cout<<"Actual: "<<is_capital('d')<<endl;

    if(is_capital('H') == 1 && is_capital('d') == 0){
        cout<<pass<<endl;
    }
    else{cout<<fail<<endl;}

    functionSeparation();

    cout<<"Function: is_even()"<<endl;
    cout<<"Test 1:"<<endl;
    cout<<"num = 14"<<endl;
    cout<<"Expected: 1"<<endl;
    cout<<"Actual: "<<is_even(14)<<endl;

    cout<<"Test 2:"<<endl;
    cout<<"num = 11"<<endl;
    cout<<"Expected: 0"<<endl;
    cout<<"Actual: "<<is_even(11)<<endl;

    if(is_even(14) == 1 && is_even(11) == 0){
        cout<<pass<<endl;
    }
    else{cout<<fail<<endl;}

    functionSeparation();

    cout<<"Function: is_odd()"<<endl;
    cout<<"Test 1:"<<endl;
    cout<<"num = 13"<<endl;
    cout<<"Expected: 1"<<endl;
    cout<<"Actual: "<<is_odd(13)<<endl;

    cout<<"Test 2:"<<endl;
    cout<<"num = 20"<<endl;
    cout<<"Expected: 0"<<endl;
    cout<<"Actual: "<<is_odd(20)<<endl;

    if(is_odd(13) == 1 && is_odd(20) == 0){
        cout<<pass<<endl;
    }
    else{cout<<fail<<endl;}

    functionSeparation();

    cout<<"Function: equality_test()"<<endl;
    cout<<"Test 1:"<<endl;
    cout<<"num1 = 10, num2 = 10"<<endl;
    cout<<"Expected: 0"<<endl;
    cout<<"Actual: "<<equality_test(10,10)<<endl;

    cout<<"Test 2:"<<endl;
    cout<<"num1 = 5, num2 = 10"<<endl;
    cout<<"Expected: -1"<<endl;
    cout<<"Actual: "<<equality_test(5,10)<<endl;

    cout<<"Test 3:"<<endl;
    cout<<"num1 = 10, num2 = 15"<<endl;
    cout<<"Expected: 1"<<endl;
    cout<<"Actual: "<<equality_test(15,10)<<endl;

    if(!equality_test(10,10) && equality_test(15,10) && equality_test(5,10) == -1){
        cout<<pass<<endl;
    }
    else{ cout<<fail<<endl; }

    functionSeparation();

    cout<<"Function: float_is_equal()"<<endl;
    cout<<"Test 1:"<<endl;
    cout<<"num1 = 123.50, num2 = 123.45, precision = .1"<<endl;
    cout<<"Expected: 1"<<endl;
    cout<<"Actual: "<<float_is_equal(123.50,123.45,.1)<<endl;

    cout<<"Test 2:"<<endl;
    cout<<"num1 = 5.02, num2 = 5.09, precision = .002"<<endl;
    cout<<"Expected: 0"<<endl;
    cout<<"Actual: "<<float_is_equal(5.02,5.09,.002)<<endl;

    if(float_is_equal(123.50,123.45,.1) && !float_is_equal(5.02,5.09,.002)){
        cout<<pass<<endl;
    }
    else{cout<<fail<<endl;}

    functionSeparation();

    cout<<"Function: numbers_present()"<<endl;
    cout<<"Test 1:"<<endl;
    cout<<"sentence = hell0 w0rld"<<endl;
    cout<<"Expected: 1"<<endl;
    cout<<"Actual: "<<numbers_present("hell0 w0rld")<<endl;

    cout<<"Test 2:"<<endl;
    cout<<"sentence = hello world"<<endl;
    cout<<"Expected: 0"<<endl;
    cout<<"Actual: "<<numbers_present("hello world")<<endl;

    if(numbers_present("hell0 w0rld") && !numbers_present("hello world")){
        cout<<pass<<endl;
    }
    else{cout<<fail<<endl;}

    functionSeparation();

    cout<<"Function: letters_present()"<<endl;
    cout<<"Test 1:"<<endl;
    cout<<"sentence = hell0 w0rld"<<endl;
    cout<<"Expected: 1"<<endl;
    cout<<"Actual: "<<letters_present("hell0 w0rld")<<endl;

    cout<<"Test 2:"<<endl;
    cout<<"sentence = 12345"<<endl;
    cout<<"Expected: 0"<<endl;
    cout<<"Actual: "<<letters_present("12345")<<endl;
    if(letters_present("hell0 w0rld") && !letters_present("12345")){
        cout<<pass<<endl;
    }
    else{cout<<fail<<endl;}

    functionSeparation();

    cout<<"Function: contains_sub_string()"<<endl;
    cout<<"Test 1:"<<endl;
    cout<<"sentence = hello world, sub_string = hello"<<endl;
    cout<<"Expected: 1"<<endl;
    cout<<"Actual: "<<contains_sub_string("hello world", "hello")<<endl;

    cout<<"Test 2:"<<endl;
    cout<<"sentence = hello world, sub_string = hello world1"<<endl;
    cout<<"Expected: 0"<<endl;
    cout<<"Actual: "<<contains_sub_string("hello world", "hello world1")<<endl;

    if(contains_sub_string("hello world", "hello") && !contains_sub_string("hello world", "hello world1")){
        cout<<pass<<endl;
    }
    else{cout<<fail<<endl;}

    functionSeparation();

    cout<<"Function: word_count()"<<endl;
    cout<<"Test 1:"<<endl;
    cout<<"sentence = hello world"<<endl;
    cout<<"Expected: 2"<<endl;
    cout<<"Actual: "<<word_count("hello world")<<endl;

    cout<<"Test 2:"<<endl;
    cout<<"sentence = "<<endl;
    cout<<"Expected: 0"<<endl;
    cout<<"Actual: "<<word_count("")<<endl;

    if(contains_sub_string("hello world", "hello") && !contains_sub_string("hello world", "hello world1")){
        cout<<pass<<endl;
    }
    else{cout<<fail<<endl;}

    functionSeparation();

    cout<<"Function: to_upper()"<<endl;
    cout<<"Test 1:"<<endl;
    cout<<"sentence = hello world"<<endl;
    cout<<"Expected: HELLO WORLD"<<endl;
    cout<<"Actual: "<<to_upper("hello world")<<endl;

    cout<<"Test 2:"<<endl;
    cout<<"sentence = 1234"<<endl;
    cout<<"Expected: 1234"<<endl;
    cout<<"Actual: "<<to_upper("1234")<<endl;

    if(to_upper("hello world") == "HELLO WORLD" && to_upper("1234") == "1234"){
        cout<<pass<<endl;
    }
    else{cout<<fail<<endl;}


    functionSeparation();

    cout<<"Function: to_lower()"<<endl;
    cout<<"Test 1:"<<endl;
    cout<<"sentence = HELLO WORLD"<<endl;
    cout<<"Expected: hello world"<<endl;
    cout<<"Actual: "<<to_lower("HELLO WORLD")<<endl;

    cout<<"Test 2:"<<endl;
    cout<<"sentence = H3770 W0rLd"<<endl;
    cout<<"Expected: h3770 w0rld"<<endl;
    cout<<"Actual: "<<to_lower("H3770 W0rLd")<<endl;

    if(to_lower("HELLO WORLD") == "hello world" && to_lower("H3770 W0rLd") == "h3770 w0rld"){
        cout<<pass<<endl;
    }
    else{cout<<fail<<endl;}

    functionSeparation();

    string prompt;
    cout<<"Give me an integer: " <<endl;
    getline(cin, prompt);
    get_int(prompt);

    functionSeparation();
    prompt = "";
    cout<<"Give me a float: " <<endl;
    getline(cin, prompt);
    get_float(prompt);

}









