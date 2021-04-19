#include<iostream>
#include<string>
using namespace std;

struct initialNode {
    string initial; //item of node
    initialNode* link; //link to another node
};

int main() {
    //declarations
    string initial = ""; //displays a number of initials by the user input

    //creates the initial values for the head node
    initialNode* head = new initialNode; //points to the head node
    head->initial = "";
    head->link = nullptr;

    //creates an initial link list of values based on the user input
    //get user input
    initialNode* nextInitialNode = new initialNode;
    nextInitialNode = head; //nextInitialNode is the first node

    cout << "How many initials are you going to enter? ";
    cin >> initial;

    //calculation
    for (int i = 0; i < stoi(initial); i++) {
        nextInitialNode->link = new initialNode; //creates a node at the end of the list
        nextInitialNode = nextInitialNode->link; //points to that node
        nextInitialNode->link = nullptr;

        cout << "Enter initial " << (i + 1) << ": ";
        cin >> nextInitialNode->initial;
    }

    //output
    //traverse the linked list and displays contents
    cout << endl << "Traversing the link list" << endl;
    nextInitialNode = head->link;
    while (nextInitialNode != nullptr) {
        cout << nextInitialNode->initial << endl;
        nextInitialNode = nextInitialNode->link;
    }

    //deletes the head node from the free store memory
    delete nextInitialNode;
    nextInitialNode = nullptr;

    delete head;
    head = nullptr;
    return 0;
}