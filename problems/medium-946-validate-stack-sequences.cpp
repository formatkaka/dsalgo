//
// Created by Siddhant on 2019-11-04.
//

#include "iostream"
#include "vector"
#include "string"
#include "stack"

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

    if(pushed.empty()){
        return true;
    }

    int popIndex = 0;
    int pushIndex = 1;

    stack<int> pushStack;
    pushStack.push(pushed[0]);

    while(pushIndex <= pushed.size() && popIndex <= pushed.size()){

        if(pushIndex == pushed.size() && popIndex == pushed.size()  && pushStack.empty()){
            return true;
        }


        if(!pushStack.empty() && pushStack.top() == popped[popIndex]){
            pushStack.pop();
            popIndex++;
        }else if(pushIndex < pushed.size()){
            pushStack.push(pushed[pushIndex]);
            pushIndex++;
        }else{
            return false;
        }


    }

    return true;

}

int main(){

    vector<int> pushed = {1,2,3};
    vector<int> popped = {2,1,3};
    cout << "valid stack sequence : " << validateStackSequences(pushed, popped);
    return 0;
}