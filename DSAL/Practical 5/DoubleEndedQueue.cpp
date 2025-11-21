#include<iostream>
using namespace std;
#define MAX 100
class MyDoubleEndedQueue{
    int arr[MAX];
    int front, rear;
    
    public : 
        // Constructor to initialze
        MyDoubleEndedQueue(){
            front = -1;
            rear = -1;
        }
        // to get an input from the user
        int getInput(){
            int data;
            cout<<"Enter Data to Insert : "<<endl;
            cin>>data;
            return data;
        }
        // inserting fron the front end
        void enqueueFront(){
            if(isFull()){
                cout<<"Cannot Insert Data, Queue Full!!"<<endl;
                return;
            }
            if(rear == -1 && front == -1){
                front = 0;
                rear = 0;
            }
            else if(front == 0){
                front = MAX - 1;
            }
            else{
                front = front - 1;
            }
            arr[front] = getInput();
        }
        // inserting from the rear end
        void enqueueLast(){
            if(isFull()){
                cout<<"Cannot Insert Data, Queue Full!!"<<endl;
                return;
            }
            else if(front == -1 && rear == -1){
                rear = 0;
                front = 0;
            }
            else{
                rear = (rear + 1)%MAX;
            }
            arr[rear] = getInput();
        }
        // deleting from the front end
        void dequeueFront(){
            if(isEmpty()){
                cout<<"Cannot Delete Element, Queue is Empty!!"<<endl;
                return;
            }
            cout<<"Dequeued Element : "<<arr[front]<<endl;
            if(front == rear){
                front = rear = -1;
            }
            else{
                front = (front + 1)%MAX;
            }
        }
        // deleting from the rear end
        void dequeueLast(){
            if(isEmpty()){
                cout<<"Cannot Delete Element, Queue is Empty!!"<<endl;
                return;
            }
            cout<<"Dequeued Element : "<<arr[rear]<<endl;
            if(front == rear){
                front = rear = -1;
            }
            else if(rear == 0){
                rear = MAX-1;
            }
            else{
                rear--;
            }
        }
        // displaying the data in the queue
        void display(){
            if(isEmpty()){
                cout<<"List is Empty"<<endl;
            }
            else{
                cout<<"Double Endede Queue Data!!"<<endl;
                
                int i = front;
                while(true){
                    cout<<arr[i]<<endl;
                    if(i == rear)
                        break;
                    i = (i+1)%MAX;
                    cout<<endl;
                }
            }
        }
        // checks if the queue is empty
        bool isEmpty(){
            if(front == -1 || rear ==-1)
                return true;
            return false;
        }
        bool isFull(){
            if((front == 0 && rear == MAX-1) || (rear+1)%MAX == front){
                return true;
            }
            return false;
        }
};
int main(){
    MyDoubleEndedQueue de;
    while(true){
        int ch;
        cout<<endl;
        cout<<"******* MENU **********"<<endl;
        cout<<"1. To Insert from Front"<<endl;
        cout<<"2. To Insert from Rear"<<endl;
        cout<<"3. To Delete from Front"<<endl;
        cout<<"4. To Delete from Rear"<<endl;
        cout<<"5. To Display the Elements"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<endl<<"Enter Choice : ";
        cin>>ch;

        switch (ch)
        {
        case 1:
            de.enqueueFront();
            break;
        case 2:
            de.enqueueLast();
            break;
        case 3 : 
            de.dequeueFront();
            break;
        case 4 : 
            de.dequeueLast();
            break;
        case 5 :
            de.display();
            break;
        case 6 : 
            cout<<"Thankyou for using!!"<<endl;
            exit(0);
        default:
            cout<<"Enter Proper Choice!!"<<endl;
            break;
        }
    }
    return 0;
}