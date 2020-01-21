#include <iostream>

using namespace std;

// PURPOSE: Models a data item in a container
class Node {
    int data;
    Node *next;

public:
    // CONSTRUCTORS
    Node() : data(0), next(NULL) {}

    Node(int new_data) : data(new_data), next(NULL) {}

    // PURPOSE: Simple getters and setters
    Node *get_next() {
        return next;
    }

    void set_next(Node *new_next) {
        next = new_next;
    }

    int get_data() {
        return data;
    }

    void set_data(int new_data) {
        data = new_data;
    }
};

// PURPOSE: Models a linked list container
class LinkedList {
    Node *first;
    int size;

public:
    // CONSTRUCTORS
    LinkedList() : first(NULL), size(0) {
    }

    // PURPOSE: Simple getters and setters
    int get_size() {
        return size;
    }

    // PURPOSE: Inserts a data value at the end of the linked list
    bool push_back(int data);

    // PURPOSE: Removes the last item from a linked list
    bool pop_back();

    // PURPOSE: Prints linked list contents
    void print();

    // PURPOSE: Checks if a specified data value is in the list
    bool find(int value);
};

/**
 *
 * @param {int} data
 * @return
 */
bool LinkedList::push_back(int data) {
    if (!first) {
        first = new Node(data); // set first to point to new node
    } else { // general case
        Node *end = first; //initialize end pointer
        while (end->get_next()) { // iterate until NULL
            end = end->get_next();
        }
        end->set_next((new Node(data))); // insert at the end
        // set next=NULL
    }
    ++size;
    return true; // return true
}

bool LinkedList::pop_back() {
    if (!first) { // if empty list
        return false;
    } else if (!first->get_next()) {
        //if one  none
        delete first;
        first = NULL;
    } else { // general case
        Node *end = first;
        while (end->get_next()->get_next()) { // iterate until we get to the 2nd last node
            end = end->get_next();
        }
        delete end->get_next(); // free up memory for last node
        end->set_next(NULL); //set the last node to point to NULL
        --size;
    }

    return true; // return true
}

void LinkedList::print() {
/**
 * Left for practice
 */
}

bool LinkedList::find(int value) {
    if (!first) {
        return false;
    }
    if (!first->get_next()) {
        return value == first->get_data();
    } else {
        Node *end = first;
        while (end) { // execute until the last node
            if (value == end->get_data()) {
                return true;
            }
            end = end->get_next();
        }
    }
    return false; // return false if the value is not found
}

int main() {
    // driver code to test LinkedList and Node classes
    LinkedList list; // create a new list

    // test push_back() and print()
    list.push_back(5);
    list.push_back(7);
    list.push_back(3);
    list.push_back(1);
    list.push_back(14);
    list.print();
    cout << "The number of inserted nodes in the list: " << list.get_size() << endl;

    // test find()
    cout << "The value 11 is inside the list: " << (list.find(11) ? "Yes" : "No") << endl;
    cout << "The value 3 is inside the list: " << (list.find(3) ? "Yes" : "No") << endl;

    // test pop_back() and print()
    list.pop_back(); // delete the last node
    list.pop_back(); // delete the last node
    list.pop_back(); // delete the last node
    list.pop_back(); // delete the last node
    list.pop_back(); // delete the last node
    list.pop_back(); // delete the last node; try one extra
    list.print();
    cout << "The number of inserted nodes in the list: " << list.get_size() << endl;

    return 0;
}

