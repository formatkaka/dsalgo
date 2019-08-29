#include "iostream"
#include "vector"
#include "string"

using namespace std;

int main(){

    for (int i = 0; i < 5; ++i) {
        int found = 0;
        for (int j = 0; j < 7; ++j) {
            cout << " i j : " << i << " " << j << std::endl;
            if(j == 3) {

                cout << "Inside\n";
                break;
            }
        }

    }
    return 0;
}