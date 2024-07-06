//r 
// r
#include <bits/stdc++.h>
#define int long long int
using namespace std;
#define F first
#define S second
#define pb push_back
#define optimize()              \
  ;                             \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define endl '\n'

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int value) : val(value), next(nullptr) {}
};

void insert_Head_at_linked_list(Node*& head, int value) {
    Node* new_node = new Node(value);
    new_node->next = head;
    head = new_node;
    cout << "Inserted value " << value << " at the head" << endl;
}

void insert_at_tail(Node*& head, int value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
        head = new_node;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    cout << "Inserted value " << value << " at the tail" << endl;
}

void print_linked_list(Node* head) {
    cout << "Linked List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insert_linked_list(Node*& head, int pos, int val) {
    if (pos < 0) {
        cout << "Position out of bounds" << endl;
        return;
    }
    if (pos == 0) {
        insert_Head_at_linked_list(head, val);
        return;
    }

    Node* new_node = new Node(val);
    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
        if(temp==NULL){
            cout<<"Invalid Index"<<endl;
        }
    }
    if (temp == nullptr) {
        cout << "Position out of bounds" << endl;
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    cout << "Inserted value " << val << " at position " << pos << endl;
}

void Delete_linked_list_at_position(Node*& head, int pos) {
    if (head == nullptr) {
        cout << "Linked List is empty" << endl;
        return;
    }
    if (pos < 1) {
        cout << "Position out of bounds" << endl;
        return;
    }

    Node* temp = head;
    if (pos == 1) {
        head = temp->next;
        delete temp;
        cout << "Deleted node at position " << pos << endl;
        return;
    }

    for (int i = 0; temp != nullptr && i < pos - 2; ++i) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position out of bounds" << endl;
        return;
    }

    Node* deletedNode = temp->next;
    temp->next = temp->next->next;
    delete deletedNode;
    cout << "Deleted node at position " << pos << endl;
}

void Delete_HeadNode(Node*& head) {
    if (head == nullptr) {
        cout << "Linked List is empty" << endl;
        return;
    }

    Node* deletedNode = head;
    head = head->next;
    delete deletedNode;
    cout << "Head node has been successfully deleted" << endl;
}

int32_t main() {
  
    Node* head = nullptr;

    while (true) {
        cout << "Option 0: Insert at the Head" << endl;//done
        cout << "Option 1: Insert at the Tail" << endl;//done
        cout << "Option 2: Print the Linked List" << endl;//done
        cout << "Option 3: Insert at any Position" << endl;//done
        cout << "Option 4: Delete a Node at a Position" << endl;//done
        cout << "Option 5: Delete the Head Node" << endl;
        cout << "Option 6: Terminate the Program" << endl;

        int option;
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
            case 0:
                int value;
                cout << "Insert value for Head: ";
                cin >> value;
                insert_Head_at_linked_list(head, value);
                break;
            case 1:
                int tailValue;
                cout << "Please Enter Value: ";
                cin >> tailValue;
                insert_at_tail(head, tailValue);
                break;
            case 2:
                print_linked_list(head);
                break;
            case 3:
                int pos, val;
                cout << "Enter the position: ";
                cin >> pos;
                cout << "Enter the value: ";
                cin >> val;
                insert_linked_list(head, pos, val);
                break;
            case 4:
                int positionToDelete;
                cout << "Give the position index to delete the value from linked list: ";
                cin >> positionToDelete;
                if (positionToDelete == 0) {
                    Delete_HeadNode(head);
                } else {
                    Delete_linked_list_at_position(head, positionToDelete);
                }
                break;
            case 5:
                Delete_HeadNode(head);
                break;
            case 6:
                cout << "Program terminated" << endl;
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    }

    return 0;
}

