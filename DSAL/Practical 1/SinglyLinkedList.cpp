#include <iostream>
#include <string>
using namespace std;

struct Snode {
    string name;
    string phoneNumber;
    int roll;
    Snode *next;
};

class SLinkedList {
public:
    Snode *head;

    SLinkedList() {
        head = nullptr;
    }

    Snode *getNode(string name, string phoneNumber, int roll) {
        Snode *newNode = new Snode;
        newNode->name = name;
        newNode->phoneNumber = phoneNumber;
        newNode->roll = roll;
        newNode->next = nullptr;
        return newNode;
    }

    void insertNode() {
        int roll, pos;
        string name, phoneNumber;
        cout << "\n\nEnter a position to insert data : ";
        cout << "\n1. At beginning";
        cout << "\n2. At end";
        cout << "\n3. At specific position : " << endl;
        cin >> pos;
        cout << "\nEnter the name : ";
        cin >> name;
        cout << "\nEnter the phone number : ";
        cin >> phoneNumber;
        cout << "\nEnter the roll : ";
        cin >> roll;

        if (pos == 1)
            insertAtBeginning(name, phoneNumber, roll);
        else if (pos == 2)
            insertAtEnd(name, phoneNumber, roll);
        else
            insertAtPos(name, phoneNumber, roll, pos);
    }

    void insertAtBeginning(string name, string phoneNumber, int roll) {
        Snode *temp = getNode(name, phoneNumber, roll);
        temp->next = head;
        head = temp;
    }

    void insertAtEnd(string name, string phoneNumber, int roll) {
        Snode *temp = getNode(name, phoneNumber, roll);
        if (head == nullptr) {
            head = temp;
        } else {
            Snode *ptr = head;
            while (ptr->next != nullptr)
                ptr = ptr->next;
            ptr->next = temp;
        }
    }

    int getCount() {
        int count = 0;
        Snode *temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void insertAtPos(string name, string phoneNumber, int roll, int pos) {
        int count = getCount();
        if (pos < 1 || pos > count + 1) {
            cout << "Enter a valid position (1 to " << count + 1 << ")\n";
            return;
        }
        if (pos == 1) {
            insertAtBeginning(name, phoneNumber, roll);
        } else if (pos == count + 1) {
            insertAtEnd(name, phoneNumber, roll);
        } else {
            Snode *newNode = getNode(name, phoneNumber, roll);
            Snode *temp = head;
            for (int i = 1; i < pos - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        Snode *temp = head;
        if (head == nullptr) {
            cout << "List is empty!!";
        } else {
            cout << "\n\nUser Data : " << endl;
            cout << "Name\tPhoneNumber\tRoll-No";
            while (temp != nullptr) {
                cout << "\n" << temp->name << "\t" << temp->phoneNumber << "\t" << temp->roll;
                temp = temp->next;
            }
        }
        cout << endl;
    }

    void searchNode() {
        string field;
        int roll;
        cout << "\nEnter a field to search : ";
        cin >> field;
        cout << "\nEnter roll (else -1): ";
        cin >> roll;

        Snode *temp = head;
        while (temp != nullptr) {
            if (temp->name == field || temp->phoneNumber == field || (roll != -1 && temp->roll == roll)) {
                cout << "\nContact found!!\n";
                cout << "Name : " << temp->name << "\nPhone Number : " << temp->phoneNumber << "\nRoll-No : " << temp->roll << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "\nContact not found!!";
    }

    void deleteNode() {
        int pos;
        cout << "\nEnter position to delete (Enter -1 for last): ";
        cin >> pos;
        int count = getCount();

        if (pos == 1) {
            deleteAtFirst();
        } else if (pos == count || pos == -1) {
            deleteAtLast();
        } else {
            deleteAtPos(pos);
        }
    }

    void deleteAtFirst() {
        if (head == nullptr) {
            cout << "List is empty!!\n";
            return;
        }
        Snode *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtLast() {
        if (head == nullptr) {
            cout << "List is empty!!\n";
            return;
        } else if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Snode *temp = head;
            while (temp->next->next != nullptr)
                temp = temp->next;
            delete temp->next;
            temp->next = nullptr;
        }
    }

    void deleteAtPos(int pos) {
        int count = getCount();
        if (pos < 1 || pos > count) {
            cout << "Invalid position!!\n";
            return;
        }
        if (pos == 1) {
            deleteAtFirst();
        } else {
            Snode *temp = head;
            for (int i = 1; i < pos - 1; i++) {
                temp = temp->next;
            }
            Snode *delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
        }
    }

    void reverseList() {
        Snode *prev = nullptr;
        Snode *current = head;
        Snode *next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        cout << "List reversed successfully!!\n";
    }
};

int main() {
    int ch;
    SLinkedList sl;
    while (true) {
        cout << "\n-------- SINGLY LINKED LIST --------------" << endl;
        cout << "1. Insert data\n2. Display data\n3. Delete data\n4. Search data\n5. Reverse list\n6. Exit\n";
        cin >> ch;

        switch (ch) {
        case 1: sl.insertNode(); cout << "Node Inserted Successfully!!\n"; break;
        case 2: sl.display(); break;
        case 3: sl.deleteNode(); cout << "Node deleted Successfully!!\n"; break;
        case 4: sl.searchNode(); break;
        case 5: sl.reverseList(); break;
        case 6: exit(0);
        default: cout << "\nEnter a proper choice!\n";
        }
    }
    return 0;
}
