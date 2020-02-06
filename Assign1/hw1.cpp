/****************
 * Program File Name: hw1.cpp
 * Author: Luke Puppo
 * Date: 1/8/18
 * Description: Homework 1
 * Input: None
 * Output: Various prints to the screen
 * *************/

#include <cmath>
#include <iostream>
using namespace std;

int main(){
	cout<<"cos(2/3) =  "<<cos(2.0/3.0)<<endl;
	cout<<"2sin(2/3) = "<<2*sin(2.0/3.0)<<endl;
	cout<<"tan(-3/4) = "<<tan(-3.0/4.0)<<endl;
	cout<<"log10 55 = "<<log10(55)<<endl;
	cout<<"ln 60 = "<<log(60)<<endl<<endl;



/////////////////////////////////////////////


	cout<<"Find the log base 2 of 15"<<endl;
	cout<<"ln(x) = "<<log(15)<<endl;
	cout<<"ln(b) = "<<log(2)<<endl;
	cout<<"ln(x)/ln(b) = "<<log(15)/log(2)<<endl<<endl;
	

	cout<<"Find the log base 4 of 40"<<endl;
	cout<<"ln(x) ="<<log(40)<<endl;
	cout<<"ln(b) ="<<log(4)<<endl;
	cout<<"ln(x)/ln(b) = "<<log(40)/log(4)<<endl<<endl;

    
///////////////////////////////////////////////
    
    
	double x = 1.0;
	cout<<"3^sin(x) where x is 1, 10 and 100"<<endl;
    cout<<"sin(1) = "<<sin(x)<<endl;
	cout<<"3^sin(1) = "<<pow(3,sin(1.0))<<endl;
	x = 10.0;
    cout<<"sin(10) = "<<sin(x)<<endl;
	cout<<"3^sin(10) = "<<pow(3,sin(x))<<endl;
	x = 100.0;
    cout<<"sin(100) = "<<sin(x)<<endl;
	cout<<"3^sin(100) = "<<pow(3,sin(x))<<endl<<endl;

    x = 1.0;
    cout<<"Find log2(1^2 + 1) as x = 1"<<endl;
    cout<<"1^2 + 1 = "<<pow(x,2)+1<<endl;
    cout<<"ln(x) = "<<log(pow(x,2)+1)<<endl;
    cout<<"ln(b) = "<<log(2)<<endl;
    cout<<"log2(1^2 + 1) = "<<(log(pow(1,2)+1))/(log(2))<<endl<<endl;
    
    x = 10.0;
    cout<<"Find log2(10^2 + 1) as x = 10"<<endl;
    cout<<"10^2 + 1 = "<<pow(x,2)+1<<endl;
    cout<<"ln(x) = "<<log(pow(x,2)+1)<<endl;
    cout<<"ln(b) = "<<log(2)<<endl;
    cout<<"log2(10^2 + 1) = "<<(log(pow(x,2)+1))/(log(2))<<endl<<endl;
    
    x = 100;
    cout<<"Find log2(100^2 + 1) as x = 100"<<endl;
    cout<<"100^2 + 1 = "<<pow(x,2)+1<<endl;
    cout<<"ln(x) = "<<log(pow(x,2)+1)<<endl;
    cout<<"ln(b) = "<<log(2)<<endl;
    cout<<"log2(100^2 + 1) = "<<(log(pow(x,2)+1))/(log(2))<<endl<<endl;
    

	return 0;
}
