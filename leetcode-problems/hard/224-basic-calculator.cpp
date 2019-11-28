//
// Created by Siddhant on 2019-11-28.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"
#include "stack"

using namespace std;

const char DIV = '/';
const char MUL = '*';
const char ADD = '+';
const char SUB = '-';

char OPENING_BRACKET = '(';
char CLOSING_BRACKET = ')';

bool isop(char c) {
    return c == DIV || c == MUL || c == ADD || c == SUB;
}

int getPrecedence(char op) {

    unordered_map<char, int> prec;
    prec.insert(make_pair(DIV, 3));
    prec.insert(make_pair(MUL, 3));
    prec.insert(make_pair(ADD, 1));
    prec.insert(make_pair(SUB, 1));

    return prec[op];
}

int findClosingBracket(string s, int startIndex) {

    int openingBr = 1;
    int closingBr = 0;


    while(openingBr != closingBr){
        startIndex++;

        if(s[startIndex] == CLOSING_BRACKET){
            closingBr++;
        }

        if(s[startIndex] == OPENING_BRACKET){
            openingBr++;
        }

//        startIndex++;

    }

    return startIndex;

}

string infixToPostfix(string s, int startIndex, int endIndex) {

    string res = "";
    stack<char> ops;

    while (startIndex <= endIndex) {

        char c = s[startIndex];
        int closingbrackingIndex = -1;


        if(c == ' '){
            startIndex++;
            continue;
        }

        if (c == OPENING_BRACKET) {
            // opening bracket found
            closingbrackingIndex = findClosingBracket(s, startIndex);
            string r = infixToPostfix(s, startIndex + 1, closingbrackingIndex - 1);
            res += r;
            startIndex = closingbrackingIndex + 1;
            continue;
        }

        if (isop(c)) {
//            res += ',';
            // the character is operator
            if (!ops.empty()) {

                int opsTopPrec = getPrecedence(ops.top());

                if (opsTopPrec >= getPrecedence(c)) {
                    // if stack is not empty and the top element of stack's precedence is higher than current op

                    while (!ops.empty() && opsTopPrec >= getPrecedence(c)) {

                        res += ops.top();
                        ops.pop();

                        if(!ops.empty()) {
                            opsTopPrec = getPrecedence(ops.top());
                        }
                    }

                }

            }

            ops.push(c);

            startIndex++;
            continue;
        }

        while(!isop(c) && c !=OPENING_BRACKET && c!=CLOSING_BRACKET && startIndex <= endIndex){
            res += c;
            startIndex++;
            c = s[startIndex];
        }

        res += ',';


    }

    while(!ops.empty()){
        res += ops.top();
        ops.pop();
    }

    return res;

}

int calculateEq(int n1, int n2, char op){

    switch(op){
        case MUL:
            return n1*n2;
        case ADD:
            return n1+n2;
        case SUB:
            return n1-n2;
        case DIV:
            return n1/n2;
    }
    return -1;
}

int calculatePostfix(string s) {

    stack<int> nums;

    int startIndex = 0;

    while(startIndex < s.length()){

        char c = s[startIndex];

        if(isop(c)){

            int n1 = nums.top();nums.pop();
            int n2 = nums.top();nums.pop();

            nums.push(calculateEq(n2, n1, c));
            startIndex++;
            continue;
        }

        string num;

        while(s[startIndex] != ','){
            num += s[startIndex];
            startIndex++;
        }

//        string num(1, s[startIndex]);

        int k = stoi(num) ;
        nums.push(k);
        startIndex++;
    }

    return nums.top();

}

int calculate(string s) {

    string postfix = infixToPostfix(s, 0, s.length() - 1);
    cout << "postfix : " << postfix << endl;
    int ans = calculatePostfix(postfix);
    return ans;
}

int main() {

    string eq1 = "(123+(4+5+2)-3)+(6+8)";
    string eq2 = "2-1+2";
    string eq3 = "1+2*5/3+6/4*2";
    cout << "ans is : " << calculate(eq1);

    return 0;
}