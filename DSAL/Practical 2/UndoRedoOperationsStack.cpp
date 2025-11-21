#include <iostream>
#include <string>
using namespace std;

struct SNode {
    string data;
    SNode *next;
};

class MyStack {
public:
    SNode *top;
    MyStack() {
        top = nullptr;
    }

    SNode *create(string data) {
        SNode *temp = new SNode();
        temp->data = data;
        temp->next = NULL;
        return temp;
    }

    // pushing elements into stack
    void push(string data) {
        SNode *temp = create(data);
        temp->next = top;
        top = temp;
        cout << "Node inserted successfully!!" << endl;
    }

    // popping elements from stack
    string pop() {
        if (isEmpty()) {
            cout << "Stack is empty!!" << endl;
            return "";
        } else {
            SNode *temp = top;
            string data = top->data;
            top = top->next;
            delete temp;
            return data;
        }
    }

    // peek -> topmost element in the list
    string peek() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return "";
        }
        return top->data;
    }

    // displays data (top to bottom)
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Elements in the Stack (Top to Bottom): ";
            SNode *temp = top;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    // checks if the stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // clears the entire stack
    void clear() {
        while (!isEmpty()) {
            pop();
        }
        cout << "Stack cleared!!" << endl;
    }
};

class TextEditor {
public:
    MyStack undoStack, redoStack;

    void insert(string data) {
        undoStack.push(data);
        redoStack.clear();
    }

    // pushing data from undoStack to redoStack
    void undo() {
        if (undoStack.isEmpty()) {
            cout << "UndoStack is Empty" << endl;
        } else {
            string data = undoStack.pop();
            redoStack.push(data);
            cout << "Undo Element : " << data << endl;
        }
    }

    // pushing data from redoStack to undoStack
    void redo() {
        if (redoStack.isEmpty()) {
            cout << "RedoStack is Empty" << endl;
        } else {
            string data = redoStack.pop();
            undoStack.push(data);
            cout << "Redo Element : " << data << endl;
        }
    }

    // displays current document (undo stack contents)
    void displayData() {
        cout << "Current Document Content: ";
        undoStack.display();
    }
};

int main() {
    TextEditor editor;
    int choice;
    string data;

    while (true) {
        cout << "\n************** Text Editor *************" << endl;
        cout << "1. Insert" << endl
             << "2. Undo" << endl
             << "3. Redo" << endl
             << "4. Display Document" << endl
             << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            editor.insert(data);
            break;
        case 2:
            editor.undo();
            break;
        case 3:
            editor.redo();
            break;
        case 4:
            editor.displayData();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
