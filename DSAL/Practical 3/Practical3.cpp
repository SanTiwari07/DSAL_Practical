#include <iostream>
#include <string>
using namespace std;

// Assignment 3: Sorting and Searching
struct SEIT
{
    int roll;
    string name;
    float sgpa;
};

class StudentDetails
{
    SEIT stud[15];
    int n; // actual number of students

public:
    StudentDetails()
    {
        n = 0;
    }

    int inputDetails()
    {
        cout << "Enter number of students: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "\nEnter details of student " << i + 1 << endl;
            cout << "Roll number: ";
            cin >> stud[i].roll;
            cout << "Name: ";
            cin >> stud[i].name;
            cout << "SGPA: ";
            cin >> stud[i].sgpa;
        }
        return n;
    }

    void displayDetails()
    {
        cout << "\n--- Student Details ---\n";
        for (int i = 0; i < n; i++)
        {
            cout << "Roll Number: " << stud[i].roll << endl;
            cout << "Name: " << stud[i].name << endl;
            cout << "SGPA: " << stud[i].sgpa << endl;
            cout << "-----------------------" << endl;
        }
    }

    // Bubble Sort by Roll No
    void bubbleSortByRoll()
    {
        for (int t = 0; t < n - 1; t++)
        {
            for (int i = 0; i < n - t - 1; i++)
            {
                if (stud[i].roll > stud[i + 1].roll)
                {
                    SEIT temp = stud[i];
                    stud[i] = stud[i + 1];
                    stud[i + 1] = temp;
                }
            }
        }
        cout << "\nSorted by Roll Number:\n";
        displayDetails();
    }

    // Bubble Sort by Name
    void bubbleSortByName()
    {
        for (int t = 0; t < n - 1; t++)
        {
            for (int i = 0; i < n - t - 1; i++)
            {
                if (stud[i].name > stud[i + 1].name)
                {
                    SEIT temp = stud[i];
                    stud[i] = stud[i + 1];
                    stud[i + 1] = temp;
                }
            }
        }
        cout << "\nSorted by Name:\n";
        displayDetails();
    }

    // Insertion Sort by Roll
    void insertionSortByRoll()
    {
        for (int i = 1; i < n; i++)
        {
            SEIT key = stud[i];
            int j = i - 1;
            while (j >= 0 && stud[j].roll > key.roll)
            {
                stud[j + 1] = stud[j];
                j--;
            }
            stud[j + 1] = key;
        }
        cout << "Sorted using Insertion Sort (Roll-No)" << endl;
        displayDetails();
    }

    // Insertion Sort by Name
    void insertionSortByName()
    {
        for (int i = 1; i < n; i++)
        {
            SEIT key = stud[i];
            int j = i - 1;
            while (j >= 0 && stud[j].name > key.name)
            {
                stud[j + 1] = stud[j];
                j--;
            }
            stud[j + 1] = key;
        }
        cout << "Sorted using Insertion Sort (Name)" << endl;
        displayDetails();
    }
    // Linear Search by Roll No
    void linearSearch()
    {
        int r;
        cout << "Enter roll number to search: ";
        cin >> r;
        for (int i = 0; i < n; i++)
        {
            if (stud[i].roll == r)
            {
                cout << "\nStudent found:\n";
                cout << "Roll Number: " << stud[i].roll << endl;
                cout << "Name: " << stud[i].name << endl;
                cout << "SGPA: " << stud[i].sgpa << endl;
                return;
            }
        }
        cout << "Student with roll number " << r << " not found.\n";
    }
    //Binary Search on roll no
    void binarySearch(){
        int r;
        cout<<"Enter the roll-no to search : "<<endl;
        cin>>r;

        int low = 0, high = n - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(stud[mid].roll == r)
            {
                cout << "Student found:\n";
                cout << "Roll Number: " << stud[mid].roll << endl;
                cout << "Name: " << stud[mid].name << endl;
                cout << "SGPA: " << stud[mid].sgpa << endl;
                return;
            }
            else if(stud[mid].roll < r){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        cout<<"Student with Roll-No "<<r<<" not found!!"<<endl;
    }
    // Partition by SGPA
    int partition(int low, int high){
        float pivot = stud[high].sgpa;
        // hold the element that is >= pivot
        // in short all the elements upto i are sorted
        int i = low - 1;
        for(int j = low;j < high; j++){
            if(stud[j].sgpa >= pivot){
                i++;
                SEIT temp = stud[i];
                stud[i] = stud[j];
                stud[j] = temp; 
            }
        }
        // swapping the new pivot and the last element
        SEIT temp = stud[i + 1];
        stud[i+1] = stud[high];
        stud[high] = temp;

        // returning pivot
        return i + 1;
    }
    void quickSort(int low, int high){
        if(low < high){
            int pi = partition(low,high);
            quickSort(low,pi-1);
            quickSort(pi+1,high);
        }
        displayDetails();
    }
};

int main()
{
    StudentDetails sd;
    int n;
    int ch;
    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Input Student Details\n";
        cout << "2. Display Student Details\n";
        cout << "3. Bubble Sort by Roll Number\n";
        cout << "4. Bubble Sort by Name\n";
        cout << "5. Insertion Sort by Roll Number\n";
        cout << "6. Insertion Sort by Name\n";
        cout << "7. Search by Roll Number(Linear Search)\n";
        cout << "8. Search by Roll Number(Binary Search)\n";
        cout << "9. Quick Sort (SGPA)\n";
        cout << "10. EXIT\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            n = sd.inputDetails();
            break;
        case 2:
            sd.displayDetails();
            break;
        case 3:
            sd.bubbleSortByRoll();
            break;
        case 4:
            sd.bubbleSortByName();
            break;
        case 5:
            sd.insertionSortByRoll();
            break;
        case 6:
            sd.insertionSortByName();
            break;
        case 7:
            sd.linearSearch();
            break;
        case 8:
            sd.binarySearch();
            break;
        case 9 : 
            sd.quickSort(0,n-1);
            break;
        case 10:
            cout<<"\nExiting"<<endl;
            break;
        default:
            cout << "Invalid Choice\n";
            break;
        }
    } while (ch != 9);

    return 0;
}
