#include <iostream>
#include <climits>
#include <cmath>


using namespace std;

int main(){
	    cout << "Please insert the number of bytes you would like to use?" <<endl;
		double bytes = 0;
		cin >> bytes;
		double bits = bytes*8;

		double minUns = 0;
		double maxUns = pow(2,bits) - 1;
		double minSign = -1*pow(2,bits-1);
		double maxSign = pow(2,bits-1) -1;


		cout<<"Min Unsigned: "<<minUns<<endl;
		cout<<"Max Unsigned: "<<maxUns<<endl;
		cout<<"Min Signed: "<<minSign<<endl;
		cout<<"Max Signed: "<<maxSign<<endl;
}

