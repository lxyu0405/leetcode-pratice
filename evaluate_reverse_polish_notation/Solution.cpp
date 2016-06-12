#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> RPN;
        for (auto token : tokens) {
            if (isOperator(token)) {
                int operand2 = RPN.top();
                RPN.pop();
                int operand1 = RPN.top();
                RPN.pop();
                RPN.push(calculate(operand1, operand2, token));
            }else{
                RPN.push(stoi(token));
            }
        }
        return RPN.top();
    }
private:
    bool isOperator(string op){
        return (op == "+" || op == "-" || op == "*" || op == "/") ? true : false;
    }
    
    int calculate(int operand1, int operand2, string op){
        if (op == "+") {    return operand1 + operand2;}
        if (op == "-") {    return operand1 - operand2;}
        if (op == "*") {    return operand1 * operand2;}
        if (op == "/") {    return operand1 / operand2;}
        return 0;
    }
};
