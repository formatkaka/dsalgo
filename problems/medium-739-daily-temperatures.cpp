//
// Created by Siddhant on 2019-10-17.
//

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

//vector<int> dailyTemperatures(vector<int>& T) {
//
//    vector<int> soln;
//    vector<int> mapToNextLargest;
//    bool foundByMemo = false;
//
//    for (int i = 0; i < T.size(); ++i) {
//        int j = i;
//        foundByMemo = false;
//
//        for (int k = 0; k < i; ++k) {
//            if(T[k] == T[i]){
//                if(mapToNextLargest[k] == -1){
//                    soln.push_back(0);
//                    mapToNextLargest.push_back(-1);
//                    foundByMemo = true;
//                    break;
//                }else if(mapToNextLargest[k] > i){
//                    soln.push_back(mapToNextLargest[k] - i);
//                    mapToNextLargest.push_back(i);
//                    foundByMemo = true;
//                    break;
//                }
//            }
//        }
//
//        if(foundByMemo){
//            continue;
//        }
//
//        // search
//        while(j < T.size() && T[j] <= T[i]){
//            j++;
//        }
//
//        if(
//           (j > T.size()-1) ||
//           (j == T.size()-1 && T[j] < T[i]) ||
//           (i == T.size()-1))
//        {
//            soln.push_back(0);
//            mapToNextLargest.push_back(-1);
//        }else{
//            soln.push_back(j-i);
//            mapToNextLargest.push_back(j);
//        }
//
//    }
//
//    return soln;
//
//}

int findGreaterIndex(vector<int> indexes, int currIndex) {
    auto findIt = upper_bound(indexes.begin(), indexes.end(), currIndex);
    if (findIt != indexes.end()) {
        return *findIt ;
    }

    return -1;
}

vector<int> dailyTemperatures(vector<int> T) {

    vector<vector<int>> tempHash(71);
    vector<int> solution;

    for (int i = 0; i < T.size(); ++i) {

        tempHash[T[i] - 30].push_back(i);
    }

    for (int j = 0; j < T.size(); ++j) {

        int temp = T[j]+1;
        solution.push_back(0);
        while (temp < 100) {
            int nextGreaterIndex = findGreaterIndex(tempHash[temp-30], j);

            if (nextGreaterIndex > j) {
                solution[j] = nextGreaterIndex-j;
                break;
            } else {
                temp++;
            }

        }


    }

    return solution;

}

int main() {

    vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
//    cout << "lower bound : " << findGreaterIndex(T, 34);
    vector<int> soln = dailyTemperatures(T);
    for (int i = 0; i < soln.size(); ++i) {
        cout << i << " : " << soln[i] << endl;
    }

    return 0;
}