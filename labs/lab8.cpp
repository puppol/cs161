#include <iostream>
#include <cstring>
using namespace std;

void get_string(char*);
void set_replace_string(char*, char*);
int get_replace_string(char*,char*);


void get_string(char *str){
    //cout<<"Copy = " << copy << endl;
    char copy[strlen(str)];
    strcpy(copy, str);
    set_replace_string(copy, str);
}

void set_replace_string(char* strCopy, char *str){
    int length = strlen(strCopy);
    for(int i = 0; i < length; i++)
        if(strCopy[i] != ' ')
            strCopy[i] = '-';
    cout<<strCopy<<endl;
    cout<<get_replace_string(strCopy, str) <<endl;
}

int get_replace_string(char *strCopy, char *str){
    int length = strlen(strCopy);
    cout<<"Enter a char: "<<endl;
    char c;
    cin >> c;
    int counter = 0;
    for(int i = 0; i < length; i++){
        if(str[i] == c){
            strCopy[i] = c;
            counter++;
        }
    }
    cout<<strCopy<<endl;
    return counter;
}


int main(){
    int maxNum = 0;
    cout<<"Please enter the number of characters you will be inputting: "<<endl;
    cin >> maxNum;
    char* userInput = new char[maxNum + 1];
    cout<<"Please enter string: " << endl;
    cin.ignore();
    cin.getline(userInput,maxNum);
    get_string(userInput);

    delete [] userInput;

    return 0;
}
