#include <iostream>
#include <string>
using namespace std;


int* mem1();
void mem2(int**);
void mem3(int*&);


int* mem1(){
    int* newPointer = new int;
    *newPointer = 5;
    return newPointer;
}

void mem2(int** p){
    cout<<*p<<endl;
    cout<<**p<<endl;
    delete *p;
}

void mem3(int*& p){
    cout<<*p<<endl;
    cout<<&*p<<endl;
    delete p;
}

int main(){
    int* func1 = mem1();
    cout<<func1<<endl;
    cout<<*func1<<endl;

    int* func2 = new int;
    mem2(&func2);

    int* func3 = new int;
    mem3(func3);

    delete func1;
    







}
