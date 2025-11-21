#include <iostream>
using namespace std;

typedef struct Node {
  struct Node *next;
  string name, email;
  long long contact;
} Cnode;
bool is_valid_number(long long contact) {
  // Function to check contact number
  string s = to_string(contact);
  int n = s.length();
  return (n == 10);
}
bool is_valid_name(string name) {
  // Function to check name
  int n = name.length();
  for (int i = 0; i < n; i++) {
    if (!isalpha(name[i])) {
      return false;
    }
  }
  return true;
}

bool is_valid_email(string email) {
  // Function to check email
  int n = email.length();
  int f1 = 0, f2 = 0;
  int temp1 = 0;
  for (int i = 0; i < n; i++) {
    if (email[i] == '@') {
      f1++;
      temp1 = i;
    }
  }
  if (f1 != 1)
    return false;
  int temp2 = 0;
  for (int i = 0; i < n; i++) {
    if (email[i] == '.') {
      f2++;
      temp2 = i;
    }
  }
  return (f2 == 1) && (temp2 > temp1);
}

class singly_linked_list {
  Cnode *head = NULL;
  int count = 0;

public:
  Cnode *get_node() {
    // Creation of new node
    Cnode *node = new Cnode;
    bool flag = 1;
    do {
      if (!flag)
        cout << "Please enter valid details!!\n";
      cout << "Enter Name,Email,Contact No.:";
      cin >> (node->name);
      cin >> (node->email);
      cin >> (node->contact);
      flag = is_valid_name(node->name) && is_valid_number(node->contact) &&
             is_valid_email(node->email);
    } while (!flag);
    count++;
    node->next=NULL;
    return node;
  }
  void insert_beg(Cnode *new_node) {
    if (head == NULL) {
      head = new_node;
    } else {
      new_node->next = head;
      head = new_node;
    }
    cout << "Insertion Successfull!\n";
  }
  void insert_end(Cnode *new_node) {
    if (head == NULL) {
      head = new_node;
    } else {
      Cnode *temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = new_node;
    }
    cout << "Insertion Successfull!\n";
  }
  void insert_pos(Cnode *new_node, int pos) {
    Cnode *prev = NULL;
    Cnode *current = head;
    while (current != NULL && pos > 1) {
      prev = current;
      current = current->next;
      pos--;
    }
    if (pos != 1) {
      cout << "Invalid Position\n";
    } else {
      prev->next = new_node;
      new_node->next = current;
      cout << "Insertion Successfull!\n";
    }
  }
  void insert_menu() {
    int pos;
    cout << "Enter Position:";
    cin >> pos;
    Cnode *new_node = get_node();
    if (pos == 1)
      insert_beg(new_node);
    else if (pos == count + 1)
      insert_end(new_node);
    else {
      insert_pos(new_node, pos);
    }
  }
  void reverse() {
    if (head == NULL) {
      cout << "Contact List is Empty!\n";
    } else {
      Cnode *prev = NULL;
      Cnode *current = head;
      Cnode *next = head->next;
      while (next != NULL) {
        current->next = prev;
        prev = current;
        current = next;
        next = current->next;
      }
      current->next=prev;
      head=current;
      cout << "Reverse Successfull!\n";
    }
  }
  void search() {
    long long contact;
    cout << "Enter contact number to search:";
    cin >> contact;
    Cnode *temp = head;
    while (temp != NULL) {
      if (temp->contact == contact) {
        cout << "Found!!\n";
        cout << "Name:" << temp->name << '\n';
        cout << "Email:" << temp->email << '\n';
        return;
      }
      temp = temp->next;
    }
    cout << "Not found!!\n";
  }
  void delete_beg() {
    if (head == NULL) {
      cout << "Nothing to delete\n";
    } else {
      Cnode *temp = head;
      head = head->next;
      delete temp;
      count--;
      cout << "Deletion Successful\n";
    }
  }
  void delete_end() {
    if (head == NULL) {
      cout << "Nothing to delete\n";
    } else if (head->next == NULL) {
      // Only one node
      delete head;
      head = NULL;
      count--;
      cout << "Deletion Successful\n";
    } else {
      Cnode *temp = head;
      Cnode* prev=NULL;
      while (temp->next != NULL) {
        prev=temp;
        temp = temp->next;
      }
      prev->next=NULL;
      delete temp;
      count--;
      cout << "Deletion Successful\n";
    }
  }
  void delete_pos(int pos) {
    Cnode *prev = NULL;
    Cnode *current = head;
    while (current != NULL && pos > 1) {
      prev = current;
      current = current->next;
      pos--;
    }
    if (pos > 1 || current == NULL) {
      cout << "Invalid position\n";
    } else {
      prev->next = current->next;
      delete current;
      count--;
      cout << "Deletion Successful\n";
    }
  }
  void delete_menu() {
    int pos;
    cout << "Enter position to delete:\n";
    cin >> pos;
    if (pos == 1) {
      delete_beg();
    } else if (pos == count) {
      delete_end();
    } else {
      delete_pos(pos);
    }
  }
  void display() {
    Cnode *temp = head;
    while (temp != NULL) {
      cout << "Name:" << temp->name << '\n';
      cout << "Email:" << temp->email << '\n';
      cout << "Contact Number:" << temp->contact << '\n';
      temp = temp->next;
    }
  }
};
int main() {
  singly_linked_list list;
  while (true) {
    cout << "\n=== Contact List Menu ===\n";
    cout << "1. Insert Contact\n";
    cout << "2. Delete Contact\n";
    cout << "3. Search Contact\n";
    cout << "4. Display All Contacts\n";
    cout << "5. Reverse List\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
      list.insert_menu();
      break;
    case 2:
      list.delete_menu();
      break;
    case 3:
      list.search();
      break;
    case 4:
      list.display();
      break;
    case 5:
      list.reverse();
      break;
    case 6:
      cout << "Exiting program. Goodbye!\n";
      exit(0);
    default:
      cout << "Invalid choice! Please try again.\n";
    }
  }
  return 0;
}