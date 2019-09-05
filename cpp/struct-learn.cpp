//
// Created by Siddhant on 2019-09-03.
//

#include "iostream"

struct Student {

    int rollno;
    char name[25];
    char dept[10];

};

int main(){

    struct Student Siddhant = {36, "Siddhant", "ECE"};

    std::cout << "rollno : " << Siddhant.rollno << std::endl;
    std::cout << "name : " << Siddhant.name << std::endl;
    std::cout << "dept : " << Siddhant.dept << std::endl;

}