#include <iostream>
using namespace std;

// Generic Programming - Ignore 

class Node{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    Node * next;
    Node * prev;
    // Construct that makes the ptr to NULL
    Node(int value){
        next = NULL;
        prev = NULL;
        data = value;
    }
};

class DLL{
    public:
    Node * head;
    Node * tail;
    DLL(){
        head = NULL;
        tail = NULL;
    }
    void insert(int value){
        // Create a new node
        Node * temp = new Node(value);
        // CHeck if empty list
        if(head == NULL){
            head = temp;
        }  
        else{ // If not empty list. 
            Node * current = head;
            while(current->next != NULL)
                current = current->next;
            current->next = temp;
            temp->prev = current;    
        }
    }
    void display(){
        Node *current = head;
        Node *last;
        cout << "Print in   order : ";
        while(current!=NULL){
            cout <<current->data<< "->"; 
            // Store the current in last (to catch the tail to print in reverse)
            last = current;
            // Move Forward
            current = current->next;
        }
        cout << endl;
        cout << "Print in Reverse order : ";
        while(last!=NULL){
            cout <<last->data<< "->";
            // Move backwards 
            last = last->prev;
        }
        cout << endl;   
    }
    void InsertAt(int value, int pos){
         // Reach the place before the pos
        Node * current = head;
        int i =1;
        while(i < pos-1)
        {
            i++;
            current = current->next;
        }

        // Create a node
        Node * temp = new Node(value);
        temp -> data = value;


        // Moving ptrs like magic ! if not head
        temp->next = current->next;
        current->next = temp;
        temp->prev = current;
        temp->next->prev = temp;
    }
    void DeleteAt(int pos){
         // Reach the place before the pos
        Node * current = head;
        int i =1;
        while(i < pos-1)
        {
            i++;
            current = current->next;
        } 
        //move the ptrs
        Node * temp = current->next;
        current->next = temp->next;
        temp->next->prev = current;
        // delete temp 
        delete temp; 
    }
    void Del(){
        // Deletes the last element.
        // store the tail in temp
        Node * temp = tail;
        
        // before tail has to point to null
        Node * current = head;
        while(current->next != tail)
        {
            current = current->next;
        }
        current->next = NULL; 

        // update tail
        current = tail;
        // delete temp
         delete temp;
    }
    void CountItems(){
        // Counts the Number of items.
         // Initialze count
        int count = 0;
        // Initialise current
        Node * current = head;
        while(current != NULL)
        {
           count++;
           current = current->next;
        }
        cout << count << endl;
        
    }

};

int main(){
    DLL dll1;
    for(int i= 1; i < 11; i++){
        dll1.insert(i);
    }
    dll1.display();
    dll1.InsertAt(9,5);
    dll1.display();
    dll1.CountItems();
    dll1.DeleteAt(5);
    dll1.display();
    dll1.CountItems();
    dll1.Del();
    dll1.display();
    dll1.CountItems();
}
