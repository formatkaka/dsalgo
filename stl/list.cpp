//
// Created by Siddhant on 2019-08-27.
//

#include "iostream"
#include "list"

using namespace std;

void print_list(std::list<int> deq){
    for (auto it = deq.begin() ; it != deq.end() ; it++) {
        std::cout << *it << " " ;
    }
    std::cout << std::endl;
}

int main(){

    std::list<int> my_list;
    std::list<int> temp_list;

    temp_list.push_front(6);
    temp_list.push_front(-3);
    temp_list.push_front(3);

    my_list.push_back(2);
    my_list.push_front(5);
    my_list.push_front(8);

    print_list(my_list);

    auto itr = find(my_list.begin(), my_list.end(), 5);
    my_list.insert(itr, 4);

    print_list(my_list);

//    my_list.erase(itr);

//    print_list(my_list);

    my_list.splice(itr, temp_list, temp_list.begin(), temp_list.end());
    print_list(my_list);

}