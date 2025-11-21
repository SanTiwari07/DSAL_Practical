#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    string rollNo;
    string address;
};

void createStudentData() {
    ofstream outFile("Student.txt");
    if (!outFile) {
        cout << "Error in opening the file!!" << endl;
        return;
    }
    int noOfRecords;
    cout << "Enter the number of records : " << endl;
    cin >> noOfRecords;
    cin.ignore();
    outFile << left << setw(15) << "Name" << setw(10) << "Roll-No" << "Address" << endl;
    for (int i = 0; i < noOfRecords; i++) {
        Student s;
        cout << "Enter Name of Student " << (i + 1) << " : " << endl;
        getline(cin, s.name);
        cout << "Enter Roll-No of Student " << (i + 1) << " : " << endl;
        getline(cin, s.rollNo);
        cout << "Enter Address of Student " << (i + 1) << " : " << endl;
        getline(cin, s.address);
        outFile << left << setw(15) << s.name << setw(10) << s.rollNo << s.address << "\n";
    }
    outFile.close();
    cout << "Written to file successfully!!" << endl;
}

void display() {
    ifstream inFile("Student.txt");
    if (!inFile) {
        cout << "Error : Student.txt not found!!" << endl;
        return;
    }
    cout << "\nStudent Records" << endl;
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}

void addNewRecords() {
    ofstream outFile("Student.txt", ios::app);
    if (!outFile) {
        cout << "Error: Student file not found.\n";
        return;
    }
    Student s;
    cin.ignore();
    cout << "\nPlease enter the information of the new student:\n";
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Roll-No: ";
    getline(cin, s.rollNo);
    cout << "Enter Address: ";
    getline(cin, s.address);
    outFile << left << setw(15) << s.name << setw(10) << s.rollNo << s.address << '\n';
    outFile.close();
    cout << "New data inserted successfully!!" << endl;
}

void searchStudent() {
    ifstream inFile("Student.txt");
    if (!inFile) {
        cout << "Error: Student.txt not found.\n";
        return;
    }
    string searchTerm;
    cin.ignore();
    cout << "Enter Name or Roll-No to search: ";
    getline(cin, searchTerm);

    bool found = false;
    string line;
    getline(inFile, line); // skip header

    while (getline(inFile, line)) {
        stringstream ss(line);
        Student s;
        ss >> s.name >> s.rollNo;
        getline(ss, s.address);
        if (!s.address.empty() && s.address[0] == ' ')
            s.address.erase(0, s.address.find_first_not_of(' '));

        if (s.name == searchTerm || s.rollNo == searchTerm) {
            cout << left << setw(15) << s.name << setw(10) << s.rollNo << s.address << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No record found matching \"" << searchTerm << "\".\n";
    }
    inFile.close();
}

void modifyStudent() {
    ifstream inFile("Student.txt");
    if (!inFile) {
        cout << "No student records found.\n";
        return;
    }
    string rollNoToModify;
    cin.ignore();
    cout << "Enter Roll-No of student to modify: ";
    getline(cin, rollNoToModify);

    ofstream tempFile("temp.txt");
    if (!tempFile) {
        cout << "Error creating temp file.\n";
        return;
    }

    string line;
    getline(inFile, line);
    tempFile << line << "\n";

    bool found = false;
    while (getline(inFile, line)) {
        stringstream ss(line);
        Student s;
        ss >> s.name >> s.rollNo;
        getline(ss, s.address);
        if (!s.address.empty() && s.address[0] == ' ')
            s.address.erase(0, s.address.find_first_not_of(' '));

        if (s.rollNo == rollNoToModify) {
            found = true;
            cout << "Enter new name (current: " << s.name << "): ";
            getline(cin, s.name);
            cout << "Enter new address (current: " << s.address << "): ";
            getline(cin, s.address);
        }

        tempFile << left << setw(15) << s.name << setw(10) << s.rollNo << s.address << "\n";
    }
    inFile.close();
    tempFile.close();

    if (!found) {
        cout << "Student with Roll-No " << rollNoToModify << " not found.\n";
        remove("temp.txt");
        return;
    }

    remove("Student.txt");
    rename("temp.txt", "Student.txt");
    cout << "Student record updated successfully.\n";
}

void deleteStudent() {
    ifstream inFile("Student.txt");
    if (!inFile) {
        cout << "No student records found.\n";
        return;
    }
    string rollNoToDelete;
    cin.ignore();
    cout << "Enter Roll-No of student to delete: ";
    getline(cin, rollNoToDelete);

    ofstream tempFile("temp.txt");
    if (!tempFile) {
        cout << "Error creating temp file.\n";
        return;
    }

    string line;
    getline(inFile, line);
    tempFile << line << "\n";

    bool found = false;
    while (getline(inFile, line)) {
        stringstream ss(line);
        Student s;
        ss >> s.name >> s.rollNo;
        getline(ss, s.address);
        if (!s.address.empty() && s.address[0] == ' ')
            s.address.erase(0, s.address.find_first_not_of(' '));

        if (s.rollNo == rollNoToDelete) {
            found = true;
            continue; // skip writing this record (delete)
        }
        tempFile << left << setw(15) << s.name << setw(10) << s.rollNo << s.address << "\n";
    }
    inFile.close();
    tempFile.close();

    if (!found) {
        cout << "Student with Roll-No " << rollNoToDelete << " not found.\n";
        remove("temp.txt");
        return;
    }

    remove("Student.txt");
    rename("temp.txt", "Student.txt");
    cout << "Student record deleted successfully.\n";
}

int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Create Student Data (Overwrite file)\n";
        cout << "2. Display All Student Records\n";
        cout << "3. Add New Student Record\n";
        cout << "4. Search a Student\n";
        cout << "5. Modify Student Record\n";
        cout << "6. Delete Student Record\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                createStudentData();
                break;
            case 2:
                display();
                break;
            case 3:
                addNewRecords();
                break;
            case 4:
                searchStudent();
                break;
            case 5:
                modifyStudent();
                break;
            case 6:
                deleteStudent();
                break;
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);
    return 0;
}
