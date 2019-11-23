//
// Created by Siddhant on 2019-09-10.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int main(){

    string s = "ebcbbececabbacecbbcbe";

    auto start = s.begin();
    auto end = s.end() - 1;
    bool deleteDone = false;
    bool altAvailable = false;

    auto altStart = s.begin();
    auto altEnd = s.end();

    while(start < end){

        if((*start != *end) && deleteDone && !altAvailable) return 0;

        if((*start != *end) && deleteDone && altAvailable){
            start = altStart;
            end = altEnd;
            altAvailable = false;
        }

        if((*start != *end)){

            bool canMoveEndPointer = *start == *(end-1);
            bool canMoveStartPointer = *(start+1) == *end;

            if(canMoveEndPointer){
                end--;
                deleteDone = true;
            }else if(canMoveStartPointer){
                start++;
                deleteDone = true;
            }else{
                return 0;
            }

            if(canMoveStartPointer && canMoveEndPointer){
                altStart = start+1;
                altEnd = end;
                altAvailable = true;
            }
        }

        start++;
        end--;

    }

    return 1;
}

/*
 * Attempt 1 : Missed edge case - (*start == *(end-1)) and (*(start+1) == *end)
 *
 * Which char to delete if both the cases are true ?
 *
 * One solution can be to save the alternate path and if the current path fails, switch to that path.
 * It's not possible to predict what can happen down the line from here, thus the best path seems to be to reset
 *
 */