#include<iostream>
#include<string>
using namespace std;
struct SNode{
    string data;
    SNode *next;
};
class MyStack{
    public :
        SNode *top;
        MyStack(){
            top = nullptr;
        }
        SNode *create(string data){
            SNode *temp = new SNode();
            temp->data = data;
            temp->next = NULL;
            return temp;
        } 
        // pushing elements into stack
        void push(string data){
            SNode *temp;
            temp = create(data);

            // temp->next = top;
            // top = temp;
            if(isEmpty()){
                top = temp;
            }
            else{
                temp->next = top;
                top = temp;
            }
            cout<<"Node inserted successfully!!"<<endl;
        }
        // popping elements from stack
        string pop(){
            SNode *temp;
            string data;
            if(isEmpty()){
                cout<<"Stack is empty!!"<<endl;
            }
            else{
                data = top->data;
                temp = top;
                top = top->next;
                delete temp;
            }
            return data;
        }
        // peek -> topmost element in the list
        string peek(){
            return top->data;
        }
        // displays data
        void display(){
            if(isEmpty()){
                cout<<"Stack is empty"<<endl;
            }
            else{
                cout<<"Elements in the Stack!!"<<endl;
                SNode *temp = top;
                while(temp!=NULL){
                    cout<<temp->data<<endl;
                    temp = temp->next;
                }
            }
        }
        // checks if the stack is empty
        bool isEmpty(){
            if(top == NULL){
                return true;
            }
            else{
                return false;
            }
        }
};
int main(){
    MyStack s;
    int choice;
    string data;
    while(true){
        cout<<"**************Stack Operation*************"<<endl;
        cout<<"1. Push"<<endl<<"2. Pop"<<endl<<"3. Display"<<endl<<"4. Peek"<<endl<<"5. Exit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter data : "<<endl;
            cin>>data;
            s.push(data);
            break;
        case 2:
            cout<<"Popped Element : "<<s.pop()<<endl;
            break;
        case 3:
            s.display();
            break;
        case 4 : 
            cout<<"Top Element : "<<s.peek()<<endl;
            break;
        case 5 : 
            exit;
        default:
            break;
        }
    }
    return 0;
}
