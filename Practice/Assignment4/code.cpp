#include<iostream>
#include<stack>
#include<map>
#include<string>
#include<cctype>
using namespace std;

int precedence(char op){
    if(op=='(')return 4;
    if(op=='^')return 3;
    if(op=='/' || op=='*')return 2;
    if(op=='+' || op=='-')return 1;
    return -1;
}

string postfix(string infix){
    string output="";
    stack<char> operand;
    for(int i=0;i<infix.length();i++){
        char c=infix[i];
        if(c=='(')operand.push('(');
        else if(c==')'){
            while(!operand.empty() && operand.top()!='('){
                output.push_back(operand.top());
                operand.pop();
            }
            operand.pop();
        }
        else if(c=='+' || c=='-' || c=='/' || c=='*' || c=='^'){
            while(!operand.empty() && ((precedence(operand.top())>precedence(c)) || (precedence(operand.top())==precedence(c) && c!='^'))){
                if(operand.top()=='(')break;
                output.push_back(operand.top());
                operand.pop();
            }
            operand.push(c);
        }
        else if(isalpha(c)){
            output.push_back(c);
        }
        else{
            cout<<"Invalid Character entered in infix expression!\n";
            break;
        }
    }
    while(!operand.empty()){
        output.push_back(operand.top());
        operand.pop();
    }
    return output;
}

string prefix(string infix){
    reverse(infix.begin(),infix.end());
    for(int i=0;i<infix.length();i++){
        if(infix[i]=='(')infix[i]=')';
        else if(infix[i]==')')infix[i]='(';
    }
    string res=postfix(infix);
    reverse(res.begin(),res.end());
    return res;
}
float perform_op(float a,float b,char op){
    // Function to perform operation for evaluation
    switch (op)
    {
    case '+':
        return a+b;
    case '-':
        return a-b;
    case '*':
        return a*b;
    case '/':
        return a/b;
    case '^':
        return (int)pow(a,b);
    }
    return 0;
}
float evaluate(string infix){
    string res=postfix(infix);
    map<char,float> variables_values;
    cout<<"result:"<<res<<'\n';
    for(char c:res){
        if(isalpha(c) && variables_values.find(c)==variables_values.end()){
            cout<<"Enter value of variable "<<c<<':';
            float value;
            cin>>value;
            variables_values[c]=value;
        }
    }
    stack<float> operand;
    for(int i=0;i<res.length();i++){
        if(isalpha(res[i])){
            operand.push(variables_values[res[i]]);
        }
        else{
            float b=operand.top();
            operand.pop();
            float a=operand.top();
            operand.pop();
            cout<<a<<' '<<b<<'\n';
            operand.push(perform_op(a,b,res[i]));
        }
    }
    return operand.top();
}

int main(){
    while (true) {
        int choice;
        string infix;
        cout<<"--- Menu ---\n";
        cout<<"1.Convert Infix to Postfix\n";
        cout<<"2.Convert Infix to Prefix\n";
        cout<<"3.Evaluate Infix Expression\n";
        cout<<"4.Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"Enter infix expression: ";
                cin>>infix;
                cout<<"Postfix Expression: "<<postfix(infix)<<'\n';
                break;

            case 2:
                cout<<"Enter infix expression: ";
                cin>>infix;
                cout<<"Prefix Expression: "<<prefix(infix)<<'\n';
                break;

            case 3:
                cout<<"Enter infix expression: ";
                cin>>infix;
                cout<<"Evaluated Value: "<<evaluate(infix)<<'\n';
                break;

            case 4:
                cout<<"Exiting...\n";
                return 0;

            default:
                cout<<"Invalid choice! Try again.\n";
        }
    }
    return 0;
}