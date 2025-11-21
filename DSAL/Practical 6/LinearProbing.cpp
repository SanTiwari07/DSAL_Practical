#include <iostream>
#include <vector>
using namespace std;

class HashTable {
    vector<int> table;
    int size;
    bool isQuadratic; // true = quadratic probing, false = linear probing

public:
    HashTable(int s, bool quadratic = false) {
        size = s;
        isQuadratic = quadratic;
        table.assign(size, -1); // set all slots to empty
    }


    int hash(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hash(key);
        int i = 0;

        while (i < size) {
            int newIndex = isQuadratic
                ? (index + i * i) % size  // quadratic probing
                : (index + i) % size;     // linear probing

            if (table[newIndex] == -1) {  // found empty slot
                table[newIndex] = key;
                cout << "Inserted " << key << " at index " << newIndex << endl;
                return;
            }
            i++;
        }

        cout << "Hash table is full, cannot insert " << key << endl;
    }

    bool search(int key) {
        int index = hash(key);
        int i = 0;

        while (i < size) {
            int newIndex = isQuadratic
                ? (index + i * i) % size
                : (index + i) % size;

            if (table[newIndex] == key)
                return true;
            if (table[newIndex] == -1)
                return false;

            i++;
        }
        return false;
    }

    void display() {
        cout << "\nHash Table (" << (isQuadratic ? "Quadratic" : "Linear") << " Probing):\n";
        for (int i = 0; i < size; i++) {
            cout << i << " --> ";
            if (table[i] == -1)
                cout << "empty";
            else
                cout << table[i];
            cout << endl;
        }
    }
};

int main() {
    int size, choice, key;
    bool quadratic;

    cout << "Enter hash table size: ";
    cin >> size;

    cout << "\nChoose probing method:\n";
    cout << "1. Linear Probing\n";
    cout << "2. Quadratic Probing\n";
    cout << "Enter choice: ";
    cin >> choice;

    quadratic = (choice == 2);
    HashTable ht(size, quadratic);

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                ht.insert(key);
                break;

            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                cout << (ht.search(key) ? "Key found!" : "Key not found!") << endl;
                break;

            case 3:
                ht.display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}