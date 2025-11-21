#include <iostream>
using namespace std;

class PriorityQueue {
private:
    // structure to take value and priority
    struct data{
        int value;
        int priority;
    };
    struct data arr[100];
    int size;

public:
    // Constructor for initilazation
    PriorityQueue() {
        size = 0;
    }

    // Insert element according to priority (descending order)
    void insert(int value,int prio) {
        if (size == 100) {
            cout << "Priority Queue is full!\n";
            return;
        }
        int i;
        // Find the position where value should be inserted
        for (i = size - 1; i >= 0 && arr[i].priority < prio; i--) {
            arr[i + 1] = arr[i];  // Shift elements to the right
        }
        arr[i + 1].priority = prio;
        arr[i+1].value = value;
        size++;
    }

    // Extract the highest priority element (front element)
    int extractMax() {
        if (size == 0) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        int maxValue = arr[0].priority;
        // Shift all elements left by one
        for (int i = 1; i < size; i++) {
            arr[i - 1] = arr[i];
        }
        size--;
        return maxValue;
    }
    // checks for the empty condition
    bool isEmpty() {
        return size == 0;
    }
    // display data to the user
    void display() {
        cout << "Queue: "<<endl;
        cout<<"Priority-->Value"<<endl;
        for (int i = 0; i < size; i++) {
            cout << arr[i].priority << "\t"<<arr[i].value<<endl;
        }
        cout << "\n";
    }
};
int main() {
    PriorityQueue pq;

    int ch;
    while(true){
        cout<<"------------------MENU------------------"<<endl;
        cout<<"1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;
        
        cout<<"Enter Choice : "<<endl;
        cin>>ch;

        switch (ch) 
        {
            case 1:
                int no,pri;
                cout<<"Insert Value : "<<endl;
                cin>>no;
                cout<<"Insert Priority : "<<endl;
                cin>>pri;
                pq.insert(no,pri);
                break;
            case 2 : 
                cout << "Extracted max: " << pq.extractMax() << "\n"; // 30
                break;
            case 3 : 
                pq.display();
            case 4 : 
                exit;
            default:
                cout<<"Enter valid data"<<endl;
                break;
        }
    }
    return 0;
}