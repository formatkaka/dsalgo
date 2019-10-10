//
// Created by Siddhant on 2019-10-10.
//

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

//int totalSteps[]

int getTotalSteps(vector<int> & totalSteps, int steps, int index){

    if(index > steps-2){
        return 0;
    }

    if(totalSteps[index]>-1){
        return totalSteps[index];
    }

    int s = getTotalSteps(totalSteps, steps, index+1) + getTotalSteps(totalSteps, steps, index+2);

    totalSteps[index] = 1+s;
    return 1+s;

}

int main(){

    cout << "Enter steps : " ;
    int steps;
    cin >> steps;
    vector<int> totalSteps(steps, -1);
    cout << "Total steps possible are : " << getTotalSteps(totalSteps, steps, 0)+1;
    return 0;
}