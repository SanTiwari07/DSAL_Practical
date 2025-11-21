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
struct Record{
    string name,password;
    int roll_no;
    bool occupied=false;
};

class HashTable{
    struct Record data[10];
    public:
        int hash_func(string name){
            int sum=0;
            int n=name.length();
            for(int i=0;i<n;i++){
                sum+=name[i];
            }
            return sum%10;
        }
        void insert(string name,string password,int roll_no){
            int index=hash_func(name);
            int start=index;
            int i=1;
            while(1){
                if(!data[index].occupied){
                    data[index].occupied=true;
                    data[index].name=name;
                    data[index].password=password;
                    data[index].roll_no=roll_no;
                    cout<<"Insertion successful at index "<<index<<"!\n";
                    return;
                }
                index=(index+i*i)%10;
                i++;
                if(start==index || i>=10){
                    cout<<"Hash table is full\n";
                    return;
                }
            }
        }
        void search(string name){
            int index=hash_func(name);
            int start=index;
            while(1){
                if(data[index].occupied && data[index].name==name){
                    cout<<"\nRecord Found at index "<<index<<"!\n";
                    cout<<"Name: "<<data[index].name<<endl;
                    cout<<"Roll No: "<<data[index].roll_no<<endl;
                    cout<<"Password: "<<data[index].password<<endl;
                    return;
                }
                index=(index+1)%10;
                if(index==start){
                    cout<<"Record not found!\n";
                    return;
                }
            }
        }
        void remove(string name){
            int index=hash_func(name);
            int start=index;
            while(1){
                if(data[index].occupied && data[index].name==name){
                    data[index].occupied=false;
                    data[index].name="";
                    data[index].password="";
                    data[index].roll_no=0;
                    cout<<"Record deleted successfully from index "<<index<<"!\n";
                    return;
                }
                index=(index+1)%10;
                if(index==start){
                    cout<<"Record not found!\n";
                    return;
                }
            }
        }
        void display(){
            cout<<"\n========== Hash Table Contents ==========\n";
            bool isEmpty=true;
            for(int i=0;i<10;i++){
                if(data[i].occupied){
                    isEmpty=false;
                    cout<<"Index "<<i<<": ";
                    cout<<"Name: "<<data[i].name<<", ";
                    cout<<"Roll No: "<<data[i].roll_no<<", ";
                    cout<<"Password: "<<data[i].password<<endl;
                }
            }
            if(isEmpty){
                cout<<"Hash table is empty!\n";
            }
            cout<<"========================================\n";
        }
};
int main(){
    HashTable ht;
    int choice;
    
    do{
        cout<<"\n========== HASH TABLE MENU (Linear Probing) ==========\n";
        cout<<"1. Insert Record\n";
        cout<<"2. Search Record\n";
        cout<<"3. Delete Record\n";
        cout<<"4. Display Hash Table\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore();
        
        switch(choice){
            case 1:{
                string name, password;
                int roll_no;
                
                cout<<"\nEnter name: ";
                getline(cin, name);
                
                if(!is_valid_name(name)){
                    cout<<"Invalid name! Please use only alphabets and spaces.\n";
                    break;
                }
                
                cout<<"Enter roll number: ";
                cin>>roll_no;
                
                if(!is_valid_roll(roll_no)){
                    cout<<"Invalid roll number! Must be positive.\n";
                    break;
                }
                
                cin.ignore();
                cout<<"Enter password: ";
                getline(cin, password);
                
                if(password.empty()){
                    cout<<"Password cannot be empty!\n";
                    break;
                }
                
                ht.insert(name, password, roll_no);
                break;
            }
            case 2:{
                string name;
                cout<<"\nEnter name to search: ";
                getline(cin, name);
                
                if(name.empty()){
                    cout<<"Name cannot be empty!\n";
                    break;
                }
                
                ht.search(name);
                break;
            }
            case 3:{
                string name;
                cout<<"\nEnter name to delete: ";
                getline(cin, name);
                
                if(name.empty()){
                    cout<<"Name cannot be empty!\n";
                    break;
                }
                
                ht.remove(name);
                break;
            }
            case 4:{
                ht.display();
                break;
            }
            case 5:{
                cout<<"\nExiting program. Thank you!\n";
                break;
            }
            default:{
                cout<<"\nInvalid choice! Please try again.\n";
            }
        }
    }while(choice != 5);

    return 0;
}