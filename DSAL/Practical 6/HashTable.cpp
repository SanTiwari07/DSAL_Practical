#include<iostream>
#include<string>
#include<functional>
using namespace std;
// no of elements in the array
const int NUM_LISTS = 10;
// stucture to store user information
struct UserData{
    string name;
    string password;
};
// Node structure for a linked list
struct Node{
    struct UserData s;
    Node *next;

    // default constructor
    Node(){
        next = nullptr;
    }
};
// Class for inserting, searching and displaying operations
class HashTable{
    public : 
        Node *arrayOfList[NUM_LISTS];
        // initializing the entire list with nullptr
        HashTable(){
            for(int i = 0;i < NUM_LISTS; i++){
                arrayOfList[i] = nullptr;
            }
        }

        // getting input from the user
        UserData getData(){
            UserData ud;
            cout<<"Enter Username : "<<endl;
            cin>>ud.name;
            cout<<"Enter Password : "<<endl;
            cin>>ud.password;
            return ud;
        }

        // getting the hashvalue of the username
        size_t getUserNameHash(const string &name){
            hash<string> hasher;
            return hasher(name);
        }

        // getting the hash value of the password
        size_t getPasswordHash(const string &password){
            hash<string> hasher;
            return hasher(password);
        }

        // insertion at the beginning
        void insert(UserData &ud){
            size_t hashValue = getUserNameHash(ud.name);
            int index = hashValue % NUM_LISTS;

            Node *newNode = new Node;
            newNode->s = ud;
            newNode->next = arrayOfList[index];
            arrayOfList[index] = newNode;
        }
        
        // displaying data to the user
        void display(){
            for(int i = 0; i < NUM_LISTS; i++){
                cout<<"Bucket "<<i<<" : ";
                Node *current = arrayOfList[i];
                while(current!=nullptr){
                    cout<<"( "<< current->s.name<<" "<<current->s.password<<") ->";
                    current = current->next;
                }
                cout<<"NULL"<<endl;
            }
        }

        // searching a username in the buckets stored
        bool search(string &username){
            size_t hashValue = getUserNameHash(username);
            int index = hashValue % 10;

            Node *current = arrayOfList[index];
            while(current!=nullptr){
                if(current->s.name == username){
                    cout<<"Data Found!!"<<endl;
                     cout << "Username: " << current->s.name << ", Password: " << current->s.password << endl;
                    return true;
                }
                current = current->next;
            }
            cout<<"Data Entry Not Found!!"<<endl;
            return false;
        }
};  
int main() {
    HashTable ht;
    int choice;
    // user menu
    do {
        cout << "\n1. Add User\n2. Display Table\n3. Search User\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                UserData u = ht.getData();
                ht.insert(u);
                break;
            }
            case 2: {
                ht.display();
                break;
            }
            case 3: {
                string username;
                cout << "Enter username to search: ";
                cin >> username;
                ht.search(username);
                break;
            }
            case 4: {
                cout << "Exiting...\n";
                break;
            }
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
