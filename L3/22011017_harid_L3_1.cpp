/*
id:22011017
name:harid
group: g1
lab: L3
*/

#include <iostream>
#include <string>
using namespace std;


struct Node {
    string name;
    Node* next_ptr;

    Node(string n) : name(n), next_ptr(nullptr) {}
};


class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    
    void add_element(Node* newNode) {
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next_ptr) {
                temp = temp->next_ptr;
            }
            temp->next_ptr = newNode;
        }
    }

    
    void display_list() {
        Node* temp = head;
        while (temp) {
            cout << temp->name << " -> ";
            temp = temp->next_ptr;
        }
        cout << "NULL" << endl;
    }

    
    void delete_by_value(const string& val) {
        Node* temp = head;
        Node* prev = nullptr;

        while (temp && temp->name != val) {
            prev = temp;
            temp = temp->next_ptr;
        }

        if (!temp) {
            cout << "Value '" << val << "' not found." << endl;
            return;
        }

        if (!prev) {
            head = temp->next_ptr;
        } else {
            prev->next_ptr = temp->next_ptr;
        }

        delete temp;
        cout << "Deleted node with value: " << val << endl;
    }
};


int main() {
    
    Node* node1 = new Node("Alice");
    Node* node2 = new Node("Bob");
    Node* node3 = new Node("Charlie");

    
    LinkedList linkedlst;
    linkedlst.add_element(node1);
    linkedlst.add_element(node2);
    linkedlst.add_element(node3);

    
    linkedlst.display_list();

    return 0;
}
