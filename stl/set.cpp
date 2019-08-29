//
// Created by Siddhant on 2019-08-27.
//

#include "iostream"
#include "set"


using namespace std;

void print_set(std::set<int> myset){
    for (auto it = myset.begin() ; it != myset.end() ; it++) {
        std::cout << *it << " " ;
    }
    std::cout << std::endl;
}

int main(){

    set<int> my_set;
    my_set.insert(3);
    my_set.insert(1);
    my_set.insert(2);
    my_set.insert(12);

    print_set(my_set);

    set<int>::iterator itr;

    itr = my_set.find(2);
    pair<set<int>::iterator, bool> ret;

    ret = my_set.insert(3);
    if(!ret.second){
        itr = ret.first;
    }

    my_set.insert(itr, 7);

    print_set(my_set);

    std::cout << "Iterator value : " << *itr << std::endl;

    my_set.erase(itr);

    print_set(my_set);



}