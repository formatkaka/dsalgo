//
// Created by Siddhant on 2019-09-10.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int main(){

    string input = ".,,ab";


    auto inputStart = input.begin();
    auto inputEnd = input.end() - 1;

        while(inputStart < inputEnd){

            /* Added while loops below because I didn't want the if condition to
             * be executed until I reach a valid character in the string
             *
             * Another way to write this is
             *
             * 	while(start<end) {
		     *      if (!isalnum(s[start])) start++;
		     *      else if (!isalnum(s[end])) end--;
             *      else {
             *      ...
             *      ...
             *      }
             *  }
             *
             *  Ref - https://leetcode.com/problems/valid-palindrome/discuss/40261/Passed-clean-c%2B%2B-code
             *
             */

            while(!isalnum(*inputStart) && inputStart < inputEnd){
                inputStart++;
            }

            while(!isalnum(*inputEnd) && inputStart < inputEnd){
                inputEnd--;
            }

            bool isValidPalindromeTillNow = tolower(*inputStart) == tolower(*inputEnd);


            if(!isValidPalindromeTillNow) {
                return 0;
            }

            inputStart++;
            inputEnd--;
        }

    return 1;
}



//
// Created by Siddhant on 2019-09-10.
//
//
//#include "iostream"
//#include "vector"
//#include "string"
//
//using namespace std;
//
//int main(){
//
//    string input = ".aab";
//
//
//    string middle = "";
//
//    for (auto str = input.begin(); str != input.end(); ++str) {
//        if(!isalnum(*str)) continue;
//
//        middle = middle + *str;
//    }
//
//    auto inputStart = middle.begin();
//    auto inputEnd = middle.end() - 1;
//
//    while(inputStart < inputEnd){
//
//        cout << "inputStart : " << *inputStart << endl;
//        cout << "inputEnd : " << *inputEnd << endl;
//
//
//        bool isValidPalindromeTillNow = tolower(*inputStart) == tolower(*inputEnd);
//
//
//        if(!isValidPalindromeTillNow) {
//            return 0;
//        }
//
//        inputStart++;
//        inputEnd--;
//
//    }
//
//
//
//    return 1;
//}