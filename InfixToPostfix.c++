#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Function to check matching parentheses
bool isMatchingParentheses(const string &expr) {
    stack<char> s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty() || (ch == ')' && s.top() != '(') ||
                (ch == '}' && s.top() != '{') || (ch == ']' && s.top() != '[')) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

// Function to get precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to convert infix expression to postfix
string infixToPostfix(const string &infix) {
    stack<char> s;
    string postfix;
    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(const string &postfix) {
    stack<int> s;
    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0'); // Convert char to int
        } else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.top();
}

int main() {
    int choice;
    string expression;
    do {
        cout << "\nMenu:";
        cout << "\n1. Check Matching Parentheses";
        cout << "\n2. Convert Infix to Postfix";
        cout << "\n3. Evaluate Postfix Expression";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character

        switch (choice) {
            case 1:
                cout << "Enter expression with parentheses: ";
                getline(cin, expression);
                if (isMatchingParentheses(expression)) {
                    cout << "Parentheses are balanced." << endl;
                } else {
                    cout << "Parentheses are not balanced." << endl;
                }
                break;
            case 2:
                cout << "Enter infix expression: ";
                getline(cin, expression);
                cout << "Postfix expression: " << infixToPostfix(expression) << endl;
                break;
            case 3:
                cout << "Enter postfix expression: ";
                getline(cin, expression);
                cout << "Evaluated result: " << evaluatePostfix(expression) << endl;
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != 4);

    return 0;
}
