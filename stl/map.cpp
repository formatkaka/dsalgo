//
// Created by Siddhant on 2019-08-27.
//

#include "iostream"
#include "map"

using namespace std;

void print_map(std::map<char,int> mymap){
    for (auto it = mymap.begin() ; it != mymap.end() ; it++) {
        std::cout << (*it).first << " " << (*it).second << std::endl ;
    }
    std::cout << std::endl;
}

int main(){

    map<char, int> mymap;
    mymap.insert(make_pair('a',100));
    mymap.insert(make_pair('c',102));
    mymap.insert(make_pair('e',105));
    mymap.insert(make_pair('1',10));
    mymap.insert(make_pair('"',110));
    mymap.insert(make_pair('a', 10));

    map<char, int>::iterator itr;

    itr = mymap.find('e');
    print_map(mymap);

    return 0;
}
