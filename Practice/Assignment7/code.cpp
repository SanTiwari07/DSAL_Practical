#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

typedef struct Student{
    string name,division;
    int rollno;
} Student;

bool is_valid_name(const string &name){
    // Function to validate student name (only alphabets and spaces allowed)
    if(name.empty())return false;
    for(char c: name){
        if(!isalpha(c) && c!=' ')return false;
    }
    return true;
}

bool is_valid_roll(int r){
    // Function to validate roll number (must be positive)
    return r>0;
}


class StudentDatabase{
    public:
        Student get_input(){
            Student s;
            bool rollValid = false, nameValid = false, divValid = false;
            while(!rollValid || !nameValid || !divValid){
                if(!rollValid){
                    cout<<"Enter Student's Roll Number:";
                    cin>>s.rollno;
                    if(is_valid_roll(s.rollno)){
                        rollValid = true;
                    } else {
                        cout<<"Invalid roll number!\n";
                    }
                }
                if(!nameValid){
                    cout<<"Enter Student's Name:";
                    cin>>s.name;
                    if(is_valid_name(s.name)){
                        nameValid = true;
                    } else {
                        cout<<"Invalid name\n";
                    }
                }
                
                if(!divValid){
                    cout<<"Enter Student's Division:";
                    cin>>s.division;
                    divValid = true;
                }
            }
            return s;
        }
        void create(){
            ofstream fout("Student_data.txt");
            if(!fout){
                cout<<"File error\n";
                return;
            }
            int n;
            cout<<"Enter number of records: ";
            cin>>n;
            for(int i=0;i<n;i++){
                Student s=get_input();
                fout<<s.name<<','<<s.division<<','<<s.rollno<<'\n';
                cout<<"Student added to database\n";
            }
            fout.close();
        }
        void add_student(){
            Student s=get_input();
            ofstream fout("Student_data.txt",ios::app);
            fout<<s.name<<','<<s.division<<','<<s.rollno<<'\n';
            cout<<"Student added to database\n";
            fout.close();
        }  
        void delete_record(){
            int rollno;
            cout<<"Enter Roll Number to delete:\n";
            cin>>rollno;
            ifstream fin("Student_data.txt");
            ofstream fout("temp.txt");
            string line;
            bool flag=0;
            while(getline(fin,line)){
                vector<string> records;
                string sub_record="";
                for(int i=0;i<line.length();i++){
                    if(line[i]==','){  
                        records.push_back(sub_record);
                        sub_record="";
                    }
                    else sub_record.push_back(line[i]);
                }
                records.push_back(sub_record);
                int roll_no=stoi(records[2]);
                if(roll_no==rollno){
                    flag=1;
                }
                else{
                    fout<<line<<'\n';
                }
            }
            if(!flag){
                cout<<"Roll Number not found to delete\n";
            }
            else{
                cout<<"Record deleted successfully\n";
            }
            remove("Student_data.txt");
            rename("temp.txt","Student_data.txt");
            fin.close();
            fout.close();
        }
        void modify_record(){
            int rollno;
            cout<<"Enter Roll Number to Modify Record:\n";
            cin>>rollno;
            ifstream fin("Student_data.txt");
            ofstream fout("temp.txt");
            string line;
            bool flag=0;
            while(getline(fin,line)){
                vector<string> records;
                string sub_record="";
                for(int i=0;i<line.length();i++){
                    if(line[i]==','){  
                        records.push_back(sub_record);
                        sub_record="";
                    }
                    else sub_record.push_back(line[i]);
                }
                records.push_back(sub_record);
                int roll_no=stoi(records[2]);
                if(roll_no==rollno){
                    cout<<"Roll Number found!!Enter details to modify record\n";
                    Student s=get_input();
                    fout<<s.name<<','<<s.division<<','<<s.rollno<<'\n';
                    flag=1;
                }
                else{
                    fout<<line<<'\n';
                }
            }
            if(!flag){
                cout<<"Roll Number not found to modify\n";
            }
            else{
                cout<<"Record modified successfully\n";
            }
            remove("Student_data.txt");
            rename("temp.txt","Student_data.txt");
            fin.close();
            fout.close();
        }
        void display_record(){
            ifstream fin("Student_data.txt");
            if(!fin){
                cout<<"File error or no records found\n";
                return;
            }
            string line;
            bool hasRecords = false;
            cout<<"\n========== Student Database ==========\n";
            cout<<"Roll No\t\tName\t\t\tDivision\n";
            cout<<"--------------------------------------\n";
            while(getline(fin,line)){
                hasRecords = true;
                vector<string> records;
                string sub_record="";
                for(int i=0;i<line.length();i++){
                    if(line[i]==','){  
                        records.push_back(sub_record);
                        sub_record="";
                    }
                    else sub_record.push_back(line[i]);
                }
                records.push_back(sub_record);
                if(records.size()==3){
                    cout<<records[2]<<"\t\t"<<records[0]<<"\t\t\t"<<records[1]<<"\n";
                }
            }
            if(!hasRecords){
                cout<<"No records in database\n";
            }
            cout<<"======================================\n\n";
            fin.close();
        }
};
int main(){
    StudentDatabase db;
    int choice;
    
    do{
        cout<<"\n===== Student Database Management System =====\n";
        cout<<"1. Create Database\n";
        cout<<"2. Add Student\n";
        cout<<"3. Display All Records\n";
        cout<<"4. Modify Record\n";
        cout<<"5. Delete Record\n";
        cout<<"6. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        
        switch(choice){
            case 1:
                db.create();
                break;
            case 2:
                db.add_student();
                break;
            case 3:
                db.display_record();
                break;
            case 4:
                db.modify_record();
                break;
            case 5:
                db.delete_record();
                break;
            case 6:
                cout<<"Exiting program. Goodbye!\n";
                break;
            default:
                cout<<"Invalid choice! Please try again.\n";
        }
    }while(choice!=6);

    return 0;
}