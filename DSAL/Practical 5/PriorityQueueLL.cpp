#include<iostream>
using namespace std;
struct Node{
    int data;
    int priority;
    Node *next;
};
class PriorityQueue{
    public : 
    Node *head;
    PriorityQueue(){
        head = nullptr;
    }
    Node *getNode(){
        int data, priority;
        cout<<"Enter data : "<<endl;
        cin>>data;
        cout<<"Enter Priority : "<<endl;
        cin>>priority;

        Node *temp = new Node();
        temp->data = data;
        temp->priority = priority;

        return temp;
    }
    void *insertNode(){
        
        Node *temp = getNode();
        Node *curr = head;
        Node *prev = nullptr;

        while(curr->next != nullptr && curr->priority > temp->priority){
            prev = curr;
            curr = curr->next;
        }

        temp->next = prev->next;
        prev->next = temp;

        cout<<"Inserted Successfully!!"<<endl;
    }
    void display(){
        Node *temp = head;
        while(temp){
            cout<<temp->data<<"\t"<<temp->priority<<endl;
        }
    }
};
int main(){
    PriorityQueue pq;
    while(true){
        cout<<"1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;

        int ch;
        cin>>ch;

        switch (ch)
        {
        case 1:
            pq.insertNode();
            break;
        case 3 :
            pq.display();
        default:
            break;
        }
    }
    return 0;
}