#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<map>
#include<cctype>

using namespace std;

class StackOperations {
    string postfix = "";
    string prefix = "";
    map<char, int> variableValues;

public:
    int precedence(char ch) {
        if (ch == '^') return 3;
        else if (ch == '*' || ch == '/') return 2;
        else if (ch == '+' || ch == '-') return 1;
        else return -1;
    }

    void postfixConversion(string str) {
        stack<char> s;
        postfix = "";
        for (char ch : str) {
            if (isalpha(ch) || isdigit(ch)) {
                postfix += ch;
            }
            else if (ch == '(') {
                s.push(ch);
            }
            else if (ch == ')') {
                while (!s.empty() && s.top() != '(') {
                    postfix += s.top();
                    s.pop();
                }
                if (!s.empty()) s.pop();
            }
            else {
                while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                    if (s.top() == '(') break;
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
        cout << "Postfix : " << postfix << endl;
    }

    void prefixConversion(string str) {
        reverse(str.begin(), str.end());
        for (char &ch : str) {
            if (ch == '(')
                ch = ')';
            else if (ch == ')')
                ch = '(';
        }

        stack<char> s;
        string temp = "";
        for (char ch : str) {
            if (isalpha(ch) || isdigit(ch)) {
                temp += ch;
            }
            else if (ch == '(') {
                s.push(ch);
            }
            else if (ch == ')') {
                while (!s.empty() && s.top() != '(') {
                    temp += s.top();
                    s.pop();
                }
                if (!s.empty())
                    s.pop();
            }
            else {
                while (!s.empty() && precedence(s.top()) > precedence(ch)) {
                    if (s.top() == '(') break;
                    temp += s.top();
                    s.pop();
                }
                s.push(ch);
            }
        }
        while (!s.empty()) {
            temp += s.top();
            s.pop();
        }

        reverse(temp.begin(), temp.end());
        prefix = temp;
        cout << "Prefix  : " << prefix << endl;
    }

    void getVariableValues(string str) {
        variableValues.clear();
        cout << "Please enter values for the variables." << endl;
        for (char ch : str) {
            if (isalpha(ch) && variableValues.find(ch) == variableValues.end()) {
                int value;
                cout << "Enter value for " << ch << ": ";
                cin >> value;
                variableValues[ch] = value;
            }
        }
    }

    void postfixEvaluation(string str){
        postfixConversion(str);
        getVariableValues(str);
        stack<int> s;
        int result = 0;
        for(char ch : postfix){
            if(isdigit(ch)){
                s.push(ch - '0');
            }
            else if(isalpha(ch)){
                s.push(variableValues[ch]);
            }
            else{
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
                switch(ch){
                    case '+' :
                        result = op1 + op2;
                        break;
                    case '-' :
                        result = op1 - op2;
                        break;
                    case '*' :
                        result = op1 * op2;
                        break;
                    case '/' :
                        if(op2 == 0){
                            cout << "Division by Zero" << endl;
                            return;
                        }
                        else{
                            result = op1 / op2;
                        }
                        break;
                    case '^' :
                        result = 1;
                        for(int i = 1; i <= op2; i++){
                            result *= op1;
                        }
                        break;
                    default :
                        cout << "Enter proper option" << endl;
                        return;
                }
                s.push(result);
            }
        }
        if(!s.empty()){
            cout << "Postfix Evaluation Result : " << s.top() << endl;
        }
        else{
            cout << "Error in evaluation" << endl;
        }
    }

    void prefixEvaluation(string str){
        prefixConversion(str);
        getVariableValues(str);
        reverse(prefix.begin(), prefix.end());
        stack<int> s;
        int result = 0;
        for(char ch : prefix){
            if(isdigit(ch)){
                s.push(ch - '0');
            }
            else if(isalpha(ch)){
                s.push(variableValues[ch]);
            }
            else{
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                switch(ch){
                    case '+' :
                        result = op1 + op2;
                        break;
                    case '-' :
                        result = op1 - op2;
                        break;
                    case '*' :
                        result = op1 * op2;
                        break;
                    case '/' :
                        if(op2 == 0){
                            cout << "Division by Zero" << endl;
                            return;
                        }
                        else{
                            result = op1 / op2;
                        }
                        break;
                    case '^' :
                        result = 1;
                        for(int i = 1; i <= op2; i++){
                            result *= op1;
                        }
                        break;
                    default :
                        cout << "Enter proper option" << endl;
                        return;
                }
                s.push(result);
            }
        }
        if(!s.empty()){
            cout << "Prefix Evaluation Result  : " << s.top() << endl;
        }
        else{
            cout << "Error in evaluation" << endl;
        }
    }
};

int main() {
    StackOperations so;
    string str;
    cout << "Enter Infix Expression (e.g., a+b): ";
    cin >> str;
    cout << endl;
    so.postfixEvaluation(str);
    cout << endl;
    so.prefixEvaluation(str);
    return 0;
}