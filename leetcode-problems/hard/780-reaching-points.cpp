//
// Created by Siddhant on 2019-11-17.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

//bool find(int x, int y, int sx, int sy, int tx, int ty, bool& done) {
//
//    if (done) {
//        return true;
//    }
//
//    if (x < sx || y < sy) {
//        return false;
//    }
//
//    if (x == sx && y == sy) {
//        done = true;
//        return true;
//    }
//
//    find(x - y, y, sx, sy, tx, ty, done);
//    find(x, y - x, sx, sy, tx, ty, done);
//
//    return done;
//}

bool find(int sx, int sy, int tx, int ty){

    while(tx >= sx && ty >= sy){
        if(tx == ty) break;

        if(tx > ty){

            if(ty == sy){
                return (tx-sx)%ty == 0;
            }

            tx %= ty;
            cout << "tx%=ty : " << tx << endl;
        }else {

            if(tx == sx){
                return (ty-sy)%tx == 0;
            }

            ty%= tx;
            cout << "ty%=tx : " << ty << endl;
        }

    }

    return (tx == sx) && (ty == sy);



}

bool reachingPoints(int sx, int sy, int tx, int ty) {
    bool done = find(sx, sy, tx, ty);
    cout << done << endl;
    return done;
}

int main() {

    reachingPoints(1,1,100000000,2);
    int z = 10000;
    z %= 1;
    cout << "z : " <<  z;
    return 0;
}