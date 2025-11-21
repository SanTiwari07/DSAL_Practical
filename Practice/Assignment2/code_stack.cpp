#include<iostream>
using namespace std;

typedef struct node{
    node* next;
    string word;
} node;
bool is_valid_word(string title){
    if(title.empty())return false;
    for(char c:title){
        if(!isalpha(c) && c!=' ')return false;
    }
    return true;
}
class my_stack{
    node* head=NULL;
    public: 
        node* get_node(string word){
            node* new_node=new node;
            new_node->word=word;
            return new_node;
        }
        void push(string word){
            node* new_node=get_node(word);
            if(head==NULL){
                head=new_node;
            }
            else{
                new_node->next=head;
                head=new_node;
            }
            cout<<"Node pushed to stack!\n";
        }
        bool isEmpty(){
            return head==NULL;
        }
        string peek(){
            if(isEmpty()){
                cout<<"Stack is empty!";
                return NULL;
            }
            else{
                return head->word;
            }
        }
        void pop(){
            if(isEmpty()){
                cout<<"Stack is empty!";
            }
            else{
                node* temp=head;
                head=head->next;
                delete temp;
                cout<<"Node popped from stack!\n";
            }
        }
        void display(){ 
            // Display Stack from top to bottom
            if(isEmpty()){
                cout<<"Stack is empty. Nothing to display";
            }
            else{
                node* temp=head;
                cout<<"Text:\n";
                while(temp!=NULL){
                    cout<<temp->word<<' ';
                    temp=temp->next;
                }
            }
            cout<<'\n';
        }
        ~my_stack(){
            // Destructor to delete the stack
            while(head!=NULL){
                node* temp=head;
                head=head->next;
                delete temp;
            }
        }
};
int main(){
    my_stack main_stack;
    my_stack removed_stack;
    while(true){
        cout<<"Enter 0(Undo),1(Redo),2(Push word),3(Show Text),4(Exit):";
        int choice;
        cin>>choice;
        node* new_node;
        bool flag=false;
        string word;
        switch(choice){
            case 0:
                if(main_stack.isEmpty()){
                    cout<<"Nothing to Undo!\n";
                }
                else{
                    removed_stack.push(main_stack.peek());
                    main_stack.pop();
                    cout<<"Undo Operation Complete!\n";
                }
                break;
            case 1:
                if(removed_stack.isEmpty()){
                    cout<<"Nothing to redo!\n";
                }
                else{
                    main_stack.push(removed_stack.peek());
                    removed_stack.pop();
                    cout<<"Redo Operation Complete!\n";
                }
                break;
            case 2:
                while(!flag){
                    cout<<"Enter a word:";
                    cin>>word;
                    flag=is_valid_word(word);
                    if(!flag)cout<<"Invalid word!!\n";
                }
                main_stack.push(word);
                cout<<"Word added!\n";
                break;
            case 3:
                main_stack.display();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout<<"Invalid choice entered!!";
        }
    }
    return 0;
}