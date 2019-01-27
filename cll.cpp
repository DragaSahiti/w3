#include <iostream>
using namespace std;

// Generic Programming - Ignore 

class Node{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    Node * next;
    // Construct that makes the ptr to NULL
    Node(int value){
        next = NULL;
        data = value;
    }
};

class CSLL{
    public:
    Node * head;
    CSLL(){
        head = NULL;
    }
    // Inserts to the end of the linked list.
    void insert(int value){
        
        // Create a new node
        Node * temp = new Node(value);
        // CHeck if empty list
        if(head == NULL){
            head = temp;
        }  
        else{ // If not empty list. 
            Node * current = head;
            while(current->next != head)
                current = current->next;
            current->next = temp;
        }
        temp->next = head;
    }
    // Displays the linked list.
    void display(){
        Node * current = head;
        if(current == NULL) {
            cout << "No elements " << endl;
            return;
        }
        while(current->next != head){ // Stopping at head
            cout << current -> data << "->";
            current = current -> next;
        }
        // Printing the last element
        cout << current -> data ;
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

        // Create a new Node
        Node * temp = new Node(value);
       
        // Moving ptrs like magic ! if not head
        temp->next = current->next;
        current->next = temp;
         
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
        // delete temp 
        delete temp; 
    }
    
    void Delet(){
        // Deletes the last element.
        // Reach the place before head
        Node * current = head;
        while (current->next->next == head){
             current = current->next;
        }
        // Move ptrs
        Node * temp = current->next;
        current->next = temp->next;
        // Delete temp
        delete temp;
        
    }
    void CountItems(){
        // Counts the Number of items.
        // Initialze count
        int count = 1;
        // Initialise current
        Node * current = head;
        while(current->next != head)
        {
           count++;
           current = current->next;
        }
        cout << count << endl;
    }

};

int main(){
    CSLL csll1;
    for(int i= 1; i < 11; i++){
       csll1.insert(i);
    }
    //csll1.insert(1);
    csll1.display();
    csll1.CountItems();
    
    csll1.InsertAt(9,5);
    csll1.display();
    csll1.CountItems();
    
    csll1.Delet();
    csll1.display();
    csll1.CountItems();
    
    csll1.DeleteAt(5);
    csll1.display();
    csll1.CountItems();
}
