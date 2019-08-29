//
// Created by Siddhant on 2019-08-27.
//

#include "iostream"
#include "deque"

void print_deque(std::deque<int> deq){
    for (auto it = deq.begin() ; it != deq.end() ; it++) {
        std::cout << *it << " " ;
    }
    std::cout << std::endl;
}

int main(){

    std::deque<int> my_deque;

    std::cout << "Deque size : " << my_deque.size() << std::endl;

    my_deque.push_back(2);
    my_deque.push_front(5);

    print_deque(my_deque);

    my_deque.push_front(9);

    print_deque(my_deque);

    std::cout << "Value at index 0 : " << my_deque.at(2) << std::endl;

    return 0;
}