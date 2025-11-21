/*
    Develop a hashing-based system for securely storing user credentials, where usernames act as keys
and hashed passwords as values. Implement and demonstrate collision handling using:
• Chaining (Array-based collision resolution)
• Open Addressing (Linear or Quadratic Probing without chaining)
*/
#include<iostream>
using namespace std;

bool is_valid_name(const string &name){
    if(name.empty())return false;
    for(char c: name){
        if(!isalpha(c) && c!=' ')return false;
    }
    return true;
}

bool is_valid_roll(int r){
    return r>0;
}
struct Node{
    string name,password;
    int roll_no;
    Node* next;
};

class Linked_List{
    Node* head=NULL;
public:
    Node* get_node(string name,string password,int roll_no){
        // Function to create a new node with user details
        Node* new_node=new Node;
        new_node->name=name;
        new_node->roll_no=roll_no;
        new_node->password=password;
        new_node->next=NULL;
        return new_node;
    }
    void insert(string name,string password,int roll_no){
        // Function to insert a new node at the end of the linked list
        Node* new_node=get_node(name,password,roll_no);
        if(head==NULL){
            head=new_node;
        }else{
            Node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=new_node;
        }
    }
    void display(){
        // Function to display all nodes in the linked list
        Node* temp=head;
        while(temp!=NULL){
            cout<<"\nName:"<<temp->name<<'\n';
            cout<<"Roll No:"<<temp->roll_no<<'\n';
            temp=temp->next;
        }
    }
    bool is_Empty(){
        // Function to check if linked list is empty
        return head==NULL;
    }
    ~Linked_List(){
        // Destructor to free all allocated nodes
        while(head!=NULL){
            Node *temp=head;
            head=head->next;
            delete temp;
        }
    }
};

int get_index(string name){
    // Function to compute hash index based on ASCII sum of characters
    int sum=0;
    for(int i=0;i<name.length();i++){
        sum+=name[i];
    }
    return sum%10;
}

class Student_data{
    Linked_List data[10];
public:
    int insert(string name,string password,int roll_no){
        // Function to insert student record into hash table using chaining
        int index=get_index(name);
        data[index].insert(name,password,roll_no);
        return index;
    }
    void display_index(int index){
        // Function to display students at a particular index
        if(!data[index].is_Empty())cout<<"\nIndex:"<<index<<'\n';
        data[index].display();
    }
    void display_all(){
        // Function to display all records in the hash table
        for(int i=0;i<10;i++){
            display_index(i);
        }
    }
};

int main(){
    Student_data students;
    int choice;
    do{
        cout<<"\nMenu:\n";
        cout<<"1.Insert student\n";
        cout<<"2.Display students at an index\n";
        cout<<"3.Display all students\n";
        cout<<"4.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        string name,password;
        int index;
        int roll_no;
        switch(choice){
            case 1:
                cout<<"Enter name: ";
                cin>>ws;
                getline(cin,name);
                if(!is_valid_name(name)){
                    cout<<"Invalid name. Insert aborted\n";
                    break;
                }
                cout<<"Enter password: ";
                getline(cin,password);
                cout<<"Enter roll number: ";
                cin>>roll_no;
                if(!is_valid_roll(roll_no)){
                    cout<<"Invalid roll number. Insert aborted\n";
                    break;
                }
                index=students.insert(name,password,roll_no);
                cout<<"Student inserted at index "<<index<<".\n";
                break;
            case 2:
                cout<<"Enter index (0-9):";
                cin>>index;
                if(index>=0 && index<10){
                    students.display_index(index);
                }
                else{
                    cout<<"Invalid index. Must be between 0 and 9.\n";
                }
                break;
            case 3:
                students.display_all();
                break;
            case 4:
                cout<<"Exiting program.\n";
                break;
            default:
                cout<<"Invalid choice. Please try again.\n";
        }
    }while(choice!=4);
    return 0;
}

/*
    Menu:
1.Insert student
2.Display students at an index
3.Display all students
4.Exit
Enter your choice: 1
Enter name: Prathamesh 
Enter password: 1223  
Enter roll number: 23340
Student inserted at index 7.

Menu:
1.Insert student
2.Display students at an index
3.Display all students
4.Exit
Enter your choice: 1
Enter name: Chaintanya
Enter password: 23341
Enter roll number: 23341
Student inserted at index 4.

Menu:
1.Insert student
2.Display students at an index
3.Display all students
4.Exit
Enter your choice: 3

Index:4

Name:Chaintanya
Roll No:23341

Index:7

Name:Prathamesh
Roll No:23340

Menu:
1.Insert student
2.Display students at an index
3.Display all students
4.Exit
Enter your choice: 1
Enter name: Aarush
Enter password: 12345
Enter roll number: 233332
Student inserted at index 2.

Menu:
1.Insert student
2.Display students at an index
3.Display all students
4.Exit
Enter your choice: 2
Enter index (0-9):7

Index:7

Name:Prathamesh
Roll No:23340

Menu:
1.Insert student
2.Display students at an index
3.Display all students
4.Exit
Enter your choice: 4
Exiting program.
*/