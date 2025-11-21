#include<iostream>
using namespace std;
struct data{
    int priority;
    int data;
};
class PriorityQueue{
    struct data arr[100];
    int size=0;
    public:
        void insert(int data, int priority){
            if(size==100){
                cout<<"Priority Queue is full!\n";
            }
            else{
                int i;
                for(i=size-1;i>=0 && arr[i].priority<priority;i--){
                    arr[i+1]=arr[i];
                }
                arr[i+1].data=data;
                arr[i+1].priority=priority;
                size++;
            }
        }
        int extract_max(){
            if(size==0){
                cout<<"Priority Queue is Empty\n";
                return -1;
            }
            struct data maxe=arr[0];
            for(int i=1;i<size;i++){
                arr[i-1]=arr[i];
            }
            size--;
            cout<<"Extracted data: "<<maxe.data<<" with priority: "<<maxe.priority<<endl;
            return maxe.data;    
        }
        void display(){
            if(size==0){
                cout<<"Priority Queue is Empty\n";
                return;
            }
            cout<<"Priority Queue (data, priority):\n";
            for(int i=0;i<size;i++){
                cout<<"("<<arr[i].data<<", "<<arr[i].priority<<") ";
            }
            cout<<endl;
        }     
};
#define MAX 100
class DoubleEndedQueue{
    int front=-1;
    int rear=-1;
    int arr[MAX];
    public:
        bool isFull(){
            return ((front==0 && rear==MAX-1) || ((rear+1)%MAX==front));
        }
        bool isEmpty(){
            return front==-1;
        }
        int getInput(){
            int data;
            cout<<"Enter data to insert:";
            cin>>data;
            return data;
        }
        void insert_front(){
            if(isFull()){
                cout<<"Dequeu is full!\n";
            }
            else if(front==-1){
                front=0;
                rear=0;
            }
            else if(front==0){
                front=MAX-1;
            }
            else front--;
            arr[front]=getInput();
        }
        void insert_rear(){
            if(isFull()){
                cout<<"Dequeu is full\n";
            }
            else if(rear==-1){
                front=0;
                rear=0;
            }
            else rear=(rear+1)%MAX;
            arr[rear]=getInput();
        }
        void delete_front(){
            if(isEmpty()){
                cout<<"Deque is empty\n";
            }
            else if(front==rear){
                front=rear=-1;
            }
            else if(front==MAX-1){
                front=0;
            }
            else front++;
        }
        void delete_rear(){
            if(isEmpty()){
                cout<<"Dequeu is empty\n";
            }
            else if(front==rear){
                front=rear=-1;
            }
            else if(rear==0){
                rear=MAX-1;
            }
            else rear--;
        }
        void display(){
            if(isEmpty()){
                cout<<"Deque is empty\n";
                return;
            }
            cout<<"Deque elements: ";
            if(front<=rear){
                for(int i=front;i<=rear;i++){
                    cout<<arr[i]<<" ";
                }
            }
            else{
                for(int i=front;i<MAX;i++){
                    cout<<arr[i]<<" ";
                }
                for(int i=0;i<=rear;i++){
                    cout<<arr[i]<<" ";
                }
            }
            cout<<endl;
        }
};
int main(){
    int mainChoice;
    
    do{
        cout<<"\n========== MAIN MENU ==========\n";
        cout<<"1. Priority Queue Operations\n";
        cout<<"2. Double Ended Queue Operations\n";
        cout<<"3. Exit\n";
        cout<<"Enter your choice: ";
        cin>>mainChoice;
        
        switch(mainChoice){
            case 1:{
                PriorityQueue pq;
                int choice;
                do{
                    cout<<"\n----- Priority Queue Menu -----\n";
                    cout<<"1. Insert element\n";
                    cout<<"2. Extract maximum priority element\n";
                    cout<<"3. Display Priority Queue\n";
                    cout<<"4. Back to Main Menu\n";
                    cout<<"Enter your choice: ";
                    cin>>choice;
                    
                    switch(choice){
                        case 1:{
                            int data, priority;
                            cout<<"Enter data: ";
                            cin>>data;
                            cout<<"Enter priority: ";
                            cin>>priority;
                            pq.insert(data, priority);
                            cout<<"Element inserted successfully!\n";
                            break;
                        }
                        case 2:{
                            int result = pq.extract_max();
                            if(result != -1){
                                cout<<"Element extracted successfully!\n";
                            }
                            break;
                        }
                        case 3:{
                            pq.display();
                            break;
                        }
                        case 4:{
                            cout<<"Returning to Main Menu...\n";
                            break;
                        }
                        default:{
                            cout<<"Invalid choice! Please try again.\n";
                        }
                    }
                }while(choice != 4);
                break;
            }
            case 2:{
                DoubleEndedQueue deque;
                int choice;
                do{
                    cout<<"\n----- Double Ended Queue Menu -----\n";
                    cout<<"1. Insert at Front\n";
                    cout<<"2. Insert at Rear\n";
                    cout<<"3. Delete from Front\n";
                    cout<<"4. Delete from Rear\n";
                    cout<<"5. Display Deque\n";
                    cout<<"6. Back to Main Menu\n";
                    cout<<"Enter your choice: ";
                    cin>>choice;
                    
                    switch(choice){
                        case 1:{
                            deque.insert_front();
                            cout<<"Element inserted at front successfully!\n";
                            break;
                        }
                        case 2:{
                            deque.insert_rear();
                            cout<<"Element inserted at rear successfully!\n";
                            break;
                        }
                        case 3:{
                            deque.delete_front();
                            if(!deque.isEmpty() || deque.isFull()){
                                cout<<"Element deleted from front successfully!\n";
                            }
                            break;
                        }
                        case 4:{
                            deque.delete_rear();
                            if(!deque.isEmpty() || deque.isFull()){
                                cout<<"Element deleted from rear successfully!\n";
                            }
                            break;
                        }
                        case 5:{
                            deque.display();
                            break;
                        }
                        case 6:{
                            cout<<"Returning to Main Menu...\n";
                            break;
                        }
                        default:{
                            cout<<"Invalid choice! Please try again.\n";
                        }
                    }
                }while(choice != 6);
                break;
            }
            case 3:{
                cout<<"Exiting program. Thank you!\n";
                break;
            }
            default:{
                cout<<"Invalid choice! Please try again.\n";
            }
        }
    }while(mainChoice != 3);

    return 0;
}