#include<iostream>
using namespace std;
#define MAX 100
class MyDoubleEndedQueue{
    int arr[MAX];
    int front, rear;
    
    public : 
        MyDoubleEndedQueue(){
            front = -1;
            rear = -1;
        }
        int getInput(){
            int data;
            cout<<"Enter Data to Insert : "<<endl;
            cin>>data;
            return data;
        }
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
        void enqueueLast(){
            if(isFull()){
                cout<<"Cannot Insert Data, Queue Full!!"<<endl;
                return;
            }
            else if(front == -1 && rear == -1){
                rear = 0;
                front = 0;
            }
            else if(rear == MAX - 1){
                rear = 0;
            }
            else{
                rear = rear + 1;
            }
            arr[rear] = getInput();
        }
        void dequeueFront(){
            if(isEmpty()){
                cout<<"Cannot Delete Element, Queue is Empty!!"<<endl;
                return;
            }
            else if(front == MAX - 1){
                cout<<"Dequeued Element : "<<arr[front];
                front = 0;
            }
            else{
                cout<<"Dequeued Element : "<<arr[front];
                front++;
            }
        }
        void dequeueLast(){
            if(isEmpty()){
                cout<<"Cannot Delete Element, Queue is Empty!!"<<endl;
                return;
            }
            else if(rear == 0){
                cout<<"Dequeued Element : "<<arr[rear];
                rear = MAX-1;
            }
            else{
                cout<<"Dequeued Element : "<<arr[rear]<<endl;
                rear--;
            }
        }
        void display(){
            if(isEmpty()){
                cout<<"List is Empty"<<endl;
            }
            else{
                cout<<"Double Endede Queue Data!!"<<endl;
                for(int i = front;i<=rear;i++){
                    cout<<arr[i]<<"\t";
                }
            }
        }
        bool isEmpty(){
            if(front == -1 || rear ==-1)
                return true;
            return false;
        }
        bool isFull(){
            if((front == 0 && rear == MAX-1) || rear+1 == front){
                return true;
            }
            return false;
        }
};
int main(){
    while(true){
        MyDoubleEndedQueue de;
        int ch;
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
            exit;
        default:
            cout<<"Enter Proper Choice!!"<<endl;
            break;
        }
    }
    return 0;
}