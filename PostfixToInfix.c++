#include <iostream>
#include <string>
using namespace std;

// Custom Stack implementation
class Stack {
    static const int MAX = 100;
    string arr[MAX];
    int topIndex;
public:
    Stack() : topIndex(-1) {}
    void push(string x) {
        if (topIndex < MAX - 1) arr[++topIndex] = x;
    }
    void pop() {
        if (topIndex >= 0) --topIndex;
    }
    string top() {
        return (topIndex >= 0) ? arr[topIndex] : "";
    }
    bool isEmpty() {
        return topIndex == -1;
    }
};

// Function to check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to convert Postfix to Infix
string postfixToInfix(const string &postfix) {
    Stack s;
    
    for (char ch : postfix) {
        if (isalnum(ch)) {
            // Operand: Push it as a string
            s.push(string(1, ch));
        } else if (isOperator(ch)) {
            // Operator: Pop top two operands
            string operand2 = s.top(); s.pop();
            string operand1 = s.top(); s.pop();
            
            // Create the new infix expression and push it back
            string newExpr = "(" + operand1 + ch + operand2 + ")";
            s.push(newExpr);
        }
    }
    
    return s.top(); // The final result
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;
    
    cout << "Infix expression: " << postfixToInfix(postfix) << endl;
    
    return 0;
}
