//r 
#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define F first
#define S second
#define pb push_back
#define optimize();ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }

};
//inse
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
//print linked list
void print_linked_list(Node* head) {
    cout << "Linked List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int32_t main(){
    int value;
    Node *head=NULL;
    while(true){
        cin>>value;
        if(value==-1){
            break;
        }
        // insert_at_tail
        insert_at_tail(head, value) 
    
  }   
      //print
        print_linked_list(head)    
}
 
