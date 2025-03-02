
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
#include <stdexcept>

using namespace std;

// Stack class implementation
class Stack {
public:
    stack<int> s;

    void push(int value) {
        s.push(value);
    }

    void pop() {
        if (!s.empty()) {
            s.pop();
        } else {
            cout << "Stack is empty!" << endl;
        }
    }

    int top() {
        if (!s.empty()) {
            return s.top();
        } else {
            cout << "Stack is empty!" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    void display() {
        stack<int> temp = s;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

// Postfix Expression Evaluation
int evaluatePostfix(const string& exp) {
    Stack stack;
    for (char c : exp) {
        if (isdigit(c)) {
            stack.push(c - '0');
        } else {
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            switch (c) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(a / b); break;
            }
        }
    }
    return stack.top();
}

// Balanced Parentheses Check
bool areParenthesesBalanced(const string& exp) {
    Stack stack;
    for (char c : exp) {
        if (c == '(') {
            stack.push(1);
        } else if (c == ')') {
            if (stack.isEmpty()) return false;
            stack.pop();
        }
    }
    return stack.isEmpty();
}

int main() {
    cout << "Postfix Evaluation (Expression: 23*54*+") << endl;
    string exp = "23*54*+";
    cout << "Result: " << evaluatePostfix(exp) << endl;

    string parenthesesExp = "(a+b)*(c+d)";
    cout << "Are parentheses balanced? " << (areParenthesesBalanced(parenthesesExp) ? "Yes" : "No") << endl;

    return 0;
}
