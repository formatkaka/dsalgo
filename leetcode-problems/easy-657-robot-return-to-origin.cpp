#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

int main(){

    string moves = "LURD";
    int horizontal = 0;
    int vertical = 0;

    for (int i = 0; i < moves.size(); i++) {

        switch (moves[i]) {
            case 'U':
                vertical++;
                break;
            case 'D':
                vertical--;
                break;
            case 'L':
                horizontal--;
                break;
            case 'R':
                horizontal++;
                break;

        }

    }

    if(horizontal==0 && vertical==0){
        cout << "True";
    }else{
        cout << "False";
    }


    return 0;
}

/*
 * Final Solution:
 *
 * #include "algorithm"
 *
 * std::count --> Returns the number of elements in the range [first,last) that compare equal to val.
 *
 * return
 *      count(begin(moves), end(moves), 'U') == count(begin(moves), end(moves), 'D') &&
 *      count(begin(moves), end(moves), 'L') == count(begin(moves), end(moves), 'R');
 *
 */