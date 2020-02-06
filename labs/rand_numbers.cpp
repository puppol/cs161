#include <iostream>
#include <ctime> /*included to allow time() to be used*/
#include <cstdlib> /*include to allow rand() and srand() to be used*/
using namespace std;
int main() {
	int x; /* variable to hold our random integer*/
	srand(time(NULL)); /*seeds random number generator. Do this just once*/
	x = rand();
	cout << "x = " << x << endl;
	//srand(time(NULL));
	x = rand();
	cout << "x = " << x << endl;
	

	x = rand() % 6;
	cout<<"x = " << x << endl;

	if(x == 0){
		cout<<"Bummer, I'm zero!"<<endl;
	}
	else if(x % 2 == 0){
		cout<<"I am an even number"<<endl;
	}
	else{
		cout<<"I am an odd number"<<endl;
	}
}
