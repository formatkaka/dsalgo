//
// Created by Siddhant on 2019-08-27.
//

#include <vector>
#include "iostream"
//#include <bits/stdc++.h>

int main(){

    std::vector<int> vec;

    vec.push_back(3);
    vec.push_back(0);
    vec.push_back(7);

    std::vector<int>::iterator it1 = vec.begin();
    std::vector<int>::iterator it2 = vec.end();

//    std::cout << std::sort(it1, it2)
    std::sort(it1, it2);

    for (std::vector<int>::iterator it = it1; it != it2 ; ++it) {
        std::cout << *it << std::endl;
    }


    // size
    std::cout << "vector size : " << vec.size() << std::endl;
    std::cout << "vec access : " << vec.at(2)<< std::endl ; // Will throw range error if index is out of bound

    std::vector<int> vec_copy(vec);

    for (std::vector<int>::iterator it = vec_copy.begin(); it != vec_copy.end() ; ++it) {
        std::cout << *it << std::endl;
    }

    // clear vec
    vec.clear();

    vec_copy.swap(vec);

    std::cout << "Is vec copy empty ? " << vec_copy.size() << std::endl;


    return 0;

}