#include <iostream>
#include <cstdlib>

using namespace std;

void towers(int disks, int **b, int from_col, int to_col, int spare);


void printArray(int disks, int **b){
    for(int i = 0; i < disks; i++){
        for(int j = 0; j < 3; j++)
            cout<<b[i][j] << " ";
        cout<<endl;
    }
    cout<<"-------------"<<endl;

}
void towers(int disks, int **b, int from_col, int to_col, int spare,int totalDisks){
    if(disks >= 1){
        towers(disks-1, b, from_col, spare, to_col,totalDisks);
        int tempValue = 0;
        for(int i = 0; i < totalDisks; i++)
            if(b[i][from_col] != 0){
                tempValue = b[i][from_col];
                b[i][from_col] = 0;
                break;
            }
        for(int i = 0; i < totalDisks; i++){
            if(b[i][to_col] != 0){
                b[i-1][to_col] = tempValue;
                break;
            }
            else if(i == totalDisks - 1){
                b[i][to_col] = tempValue;
                break;
            }

        }
        towers(disks-1,b,spare,to_col,from_col,totalDisks);
    }

    printArray(totalDisks,b);
}



void makeArray(int disks, int **b){
    for(int i = 0; i < disks; i++)
        for(int j = 0; j < 3; j++)
            b[i][j] = (j==0) ? i+1 : 0;
}

void deleteArray(int disks, int **b){
    for(int i = 0; i < disks; i++)
        delete [] b[i];
    delete [] b;
}

int main(int argc, char** argv){
    int userInput = atoi(argv[1]);

    int** b = new int*[userInput];
    for(int i = 0; i < userInput; i++)
        b[i] = new int[3];

    cout<<"Created array"<<endl;
    makeArray(userInput,b);
    printArray(userInput,b);
    towers(userInput,b,0,2,1,userInput);
    printArray(userInput,b);
    deleteArray(userInput,b);
 }

