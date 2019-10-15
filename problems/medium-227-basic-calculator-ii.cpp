//
// Created by Siddhant on 2019-10-15.
//

#include "iostream"
#include "vector"
#include "string"
#include "stack"

using namespace std;

int getOperandPrecedence(char operand) {

    switch (operand) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }

    return INT_MIN;

}

string infixToPostfix(string infixEquation) {

    stack<char> s;
    string postfixEquation = "";

    for (int i = 0; i < infixEquation.length();i++) {

        if (isdigit(infixEquation[i])) {
//            postfixEquation += '[';
            while(i<infixEquation.length() && isdigit(infixEquation[i])){
                postfixEquation += infixEquation[i];
                i++;
            }
//            postfixEquation += ']';
        }

        if(i >= infixEquation.length()){
            break;
        }

        char stackTop = s.empty() ? '.' : s.top();
        int stackTopPrecedence = getOperandPrecedence(stackTop);
        int currOpPrecedence = getOperandPrecedence(infixEquation[i]);

        if (currOpPrecedence > stackTopPrecedence) {
            s.push(infixEquation[i]);
            continue;
        }

        while (!s.empty()) {
            postfixEquation += s.top();
            s.pop();
        }

        s.push(infixEquation[i]);

    }

    while (!s.empty()) {
        postfixEquation += s.top();
        s.pop();
    }


    return postfixEquation;
}

int solveOperand(int num1, int num2, char operand){

    switch (operand){
        case '+':
            return num1 + num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        case '-':
            return num1 - num2;
    }
    return INT_MIN;
}

int calculatePostfix(string postfixEquation){

    stack<int> nums;

    for (int i = 0; i < postfixEquation.length(); ++i) {

        if(postfixEquation[i] == '['){
            i++;
            string num;
            while(postfixEquation[i] != ']'){
                num += postfixEquation[i];
                i++;
            }
            nums.push(stoi(num));
            continue;
        }

        int n1 = nums.top(); nums.pop();
        int n2 = nums.top(); nums.pop();

        int ans = solveOperand(n2, n1, postfixEquation[i]);
        nums.push(ans);

    }

    return nums.top();

}

int main() {

    string equation = "1+2*5/3+6/4*2";

    // remove spaces
    equation.erase(remove(equation.begin(), equation.end(), ' '), equation.end());

    // convert infix to postfix form
    string postfixEquation = infixToPostfix(equation);
    cout << "postfix form is : " << postfixEquation << endl;

    // calculate postfix form
//    cout << "equation answer is : " << calculatePostfix(postfixEquation);

    return 0;
}