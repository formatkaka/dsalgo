//
// Created by Siddhant on 2019-10-16.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int trap(vector<int>& height) {

    if(height.size() < 3) return 0;

    int waterCapacity = 0;
    int secStart = 0;
    int secEnd = 0;
    int sectionFound = false;
    for (int i = 1; i < height.size(); ++i) {

        // get section
        if(height[i] >= height[secStart]){
            secEnd = i;
            sectionFound = true;
        }else if(i == height.size()-1 && secStart < height.size() - 1){
            secStart += 1;
            i = secStart;
        }

        if(sectionFound){

            for (int j = secStart+1; j < secEnd; ++j) {
                waterCapacity += (height[secStart] - height[j]);
            }

            secStart = secEnd;
            sectionFound = false;
        }

    }

    cout << "water capacity L2R : " << waterCapacity << endl;

    secStart = height.size()-1;
    secEnd = 0;
    sectionFound = false;

    for (int i = height.size()-2; i > 0; --i) {

        // get section
        if(height[i] > height[secStart]){
            secEnd = i;
            sectionFound = true;
        }else if(i == 0 && secStart > 0){
            secStart -= 1;
            i = secStart;
        }

        if(sectionFound){

            for (int j = secStart-1; j > secEnd; --j) {
                waterCapacity += (height[secStart] - height[j]);
            }

            secStart = secEnd;
            sectionFound = false;
        }

    }

    return waterCapacity;

}

int main(){

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "water holding capacity : " << trap(height);
    return 0;
}