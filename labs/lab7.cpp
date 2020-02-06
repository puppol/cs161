#include <iostream>
#include <string>
using namespace std;

void get_string(string*);
void set_replace_string(string, string*);
int get_replace_string(char,string,string &);


void get_string(string *str){
    string copy = *str;
    //cout<<"Copy = " << copy << endl;
    set_replace_string(copy, str);
}

void set_replace_string(string strCopy, string *str){
    for(int i = 0; i < strCopy.length(); i++)
        if(strCopy[i] != ' ')
            strCopy[i] = '-';
    cout<<strCopy<<endl;
    cout<<"Enter a char: "<<endl;
    char userChar;
    cin >> userChar;

    cout<<get_replace_string(userChar,strCopy,*str) <<endl;
}

int get_replace_string(char c, string copy, string &str){
    int counter = 0;
    for(int i = 0; i < copy.length(); i++){
        if(str[i] == c){
            copy[i] = c;
            counter++;
        }
    }
    cout<<copy<<endl;
    return counter;
}


int main(){
    string userInput = "";
    cout<<"Please enter string: " << endl;
    getline(cin, userInput);
    get_string(&userInput);


    return 0;
}
