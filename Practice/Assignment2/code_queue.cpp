#include<iostream>
using namespace std;

enum level{
    low=0,
    mid,
    high
};
typedef struct task{
    struct task* next;
    string title;
    enum level difficulty;
    enum level priority;
} task;

bool is_valid_title(string title){
    if(title.empty())return false;
    for(char c:title){
        if(!isalpha(c) && c!=' ')return false;
    }
    return true;
}
bool is_valid_difficulty(int difficulty){
    return difficulty>=0 && difficulty<=2;
}
bool is_valid_priority(int priority){
    return priority>=0 && priority<=2;
}
class task_scheduler{
    task* front=NULL;
    task* rear=NULL;
    public:
        task* get_task(){
            string title;
            int difficulty;
            int priority;
            level levels[]={low,mid,high};
            bool flag1=false,flag2=false,flag3=false;
            while(!flag1){
                cout<<"Enter task title:";
                cin>>title;
                flag1=is_valid_title(title);
                if(!flag1)cout<<"Invalid title!!\n";
            }
            while(!flag2){
                cout<<"Enter task difficulty(0,1,2):";
                cin>>difficulty;
                flag2=is_valid_difficulty(difficulty);
                if(!flag2)cout<<"Invalid difficulty!!\n";
            }
            while(!flag3){
                cout<<"Enter task priority(0,1,2):";
                cin>>priority;
                flag3=is_valid_priority(priority);
                if(!flag3)cout<<"Invalid Priority!!\n";
            }
            
            task* new_task=new task;
            new_task->title=title;
            new_task->priority=levels[priority];
            new_task->difficulty=levels[difficulty];
            return new_task;
        }
        void enqueue(){
            task* new_task=get_task();
            if(front==NULL){
                front=new_task;
                rear=new_task;
            }
            else{
                rear->next=new_task;
                rear=new_task;
            }
        }
        void dequeue(){
            if(front==NULL){
                cout<<"No tasks to delete!\n";
            }
            else{
                task* temp=front;
                front=front->next;
                delete temp;
                cout<<"Task deleted!\n";
            }
        }
        task* peek(){
            if(front==NULL){
                cout<<"Task list is empty!\n";
                return NULL;
            }
            else{
                return front;
            }
        }
        bool isEmpty(){
            return front==NULL;
        }
};
int main(){
    task_scheduler Tasks;
    while(true){
        cout<<"Enter 0(Exit),1(Add Task),2(Complete Task),3(Peek):";
        int choice;
        cin>>choice;
        switch(choice){
            case 0:
                cout<<"Exiting, Bye!\n";
                exit(0);
                break;
            case 1:
                Tasks.enqueue();
                cout<<"Task Added to front!\n";
                break;
            case 2:
                if(Tasks.isEmpty()){
                    cout<<"No Tasks to Complete\n";
                }
                else {
                    Tasks.dequeue();
                    cout<<"Task Completed\n";
                }
                break;
            case 3:
                if(Tasks.isEmpty()){
                    cout<<"No Tasks to Show\n";
                }
                else{
                    task* first_task=Tasks.peek();
                    cout<<"Title:"<<first_task->title<<'\n';
                    cout<<"Difficulty:"<<first_task->difficulty<<'\n';
                    cout<<"Priority:"<<first_task->priority<<"\n";
                }
                break;
            default:
                cout<<"Invalid choice entered!\n";

        }
    }
    return 0;
}