//
// Created by Siddhant on 2019-10-01.
//

#include "iostream"
#include "vector"
#include "string"
#include "stack-using-array.h"
#include "stack"
#include "unordered_map"
#include "algorithm"

using namespace std;

bool isNotSpecialChar(char op) {
    return (op >= 65 && op <= 90) || (op >= 97 && op <= 122);
}

int getOperandPrecedence(char op) {
    unordered_map<char, int> precedenceMapping;
    precedenceMapping.insert(make_pair('+', 1));
    precedenceMapping.insert(make_pair('-', 1));
    precedenceMapping.insert(make_pair('*', 2));
    precedenceMapping.insert(make_pair('/', 2));

    return precedenceMapping.at(op);
}

void calculatePostfix(string postfixEq) {

    unordered_map<char, int> varMapping;
    varMapping.insert(make_pair('a', 5));
    varMapping.insert(make_pair('b', 4));
    varMapping.insert(make_pair('c', 3));
    varMapping.insert(make_pair('d', 2));
    varMapping.insert(make_pair('e', 1));

    stack<int> c;
    for (auto op = postfixEq.begin(); op != postfixEq.end(); ++op) {

        if (isNotSpecialChar(*op)) {
            c.push(varMapping.at(*op));
            continue;
        }

        int x1 = c.top();
        c.pop();
        int x2 = c.top();
        c.pop();
        int ans = INT_MIN;
        switch (*op) {
            case '+':
                ans = x1 + x2;
                break;
            case '-':
                ans = x2 - x1;
                break;
            case '*':
                ans = x1 * x2;
                break;
            case '/':
                ans = x2 / x1;
                break;
        }
        c.push(ans);
    }

    cout << "Ans : " << c.top();
}

int main() {

    string expr = "a+b*c-d/e";
    string output = "";
    stack<char> s;
    for (auto op = expr.begin(); op != expr.end(); ++op) {

        if (isNotSpecialChar(*op)) {
            output += (*op);
            continue;
        }


        while (!s.empty()) {
            if (getOperandPrecedence(s.top()) >= getOperandPrecedence(*op)) {
                output += s.top();
                s.pop();
            } else {
                break;
            }
        }

        s.push(*op);
    }


    while (!s.empty()) {
        output += s.top();
        s.pop();
    }
    cout << "output : " << output << endl;

    calculatePostfix(output);

    return 0;
}

// This does not work because, s.size is dynamic.
//    for (int i = 0; i < s.size(); ++i) {
//        cout << s.top();
//        s.pop();
//    }