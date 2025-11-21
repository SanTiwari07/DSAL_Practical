#include<iostream>
using namespace std;
typedef struct student{
    string name;
    int roll_no;
    float sgpa;
} student;


int partition(struct student s[],int n,int low,int high){
    int pivot=low;
    int i=low+1;
    int j=high;
    while(i<=j){
        while(i<=high && s[i].sgpa>=s[pivot].sgpa)i++;
        while(j>=low && s[j].sgpa<s[pivot].sgpa)j--;
        if(i<j)swap(s[i],s[j]);
    }
    swap(s[j],s[low]);
    return j;
}
class Class{
    public:
        Class(student s[],int n){
            for(int i=0;i<n;i++){
                cout<<"Enter Name:";
                cin>>s[i].name;
                cout<<"Enter Roll No.:";
                cin>>s[i].roll_no;
                cout<<"Enter SGPA:";
                cin>>s[i].sgpa;
            }
        }
        void bubble_sort(student s[],int n){
            for(int i=0;i<n;i++){
                for(int j=0;j<n-i-1;j++){
                    if(s[j].roll_no>s[j+1].roll_no)swap(s[j],s[j+1]);
                }
            }
            cout<<"Bubble sort done!!\n";
        }
        void insertion_sort(student s[],int n){
            for(int i=1;i<n;i++){
                student key=s[i];
                int j=i-1;
                while(j>=0 && s[j].name>key.name){
                    s[j+1]=s[j];
                    j--;
                }
                s[j+1]=key;
            }
        }
        void linear_search(struct student s[],float sgpa,int n){
            for(int i=0;i<n;i++){
                if(s[i].sgpa==sgpa){
                    cout<<"Student found!!\n";
                    cout<<"Name:"<<s[i].name<<'\n';
                    cout<<"Roll Number:"<<s[i].roll_no<<'\n';
                }
            }
        }
        void binary_search(struct student s[],int n){
            string name;
            cout<<"Enter name to search:";
            cin>>name;
            int low=0,high=n-1;
            insertion_sort(s,n);
            while(low<=high){
                int mid=(low+high)/2;
                cout<<mid<<'\n';
                cout<<s[mid].name<<'\n';
                if(s[mid].name>name)high=mid-1;
                else if(s[mid].name<name)low=mid+1;
                else{
                    cout<<"Name found!!";
                    cout<<"Name:"<<s[mid].name<<'\n';
                    cout<<"Roll Number:"<<s[mid].roll_no<<'\n';
                    cout<<"SGPA:"<<s[mid].sgpa<<'\n';
                    break;
                }
            }
        }
        void quick_sort(student s[],int n,int low,int high){
            if(low<high){
                int p=partition(s,n,low,high);
                quick_sort(s,n,p+1,high);
                quick_sort(s,n,low,p-1);
            }
        }
        void display(student s[],int n){
            cout<<"Student Details\n";
            for(int i=0;i<n;i++){
                cout<<"\nName:"<<s[i].name<<'\n';
                cout<<"Roll Number:"<<s[i].roll_no<<'\n';
                cout<<"SGPA:"<<s[i].sgpa<<'\n';
            }
        }
};
int main(){
    int n;
    cout<<"Enter Number of Students:";
    cin>>n;
    student s[n];
    Class obj(s,n);
    while(true){
        cout<<"Enter Operation No.\n";
        cout<<"1.Display Students\n";
        cout<<"2.Find Student with SGPA\n";
        cout<<"3.Sort According to Roll Number\n";
        cout<<"4.Sort According to Name\n";
        cout<<"5.Search for Name\n";
        cout<<"6.Display Toppers\n";
        cout<<"7.Exit\n";
        int choice;
        cin>>choice;
        
        switch(choice){
            case 1:
                obj.display(s,n);
                break;
            case 2:
                float key;
                cout<<"Enter SGPA to find:";
                cin>>key;
                obj.linear_search(s,key,n);
                break;
            case 3:
                obj.bubble_sort(s,n);
                cout<<"After Sorting according to Roll Number\n";
                obj.display(s,n);
                break;
            case 4:
                obj.insertion_sort(s,n);
                cout<<"After Sorting according to Name\n";
                obj.display(s,n);
                break;
            case 5:
                obj.binary_search(s,n);
                break;
            case 6:
                obj.quick_sort(s,n,0,n-1);
                cout<<"Displaying toppers:\n";
                for(int i=0;i<min(10,n);i++){
                    cout<<"Name:"<<s[i].name<<'\n';
                    cout<<"Roll No.:"<<s[i].roll_no<<'\n';
                    cout<<"SGPA:"<<s[i].sgpa<<"\n\n";
                }
                break;
            case 7:
                cout<<"Exiting, bye!!\n";
                exit(0);
            default:
                cout<<"Invalid Choice Entered!!\n";
        }
    }
    return 0;
}