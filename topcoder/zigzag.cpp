//
// Created by Siddhant on 2019-11-24.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

//class ZigZag{
//
//public:
//     int longestZigZag(vector<int> sequence){
//
//         vector<vector<int>> solution(sequence.size(), vector<int> (2, 1));
//        int res = 1;
//         for (int i = 0; i < sequence.size(); ++i) {
//
////             int m = 1;
////             int dir = 1;
//
//             for (int j = i-1; j >= 0; --j) {
//
//                 if(sequence[i] > sequence[j]){
//
////                     m = max(m, solution[j]+1);
//                     if(solution[i][0] < solution[j][1]+1){
//                         solution[i][0]  = solution[j][1]+1;
//                     }
//
//                 }else if(sequence[i] < sequence[j]){
//
////                     m = max(m, abs(solution[j])+1);
//
//                     if(solution[i][1] < solution[j][0]+1){
//                         solution[i][1]  = solution[j][0]+1;
//                     }
//
//
//                 }
//
//             }
//
//             res = max({res, solution[i][0], solution[i][1]});
//
//
//         }
//
//         return res ;
//
//     }
//
//};


 class ZigZag{

public:
     int longestZigZag(vector<int> sequence){

         vector<int> solution(sequence.size(), 1);
            int res = 1;
         for (int i = 0; i < sequence.size(); ++i) {

             int m = 1;
             int dir = 1;

             for (int j = i-1; j >= 0; --j) {

                 if(sequence[i] > sequence[j] && solution[j] > 0){

//                     m = max(m, solution[j]+1);
                     if(m < solution[j]+1){
                         dir = -1;
                         m = solution[j]+1;
                     }

                 }else if(sequence[i] < sequence[j] && solution[j] < 0){

//                     m = max(m, abs(solution[j])+1);

                     if(m < abs(solution[j])+1){
                        dir = 1;
                        m = abs(solution[j]) + 1;
                     }


                 }

             }

             solution[i] = m*dir;
            res = max(res, m);
         }

         return res;

     }

};

int main(){

    ZigZag z;
    vector<int> sequence = { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 249, 22, 176, 279, 23, 22, 617, 462, 459, 244 } ;
//    vector<int> sequence = { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 } ;
//    vector<int> sequence = { 1, 3,2, 3,3,3, 2} ;
    cout << abs(z.longestZigZag(sequence));
    return 0;
}