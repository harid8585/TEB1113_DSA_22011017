/*
id:22011017
name:harid
group: g1
lab: L6
*/
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string name;
    Node *next_ptr;

    Node(string name, Node *next_ptr = nullptr)
    {
        this->name = name;
        this->next_ptr = next_ptr;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    // Constructor
    Queue(Node *front = nullptr)
    {
        this->front = front;
        this->rear = front;
        if (front)
            front->next_ptr = nullptr;
    }

    // Destructor to free memory
    ~Queue()
    {
        while (front)
        {
            dequeue();
        }
    }

    // Enqueue operation
    void enqueue(Node *node)
    {
        if (!node)
            return;

        node->next_ptr = nullptr;

        if (!front)
        {
            front = node;
            rear = node;
        }
        else
        {
            rear->next_ptr = node;
            rear = node;
        }
    }

    // Dequeue operation
    void dequeue()
    {
        if (!front)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node *temp = front;
        front = front->next_ptr;
        cout << "Removing: " << temp->name << endl;
        delete temp;

        // If front becomes NULL, rear should also be NULL
        if (!front)
            rear = nullptr;
    }

    // Display the queue
    void display_queue()
    {
        Node *current = front;
        if (!current)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        while (current)
        {
            cout << current->name;
            if (current->next_ptr)
                cout << " <- ";
            current = current->next_ptr;
        }

        cout << " <- NULL" << endl;
    }
};

int main()
{
    // Create nodes dynamically
    Node *node1 = new Node("Ali");
    Node *node2 = new Node("Ahmed");
    Node *node3 = new Node("Alee");
    Node *node4 = new Node("Abu");

    // Create queue and add nodes
    Queue queue(node1);
    queue.enqueue(node2);
    queue.enqueue(node3);
    queue.enqueue(node4);

    // Display the queue
    cout << "Initial Queue: ";
    queue.display_queue();

    // Dequeue an element
    queue.dequeue();

    // Display the queue after dequeue
    cout << "After Dequeue: ";
    queue.display_queue();

    return 0;
}
