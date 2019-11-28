//
// Created by Siddhant on 2019-11-25.
//

#include "iostream"
#include "vector"
#include "string"
#include "list"

using namespace std;

string SUM = "+";
string SUB = "-";
string DIV = "/";
string MUL = "*";

bool isoperator(string c) {

    return c == SUM || c == SUB || c == DIV || c == MUL;

}

int cal(int opcode, string op, int n1, int n2) {

    switch (opcode) {

        case 0:
            if (op == DIV) {
                return n1 / n2;
            }
            break;
        case 1:
            if (op == MUL) {
                return n1 * n2;
            }
            break;
        case 2:
            if (op == SUM) {
                return n1 + n2;
            }
            break;
        case 3:
            if (op == SUB) {
                return n1 - n2;
            }
            break;

    }

    return INT_MIN;

}

list<string>::iterator solveEq(list<string> equationVec, list<string>::iterator listIt, int opcode, string op) {

    auto prevval = listIt;
    auto nextval = listIt;
    prevval--;
    nextval++;
    int val = cal(opcode, op, stoi(*prevval), stoi(*nextval));

    auto temp = prevval;
    list<string>::iterator it = equationVec.insert(temp, to_string(val));
    nextval++;
    equationVec.erase(prevval, nextval);
    return it;


}

int calculate(string s) {

    list<string> equationVec;
    string num = "";

    for (int i = 0; i < s.length(); ++i) {

        string c(1, s[i]);

        if (c == " ") continue;

        if (isoperator(c)) {
            equationVec.push_back(num);
            equationVec.push_back(c);
            num = "";
            continue;
        }

        num += c;

    }
    equationVec.push_back(num);

    for (int j = 0; j < 4; ++j) {
        list<string>::iterator listIt = equationVec.begin();

        while (listIt != equationVec.end()) {
            if (j == 0 && *listIt == DIV) {
                listIt = solveEq(equationVec, listIt, 0, *listIt);
            } else if (j == 1 && *listIt == MUL) {
                listIt = solveEq(equationVec, listIt, 1, *listIt);
            } else if (j == 2 && *listIt == SUM) {
                listIt = solveEq(equationVec, listIt, 2, *listIt);
            } else if (j == 3 && *listIt == SUB) {
                listIt = solveEq(equationVec, listIt, 3, *listIt);
            } else {
                listIt++;
            }

        }

    }

}

int main() {

    calculate("4+56 /2");
    return 0;
}